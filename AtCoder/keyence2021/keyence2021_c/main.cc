// Create your own template by modifying this file!
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
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <deque>
#include <stack>
#include <functional>
#include <bitset>
#include <numeric>
#include <atcoder/all>
#define int LL
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB emplace_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
template<class T> void _R(T &x) { cin >> x;  }
void _R(int64_t &x) { scanf("%lld", &x);  }
void _R(double &x) { scanf("%lf", &x);  }
void _R(char &x) { scanf(" %c", &x);  }
void _R(char *x) { scanf("%s", x);  }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...);  }
template<class T> void _W(const T &x) { cout << x;  }
void _W(const int64_t &x) { printf("%lld", x);  }
void _W(const double &x) { printf("%.16f", x);  }
void _W(const char &x) { putchar(x);  }
void _W(const char *x) { printf("%s", x);  }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' ');  }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...);  }
#ifdef DEBUG
 #define debug(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define debug(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
template<class T> void MIN(T& a, const T& b) { a = min(a, b); }
template<class T> void MAX(T& a, const T& b) { a = max(a, b); }

#define MULTITEST 0

using mint = atcoder::modint998244353;

char s[5005][5005];
mint dp[5005][5005];
mint uways[5005][5005], lways[5005][5005];

void solve() {
    int H, WW, K;
    R(H, WW, K);
    REP(i, K) {
        int h, w;
        char c;
        R(h, w, c);
        s[h-1][w-1] = c;
    }
    dp[0][0] = 1;
    REP(i, H) {
        REP(j, WW) {
            uways[i][j] = i ? uways[i-1][j] : 1;
            lways[i][j] = j ? lways[i][j-1] : 1;
            if (i) {
                switch (s[i-1][j]) {
                    case 0:
                        dp[i][j] += dp[i-1][j] * lways[i][j];
                    case 'D':
                    case 'X':
                        dp[i][j] += dp[i-1][j] * lways[i][j];
                        break;
                }
            }
            if (j) {
                switch (s[i][j-1]) {
                    case 0:
                        dp[i][j] += dp[i][j-1] * uways[i][j];
                    case 'R':
                    case 'X':
                        dp[i][j] += dp[i][j-1] * uways[i][j];
                        break;
                }
            }
            if (s[i][j] == 0) {
                lways[i][j] *= 3;
                uways[i][j] *= 3;
            }
            debug(i, j, lways[i][j].val(), uways[i][j].val(), dp[i][j].val());
        }
    }
    if (s[H-1][WW-1] == 0) {
        dp[H-1][WW-1] *= 3;
    }
    W(dp[H-1][WW-1].val());
}

#undef int
int main() {
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}
