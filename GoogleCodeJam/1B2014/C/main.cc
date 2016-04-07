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

V(bool) visited;
V(VI) adj;

void dfs(int u, int p) {
  visited[u] = true;
  FOR(v, adj[u]) {
    if(visited[v] || p == v) continue;
    dfs(v, u);
  }
}

bool connected(PII pr) {
  V(bool) temp = visited;
  dfs(pr.first, -1);
  bool ret = true;
  for(auto it = visited.begin()+1; it != visited.end(); it++) {
    if(*it == false)
      ret = false;
  }
  visited = move(temp);
  return ret;
}

VI z;

struct Compare {
  bool operator()(PII const &i, PII const &j) {
    return z[i.first] > z[j.first];
  }
};

void dfs1(int u) {
  visited[u] = true;
  FOR(v, adj[u]) {
    if(visited[u]) continue;
    parent()
    dfs1(v);
  }
}

int main() {
  DRI(T);
  REP1(t, 1, T) {
    printf("Case #%d: ", t);
    DRII(N, M);
    visited.resize(N+1);
    adj.resize(N+1);
    fill(ALL(adj), VI());
    fill(ALL(visited), false);
    z.resize(N+1);
    REP1(i, 1, N) RI(z[i]);
    while(M--) {
      DRII(i, j);
      adj[i].PB(j);
      adj[j].PB(i);
    }
    int root = min_element(z.begin()+1, z.end()) - z.begin();
    dfs1(root);
    priority_queue<PII, vector<PII>, Compare> pq;
    pq.push(MP(root, -1));
    while(!pq.empty()) {
      PII pr = pq.top();
      pq.pop();
      int u = pr.first;
      V(bool) temp = visited;
      if(connected(pr)) {
        printf("%d", z[u]);
        FOR(v, adj[u]) {
          if(visited[v]) continue;
          pq.push(MP(v, u));
        }
      }
    }
    puts("");
  }
  return 0;
}
