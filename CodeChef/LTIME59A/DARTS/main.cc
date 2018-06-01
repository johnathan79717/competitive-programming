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
void print(LL i);
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

#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)
const double EPS = 1e-10;

double add(double a, double b) {
    if (abs(a + b) < EPS * (abs(a) + abs(b))) return 0;
    return a + b;
}

LL add(LL a, LL b) {
    return a + b;
}

int add(int a, int b) {
    return a + b;
}

template<class T>
struct P {
    T x, y;
    P() {}
    P(T x, T y) : x(x), y(y) {}
    T det(P p) {
        return add(x * p.y, -y * p.x);
    }
    P operator - (P p) {
        return P(add(x, -p.x), add(y, -p.y));
    }
};

template<class T>
bool cmp_x(const P<T>& p, const P<T>& q) {
    if (p.x != q.x) return p.x < q.x;
    return p.y < q.y;
}

template<class T>
vector<P<T> > convex_hull(vector<P<T> > &ps) {
    int n = ps.size();
    sort(ALL(ps), cmp_x<T>);
    int k = 0;
    vector<P<T> > qs(n * 2);
    REP(i, n) {
        // XXX To include points ON the edges, change "<=" to "<"
        while (k > 1 && (qs[k-1] - qs[k-2]).det(ps[i] - qs[k-1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    for (int i = n-2, t = k; i >= 0; i--) {
        // XXX To include points ON the edges, change "<=" to "<"
        while (k > t && (qs[k-1] - qs[k-2]).det(ps[i] - qs[k-1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    qs.resize(k-1);
    return qs;
}

int main() {
    DRI(N);
    VI x(N), y(N);
    REP(i, N) {
        RI(x[i], y[i]);
    }
    DRI(Q);
    while (Q--) {
        DRI(l, r);
        l--; r--;
        V(P<LL>) p;
        REP1(i, l, r) {
            p.EB(x[i], y[i]);
        }
        auto hull = convex_hull(p);
        auto distance = [&hull](int i, int j) {
            return 1ll * (hull[i].x - hull[j].x) * (hull[i].x - hull[j].x) +
                1ll * (hull[i].y - hull[j].y) * (hull[i].y - hull[j].y);
        };
        int j = 0;
        LL ans = 0;
        REP(i, SZ(hull)) {
            while (distance(i, (j+1) % SZ(hull)) > distance(i, j)) {
                j++;
            }
            ans = max(ans, distance(i, j));
        }
        PL(ans);
    }
    return 0;
}
