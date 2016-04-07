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
#include <list>
#include <deque>
using namespace std;
#define FOR(i,c) for(auto i=(c).begin();i!=(c).end();i++)
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
// #define E emplace
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

#define MAX_N 100001
#define MAX_M 300001

int N, M, rnk, bridge;
LL ans;

list<int> E[MAX_N];
bool used[MAX_M], isE2[MAX_M];
int r[MAX_N], ptr[MAX_N], ev[MAX_N], psi[MAX_N];
int i[MAX_M], t[MAX_M], cnt[MAX_M]; //, cut[MAX_M];
vector<int> E2;

void dfs(int u) {
  r[u] = rnk++;
  for(const int &e : E[u]) {
    if(used[e]) continue;
    used[e] = true;
    int v = u ^ i[e] ^ t[e];
    if(r[v] < 0) {
      // E1
      ev[v] = e;
      dfs(v);
    } else if(r[v] < r[u]) {
      // E2
      E2.PB(e);
      isE2[e] = true;
    }
  }
}

void searchTrace() {
  MS0(used); MS0(cnt); MS0(isE2); MS1(r);
  rnk = 0;
  E2.clear();
  REP(u, N) if(r[u] < 0) dfs(u);
  REP(e, M) if(r[i[e]] < r[t[e]]) swap(i[e], t[e]);
  sort(ALL(E2), [&](const int &e1, const int &e2) {
    return r[t[e1]] < r[t[e2]];
  });
  REP(v, N) ptr[v] = v;
  bridge = N-1;
  for(const int &e : E2) {
    stack<int> path;
    int v = ptr[i[e]];
    while(r[v] > r[t[e]]) {
      if(cnt[ev[v]] == 0) {
        cnt[ev[v]]++;
        ans++;
        bridge--;
        // cut[t[ev[v]]] = e;
      } else if(cnt[ev[v]] == 1)
        path.push(v);
      v = ptr[t[ev[v]]];
    }
    while(!path.empty()) {
      int v = path.top();
      ptr[v] = ptr[t[ev[v]]];
      cnt[ev[v]] = 2;
      path.pop();
      ans--;
    }
  }
}

void dfs2(int u, int component) {
  psi[u] = component;
  for(const int &e : E[u]) {
    if(!isE2[e]) continue;
    int v = u ^ i[e] ^ t[e];
    if(psi[v] < 0)
      dfs2(v, component);
  }
}

void add_edge(int e, int u, int v) {
  i[e] = u;
  t[e] = v;
  E[u].PB(e);
  E[v].PB(e);
}

void contraction() {
  int component = 0;
  MS1(psi);
  REP(u, N)
    if(psi[u] < 0 && E[u].size() > 0)
      dfs2(u, component++);
  N = component;
  REP(u, N) E[u].clear();
  REP(e, M) {
    while(e < M && psi[i[e]] == psi[t[e]]) {
      i[e] = i[M-1];
      t[e] = t[M-1];
      M--;
      ans += bridge;
    }
    if(e >= M) break;
    i[e] = psi[i[e]];
    t[e] = psi[t[e]];
    E[i[e]].PB(e);
    E[t[e]].PB(e);
  }
}

int main() {
  RII(N, M);
  REP(e, M) {
    DRII(u, v);
    add_edge(e, u-1, v-1);
  }
  while(true) {
    searchTrace();
    if(E2.size() == 0) break;
    contraction();
  }
  PL(ans + (LL)M * (M-1) / 2);
  return 0;
}