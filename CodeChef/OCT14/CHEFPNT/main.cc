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

bool a[101][101];
bool b[101][101];

int main() {
  DRIII(N, M, K);
  REP(k, K) {
    DRII(i, j);
    a[i][j] = true;
  }
  memcpy(b, a, sizeof a);
  V(PII) ans;
  REP1(i, 1, N) {
    REP1(j, 1, M) {
      if (!b[i][j]) {
        ans.EB(i, j);
        while (j <= N && !b[i][j]) {
          b[i][j] = true;
          j++;
        }
      }
    }
  }
  memcpy(b, a, sizeof a);
  V(PII) ans2;
  REP1(j, 1, M) {
    REP1(i, 1, N) {
      if (!b[i][j]) {
        ans2.EB(i, j);
        while (i <= N && !b[i][j]) {
          b[i][j] = true;
          i++;
        }
      }
    }
  }
  if(ans2.size() < ans.size()) {
    PI(ans2.size());
    FOR(p, ans2) {
      PIS(p.F); PIS(p.S); PI(1);
    }
  } else {
    PI(ans.size());
    FOR(p, ans) {
      PIS(p.F); PIS(p.S); PI(0);
    }
  }
  
  return 0;
}
