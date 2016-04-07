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

V(VI) adj;     // adjacency list

void add_edge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

VI parent, depth;
VI heavy; // the heaviest child
VI size; // size of subtree
VI chain; // chain id
VI head; // the topmost node of the chain

void init(int n) {
  parent.resize(n+1);
  depth.resize(n+1);
  heavy.resize(n+1);
  size.resize(n+1);
  chain.resize(n+1);
  head.resize(n+1);
} 
 
// index starts with 1
template<class T>
class BIT {
  vector<T> bit;
public:
  BIT() {}
  BIT(int n): bit(n+1) {}
  T sum(int i) {
    i = min(i, (int)bit.size()-1);
    T s = 0;
    while(i > 0) {
      s += bit.at(i);
      i &= i - 1;
    }
    return s;
  }
  void add(int i, T x) {
    while(i < bit.size()) {
      bit.at(i) += x;
      i += i & -i;
    }
  }
  void resize(int n) {
    bit.resize(n+1);
  }
};

V(BIT<LL>) bit, biti; 
 
int q[250001], *qf, *qb; // BFS queue

V(LL) dist, D;
VI chainsize;
 
void heavylight_BFS(int N, int root)
{
    init(N);
    qf = qb = q;
    parent[root] = -1;
    depth[root] = 0;
    *qb++ = root;
    while (qf < qb)
        for (int i=*qf++, k=0; k<adj[i].size(); ++k)
        {
            int j = adj[i][k];
            if (j == parent[i]) continue;
            parent[j] = i;
            depth[j] = depth[i] + 1;
            *qb++ = j;
        }
    fill(size.begin(), size.end(), 0);
    fill(heavy.begin(), heavy.end(), -1);
    for (int k=N-1; k>0; --k)   
    {
        int j = q[k], i = parent[q[k]];
        size[j]++;
        size[i] += size[j];
        if (heavy[i] == -1 || size[j] > size[heavy[i]])
            heavy[i] = j;
    }
    size[0]++;
 
    int c = 0;
    for (int i=1; i<=N; ++i)
        if (parent[i] == -1 || heavy[parent[i]] != i)
        {
            for (int k = i; k != -1; k = heavy[k]) {
                chain[k] = c, head[k] = i;
                if(heavy[k] == -1) {
                  bit.EB(depth[k] - depth[i] + 1);
                  biti.EB(depth[k] - depth[i] + 1);
                }              
            }
            c++;
            dist.resize(c);
            D.resize(c);
            chainsize.resize(c);
        }
}

LL calc(int now, int node, int child) {
  int c = chain[now];
  int k = depth[now] - depth[head[now]];
  int delta = depth[node] - depth[now];
  LL ans = 2 * k * bit[c].sum(k+1) - k * bit[c].sum(1e9)
          - 2 * biti[c].sum(k+1) + biti[c].sum(1e9) + dist[c];
  if(child > 0) {
    int c2 = chain[child];
    ans += delta * (bit[c].sum(1e9) - chainsize[c2]) - D[c2];
    chainsize[c2]++;
    D[c2] += delta;
  }
  dist[c] += delta;
  bit[c].add(k+1, 1);
  biti[c].add(k+1, k);
  return ans;
}
 
int main() {
  DRI(N);
  VI a(N);
  VI root(N+1);
  adj.resize(N+1);
  REP(i, N) RI(a[i]);
  VI size(N+1);
  PER(i, N) {
    int m = a[i], l = 0, r = 0;
    size[m] = 1;
    root[m] = m;
    if(m > 1 && root[m-1]) {
      l = root[m-1];
      add_edge(l, m);
      root[m-size[l]] = m;
      size[m] += size[l];
    }
    if(m < N && root[m+1]) {
      r = root[m+1];
      add_edge(r, m);
      root[m+size[r]] = m;
      size[m] += size[r];
    }
  }
  heavylight_BFS(N, a[0]);
  LL ans = 0;
  REP(i, N) {
    int now = a[i], child = -1;
    while(now > 0) {
      ans += calc(now, a[i], child);
      child = head[now];
      now = parent[child];
    }
    PL(ans);
  }
  return 0;
}