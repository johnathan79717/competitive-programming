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
using namespace atcoder;

typedef modint998244353 mint;
#define int LL

struct Segment {
    int l, r, w;
};

#include <new>

const int POOL_SIZE = 4e6;

struct Data {
    mint pairs, sum;
};

struct Node {
    Node *child[2];
    mint lazy;
    Data dat;
    Node() : lazy(0), dat((Data){0, 0}) {
        memset(child, 0, sizeof child);
    }
    static Node pool[POOL_SIZE];
    static Node *ptr;
    Node* getChild(int c) {
        return child[c] ? child[c] : (child[c] = new(ptr++) Node);
    }

    void propagate(int l, int r) {
        mint ps = r - l;
        dat.pairs += dat.sum * lazy + ps * (lazy.val() * (lazy.val() - 1ll) / 2);
        dat.sum += lazy * ps;
        if (r - l > 1) {
            getChild(0)->lazy += lazy;
            getChild(1)->lazy += lazy;
        }
        lazy = 0;
    }

    Data combine(Data vl, Data vr) {
        return Data({vl.pairs + vr.pairs, vl.sum + vr.sum});
    }

    void update(int a, int b, int l, int r, mint d) {
        debug("update", a, b, d.val());
        // we have to make sure dat[k] is the right value after update
        // also all ancestor's lazy values should have already been propagated here
        if (a <= l && r <= b) {
            lazy += d;
            propagate(l, r);
        } else {
            propagate(l, r);
            if (r <= a || b <= l) {
                return;
            }
            int m = (l+r)/2;
            Node *chl = getChild(0);
            Node *chr = getChild(1);
            chl->update(a, b, l, m, d);
            chr->update(a, b, m, r, d);
            dat = combine(chl->dat, chr->dat);
        }
    }
} Node::pool[POOL_SIZE], *Node::ptr = pool;

# define MULTITEST 1
void solve() {
    int Q, K;
    R(Q, K);
    Node root;
    Node::ptr = Node::pool;
    while (Q--) {
        LL l, r;
        R(l, r);
        auto process = [K, &root](LL x, int w) {
            auto u = [&root, K](int a, int b, int w) {
                return root.update(a, b, 0, 1<<(K/2), w);
            };
            debug("process", x, w);
            u(0, 1<<(K/2), w * (x >> (K/2)));
            int l = 0;
            for (int i = K/2-1; i >= 0; i--) {
                if (x & (1ll<<(K-1-i))) {
                    l ^= (1<<i);
                }
                if (x & (1<<i)) {
                    int r = l + (1<<i);
                    u(l, r, w);
                    l ^= (1<<i);
                }
            }
            u(l, l+1, w);
        };
        process(r, 1);
        if (l) {
            process(l-1, -1);
        }
        root.propagate(0, 1<<(K/2));
        W(root.dat.pairs.val());
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
