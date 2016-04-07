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

class Graph {
  typedef pair<int, int> P;
  int V;
  struct edge { int to, cap, cost, rev; };
  vector<vector<edge> > G;
  vector<bool> used;
  int dfs(int v, int f) {
    if(v == sink) return f;
    used[v] = true;
    for(int i = 0; i < G[v].size(); i++) {
      edge &e = G[v][i];
      if(!used[e.to] && e.cap > 0) {
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
  Graph() { V = 0; source = addVertex(); sink = addVertex(); }
  int addVertex() {
    G.resize(V+1);
    return V++;
  }
  void addEdge(int from, int to, int cap, int cost = 0) {
    G[from].push_back((edge){to, cap, cost, G[to].size()});
    G[to].push_back((edge){from, 0, -cost, G[from].size() - 1});
  }
  int maxFlow() {
    int flow = 0;
    while(true) {
      used.resize(V);
      fill(used.begin(), used.end(), false);
      int f = dfs(source, 1e9);
      if(f == 0) return flow;
      flow += f;
    }
  }
  pair<int,int> minCostFlow(int f=2e9, bool BellmanFord=false) {
    int res = 0;
    vector<int> h(V), prevv(V), preve(V);
    while(f > 0) {
      vector<int> dist(V, 1e9);
      dist[source] = 0;
      if(BellmanFord) {
        BellmanFord = false;
        bool update = true;
        while(update) {
          update = false;
          for(int v = 0; v < V; v++) {
            if(dist[v] == 1e9) continue;
            for(int i = 0; i < G[v].size(); i++) {
              edge &e = G[v][i];
              if(e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                prevv[e.to] = v;
                preve[e.to] = i;
                update = true;
              }
            }
          }
        }    
      } else {
        priority_queue<P, vector<P>, greater<P> > que;
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
        d = min(d, G[prevv[v]][preve[v]].cap);
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

int main() {
  DRI(T);
  REP1(t, 1, T) {
    Graph G;
    DRII(m, n);
    V(VI) a(m, VI(n));
    REP(i, m) REP(j, n) RI(a[i][j]);
    VI in(m), out(n), best1(m), best2(n);
    REP(i, m) {
      in[i] = G.addVertex();
      G.addEdge(G.source, in[i], 1, 0);
      best1[i] = INT_MAX;
      REP(j, n) best1[i] = min(best1[i], a[i][j]);
    }
    REP(j, n) {
      out[j] = G.addVertex();
      G.addEdge(out[j], G.sink, 1, 0);
      best2[j] = INT_MAX;
      REP(i, m) best2[j] = min(best2[j], a[i][j]);
    }
    REP(i, m) REP(j, n) {
      if(a[i][j] - best1[i] - best2[j] < 0) {
        G.addEdge(in[i], out[j], 1, a[i][j] - best1[i] - best2[j]);
        // cout << i << ' ' << j << ' ' << best1[i] << ' ' << best2[j] << endl;
      } else
        G.addEdge(in[i], out[j], 1, 0);
    }
    int sum = 0;
    REP(i, m) sum += best1[i];
    REP(j, n) sum += best2[j];
    // cout << sum << endl;
    int ans = G.minCostFlow(min(n, m), true).first;
    printf("Case %d: ", t);
    PI(ans + sum);
  }
  return 0;
}
