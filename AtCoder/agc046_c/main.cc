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

#include <atcoder/all>
#define MULTITEST 0

using namespace atcoder;
using mint = modint998244353;
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
void _R(int &x) { scanf("%d", &x);  }
void _R(int64_t &x) { scanf("%lld", &x);  }
void _R(double &x) { scanf("%lf", &x);  }
void _R(char &x) { scanf(" %c", &x);  }
void _R(char *x) { scanf("%s", x);  }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...);  }
template<class T> void _W(const T &x) { cout << x;  }
void _W(const int &x) { printf("%d", x);  }
void _W(const int64_t &x) { printf("%lld", x);  }
void _W(const double &x) { printf("%.16f", x);  }
void _W(const char &x) { putchar(x);  }
void _W(const char *x) { printf("%s", x);  }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
void _W(const mint& x) { _W(x.val()); }
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

char s[303];

void solve() {
    int K;
    R(s, K);
    int c1 = 0, total1 = 0;
    VI A;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '0') {
            A.PB(c1);
            c1 = 0;
        } else {
            total1++;
            c1++;
        }
    }
    A.PB(c1);
    K = min(K, total1);
    vector<vector<mint>> dp(K+1, vector<mint>(K+1));
    dp[0][0] = 1;
    reverse(ALL(A));
    FOR(j, 0, K) {
        debug(dp[j]);
    }
    for (int c : A) {
        vector<vector<mint>> dp2 = dp;
        vector<vector<mint>> dp3(K+1, vector<mint>(K+1));
        FOR(j, 1, K) {
            FOR(k, 0, K-1) {
                dp2[j][k] += dp2[j-1][k+1];
            }
        }
        FOR(j, 0, K) {
            FOR(k, 1, K) {
                dp3[j][k] = dp[j][k-1] + dp3[j][k-1];
                if (k > c)
                    dp3[j][k] -= dp[j][k-c-1];
            }
        }
        FOR(j, 0, K) {
            FOR(k, 0, K) {
                dp[j][k] = dp2[j][k] + dp3[j][k];
            }
        }
        FOR(j, 0, K) {
            debug(dp[j]);
        }
        debug("dp2");
        FOR(j, 0, K) {
            debug(dp2[j]);
        }
        debug("dp3");
        FOR(j, 0, K) {
            debug(dp3[j]);
        }
    }
    mint ans = 0;
    FOR(j, 0, K) {
        ans += dp[j][0];
    }
    W(ans.val());
}

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
