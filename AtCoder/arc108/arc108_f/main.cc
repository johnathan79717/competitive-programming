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

#include <atcoder/all>
#define MULTITEST 0

using namespace atcoder;
using mint = modint1000000007;

void solve() {
    int N;
    R(N);
    vector<VI> adj(N+1);
    REP(i, N-1) {
        int a, b;
        R(a, b);
        adj[a].PB(b);
        adj[b].PB(a);
    }

    auto farthest = [&](int v) {
        queue<PII> q;
        q.emplace(v, -1);
        while (q.size()) {
            auto pr = q.front();
            v = pr.F;
            q.pop();
            for (int u : adj[v]) {
                if (u != pr.S) {
                    q.emplace(u, v);
                }
            }
        }
        return v;
    };

    int a = farthest(1), b = farthest(a);
    queue<PII> qa, qb;
    qa.emplace(a, -1);
    qb.emplace(b, -1);
    VI x(N+1);
    int u = 0, i = 0, d = 0;
    auto go = [a, b, &adj, &x, &u, &i](queue<PII> &q) {
        queue<PII> ans;
        while (q.size()) {
            auto pr = q.front();
            q.pop();
            for (int v : adj[pr.F]) {
                if (v != pr.S) {
                    ans.emplace(v, pr.F);
                    if (v != a && v != b) {
                        x[v]++;
                        if (x[v] == 1) {
                            u++;
                        } else if (x[v] == 2) {
                            i++;
                        }
                    }
                }
            }
        }
        swap(q, ans);
    };
    mint ans = 0, prev = 0;
    while (true) {
        mint cnt = u == N-2 ? mint::raw(2).pow(i) : 0;
        debug("d", d, "cnt", cnt.val());
        ans += (cnt - prev) * d;
        prev = cnt;
        go(qa);
        go(qb);
        if (qa.empty()) break;
        d++;
    }
    ans += mint::raw(2).pow(N-2) * d;
    ans *= 2;
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
