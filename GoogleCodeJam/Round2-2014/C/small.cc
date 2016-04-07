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
#include <unordered_set>
#include <unordered_map>
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
    assert(from >= 0 && to >= 0);
    G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
    G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
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
};

int main() {
  DRI(T);
  REP1(t, 1, T) {
    printf("Case #%d: ", t);
    DRIII(W, H, B);
    V(V(bool)) building(W, V(bool)(H));
    while(B--) {
      DRII(X0, Y0);
      DRII(X1, Y1);
      REP1(x, X0, X1) REP1(y, Y0, Y1) {
        building[x][y] = true;
      }
    }
    Graph g;
    V(VI) in(W, VI(H, -1)), out = in;
    REP(x, W) REP(y, H) {
      if(building[x][y]) continue;
      in[x][y] = g.addVertex();
      out[x][y] = g.addVertex();
      if(y == 0)
        g.addEdge(g.source, in[x][y], 1);
      if(y == H-1)
        g.addEdge(out[x][y], g.sink, 1);
      g.addEdge(in[x][y], out[x][y], 1);
      if(x > 0 && !building[x-1][y]) {
        g.addEdge(out[x-1][y], in[x][y], 1);
        g.addEdge(out[x][y], in[x-1][y], 1);
      }
      if(y > 0 && !building[x][y-1]) {
        g.addEdge(out[x][y-1], in[x][y], 1);
        g.addEdge(out[x][y], in[x][y-1], 1);
      }
    }
    PI(g.maxFlow());
  }
  return 0;
}
