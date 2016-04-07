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

class Graph {
  struct D
  {
    int d, l;
    D(int d, int l): d(d), l(l) {}
    D operator+ (int e) const {
      return D(d+e, l+1);
    }
    bool operator< (const D& other) const {
      if(d != other.d) return d < other.d;
      else return l > other.l;
    }
  };
  typedef pair<D, int> P;
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
    G[from].push_back((edge){to, cost});
    G[to].push_back((edge){from, cost});
  }
  vector<D> d;
  void dijkstra(int s) {
    d = V(D)(V, D(INF, INF));
    priority_queue<P, vector<P>, greater<P> > que;
    d[s] = D(0, 0);
    que.push(P(D(0, 0), s));

    while(!que.empty()) {
      P p = que.top(); que.pop();
      int v = p.second;
      if(d[v] < p.first) continue;
      for(int i = 0; i < G[v].size(); i++) {
        edge e = G[v][i];
        if(d[v] + e.cost < d[e.to]) {
          d[e.to] = d[v] + e.cost;
          que.push(P(d[e.to], e.to));
        }
      }
    }
  }
};

int main() {
  DRII(N, M);
  Graph g;
  VI v(N+1);
  REP1(i, 1, N) v[i] = g.addVertex();
  while(M--) {
    DRIII(a, b, c);
    g.addEdge(v[a], v[b], c);
  }
  g.dijkstra(v[1]);
  PIS(g.d[v[N]].d); PI(g.d[v[N]].l);
  return 0;
}
