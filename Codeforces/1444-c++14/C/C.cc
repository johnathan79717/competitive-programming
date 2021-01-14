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
    int N, M, K;
    R(N, M, K);
    VI C(N+1);
    FOR(i, 1, N) {
        R(C[i]);
        //if (C[i] == 16 || C[i] == 35) {
            //debug(i, C[i]);
        //}
    }
    VPII e;
    vector<VI> adj(N+1);
    vector<VI> all(N+1);
    REP(i, M) {
        int a, b;
        R(a, b);
        //if ((C[a] == 16 || C[a] == 35) && (C[b] == 16 || C[b] == 35)) {
            //debug(a, b);
        //}
        if (C[a] != C[b]) {
            e.PB(a, b);
        } else {
            adj[a].PB(b);
            adj[b].PB(a);
        }
        all[a].PB(b);
        all[b].PB(a);
    }
    vector<bool> good(K+1, true);
    VI color(N+1, -1);
    int c = 0;
    function<void(int)> dfs;
    dfs = [&](int v) {
        for (int u : adj[v]) {
            if (C[u] == C[v]) {
                if (color[u] < 0) {
                    color[u] = color[v] ^ 1;
                    dfs(u);
                } else if (color[u] == color[v]) {
                    good[C[u]] = false;
                    return;
                }
            }
        }
    };
    FOR(i, 1, N) {
        if (good[C[i]] && color[i] < 0) {
            color[i] = c;
            dfs(i);
            c += 2;
        }
    }

    LL ans = 0;
    FOR(k, 1, K) {
        ans += good[k];
    }
    ans = ans * (ans - 1) / 2;

    map<PII, VPII> e2;
    for (auto &pr : e) {
        int a = pr.F, b = pr.S;
        if (!good[C[a]] || !good[C[b]]) {
            continue;
        }
        if (C[a] > C[b]) {
            swap(a, b);
        }
        e2[MP(C[a], C[b])].PB(color[a], color[b]);
    }

    for (auto &pr : e2) {
        bool fail = ![&pr]() {
            int c2 = 2;
            map<int, int> color2;
            map<int, VI> adj2;
            VI vs;
            for (PII &p : pr.S) {
                adj2[p.F].PB(p.S);
                adj2[p.S].PB(p.F);
                vs.PB(p.F);
                vs.PB(p.S);
            }

            function<bool(int)> dfs2;
            dfs2 = [&](int v) {
                if (!color2[v ^ 1]) {
                    color2[v ^ 1] = color2[v] ^ 1;
                    if (!dfs2(v ^ 1)) return false;
                }
                for (int u : adj2[v]) {
                    if (!color2[u]) {
                        color2[u] = color2[v] ^ 1;
                        if (!dfs2(u)) return false;
                    } else if (color2[u] == color2[v]) {
                        return false;
                    }
                }
                return true;
            };
            for (int v : vs) {
                if (!color2[v]) {
                    color2[v] = c2;
                    c2 += 2;
                    if (!dfs2(v)) {
                        return false;
                    }
                }
            }
            return true;
        }();
        if (fail) {
            ans--;
        }
    }

    W(ans);
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
