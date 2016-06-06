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

#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define PL(x) printf("%lld\n", x)
#define RL(x) scanf("%lld", &x)
#define DRL(x) LL x; RL(x);
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
    DisjointSet(int _N): par(_N), _size(_N), N(_N) {
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
        if(_size[x] < _size[y]) {
            par[x] = y;
            _size[y] += _size[x];
        } else {
            par[y] = x;
            _size[x] += _size[y];
        }
    }

    int size(int x) {
        return _size[find(x)];
    }
};
#define MAX_LOG_V 20
V(VI) G;
int parent[MAX_LOG_V][200002];
int depth[200002];
int n;
int rep[200005], w[200005], sz[200005];

void init(DisjointSet&ds, int N) {
    MS1(depth);
    MS1(parent);
    queue<int> q;
    REP(i, N) {
        int r = rep[ds.find(i)];
        q.push(r);
        depth[r] = 0;
    }
    while (!q.empty()) {
        FOR(it, G[q.front()]) {
            int v = *it;
            if (depth[v] < 0) {
                depth[v] = depth[q.front()] + 1;
                parent[0][v] = q.front();
                q.push(v);
            }
        }
        q.pop();
    }
    for(int k = 0; k + 1 < MAX_LOG_V; k++) {
        for(int v = 0; v < n; v++) {
          if(parent[k][v] < 0)
            parent[k+1][v] = -1;
          else
            parent[k + 1][v] = parent[k][parent[k][v]];
        }
    }
}

int lca(int u, int v, int K) {
  if(depth[u] > depth[v]) swap(u, v);
  for(int k = 0; k < MAX_LOG_V; k++) {
    if((depth[v] - depth[u]) >> k & 1) {
      v = parent[k][v];
    }
  }
  if(u == v && sz[u] >= K) return u;
  for(int k = MAX_LOG_V - 1; k >= 0; k--) {
      int uu = parent[k][u], vv = parent[k][v];
      if (uu != vv || (uu >= 0 && sz[uu] < K)) {
          u = uu;
          v = vv;
      }
    //if(parent[k][u] != parent[k][v] || sz[parent[k][u]] < K) {
      //u = parent[k][u];
      //v = parent[k][v];
    //}
  }
  if (parent[0][u] < 0) return -1;
  return w[parent[0][u]];
}

set<int> s[200005];

int main() {
    DRI(N, M, Q);
    REP(i, N) {
        DRI(T);
        s[i].insert(T);
        rep[i] = i;
        sz[i] = 1;
    }
    vector<pair<int,pair<int,int>>> e;
    REP(i, M) {
        DRI(x, y, u);
        x--; y--;
        e.EB(u, MP(x, y));
    }
    n = N;
    sort(ALL(e));
    DisjointSet ds(N+1);
    G.resize(N*2);
    for (auto&p: e) {
        int u = p.X, x = p.Y.X, y = p.Y.Y;
        int xx = ds.find(x), yy = ds.find(y);
        if (xx == yy) continue;
        ds.unite(xx, yy);
        int pp = ds.find(xx);
        int xxx = rep[xx], yyy = rep[yy], ppp = rep[pp] = n++;
        G[xxx].PB(ppp);
        G[ppp].PB(xxx);
        G[yyy].PB(ppp);
        G[ppp].PB(yyy);
        w[ppp] = u;
        if (s[xxx].size() < s[yyy].size()) swap(xxx, yyy);
        s[ppp].swap(s[xxx]);
        for (int v: s[yyy]) {
            s[ppp].insert(v);
        }
        sz[ppp] = s[ppp].size();
    }
    init(ds, N);
    REP(i, Q) {
        DRI(x, y, k);
        x--; y--;
        PI(lca(x, y, k));
    }
    return 0;
}
