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

class DisjointSet {
    void init() {
        for(int i = 0; i < N; i++) {
            par[i] = i;
            _size[i] = 1;
        }
    }

public:
    VI par, _size, used;
    int N;

    V(LL) f;
    DisjointSet(int _N): par(_N), _size(_N), used(_N), N(_N), f(_N) {
        init();
    }

    int find(int x) {
        if(par[x] == x) return x;
        //else return par[x] = find(par[x]);
        else return find(par[x]);
    }

    void unite(int x, int y, int w) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        if (_size[x] > _size[y]) swap(x, y);
        par[x] = y;
        f[y] += 1ll * _size[x] * w;
        f[x] += 1ll * _size[y] * w - f[y];
        _size[y] += _size[x];
    }

    int size(int x) {
        return _size[find(x)];
    }

    void solve(int u) {
        if (par[u] == u || used[u]) return;
        solve(par[u]);
        f[u] += f[par[u]];
        used[u] = true;
    }
};
#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)

int main() {
    CASET1 {
        DRI(n, m);
        //int n = 1e5, m = 3e5;
        DisjointSet ds(n+1);
        vector<pair<int, pair<int,int>>> es;
        while (m--) {
            DRI(u, v, w);
            //int u = 1, v = (m % n) + 1, w = 1e9;
            es.EB(w, MP(u, v));
        }
        sort(ALL(es));
        for (auto &e : es) {
            int w = e.X, u = e.Y.X, v = e.Y.Y;
            ds.unite(u, v, w);
        }
        unsigned long long ans = 0;
        REP1(i, 1, n) {
            ds.solve(i);
            ans ^= 1ull * i * ds.f[i];
        }
        printf("%llu\n", ans);
    }
    return 0;
}
