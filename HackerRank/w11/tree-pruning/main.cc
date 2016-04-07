#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <set>
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
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;

int main() {
  DRII(N, K);
  V(LL) w(N*2+1);
  REP1(i, 1, N) RL(w[i]);
  V(VI) adj(N+1);
  REP(i, N-1) {
    DRII(u, v);
    adj[u].PB(v);
    adj[v].PB(u);
  }
  VI left(N*2+1), right(N*2+1);
  V(LL) sum(N*2+1);
  // function<void(int,int)> buildTree;
  // buildTree = [&](int u, int p) {
  //   int r = u;
  //   // left[u] = right[u] = -1;
  //   FOR(v, adj[u]) {
  //     if (v != p) {
  //       buildTree(v, u);
  //       left[r] = v;
  //       right[r] = ++N;
  //       r = right[u];
  //       w.PB(0);
  //     }
  //   }
  // };
  // buildTree(1, 0);
  V(V(LL)) f(N+1, V(LL)(K+1));
  function<void(int, int)> getSum;
  getSum = [&](int rt, int p) {
    if (!rt) return;
    sum[rt] = w[rt];
    FOR(v, adj[rt]) {
      // getSum(left[rt], rt);
      // getSum(right[rt], rt);
      if (v == p) continue;
      getSum(v, rt);
      sum[rt] += sum[v];
    }
    // sum[rt] = w[rt] + sum[left[rt]] + sum[right[rt]];
    // cout << rt << ' ' << sum[rt] << endl;
  };
  getSum(1, 0);
  function<void(int, int)> dfs;
  dfs = [&](int rt, int p) {
    // int j = left[rt];
    // while(j > 0) {
    //   REP1(i, 0, K) f[j][i] = f[rt][i];
    //   dfs(j);
    //   PER1(i, K, 1) f[rt][i] = min(f[j][i], f[rt][i-1] + sum[j]);
    //   j = right[j];
    // }
    if (!rt) return;
    FOR (v, adj[rt]) {
      if (v == p) continue;
      REP1(i, 0, K) f[v][i] = f[rt][i];
      PER1(i, K, 1) f[rt][i] = min(f[rt][i], f[rt][i-1] + sum[v]);
      dfs(v, rt);
      PER1(i, K, 1) f[rt][i] = min(f[v][i], f[rt][i]);
    }
  };
  dfs(1, 0);
  PL(max(0ll, sum[1] - f[1][K]));
  return 0;
}