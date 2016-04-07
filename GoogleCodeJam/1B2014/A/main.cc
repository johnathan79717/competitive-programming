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
#include <cassert>
#include <unordered_set>
#include <unordered_map>
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

char str[101][101];
int idx[101];

int main() {
  DRI(T);
  REP1(t, 1, T) {
    printf("Case #%d: ", t);
    MS0(str);
    MS0(idx);
    DRI(N);
    REP(i, N) {
      RS(str[i]);
    }
    LL ans = 0;
    bool fail = false;
    while(true) {
      REP(i, N) {
        if(str[i][idx[i]] != str[0][idx[0]]) {
          fail = true;
          break;
        }
      }
      if(fail) break;
      V(int) cnt(N);
      bool finish = false;
      REP(i, N) {
        int j = idx[i];
        while(str[i][j] && str[i][j] == str[i][idx[i]]) j++;
        cnt[i] = (j - idx[i]);
        idx[i] = j;
        if(!str[i][j]) finish = true;
      }
      sort(ALL(cnt));
      REP(i, N) ans += abs(cnt[i] - cnt[N/2]);
      if(finish) {
        REP(i, N) {
          if(str[i][idx[i]]) {
            fail = true;
            break;
          }
        }
        break;
      }
    }
    if(fail) {
      puts("Fegla Won");
    } else {
      PL(ans);
    }
  }
  return 0;
}
