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

#include <atcoder/modint>
#include <atcoder/lazysegtree>
using namespace atcoder;

typedef modint998244353 mint;
typedef modint998244353 Z;

struct S {
    mint points, sum, pairs;
};

S op(S a, S b) {
    return (S){a.points + b.points, a.sum + b.sum, a.pairs + b.pairs};
}

S e() {
    return (S){0, 0, 0};
}

typedef mint F;

S mapping(F f, S x) {
    return (S) {
        x.points,
        x.sum + x.points * f,
        x.pairs + x.sum * f + x.points * (f.val() * (f.val() - 1ll) / 2)
    };
}

F composition(F f, F g) {
    return f + g;
}

F id() {
    return 0;
}
#define int LL

struct Segment {
    int l, r, w;
};


# define MULTITEST 1
void solve() {
    int Q, K;
    R(Q, K);
    vector<vector<Segment>> queries(Q);
    VL points;
    points.PB(0);
    points.PB(1<<(K/2));
    for (auto &q : queries) {
        LL l, r;
        R(l, r);
        auto process = [&points, &q, K](LL x, int w) {
            q.PB(Segment({0, 1<<(K/2), w * int(x >> (K/2))}));
            int u = 0;
            REPP(i, K - K / 2, K) {
                u = (u << 1) | ((x >> i) & 1);
            }
            int l = 0;
            for (int i = K/2-1; i >= 0; i--) {
                if (u & (1<<i)) {
                    l ^= (1<<i);
                }
                if (x & (1<<i)) {
                    int r = l + (1<<i);
                    q.PB(Segment({l, r, w}));
                    points.PB(l);
                    points.PB(r);
                    l ^= (1<<i);
                }
            }
            points.PB(l);
            points.PB(l+1);
            q.PB(Segment({l, l+1, w}));
        };
        process(r, 1);
        if (l) {
            process(l-1, -1);
        }
    }
    SORT_UNIQUE(points);
    int N = SZ(points);
    vector<S> a;
    REP(i, N-1) {
        a.PB((S){points[i+1] - points[i], 0, 0});
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> st(a);
    for (auto &q : queries) {
        for (auto &s : q) {
            int lp = GET_POS(points, s.l);
            int rp = GET_POS(points, s.r);
            st.apply(lp, rp, s.w);
        }
        W(st.all_prod().pairs.val());
    }
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
