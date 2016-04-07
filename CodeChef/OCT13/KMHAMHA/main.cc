#include <iostream>
#include <cstring>
#include <unordered_map>
#include <queue>
#include <vector>
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
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    Graph G;
    unordered_map<int, int> ix, iy;
    // memset(adj, false, sizeof(adj));
    while(N--) {
      int X, Y;
      cin >> X >> Y;
      if(ix.find(X) == ix.end()) {
        ix[X] = G.addVertex();
        G.addEdge(G.source, ix[X], 1, 0);
      }
      if(iy.find(Y) == iy.end()) {
        iy[Y] = G.addVertex();
        G.addEdge(iy[Y], G.sink, 1, 0);
      }
      // adj[ix[X]][iy[Y]] = true;
      G.addEdge(ix[X], iy[Y], 1, 0);
    }
    // cout << bipartite_matching() << endl;
    cout << G.maxFlow() << endl;
  }
}