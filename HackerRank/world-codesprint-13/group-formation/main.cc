#include <array>
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

int a, b, f, s, t;
map<string, int> id;
int mg[3];

class DisjointSet {
    VI par, _size;
    int N;

    void init() {
        for(int i = 0; i < N; i++) {
            par[i] = i;
            _size[i] = 1;
        }
    }

public:
    vector<array<int, 3>> grade;
    DisjointSet(int _N): par(_N), _size(_N), N(_N), grade(_N) {
        init();
    }

    int find(int x) {
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        REP(i, 3) {
            if (grade[x][i] + grade[y][i] > mg[i]) {
                return;
            }
        }
        if (_size[x] + _size[y] > b) {
            return;
        }
        if(_size[x] < _size[y]) {
            par[x] = y;
            _size[y] += _size[x];
            REP(i, 3) {
                grade[y][i] += grade[x][i];
            }
        } else {
            par[y] = x;
            _size[x] += _size[y];
            REP(i, 3) {
                grade[x][i] += grade[y][i];
            }
        }
    }

    int size(int x) {
        return _size[find(x)];
    }
};
#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define PL(x) printf("%lld\n", x)
#define RL(x) scanf("%lld", &x)
#define DRL(x) LL x; RL(x);

int main() {
    DRI(N, M);
    RI(a, b, mg[0], mg[1], mg[2]);
    DisjointSet ds(N);
    V(string) names;
    REP(i, N) {
        char name[14];
        RS(name);
        names.PB(name);
        DRI(g);
        ds.grade[i][g-1] = 1;
        id[name] = i;
    }
    while (M--) {
        char name1[14], name2[14];
        RS(name1); RS(name2);
        ds.unite(id[name1], id[name2]);
    }
    int m = 0;
    REP(i, N) {
        m = max(m, ds.size(i));
    }
    if (m < a) {
        puts("no groups");
        return 0;
    }
    V(string) ans;
    REP(i, N) {
        if (ds.size(i) == m) {
            ans.PB(names[i]);
        }
    }
    sort(ALL(ans));
    for (auto &str : ans) {
        puts(str.c_str());
    }
  return 0;
}
