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
typedef long long LL;
const int INF = 1000000000;

#define MOD 1000000007
inline int add(int a, int b, int mod=MOD) { return a + b < mod ? a + b : a + b - mod; }
inline void addBy(int &a, int b, int mod=MOD) { a = add(a, b, mod); }
inline int sub(int a, int b, int mod=MOD) { return a - b < 0 ? a - b + mod : a - b; }
inline void subBy(int &a, int b, int mod=MOD) { a = sub(a, b, mod); }
inline int mul(int a, int b, int mod=MOD) { return (LL)a * b % mod; }
inline void mulBy(int &a, int b, int mod=MOD) { a = mul(a, b, mod); }

#define MAX_N 500000
int parent[MAX_N+1][21], depth[MAX_N+1];

int lca(int p, int q) {
  if(depth[p] < depth[q]) swap(p, q);
  PER(i, 21)
    if(parent[p][i] && depth[p] - (1 << i) >= depth[q])
      p = parent[p][i];
  assert(depth[p] == depth[q]);
  if(p == q) return p;
  PER(i, 21)
    if(parent[p][i] && parent[p][i] != parent[q][i])
      p = parent[p][i], q = parent[q][i];
  assert(p == q);
  return p;
}

int distance(int u, int v) {
  int r = lca(u, v);
  return depth[u] - depth[r] + depth[v] - depth[r];
}

int main() {
  depth[2] = depth[3] = depth[4] = 1;
  parent[2][0] = parent[3][0] = parent[4][0] = 1;
  int n = 4;
  DRI(q);
  int v1 = 2, v2 = 3;
  REP(qq, q) {
    DRI(v);
    REP(t, 2) {
      ++n;
      depth[n] = depth[v] + 1;
      parent[n][0] = v;
      int k = 0;
      while(parent[n][k])
        parent[n][k+1] = parent[parent[n][k]][k], ++k;
    }
    if(distance(n, v1) < distance(n, v2))
      v1 = n;
    else
      v2 = n;
    PI(distance(v1, v2));
  }
  return 0;
}
