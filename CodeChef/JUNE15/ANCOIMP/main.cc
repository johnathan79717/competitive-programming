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
#define CASET2 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d:\n", case_n++) : 0), ___T-- > 0)
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
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
#define PV(v) REP(i, SZ(v)) if(i < SZ(v)-1) PIS(v[i]); else PI(v[i]);

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

int A[1005][1005];
int value[1005];
int N;
int pos[1005], neg[1005];

bool dfs(int v, int p, int c) {
    if (value[v] == -c) {
        return false;
    }
    if (value[v]) {
        return true;
    }
    value[v] = c;
    if (c > 0) {
        pos[c]++;
    } else {
        neg[-c]++;
    }
    REP1(i, 1, N) {
        if (A[v][i] && i != p) {
            if (!dfs(i, v, -c)) {
                return false;
            }
        }
    }
    return true;
}

int ans[1005];
int dp[1005][1005];

int main() {
    DRI(T);
    while(T--) {
        RI(N);
        REP1(i, 1, N) REP1(j, 1, N) {
            RI(A[i][j]);
        }
        MS0(value);
        bool rv = true;
        MS0(pos);
        MS0(neg);
        REP1(i, 1, N) {
            if (value[i] == 0) {
                rv = rv && dfs(i, -1, i);
            }
        }
        if (!rv) {
            PI(-1);
            continue;
        }
        int p = 0, n = 1;
        MS1(dp);
        dp[0][0] = 0;
        REP1(i, 1, N) {
            REP1(j, 0, N) {
                if (j + pos[i] <= N && dp[i-1][j] >= 0) {
                    dp[i][j+pos[i]] = j;
                }
                if (j + neg[i] <= N && dp[i-1][j] >= 0) {
                    dp[i][j+neg[i]] = j;
                }
            }
        }
        int j = INT_MAX;
        REP1(i, 1, N) {
            if (dp[N][i] >= 0) {
                MIN(j, max(i, N - i));
            }
        }
        assert(j <= N);
        if (dp[N][j] < 0) j = N - j;
        assert(dp[N][j] >= 0);
        MS0(ans);
        PER1(i, N, 1) {
            if (pos[i] == 0) continue;
            int t = dp[i][j];
            assert(t >= 0);
            int c = j - t == pos[i] ? 1 : -1;
            REP1(k, 1, N) {
                if (value[k] == c * i) {
                    ans[k] = 1;
                }
            }
            j = t;
        }
        REP1(i, 1, N) {
            i < N ? PIS(ans[i]) : PI(ans[i]);
        }
    }
    return 0;
}