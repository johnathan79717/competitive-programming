#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <sstream>
#include <bitset>
using namespace std;
#define BG begin()
#define ED end()
#define FOR(i,c) for(auto &i: c)
#define SZ size()
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define RL(x) scanf("%lld",&x)
#define DRI(x) int x;RI(x)
#define DRL(x) LL x;RL(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PL(x) printf("%lld\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define PQ priority_queue
#define E emplace
#define EB emplace_back
#define LB lower_bound
#define UB upper_bound
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000;

char g[1001][1001];
bool south[1001][1001], east[1001][1001];

int main() {
  DRI(T);
  REP(t, T) {
    MS0(south);
    MS0(east);
    DRI(N);
    REP(i, N) RS(g[i]);
    REP(j, N) {
      if(g[N-1][j] == '.')
        south[N-1][j] = true;
    }
    PER(i, N-1) {
      REP(j, N) {
        if(g[i][j] != '#' && south[i+1][j])
          south[i][j] = true;
      }
    }
    REP(i, N) {
      if(g[i][N-1] == '.')
        east[i][N-1] = true;
    }
    REP(i, N) {
      PER(j, N-1) {
        east[i][j] = g[i][j] != '#' && east[i][j+1];
      }
    }
    int ans = 0;
    REP(i, N) {
      REP(j, N) {
        // PIS(east[i][j]);
        if(south[i][j] && east[i][j])
          ans++;
      }
      // puts("");
    }
    PI(ans);
  }
  return 0;
}
