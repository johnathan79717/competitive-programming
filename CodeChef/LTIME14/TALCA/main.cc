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

#define MAX_LOG_V 18
V(VI) G, parent;
VI depth;

void dfs(int v, int p, int d) {
  parent[0][v] = p;
  depth[v] = d;
  for(int i = 0; i < G[v].size(); i++) {
    if(G[v][i] != p) dfs(G[v][i], v, d+1);
  }
}

void init() {
  dfs(0, -1, 0);
  for(int k = 0; k + 1 < MAX_LOG_V; k++) {
    for(int v = 0; v < G.size(); v++) {
      if(parent[k][v] < 0) parent[k+1][v] = -1;
      else parent[k + 1][v] = parent[k][parent[k][v]];
    }
  }
}

int lca(int u, int v) {
  if(depth[u] > depth[v]) swap(u, v);
  for(int k = 0; k < MAX_LOG_V; k++) {
    if((depth[v] - depth[u]) >> k & 1) {
      v = parent[k][v];
    }
  }
  if(u == v) return u;
  for(int k = MAX_LOG_V - 1; k >= 0; k--) {
    if(parent[k][u] != parent[k][v]) {
      u = parent[k][u];
      v = parent[k][v];
    }
  }
  return parent[0][u];
}

int solve(int r, int u, int v) {
  int uv = lca(u, v);
  if(lca(uv, r) != uv) return uv;
  int ru = lca(r, u);
  int rv = lca(r, v);
  if(uv == u) {
    if(rv == v) return v;
    else return rv;
  }
  if(uv == v) {
    if(ru == u) return u;
    else return ru;
  }
  if(ru == u) return u;
  if(ru == r) return r;
  if(rv == v) return v;
  if(rv == r) return r;
  if(ru == uv) return rv;
  if(rv == uv) return ru;
  assert(false);
}

int main() {
  DRI(N);
  G = V(VI)(N);
  parent = V(VI)(MAX_LOG_V, VI(N));
  depth = VI(N);
  REP(i, N-1) {
    DRII(u, v);
    u--;
    v--;
    G[u].PB(v);
    G[v].PB(u);
  }
  init();
  DRI(Q);
  while(Q--) {
    DRIII(r, u, v);
    r--; u--; v--;
    PI(solve(r, u, v) + 1);
  }
  return 0;
}
