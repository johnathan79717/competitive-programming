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

V(VI) adj;
V(bool) visited, parent;
VI child, open, cnt;

int dfs1(int u) {
  visited[u] = true;
  int ans = open[u];
  FOR(v, adj[u]) {
    if(visited[v]) continue;
    ans += dfs1(v);
    if(open[v] || child[v] > 0)
      child[u]++;
  }
  return ans;
}

void dfs2(int u) {
  visited[u] = true;
  FOR(v, adj[u]) {
    if(visited[v]) continue;
    cnt[v] = cnt[u];
    parent[v] = parent[u] || open[u];
    if(open[v] || child[v] > 0)
      parent[v] = parent[v] || child[u] >= 2;
    else
      parent[v] = parent[v] || child[u] >= 1;
    dfs2(v);
  }
}

int main() {
  DRII(N, M);
  open.resize(N);
  adj.resize(N);
  cnt.resize(N);
  REP(i, N)
    RI(open[i]);
  REP(i, M) {
    DRII(u, v);
    u--; v--;
    adj[u].PB(v);
    adj[v].PB(u);
  }
  visited.resize(N);
  child.resize(N);
  LL furik = 0;
  REP(i, N) if(!visited[i]) {
    int c = dfs1(i);
    cnt[i] = c;
    furik += (LL) c * (c-1) / 2;
  }
  printf("%lld ", furik);
  visited.assign(N, false);
  parent.resize(N);
  REP(i, N) if(!visited[i]) dfs2(i);
  int rubik = 0;
  REP(i, N)
    if((open[i] && cnt[i] >= 2) || child[i] >= 2 || (parent[i] && child[i] > 0))
      rubik++;
  PI(rubik);
  return 0;
}