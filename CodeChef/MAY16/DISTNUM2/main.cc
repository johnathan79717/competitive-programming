#include <functional>
#include <list>
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
#include <deque>
#include <stack>
#include <cassert>
using namespace std;
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(x) (x).begin(),(x).end()
#define CASET2 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d:\n", case_n++) : 0), ___T-- > 0)
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define REP(i,n) for(int i=0;i<int(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=int(b);i++)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define RI1(x) scanf("%d",&x)
#define RI2(x,y) RI1(x), RI1(y)
#define RI3(x,y...) RI1(x), RI2(y)
#define RI4(x,y...) RI1(x), RI3(y)
#define RI5(x,y...) RI1(x), RI4(y)
#define RI6(x,y...) RI1(x), RI5(y)
#define GET_MACRO(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define RI(argv...) GET_MACRO(argv, RI6, RI5, RI4, RI3, RI2, RI1)(argv)
#define DRI(argv...) int argv;RI(argv)
#define WRI(argv...) while (RI(argv) != EOF)
#define DWRI(x...) int x; WRI(x)
#define RS(x) scanf("%s",x)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define X first
#define Y second
#define V(x) vector<x >

typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

void print(int i) { printf("%d", i); }
template<class T> void PI(T i) { print(i); puts(""); }
template<class T> void PIS(T i) { print(i); printf(" "); }

template<class T>
void PV(T const &v, int N) {
    REP(i, N) {
        print(v[i]);
        printf("%c", i == N-1 ? '\n' : ' ');
    }
}

template<class T> void PV(T const &v) { PV(v, SZ(v)); }

template<class T, class S> bool has_bit(T mask, S i) { return (mask >> i) & 1; }
long long shift(int i) { return 1ll << i; }

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(int x) { return __builtin_popcount(x); } 
int popcount(long long x) { return __builtin_popcountll(x); } 

typedef int Value;

struct Treap {
    static Treap mem[], *pmem;
    static unsigned state;
    Treap *l, *r;
    unsigned short pri;
    short int key;
    short int size;
    Treap() {}
    Treap(int _key) : l(nullptr), r(nullptr), pri(state), key(_key), size(1) {
        state = state * 1297 + 1301;
    }
    void pull() {
        size = 1;
        if (l) size += l->size;
        if (r) size += r->size;
    }
    int getKth(int k) const {
        assert(k>0 && k <= size);
        if (!l) {
            if (k == 1) return key;
            else return r->getKth(k-1);
        }
        if (l->size == k-1) {
            return key;
        } else if (l->size >= k) {
            return l->getKth(k);
        } else {
            return r->getKth(k-l->size-1);
        }
    }
} Treap::mem[1000000000], *Treap::pmem = Treap::mem;
unsigned Treap::state;

Treap *make(int key) {
    assert(Treap::pmem - Treap::mem < 1e9);
    return new (Treap::pmem++) Treap(key);
}

Treap *make(const Treap *t) {
    assert(Treap::pmem - Treap::mem < 1e9);
    return new (Treap::pmem++) Treap(*t);
}

Treap *merge(const Treap *a, const Treap *b) {
    if (!a) return make(b);
    if (!b) return make(a);

    Treap *t;
    if (a->pri > b->pri) {
        t = make(a);
        t->r = merge(a->r, b);
        t->pull();
    } else {
        t = make(b);
        t->l = merge(a, b->l);
        t->pull();
    }

    return t;
}

pair<Treap*,Treap*> split(const Treap* t, int k) {
    if (!t) return MP(nullptr, nullptr);
    else if (t->key <= k) {
        auto pr = split(t->r, k);
        Treap *ret = make(t);
        ret->r = pr.first;
        ret->pull();
        pr.first = ret;
        return pr;
    } else {
        auto pr = split(t->l, k);
        Treap *ret = make(t);
        ret->l = pr.second;
        ret->pull();
        pr.second = ret;
        return pr;
    }
}

Treap *insert(const Treap *t, int k) {
    auto pr = split(t, k);
    auto pr2 = split(pr.first, k-1);
    // pr2.first, pr2.second, pr.second
    if (pr2.second == nullptr)
        return merge(merge(pr2.first, make(k)), pr.second);
    else
        return make(t);
}

#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)

const int B = 300;

int main() {
    //DRI(N, Q);
    int N = 100000, Q = 0;
    VI A(N);
    REP(i, N) {
        //RI(A[i]);
        A[i] = i;
    }
    V(V(Treap*)) T(N/B);
    int i = B;
    while (i < N) {
        Treap *t = nullptr;
        T[i/B-1].reserve(N-i);
        REP1(j, i, N-1) {
            t = insert(t, A[j]);
            T[i/B-1].push_back(t);
        }
        i += B;
    }
    PI(Treap::pmem - Treap::mem);

    int ans = 0;
    while (Q--) {
        DRI(a, b, c, d, k);
        int l = (1ll * a * max(ans, 0) + b) % N + 1;
        int r = (1ll * c * max(ans, 0) + d) % N + 1;
        if (l > r) swap(l, r);
        l--; r--;
        //PIS(l); PIS(r); PI(k);
        int j = B;
        while (j < l) j += B;
        Treap *t;
        if (j <= r) {
            t = T[j/B-1][r-j];
        } else {
            t = nullptr;
        }
        REP1(p, l, min(r, j-1)) {
            t = insert(t, A[p]);
        }
        if (k <= t->size)
            ans = t->getKth(k);
        else
            ans = -1;
        PI(ans);
    }

    return 0;
}
