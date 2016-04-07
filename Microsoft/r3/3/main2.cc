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

#define MAX_V 100001

struct edge { int to, cost; edge(int to, int cost) : to(to), cost(cost) {} };
typedef pair<int, int> P;

int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d + V, INF);
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

int main() {
  DRI(T);
  REP1(t, 1, T) {
    DRI(N);
    V = N;
    vector<pair<int, int> > v(N);
    REP(i, N) {
      RI(v[i].F);
      v[i].S = i;
    }
    sort(ALL(v));
    REP(i, N) G[i].clear();
    REP(i, N-1) {
      DRIII(a, b, c);
      a--; b--;
      G[a].PB(edge(b, c));
      G[b].PB(edge(a, c));
    }
    PER(i, v.size()) {
      int u = v[i];
      
    }
    // LL ans = 0;
    // REP(i, N) {
    //   dijkstra(i);
    //   REP(j, N) {
    //     ans = max(ans, (LL)min(weight[i], weight[j]) * d[j]);
    //   }
    // }
    printf("Case %d: ", t);
    PL(ans);
  }
  return 0;
}
