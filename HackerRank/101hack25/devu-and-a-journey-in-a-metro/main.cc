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
#include <set>
#include <deque>
#include <stack>
#include <cassert>
using namespace std;
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
#define ALL(x) (x).begin(),(x).end()
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define RI1(x) scanf("%d",&x)
#define RI2(x,y) RI1(x), RI1(y)
#define RI3(x,y...) RI1(x), RI2(y)
#define RI4(x,y...) RI1(x), RI3(y)
#define RI5(x,y...) RI1(x), RI4(y)
#define RI6(x,y...) RI1(x), RI5(y)
#define GET_MACRO(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define RI(argv...) GET_MACRO(argv, RI6, RI5, RI4, RI3, RI2, RI1)(argv)
#define DRI(argv...) int argv;RI(argv)
#define WRI(argv...) while (RI(argv) != EOF)
#define DWRI(x...) int x; WRI(x)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define F first
#define S second
#define V(x) vector<x >

int popcount(unsigned x) { return __builtin_popcount(x); } 
int popcount(unsigned long long x) { return __builtin_popcountll(x); } 

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

#include <unordered_set>
#include <unordered_map>
#define PL(x) printf("%lld\n",x)
#define EB emplace_back
#define RL(x) scanf("%lld",&x)
#define DRL(x) LL x;RL(x)

double dp[100][100];

LL d[100][100];

int main() {
    DRI(T);
    while(T--) {
        DRI(N, K);
        V(V(PII)) adj(N);
        MS0(d);
        REP(i, N) {
          REP(j, N) {
            if (i != j)
              d[i][j] = 1e18;
          }
        }
        REP(i, N-1) {
          DRI(u, v, w);
          u--; v--;
          adj[u].EB(v, w);
          adj[v].EB(u, w);
          d[u][v] = d[v][u] = w;
        }
        REP(k, N) REP(i, N) REP(j, N) {
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
        MS0(dp);
        REP(i, N) {
          assert(d[0][i] < 1e18);
          dp[0][i] = d[0][i];
        }
        REP1(k, 1, K) {
          REP(i, N) {
            assert(dp[k][i] == 0);
            FOR(pr, adj[i]) {
              dp[k][i] += dp[k-1][pr->F];
            }
            dp[k][i] /= SZ(adj[i]);
          }
        }
        printf("%.15f\n", dp[K][0]);
    }
    return 0;
}