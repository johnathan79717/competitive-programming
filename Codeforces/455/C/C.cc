// Create your own template by modifying this file!

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

V(VI) adj;
V(bool) visited;
VI height;
VI center;

PII getCenter(int u, int p, int d) {
  V(PII) hs;
  if(d > 0)
    hs.EB(d, -1);
  FOR(v, adj[u]) {
    if(v != p)
      hs.EB(height[v]+1, v);
  }
  sort(ALL(hs), greater<PII>());
  if(hs.empty())
    return MP(u, 0);
  if(hs.size() == 1) {
    if(hs[0].second < 0)
      return MP(u, 1);
    else
      return getCenter(hs[0].second, u, 1);
  } else {
    if(abs(hs[0].first - hs[1].first) <= 1)
      return MP(u, hs[0].first + hs[1].first);
    assert(hs[0].second > 0);
    return getCenter(hs[0].second, u, hs[1].first + 1);
  }
}
void calcHeight(int u, int p) {
  height[u] = 0;
  FOR(v, adj[u]) {
    if(v != p) {
      calcHeight(v, u);
      height[u] = max(height[u], height[v] + 1);
    }
  }
}

void setCenter(int u, int p, int c) {
  visited[u] = true;
  center[u] = c;
  FOR(v, adj[u]) {
    if(v != p)
      setCenter(v, u, c);
  }
}

VI diameter;

  int find(int x) {
    if(center[x] == x) return x;
    else return center[x] = find(center[x]);
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(diameter[x] < diameter[y]) {
      swap(x, y);
    }
    center[y] = x;
    diameter[x] = max(diameter[x], (diameter[x]+1)/2 + (diameter[y]+1)/2 + 1);
  }

int main() {
  DRIII(n, m, q);
  adj.resize(n+1);
  visited.resize(n+1);
  height.resize(n+1);
  center.resize(n+1);
  diameter.resize(n+1);
  REP(i, m) {
    DRII(a, b);
    adj[a].PB(b);
    adj[b].PB(a);
  }
  REP1(i, 1, n) {
    if(!visited[i]) {
      calcHeight(i, -1);
      PII cd = getCenter(i, -1, 0);
      setCenter(i, -1, cd.first);
      diameter[cd.first] = cd.second;
    }
    // PIS(i); PI(center[i]);
  }
  while(q--) {
    DRI(t);
    if(t == 1) {
      DRI(x);
      PI(diameter[find(x)]);
    } else {
      assert(t == 2);
      DRII(x, y);
      unite(x, y);
    }
  }
  return 0;
}
