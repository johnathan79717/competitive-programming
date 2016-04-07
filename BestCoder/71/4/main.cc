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

#define DRL(x) LL x; RL(x)
#define PL(x) printf("%lld\n",x)
#define RL(x) scanf("%lld\n",&x)
struct DisjointSet {
  VI par, _size;
  int N;

  DisjointSet(int N): par(N), _size(N), N(N) {
    init();
  }

  void init() {
    for(int i = 0; i < N; i++) {
      par[i] = i;
      _size[i] = 1;
    }
  }

  int find(int x) {
    if(par[x] == x) return x;
    //else return par[x] = find(par[x]);
    else return find(par[x]);
  }

  stack<int> record;

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) {
        record.push(-1);
        return;
    }
    if(_size[x] < _size[y]) {
      par[x] = y;
      record.push(x);
      record.push(y);
      _size[y] += _size[x];
    } else {
      par[y] = x;
      record.push(y);
      record.push(x);
      _size[x] += _size[y];
    }
  }

  void undo() {
      assert(record.size());
    int y = record.top();
    record.pop();
    if (y < 0) return;
    int x = record.top();
    record.pop();
    par[x] = x;
    _size[y] -= _size[x];
  }

  int size(int x) {
    return _size[find(x)];
  }
};

struct Edge {
    int a, b, c;
};

//V(VI) dat;
VI dat[40000];
V(Edge) e;

void update(int a, int b, int k, int l, int r, int d) {
    // we have to make sure dat[k] is the right value after update
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
        dat[k].PB(d);
    } else {
        int m = (l+r)/2;
        update(a, b, 2*k+1, l, m, d);
        update(a, b, 2*k+2, m, r, d);
    }
}

bool success;
void dfs(int k, int l, int r, DisjointSet &ds) {
    for (int i: dat[k]) {
        ds.unite(e[i].a, e[i].b);
    }
    if (r - l > 1) {
        int m = (l + r) / 2;
        dfs(2*k+1, l, m, ds);
        dfs(2*k+2, m, r, ds);
    } else {
        if (ds.size(0) == ds.N) {
            success = true;
        }
    }

    REP(i, SZ(dat[k])) {
        ds.undo();
    }
}

int main() {
    CASET {
        DRI(N, M);
        if (M == 0) {
            PI(-1);
            continue;
        }
        e = V(Edge)(M);
        REP(i, M) {
            RI(e[i].a, e[i].b, e[i].c);
            e[i].a--;
            e[i].b--;
        }
        sort(ALL(e), [](Edge const &e1, Edge const &e2) {
                return e1.c < e2.c;
                });
        int lb = -1, ub = 2e9+1;
        int n = 1;
        while (n < M) {
            n *= 2;
        }

        while (ub - lb > 1) {
            REP(i, 2*n-1) {
                dat[i].clear();
            }
            //dat = V(VI)(2*n-1);
            int m = lb + (ub - lb) / 2;
            int l = 0, r = 0;
            while (l < M) {
                while (r < M && e[r].c <= e[l].c + m) {
                    update(l, r+1, 0, 0, n, r);
                    r++;
                }
                l++;
            }
            DisjointSet ds(N);
            success = false;
            dfs(0, 0, n, ds);
            if (success) {
                ub = m;
            } else {
                lb = m;
            }
        }
        if (ub < INF*2) {
            PI(ub);
        } else {
            PI(-1);
        }
    }
    return 0;
}
