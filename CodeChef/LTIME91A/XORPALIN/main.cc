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

#ifdef DEBUG
const int POOL_SIZE = 4e4;
#else
const int POOL_SIZE = 4e6;
#endif

struct Data {
    mint pairs, sum;
};

struct Node {
    Node *child[2];
    mint lazy;
    Data dat;
    int l, r;
    Node(): lazy(0), dat((Data){0, 0}), l(-1), r(-1) {
        memset(child, 0, sizeof child);
    }
    Node(int l, int r): Node() {
        this->l = l;
        this->r = r;
    }
    static Node pool[POOL_SIZE];
    static Node *ptr;
    Node* getChild(int c) {
        int m = (l + r) / 2;
        return child[c] ? child[c] : (child[c] = new(ptr++) Node(c ? m : l, c ? r : m));
    }

    void propagate() {
        dat = query();
        if (r - l > 1) {
            Node *chl = getChild(0);
            Node *chr = getChild(1);
            chl->lazy += lazy;
            chr->lazy += lazy;
        }
        lazy = 0;
    }

    Data query() {
        mint ps = r - l;
        return (Data){ dat.pairs + dat.sum * lazy + ps * (lazy.val() * (lazy.val() - 1ll) / 2), dat.sum + lazy * ps };
    }

    static Data combine(Data vl, Data vr) {
        return Data({vl.pairs + vr.pairs, vl.sum + vr.sum});
    }

    void update(mint d) {
        lazy += d;
    }
} Node::pool[POOL_SIZE], *Node::ptr = pool;

# define MULTITEST 1
void solve() {
    int Q, K;
    R(Q, K);
    Node root(0, 1<<(K/2));
    Node::ptr = Node::pool;
    while (Q--) {
        LL l, r;
        R(l, r);
        auto process = [K, &root](LL x, int w) {
            debug("process", x, w);
            root.update(w * (x >> (K/2)));
            Node *p = &root;
            stack<Node*> nodes;
            for (int i = K/2-1; i >= 0; i--) {
                p->propagate();
                nodes.push(p);
                int c = 0;
                if (x & (1ll<<(K-1-i))) {
                    c = 1;
                }
                if (x & (1<<i)) {
                    p->getChild(c)->update(w);
                    c ^= 1;
                }
                p = p->getChild(c);
            }
            p->update(w);
            while (nodes.size()) {
                Node *n = nodes.top();
                n->dat = Node::combine(n->getChild(0)->query(), n->getChild(1)->query());
                nodes.pop();
            }
            debug("val", root.dat.pairs.val());
        };
        process(r, 1);
        if (l) {
            process(l-1, -1);
        }
        W(root.query().pairs.val());
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
