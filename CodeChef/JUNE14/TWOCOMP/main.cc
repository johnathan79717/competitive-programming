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
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
using namespace std;
#define BG begin()
#define ED end()
#define FOR(i,c) for(auto &i: c)
#define SZ size()
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define RL(x) scanf("%lld",&x)
#define DRI(x) int x;RI(x)
#define DRL(x) LL x;RL(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PL(x) printf("%lld\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define PQ priority_queue
#define E emplace
#define EB emplace_back
#define LB lower_bound
#define UB upper_bound
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000;

template <typename T> using V = vector<T>;

class Graph {
  int V;
  struct edge { int to, cap, rev; };
  vector<vector<edge> > G;
  vector<bool> used;
  VI level, iter;
  void bfs() {
    fill(ALL(level), -1);
    queue<int> que;
    level[source] = 0;
    que.push(source);
    while(!que.empty()) {
      int v = que.front(); que.pop();
      FOR(e, G[v]) {
        if(e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[v] + 1;
          que.push(e.to);
        }
      }
    }
  }
  int dfs(int v, int f) {
    if(v == sink) return f;
    for(int &i = iter[v]; i < G[v].size(); i++) {
      edge &e = G[v][i];
      if(e.cap > 0 && level[v] < level[e.to]) {
        int d = dfs(e.to, min(f, e.cap));
        if(d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
public:
  int source, sink;
  Graph() { G.reserve(1400); V = 0; source = addVertex(); sink = addVertex(); }
  int addVertex() {
    G.resize(V+1);
    G.back().reserve(700);
    return V++;
  }
  void addEdge(int from, int to, int cap) {
    G[from].push_back((edge){to, cap, (int)G[to].size()});
    G[to].push_back((edge){from, 0, (int)G[from].size() - 1});
  }
  int maxFlow() {
    int flow = 0;
    level.resize(V);
    iter.resize(V);
    for (;;) {
      bfs();
      if(level[sink] < 0) return flow;
      fill(ALL(iter), 0);
      int f;
      while((f = dfs(source, INT_MAX)) > 0) {
        flow += f;
      }
    }
    return flow;
  }
};

#define MAX_LOG_V 17
V(VI) G, parent;
VI depth;


void dfs(int v, int p, int d) {
  parent[0][v] = p;
  depth[v] = d;
  for(int i = 0; i < G[v].size(); i++) {
    if(G[v][i] != p) dfs(G[v][i], v, d+1);
  }
}

void init() {
  dfs(0, -1, 0);
  for(int k = 0; k + 1 < MAX_LOG_V; k++) {
    for(int v = 0; v < G.size(); v++) {
      if(parent[k][v] < 0) parent[k+1][v] = -1;
      else parent[k + 1][v] = parent[k][parent[k][v]];
    }
  }
}

int lca(int u, int v) {
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

struct Route
{
  int x, y, j, v, lca;
};

int main() {
  DRIII(N, M1, M2);
  G = V(VI)(N);
  parent = V(VI)(MAX_LOG_V, VI(N));
  depth = VI(N);
  REP(i, N-1) {
    DRII(X, Y);
    G[X-1].PB(Y-1);
    G[Y-1].PB(X-1);
  }
  init();
  V(Route) B(M1);
  Graph g;
  int sum = 0;
  REP(i, M1) {
    RIII(B[i].x, B[i].y, B[i].j);
    sum += B[i].j;
    B[i].x--; B[i].y--;
    B[i].v = g.addVertex();
    B[i].lca = lca(B[i].x, B[i].y);
    g.addEdge(g.source, B[i].v, B[i].j);
  }
  REP(i, M2) {
    DRIII(x, y, joy);
    x--; y--; sum += joy;
    int v = g.addVertex();
    g.addEdge(v, g.sink, joy);
    int l = lca(x, y);
    REP(j, M1) {
      int a = lca(l, B[j].lca);
      if(a == l && (lca(x, B[j].lca) == B[j].lca || lca(y, B[j].lca) == B[j].lca)
        || a == B[j].lca && (lca(B[j].x, l) == l || lca(B[j].y, l) == l))
          g.addEdge(B[j].v, v, INT_MAX);
    }
  }
  PI(sum - g.maxFlow());
  return 0;
}
