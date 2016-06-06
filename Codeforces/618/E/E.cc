// Create your own template by modifying this file!
#include <ctime>
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
#define X first
#define Y second
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
#define CASET int ___T; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define FOR(i,c) for(auto &i: c)
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI1(x) scanf("%d",&x)
#define RI2(x,y) RI1(x), RI1(y)
#define RI3(x,y...) RI1(x), RI2(y)
#define RI4(x,y...) RI1(x), RI3(y)
#define RI5(x,y...) RI1(x), RI4(y)
#define RI6(x,y...) RI1(x), RI5(y)
#define GET_MACRO(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define RI(argv...) GET_MACRO(argv, RI6, RI5, RI4, RI3, RI2, RI1)(argv)
#define DRI(argv...) int argv;RI(argv)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define DRL(x) LL x; RL(x)
#ifdef ONLINE_JUDGE
    #define PL(x) printf("%I64d\n",x)
    #define RL(x) scanf("%I64d\n",&x)
#else
    #define PL(x) printf("%lld\n",x)
    #define RL(x) scanf("%lld\n",&x)
#endif
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define DRA(A, N) VI A(N); REP(i, N) RI(A[i])
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;
template<typename T>
using V = std::vector<T>;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;
#include <vector>
using namespace std;

#define chl(k) (k*2+1)
#define chr(k) (k*2+2)

const double PI = acos(-1);
struct PT {
    double x, y;
    PT() {}
    PT(double xx, double yy): x(xx), y(yy) {}
    PT operator+(const PT& p) const {
        return PT(x + p.x, y + p.y);
    }
    PT& operator+=(const PT& p) {
        x += p.x;
        y += p.y;
        return *this;
    }
    PT operator-(const PT& p) const {
        return PT(x - p.x, y - p.y);
    }
    PT operator*(double c) const {
        return PT(x * c, y * c);
    }
    PT& operator*=(double c) {
        x *= c;
        y *= c;
        return *this;
    }
    PT operator/(double c) const {
        return PT(x / c, y / c);
    }
    double operator*(const PT& p) const {
        return x * p.x + y * p.y;
    }
    double operator^(const PT& p) const {
        return x * p.y - y * p.x;
    }
    double len2() const {
        return x * x + y * y;
    }
    double len() const {
        return sqrt(len2());
    }
    PT U() const {
        return *this / len();
    }
    PT T() const {
        return PT(-y, x);
    }
    PT rot(double a) const {
        double c = cos(a), s = sin(a);
        return PT(c * x - s * y, s * x + c * y);
    }
    PT rot(int a) const {
        return rot(a * PI / 180);
    }
};

typedef PT Value;
typedef PT Data;
typedef double Lazy;
struct Treap {
    static Treap mem[300003], *pmem;
    static unsigned state;
    Treap *l, *r;
    unsigned pri;
    int key;
    Value val;
    Data data;
    Lazy lazy;
    Treap() {}
    Treap(int _key) : l(nullptr), r(nullptr), pri(state), key(_key), val(1, 0), data(1, 0) {
        state = state * 1297 + 1301;
    }
    void pull() {
        data = val;
        if (l) data += l->getData();
        if (r) data += r->getData();
    }
    Data getData() {
        return data.rot(lazy);
    }
    void push() {
        val = val.rot(lazy);
        data = data.rot(lazy);
        if (l) {
            l->lazy += lazy;
        }
        if (r) {
            r->lazy += lazy;
        }
        lazy = 0;
    }
} Treap::mem[], *Treap::pmem = Treap::mem;
unsigned Treap::state;

Treap *make(int key) {
    return new (Treap::pmem++) Treap(key);
}

Treap *merge(Treap *a, Treap *b) {
    if (!a || !b) return a ? a : b;
    if (a->pri > b->pri) {
        a->push();
        a->r = merge(a->r, b);
        a->pull();
        return a;
    } else {
        b->push();
        b->l = merge(a, b->l);
        b->pull();
        return b;
    }
}

void split(Treap *t, int k, Treap *&a, Treap *&b) {
    if (!t) a = b = nullptr;
    else if (t->key <= k) {
        a = t;
        a->push();
        split(t->r, k, a->r, b);
        a->pull();
    } else {
        b = t;
        b->push();
        split(t->l, k, a, b->l);
        b->pull();
    }
}

int main() 
{
    srand(time(0));
    Treap::state = rand();
    DRI(N, M);
    Treap *treap = nullptr;
    REP1(i, 1, N) {
        treap = merge(treap, make(i));
    }

    REP(i, M) {
        DRI(x, y, z);
        if (x == 2) {
            Treap *left, *right;
            split(treap, y-1, left, right);
            right->lazy -= PI / 180 * z;
            treap = merge(left, right);
        } else {
            Treap *left, *mid, *right;
            split(treap, y-1, left, right);
            split(right, y, mid, right);
            assert(!mid->l && !mid->r);
            double l = mid->val.len();
            mid->val *= (l + z) / l;
            mid->pull();
            treap = merge(left, merge(mid, right));
        }
        auto ans = treap->getData();
        printf("%.10f %.10f\n", ans.x, ans.y);
    }
}


