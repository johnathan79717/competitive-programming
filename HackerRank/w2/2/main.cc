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
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 2000000000;

int q[100001];
int qf, qb;

int main() {
  DRI(N);
  VI A(N);
  LL sum = 0;
  REP(i, N) {
    RI(A[i]);
    sum += A[i];
  }
  V(VI) adj(N);
  REP(i, N-1) {
    DRII(u, v);
    adj[u-1].PB(v-1);
    adj[v-1].PB(u-1);
  }
  VI parent(N, -2);
  q[qb++] = 0;
  parent[0] = -1;
  while(qf != qb) {
    int u = q[qf++];
    FOR(v, adj[u]) {
      if(parent[v] == -2) {
        q[qb++] = v;
        parent[v] = u;
      }
    }
  }
  V(LL) dp(N);
  LL ans = LLONG_MAX;
  PER(i, N) {
    // ans = min(ans, abs(sum - 2*dp[q[i]]));
    dp[q[i]] += A[q[i]];
    ans = min(ans, abs(sum - 2*dp[q[i]]));
    if(parent[q[i]] >= 0) dp[parent[q[i]]] += dp[q[i]];
  }
  PL(ans);
  return 0;
}