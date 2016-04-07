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
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <stack>
#include <functional>
#include <cassert>
using namespace std;
#define FOR(i,c) for(auto &i: c)
#define SZ size()
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define LB lower_bound
#define UB upper_bound
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
const int INF = 1000000000;

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
      for(auto e: G[v]) {
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
  Graph() { V = 0; source = addVertex(); sink = addVertex(); }
  int addVertex() {
    G.resize(V+1);
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

const int N = 5;

int node[N][N][N][N][N];

int main() {
  Graph g;
  int cnt3 = 0;
  for (int i0 = 0; i0 < N; i0++)
  for (int i1 = 0; i1 < N; i1++)
  for (int i2 = 0; i2 < N; i2++) { if (i0 < 3 && i1 < 3 && i2 < 3 && ((i0 > i1)+(i0>i2)+(i1>i2))%2) cnt3++;
  for (int i3 = 0; i3 < N; i3++)
  for (int i4 = 0; i4 < N; i4++)
  {
    node[i0][i1][i2][i3][i4] = g.addVertex();
  }}
  cout << cnt3 << endl;
  int cnt = 0;
  for (int i0 = 0; i0 < N; i0++)
  for (int i1 = 0; i1 < N; i1++)
  for (int i2 = 0; i2 < N; i2++)
  for (int i3 = 0; i3 < N; i3++)
  for (int i4 = 0; i4 < N; i4++)
  {
    int inv = (i0 > i1) + (i1 > i2) + (i0 > i2) + (i0 > i3) + (i0 > i4)
    + (i1 > i3) + (i1 > i4) + (i2 > i3) + (i2 > i4) + (i3 > i4);
    // cout << inv << endl;
    if (inv % 2) {
      cnt++;
      g.addEdge(g.source, node[i0][i1][i2][i3][i4], 1);
      if (i0 != i1) g.addEdge(node[i0][i1][i2][i3][i4], node[i1][i0][i2][i3][i4], 1);
      if (i1 != i2) g.addEdge(node[i0][i1][i2][i3][i4], node[i0][i2][i1][i3][i4], 1);
      if (i2 != i3) g.addEdge(node[i0][i1][i2][i3][i4], node[i0][i1][i3][i2][i4], 1);
      if (i3 != i4) g.addEdge(node[i0][i1][i2][i3][i4], node[i0][i1][i2][i4][i3], 1);
    } else {
      g.addEdge(node[i0][i1][i2][i3][i4], g.sink, 1);
    }
  }
  cout << pow(N, N) - g.maxFlow() << endl;
  cout << cnt << endl;
}