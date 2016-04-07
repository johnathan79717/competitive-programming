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
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
#define ALL(x) (x).begin(),(x).end()
#define CASET2 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d:\n", case_n++) : 0), ___T-- > 0)
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
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
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define X first
#define Y second
#define V(x) vector<x >
#define PV(v) REP(i, SZ(v)) if(i < SZ(v)-1) PIS(v[i]); else PI(v[i]);

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(unsigned x) { return __builtin_popcount(x); } 
int popcount(unsigned long long x) { return __builtin_popcountll(x); } 

typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
// typedef long long __int128;
const int INF = 1000000000;

#include <unordered_set>
#include <unordered_map>
#define PL(x) printf("%lld\n",x)
#define EB emplace_back
#define RL(x) scanf("%lld",&x)
#define DRL(x) __int128 x;RL(x)

std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}

#define MAX_LOG_V 20
struct Edge {
    int to, weight;
};
V(V(Edge)) G;
int parent[MAX_LOG_V][300001];
int depth[300001];
__int128 depth2[100005];

int N;

void init(int root) {
    MS1(depth);
    MS1(parent);
    queue<int> q;
    q.push(root);
    depth[root] = 0;
    depth2[root] = 0;
    while (!q.empty()) {
        FOR(it, G[q.front()]) {
            int v = it->to;
            if (depth[v] < 0) {
                depth[v] = depth[q.front()] + 1;
                depth2[v] = depth2[q.front()] + it->weight;
                parent[0][v] = q.front();
                q.push(v);
            }
        }
        q.pop();
    }
    for(int k = 0; k + 1 < MAX_LOG_V; k++) {
        for(int v = 0; v < N; v++) {
          if(parent[k][v] < 0)
            parent[k+1][v] = -1;
          else
            parent[k + 1][v] = parent[k][parent[k][v]];
        }
    }
}

int lca2(int u, int v) {
  if(depth[u] > depth[v]) swap(u, v);
  for(int k = 0; k < MAX_LOG_V; k++) {
    if((depth[v] - depth[u]) >> k & 1) {
      v = parent[k][v];
    }
  }
  if(u == v) return u;
  for(int k = MAX_LOG_V - 1; k >= 0; k--) {
    if(parent[k][u] != parent[k][v]) {
      u = parent[k][u];
      v = parent[k][v];
    }
  }
  return parent[0][u];
}

int sparse_table[17][100001];

template<class T>
void make_sparse_table(int N, const T &A) {
    REP(i, N) {
        sparse_table[0][i] = A[i];
    }
    int k = 1;
    while ((1 << k) <= N) {
        REP1(i, 0, N - (1 << k)) {
            sparse_table[k][i] = min(sparse_table[k-1][i], sparse_table[k-1][i+(1<<(k-1))]);
        }
        k++;
    }
}

int query_sparse_table(int l, int r) {
    if (l > r) swap(l, r);
    int k = sizeof(int) * 8 - 1 - __builtin_clz(r+1-l);
    return min(sparse_table[k][l], sparse_table[k][r+1-(1<<k)]);
}

VI order;
int number[100005], inv[1000000];

int lca(int u, int v) {
    return inv[query_sparse_table(number[u], number[v])];
}

__int128 distance(int u, int v) {
    int a = lca(u, v);
    assert(lca2(u, v) == a);
    return depth2[u] - depth2[a] + depth2[v] - depth2[a];
}

bool used[100005];

struct DisjointSet {
  VI par, _size;
  V(PII) v;
  int N;

  DisjointSet(int N): par(N), _size(N), N(N), v(N) {
    init();
  }

  void init() {
    for(int i = 0; i < N; i++) {
      par[i] = i;
      _size[i] = 1;
      v[i] = MP(i, i);
    }
  }

  int find(int x) {
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
  }

  __int128 unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) assert(false);
    pair<__int128, PII> best = MP(0, MP(0, 0));
    int vs[4] = {v[x].X, v[x].Y, v[y].X, v[y].Y};
    REP(i, 4) REP(j, i) {
        MAX(best, MP(distance(vs[i], vs[j]), MP(vs[i], vs[j])));
    }
    if(_size[x] < _size[y]) {
      par[x] = y;
      _size[y] += _size[x];
      v[y] = best.Y;
    } else {
      par[y] = x;
      _size[x] += _size[y];
      v[x] = best.Y;
    }
    return best.X;
  }

  int size(int x) {
    return _size[find(x)];
  }
};

void dfs(int v, int p) {
    number[v] = order.size();
    inv[number[v]] = v;
    order.PB(number[v]);
    FOR(e, G[v]) {
        if (e->to != p) {
            depth2[e->to] = depth2[v] + e->weight;
            dfs(e->to, v);
        }
        order.PB(number[v]);
    }
}

int main() {
    DRI(T);
    while(T--) {
        order.clear();
        MS0(used);
        RI(N);
        VI d(N);
        REP(i, N) RI(d[i]);
        G = V(V(Edge))(N);
        REP(i, N-1) {
            DRI(u, v, w);
            u--; v--;
            G[u].EB((Edge){v, w});
            G[v].EB((Edge){u, w});
        }
        dfs(0, -1);
        make_sparse_table(order.size(), order);
        init(0);
        VI idx(N);
        REP(i, N) {
            idx[i] = i;
        }
        sort(ALL(idx), [&d](int i, int j) {
            return d[i] > d[j];
        });
        DisjointSet ds(N);
        __int128 ans = 0;
        REP(j, N) {
            int i = idx[j];
            used[i] = true;
            FOR(it, G[i]) {
                int v = it->to;
                if (used[v]) {
                    // PIS(i); PIS(v); PL(ans);
                    MAX(ans, d[i] * ds.unite(i, v));
                }
            }
        }
        // PL(ans);
        cout << ans << endl;
    }
    return 0;
}