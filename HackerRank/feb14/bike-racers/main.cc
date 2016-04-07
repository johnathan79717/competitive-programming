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
using namespace std;
#define FOR(i,c) for(auto i=(c).begin();i!=(c).end();i++)
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
const int INF = 2000000000;

class Graph {
  typedef pair<int, int> P;
  int V;
  struct edge { LL to, cap, cost, rev; };
  vector<vector<edge> > G;
  V(V(edge)) tmp;
  vector<bool> used;
  int dfs(int v, int f, LL ub) {
    if(v == sink) return f;
    used[v] = true;
    for(int i = 0; i < tmp[v].size(); i++) {
      edge &e = tmp[v][i];
      if(!used[e.to] && e.cap > 0 && e.cost <= ub) {
        int d = dfs(e.to, min(f, (int)e.cap), ub);
        if(d > 0) {
          e.cap -= d;
          tmp[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
public:
  int source, sink;
  Graph() { V = 0; }
  int addVertex() {
    G.resize(V+1);
    return V++;
  }
  void addEdge(int from, int to, int cap, LL cost = 0) {
    G[from].push_back((edge){to, cap, cost, G[to].size()});
    G[to].push_back((edge){from, 0, -cost, G[from].size() - 1});
  }
  int maxFlow(LL ub) {
    int flow = 0;
    tmp = G;
    while(true) {
      used.resize(V);
      fill(ALL(used), false);
      int f = dfs(source, 1e9, ub);
      if(f == 0) return flow;
      flow += f;
    }
  }
  pair<int,int> minCostFlow(int f=2e9) {
    int res = 0;
    vector<int> h(V), prevv(V), preve(V);
    while(f > 0) {
      priority_queue<P, vector<P>, greater<P> > que;
      vector<int> dist(V, 1e9);
      dist[source] = 0;
      que.push(P(0, source));
      while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if(dist[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); i++) {
          edge &e = G[v][i];
          if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
            dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
            prevv[e.to] = v;
            preve[e.to] = i;
            que.push(P(dist[e.to], e.to));
          }
        }
      }
      if(dist[sink] == 1e9) {
        if(f > 1e9) return P(res, 2e9 - f);
        else return P(1e9, 0);
      }
      for(int v = 0; v < V; v++) {
        if(h[v] >= 1e9 || dist[v] >= 1e9)
          h[v] = 1e9;
        else
          h[v] += dist[v];
      }
      int d = f;
      for(int v = sink; v != source; v = prevv[v])
        d = min(d, (int)G[prevv[v]][preve[v]].cap);
      f -= d;
      res += d * h[sink];
      for(int v = sink; v != source; v = prevv[v]) {
        edge &e = G[prevv[v]][preve[v]];
        e.cap -= d;
        G[v][e.rev].cap += d;
      }
    }
    return P(res, f);
  }
};

struct Point
{
  int x, y, num;
};

LL distance(const Point &p1, const Point &p2) {
  return (LL) (p1.x - p2.x) * (p1.x - p2.x) + (LL) (p1.y - p2.y) * (p1.y - p2.y);
}

int main() {
  DRIII(N, M, K);
  V(Point) men(N), bikes(M);
  // V = N + M;
  Graph G;
  G.source = G.addVertex();
  G.sink = G.addVertex();
  REP(j, N) {
    RII(men[j].x, men[j].y);
    men[j].num = G.addVertex();
    G.addEdge(G.source, men[j].num, 1, 0);
  }
  // G.resize(V);
  REP(i, M) {
    RII(bikes[i].x, bikes[i].y);
    bikes[i].num = G.addVertex();
    G.addEdge(bikes[i].num, G.sink, 1, 0);
    REP(j, N) {
      LL d = distance(men[j], bikes[i]);
      // G[j].EB(i+N, d);
      G.addEdge(men[j].num, bikes[i].num, 1, d);
    }
  }
  LL lb = -1, ub = 2e15;
  // cout << ub << endl;
  while(ub - lb > 1) {
    LL m = (ub + lb) / 2;
    // PL(m);
    // if(bipartite_matching(m) >= K)
    if(G.maxFlow(m) >= K)
      ub = m;
    else
      lb = m;
  }
  PL(ub);
  return 0;
}