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

VI factor(int a) {
  VI ans;
  for(int p = 2; p * p <= a; p++) {
    if(a % p == 0) {
      ans.PB(p);
      do a /= p; while(a % p == 0);
    }
  }
  if(a > 1) ans.PB(a);
  return move(ans);
}

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

int gcd(int a, int b) {
  if(a == 0) return b;
  return gcd(b % a, a);
}

int main() {
  DRI(T);
  REP(t, T) {
    DRI(N);
    vector<pair<int, VI> > A(N), B(N);
    REP(i, N) {
      RI(A[i].F);
      A[i].S = factor(A[i].F);
    }
    REP(i, N) {
      RI(B[i].F);
      B[i].S = factor(B[i].F);
    }
    unordered_map<int, int> cnt1, cnt2;
    REP(i, N) {
      REP(j, N) {
        VI c(A[i].S.size() + B[j].S.size());
        c.resize(set_intersection(ALL(A[i].S), ALL(B[j].S), c.begin()) - c.begin());
        if(c.empty()) continue;
        int prod = 1;
        FOR(cc, c) prod *= cc;
        if(A[i].F < B[j].F) cnt1[prod]++;
        else if(A[i].F > B[j].F) cnt2[prod]++;
      }
    }
    Graph g;
    unordered_map<int, int> S1, S2;
    FOR(c1, cnt1)
      g.addEdge(g.source, S1[c1.F] = g.addVertex(), c1.S);
    FOR(c2, cnt2)
      g.addEdge(S2[c2.F] = g.addVertex(), g.sink, c2.S);
    FOR(s1, S1) {
      FOR(s2, S2) {
        if(gcd(s1.F, s2.F) > 1)
          g.addEdge(s1.S, s2.S, INT_MAX);
      }
    }
    PI(g.maxFlow());
  }
  return 0;
}
