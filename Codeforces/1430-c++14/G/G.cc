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
#ifdef HOME
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;

template<class T>
void MIN(T &a, T b) {
    a = min(a, b);
}

struct BT {
    int v;
    bool used;
    bool operator<(const BT& other) const {
        return v < other.v;
    }
};

BT dp[18][19][1<<18];
void solve() {
    int N, M;
    R(N, M);
    VI v(N), inv(N);
    REP(i, M) {
        int x, y, w;
        R(x, y, w);
        x--;
        y--;
        v[x] += w;
        v[y] -= w;
        inv[y] |= (1 << x);
    }
    DEBUG(v);
    function<void(int)> dfs;
    VI p, used(N);
    dfs = [&p, N, &inv, &used, &dfs](int x) {
        if (used[x]) {
            return;
        }
        used[x] = true;
        REP(y, N) {
            if ((inv[x] >> y) & 1) {
                dfs(y);
            }
        }
        p.PB(x);
    };

    REP(x, N) {
        dfs(x);
    }
    REP(i, N) {
        REP(j, N+1) {
            REP(mask, 1 << N) {
                dp[i][j][mask] = BT({MOD, false});
            }
        }
    }
    dp[0][0][0].v = 0;

    auto f = [](int i, int j, int mask) {
        return BT({dp[i][j][mask].v, false});
    };

    REP(i, N) {
        if (i) {
            REP(mask, 1 << N) {
                MIN(dp[i][0][mask], f(i-1, N, mask));
            }
        }
        REP(j, N) {
            int x = p[j];
            REP(mask, 1 << N) {
                MIN(dp[i][j+1][mask], f(i, j, mask));
                if ((mask >> x) & 1) {
                    continue;
                }
                if (mask & inv[x]) {
                    continue;
                }
                MIN(dp[i][j+1][mask ^ (1 << x)], BT({dp[i][j][mask].v + v[x] * i, true}));
            }
        } 
    }
    VI a(N);
    int i = N-1, j = N, mask = (1 << N) - 1;
    while (mask) {
        auto bt = dp[i][j][mask];
        if (bt.used) {
            int x = p[j-1];
            a[x] = i;
            mask ^= (1 << x);
        }
        j--;
        if (j < 0) {
            j = N;
            i--;
        }
    }
    W(a);
}

int main() {
#define MULTITEST 0
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}
