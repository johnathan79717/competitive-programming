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

typedef double F;

F C[51][51];

int main() {
  C[0][0] = 1;
  REP1(i, 1, 50) {
    C[i][0] = 1;
    REP1(j, 1, 50) {
      C[i][j] = C[i-1][j] + C[i-1][j-1];
    }
  }
  DRI(T);
  REP(t, T) {
    DRIII(n, c, k);
    V(V(F)) prob_dist(k+1, V(F)(c));
    V(F) avg(k+1);
    prob_dist[0][1] = 1;
    REP1(i, 0, k) {
      if(i < k) {
        REP(j, c) {
          REP(l, c) {
            prob_dist[i+1][j*l%c] += prob_dist[i][j] / c;
          }
        }
      }
      REP(j, c) {
        avg[i] += prob_dist[i][j] * j;
      }
    }
    VI left(n+1), right(n+1);
    while(k--) {
      DRII(L, R);
      left[L]++;
      right[R]++;
    }
    int layers = 0;
    F ans = 0;
    REP1(i, 1, n) {
      layers += left[i];
      // ans += avg[layers];
      REP1(j, 0, layers) {
        ans += C[layers][j] * avg[j] / (1ll<<layers);
      }
      // PI(layers);
      layers -= right[i];
    }
    printf("%.9lf\n", ans);
  }
  return 0;
}
