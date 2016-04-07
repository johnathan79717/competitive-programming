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
// #define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 2000000000;

class Graph {
  typedef pair<LL, int> P;
  int V;
  struct edge { int to; LL cost; };
  vector<vector<edge> > G;
public:
  Graph(int n): V(n), G(n) {}
  // int addVertex() {
  //   G.resize(V+1);
  //   return V++;
  // }
  void addEdge(int from, int to, LL cost) {
    G[from].push_back((edge){to, cost});
    G[to].push_back((edge){from, cost});
  }
  vector<LL> dijkstra(int s) {
    vector<LL> d = vector<LL>(V, 1e18);
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
    return move(d);
  }
};

int main() {
  DRI(T);
  while(T--) {
    DRIII(N, M, K);
    int a = -1, b = -1;
    LL c = -1;
    Graph G(N);
    REP1(m, 1, M) {
      DRII(A, B);
      DRL(C);
      A--; B--;
      C *= 2;
      if(m == K) {
        a = A, b = B, c = C;
      } else {
        G.addEdge(A, B, C);
      }
    }
    assert(a >= 0 && b >= 0 && c >= 0);
    auto da = G.dijkstra(a), db = G.dijkstra(b);
    assert(da.size() == N && db.size() == N);
    LL lb = -1, ub = 1e15;
    LL ans = -1;
    while(ub - lb > 1) {
      LL m = (lb + ub) / 2;
      vector<pair<LL, LL> > fail;
      REP(i, N) {
        LL l = m - da[i] + 1, r = db[i] + c - m - 1;
        if(l <= r && l <= c && r >= 0) {
          fail.EB(max(0ll, l), min(r, c));
        }
      }
      sort(ALL(fail));
      LL next = 0;
      FOR(p, fail) {
        if(p.F > next) {
          ub = m;
          ans = next;
        } else {
          next = max(next, p.S + 1);
        }
      }
      if(next <= c) {
        ub = m;
        ans = next;
      } else {
        lb = m;
      }
    }
    assert(ans >= 0);
    printf("%.5lf %.5lf\n", (double)ans / 2, (double)ub / 2);
  }
  return 0;
}