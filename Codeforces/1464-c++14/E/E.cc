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
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
void _W(const mint &x) { printf("%u", x.val());  }
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

void solve() {
    int N, M;
    R(N, M);
    vector<VI> adj(N+1);
    REP(i, M) {
        int u, v;
        R(u, v);
        adj[u].PB(v);
    }
    VI G(N+1, -1);
    function<void(int)> dfs;
    dfs = [&](int v) {
        if (G[v] >= 0) {
            return;
        }
        VI g;
        for (int u : adj[v]) {
            dfs(u);
            g.PB(G[u]);
        }
        SORT_UNIQUE(g);
        REP(i, SZ(g)) {
            if (g[i] != i) {
                G[v] = i;
                return;
            }
        }
        G[v] = SZ(g);
    };
    int mg = 0;
    FOR(i, 1, N) {
        dfs(i);
        mg = max(mg, G[i]);
    }
    do {
        mg++;
    } while (mg & (mg-1));
    debug(mg);
    debug(G);
    VI f(mg);
    FOR(i, 1, N) {
        f[G[i]]++;
    }
    debug(f);
    vector<vector<mint>> A(mg, vector<mint>(mg+1));
    REP(v, mg) {
        A[v][v] = N+1;
        REP(to, mg) {
            A[v][to] -= f[v ^ to];
        }
        if (v) {
            A[v][mg] = 1;
        }
    }
    for (auto &a : A) {
        debug(a);
    }
    puts("");
    REP(i, mg) {
        REPP(j, i, mg) {
            if (A[j][i].val()) {
                swap(A[i], A[j]);
                break;
            }
        }
        FOR(j, i+1, mg) {
            A[i][j] /= A[i][i];
        }
        A[i][i] = 1;
        REP(j, mg) {
            if (j == i) continue;
            FOR(k, i+1, mg) {
                A[j][k] -= A[j][i] * A[i][k];
            }
            A[j][i] = 0;
        }
        for (auto &a : A) {
            debug(a);
        }
        puts("");
    }
    W(A[0][mg].val());
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
