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
#include <unordered_map>
#include <unordered_set>
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
const int INF = 1000000000;
int K;

class Graph {
  typedef pair<int, int> P;
  int V;
  struct edge { int to, cost; };
  vector<vector<edge> > G;
public:
  Graph() { V = 0; }
  int addVertex() {
    G.resize(V+1);
    return V++;
  }
  void addEdge(int from, int to, int cost) {
    assert(cost > 0 && cost <= K);
    G[from].push_back((edge){to, cost});
    G[to].push_back((edge){from, cost});
  }
  vector<int> d;
  void dijkstra(int s) {
    d = VI(V, INF);
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
  }
};

struct Info {int i, j, l;};

int N, M;
V(VI) movable;

bool good(int i, int j) {
  return i >= 0 && i < N && j >= 0 && j < M && movable[i][j];
}

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int distance(int i, int j, int ti, int tj) {
  V(V(bool)) visited(N, V(bool)(M));
  queue<Info> q;
  q.push({i, j, 0});
  while(!q.empty()) {
    int i = q.front().i, j = q.front().j, l = q.front().l;
    q.pop();
    if(!good(i, j)) continue;
    if(visited[i][j]) continue;
    visited[i][j] = true;
    if(abs(i-ti)+abs(j-tj)+l >= K) continue;
    if(i == ti && j == tj)
      return l;
    REP(d, 4)
      q.push({i+dx[d], j+dy[d], l+1});
  }
  return K;
}

int main() {
  RIII(N, M, K); DRI(Q);
  movable = V(VI)(N, VI(M));
  REP(i, N) REP(j, M) RI(movable[i][j]);
  V(V(VI)) nodes(N, V(VI)(M, VI(4, -1)));
  Graph g;
  REP(i, N) {
    REP(j, M) {
      if(!movable[i][j]) continue;
      movable[i][j] = 0;
      REP(d1, 4) {
        if(!good(i+dx[d1], j+dy[d1])) continue;
        nodes[i][j][d1] = g.addVertex();
        REP(d2, d1) {
          if(nodes[i][j][d2] < 0) continue;
          g.addEdge(nodes[i][j][d1], nodes[i][j][d2], distance(i+dx[d1],j+dy[d1],i+dx[d2],j+dy[d2]));
        }
      }
      movable[i][j] = 1;
      if(i > 0 && nodes[i-1][j][0] >= 0 && nodes[i][j][2] >= 0)
        g.addEdge(nodes[i-1][j][0], nodes[i][j][2], 1);
      if(j > 0 && nodes[i][j-1][1] >= 0 && nodes[i][j][3] >= 0)
        g.addEdge(nodes[i][j-1][1], nodes[i][j][3], 1);
    }
  }
  while(Q--) {
    DRIII(EX, EY, SX); DRIII(SY, TX, TY);
    EX--; EY--; SX--; SY--; TX--; TY--;
    assert(EX != SX || EY != SY);
    if(SX == TX && SY == TY) {
      PI(0);
      continue;
    }
    int best = INF;
    REP(d, 4) {
      if(nodes[SX][SY][d] < 0) continue;
      g.dijkstra(nodes[SX][SY][d]);
      movable[SX][SY] = 0;
      int ans = distance(EX, EY, SX+dx[d], SY+dy[d]);
      movable[SX][SY] = 1;
      assert(ans >= 0 && ans <= K);
      REP(k, 4)
        if(nodes[TX][TY][k] >= 0)
          best = min(best, ans + g.d[nodes[TX][TY][k]]);
    }
    if(best < INF) PI(best);
    else PI(-1);
  }
  return 0;
}