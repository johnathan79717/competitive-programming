/*
ID: johnath2
PROG: crypt1
LANG: C++11
*/
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
using namespace std;
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define LEN(X) strlen(X)
#define NAME "cowroute"
#define FOR(i,c) for(auto &i: c)
#define SZ(x) ((int)(x).size())
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
#define PLL(x) printf("%lld\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
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

typedef pair<LL, int> Cost;

Cost operator+(const Cost &c1, const Cost &c2) {
    return MP(c1.F + c2.F, c1.S + c2.S); 
}

class Graph {
  typedef pair<Cost, int> P;
  int V;
  struct edge { int to; Cost cost; };
  vector<vector<edge> > G;
public:
  Graph() { V = 0; }
  Graph(int N) { V = N; G.resize(V); }
  int addVertex() {
    G.resize(V+1);
    return V++;
  }
  void addEdge(int from, int to, Cost cost) {
    G[from].push_back((edge){to, cost});
    G[to].push_back((edge){from, cost});
  }
  vector<Cost> d;
  void dijkstra(int s) {
    d = V(Cost)(V, MP(1000000000000000000ll, 1e9));
    priority_queue<P, vector<P>, greater<P> > que;
    d[s] = MP(0, 0);
    que.push(P(d[s], s));

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

int main() {
#ifndef STDIO
    freopen(NAME".in", "r", stdin);
    freopen(NAME".out", "w", stdout);
#endif
    DRIII(A, B, N);
    Graph g(1001);
    while (N--) {
        DRII(cost, num);
        VI city;
        while (num--) {
            DRI(c);
            REP(i, SZ(city)) {
                g.addEdge(c, city[i], MP(cost, SZ(city) - i));
            }
            city.PB(c);
        }
    }
    g.dijkstra(A);
    // PLL(g.d[B].F); PI(g.d[B].S);
    if (g.d[B].F == 1000000000000000000ll) puts("-1 -1");
    else printf("%lld %d\n", g.d[B].F, g.d[B].S);
    return 0;
}