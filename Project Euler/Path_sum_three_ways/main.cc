#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

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
  void addEdge(int from, int to, int cost) {
    G[from].push_back((edge){to, 1, cost});
  }
  void addFlow(int from, int to, int cap, int cost = 0) {
    G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
    G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
  }
  vector<int> dijkstra() { return dijkstra(source); }
  vector<int> dijkstra(int s) {
    vector<int> d(V, 1e9);
    priority_queue<P, vector<P>, greater<P> > que;
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()) {
      P p = que.top(); que.pop();
      int v = p.second;
      if(d[v] < p.first) continue;
      for(int i = 0; i < G[v].size(); i++) {
        edge e = G[v][i];
        if(d[e.to] > d[v] + e.cost) {
          d[e.to] = d[v] + e.cost;
          que.push(P(d[e.to], e.to));
        }
      }
    }
    return d;
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

int in[80][80], out[80][80];

int main() {
  Graph g;
  for(int i = 0; i < 80; i++) {
    for(int j = 0; j < 80; j++) {
      int m;
      scanf("%d", &m);
      in[i][j] = g.addVertex();
      out[i][j] = g.addVertex();
      g.addEdge(in[i][j], out[i][j], m);
      if(i > 0) {
        g.addEdge(out[i-1][j], in[i][j], 0);
        g.addEdge(out[i][j], in[i-1][j], 0);
      }
      if(j > 0)
        g.addEdge(out[i][j-1], in[i][j], 0);
      else
        g.addEdge(g.source, in[i][j], 0);
      if(j == 79)
        g.addEdge(out[i][j], g.sink, 0);
    }
  }
  auto d = g.dijkstra();
  printf("%d\n", d[g.sink]);
}
