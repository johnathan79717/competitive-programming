// Create your own template by modifying this file!
#include <array>
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
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<int> VVI;
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

#include <atcoder/modint>

using Z = atcoder::modint;
Z pool[99999999];
int p = 0;

Z *alloc(int n) {
  Z *ans = pool + p;
  p += n;
  return ans;
}

Z* poly_mul(Z *x, Z *y, int n) {
  if(n == 1) {
    // Z* ans = new Z[1];
    Z *ans = alloc(1);
    ans[0] = x[0] * y[0];
    return ans;
  } else {
    // Z *ans = new Z[n*2-1];
    Z *ans = alloc(n*2-1);
    for(int i = 0; i < n*2-1; i++)
      ans[i] = 0;
    int l = (n+1)/2;
    Z *z0 = poly_mul(x, y, l);
    Z *z2 = poly_mul(x+l, y+l, n-l);
    // Z *temp1 = new Z[l];
    // Z *temp2 = new Z[l];
    Z *temp1 = alloc(l), *temp2 = alloc(l);
    for(int i = 0; i < l; i++) {
      temp1[i] = x[i];
      temp2[i] = y[i];
    }
    for(int i = 0; i < n-l; i++) {
      temp1[i] += x[i+l];
      temp2[i] += y[i+l];
    }
    Z *z1 = poly_mul(temp1, temp2, l);
    for(int i = 0; i < l*2-1; i++) {
      z1[i] -= z0[i];
    }
    for(int i = 0; i < (n-l)*2-1; i++) {
      z1[i] -= z2[i];
    }
    for(int i = 0; i < l*2-1; i++) {
      ans[i] += z0[i];
      ans[i+l] += z1[i];
    }
    for(int i = 0; i < (n-l)*2-1; i++) {
      ans[i+l*2] += z2[i];
    }
    // delete[] temp1;
    // delete[] temp2;
    // delete[] z0;
    // delete[] z1;
    // delete[] z2;
    p -= l + l + (2*l-1) + (2*l-1) + (2*(n-l)-1);
    return ans;
  }
}

Z C[401][401];

void solve() {
    int N, M;
    R(N, M);
    Z::set_mod(M);
    C[0][0] = 1;
    REPP(i, 1, 401) {
        C[i][0] = 1;
        FOR(j, 1, i) {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }
    vector<vector<Z>> dp(N+1, vector<Z>(N+1));
    dp[0][0] = 1;
    dp[1][1] = 1;
    dp[2][2] = 2;
    vector<Z> f(N+1), inv(N+1);
    f[0] = 1;
    FOR(i, 1, N) {
        f[i] = f[i-1] * i;
    }
    inv[N] = 1 / f[N];
    for (int i = N; i >= 1; i--) {
        inv[i-1] = inv[i] * i;
    }
    vector<Z*> p(N+1);
    p[0] = alloc(N+1);
    p[1] = alloc(N+1);
    p[2] = alloc(N+1);
    p[0][0] = p[1][1] = p[2][2] = 1;
    FOR(i, 3, N) {
        p[i] = alloc(N+1);
        FOR(k, 1, i-3) {
            Z* x = poly_mul(p[k], p[i-2-k], N+1);
            FOR(j, i/2+1, i) {
                dp[i][j] += x[j-1] + x[j-1];
            }
        }
        FOR(k, 1, i-4) {
            Z* y = poly_mul(p[k], p[i-3-k], N+1);
            FOR(j, i/2+1, i) {
                dp[i][j] += y[j-1];
            }
        }
        FOR(j, i/2+1, i) {
            dp[i][j] = dp[i][j] * f[j-1] + dp[i-1][j-1] + dp[i-2][j-1] + dp[i-1][j-1] + dp[i-2][j-1];
            p[i][j] = dp[i][j] * inv[j];
        }
    }

    Z ans = 0;
    FOR(j, N / 2 + 1, N) {
        ans += dp[N][j];
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
