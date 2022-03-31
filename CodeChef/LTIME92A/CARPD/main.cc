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
//#define int LL
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

#define MULTITEST 1
# define MULTITEST 1
struct State {
    LL c;
    int n, f;

    bool operator< (const State& s) const {
        return c > s.c;
    }
};

LL dp[303][303];
int ds[303][303];

void solve() {
    int N, M, Cp, Cd, Pp, Pd;
    R(N, M, Cp, Cd, Pp, Pd);
    VI type(N);
    REP(i, N) {
        R(type[i]);
    }
    type[N-1] = 3;
    REP(i, N) {
        REP(j, max(Cd, Cp)+1) {
            dp[i][j] = 1e18;
        }
        REP(j, N) {
            ds[i][j] = MOD;
        }
        ds[i][i] = 0;
    }
    while (M--) {
        int u, v;
        R(u, v);
        u--; v--;
        R(ds[u][v]);
    }

    if (type[0] == 0) {
        W(-1);
        return;
    }

    REP(k, N) {
        REP(i, N) {
            REP(j, N) {
                ds[i][j] = min(ds[i][j], ds[i][k] + ds[k][j]);
            }
        }
    }

    dp[0][0] = 0;
    if (type[0] & 1) {
        dp[0][0] += Cp * Pp;
    }
    if (type[0] & 2) {
        dp[0][0] += Cd * Pd;
    }

    priority_queue<State> pq;
    pq.push((State){dp[0][0], 0, 0});
    while (pq.size()) {
        State s = move(pq.top()); pq.pop();
        int n = s.n, p, d;
        if (type[n] == 1) {
            p = Cp;
            d = s.f;
        } else if (type[n] == 2) {
            d = Cd;
            p = s.f;
        } else {
            d = Cd;
            p = Cp;
        }
        LL c = s.c;
        debug(n, p, d, c);
        if (n == N-1) {
            W(c - p * Pp - d * Pd);
            return;
        }
        if (c > dp[n][s.f]) {
            continue;
        }
        REP(v, N) {
            if (v == n || (type[v] == 0 && v != N-1)) {
                continue;
            }
            int l = ds[n][v];
            if (p + d < l) {
                continue;
            }
            for (int i : {max(0, l - d), min(p, l)}) {
                int p1 = p - i, d1 = d - (l - i), c1 = c, f1 = type[v] == 1 ? d1 : type[v] == 2 ? p1 : 0;
                if (type[v] & 1) {
                    c1 += (Cp - p1) * Pp;
                }
                if (type[v] & 2) {
                    c1 += (Cd - d1) * Pd;
                }
                if (c1 < dp[v][f1]) {
                    pq.push(State{dp[v][f1] = c1, v, f1});
                }
            }
        }
    }
    W(-1);
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
