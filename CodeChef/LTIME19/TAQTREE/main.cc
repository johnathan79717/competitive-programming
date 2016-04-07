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
#include <sstream>
#include <bitset>
using namespace std;
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define BG begin()
#define ED end()
#define FOR(i,c) for(auto &i: c)
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
struct Edge {int to, cost, index; };
V(V(Edge)) adj;     // adjacency list

VI parent, depth;
VI heavy; // the heaviest child
VI size; // size of subtree

VI chain; // chain id
VI head; // the topmost node of the chain

void init(int n) {
  parent.resize(n);
  depth.resize(n);
  heavy.resize(n);
  size.resize(n);
  chain.resize(n);
  head.resize(n);
} 
 
#define M 100005

int weight[M], down[M];
void DFS(int i)
{
    if(parent[i] < 0) depth[i] = 0;
    size[i] = 1;
    for (int k=0; k<adj[i].size(); ++k)
    {
        int j = adj[i][k].to;
        if (j == parent[i]) continue;
        down[adj[i][k].index] = j;
        weight[j] = adj[i][k].cost;
        parent[j] = i;
        depth[j] = depth[i] + 1;
 
        DFS(j);
 
        size[i] += size[j];
        if (heavy[i] == -1 || size[j] > size[heavy[i]]) 
            heavy[i] = j;
    }
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

V(BIT<LL>) bits;
 
void heavylight_DFS(int N)
{
    init(N);
    fill(heavy.begin(), heavy.end(), -1);
 
    parent[0] = -1;
    depth[0] = 0;
    DFS(0);
 
    int c = 0;  
    for (int i=0; i<N; ++i)
        if (parent[i] == -1 || heavy[parent[i]] != i)
        {
            int l = 0;
            for (int k = i; k != -1; k = heavy[k])
                chain[k] = c, head[k] = i, l++;
            bits.EB(l);
            for (int k = i; k != -1; k = heavy[k]) {
                bits.back().add(depth[k] - depth[i] + 1, weight[k]);
            }
            c++;
        }
}
 
int lca(int i, int j)
{
    while (chain[i] != chain[j])
        if (depth[head[i]] > depth[head[j]])
            i = parent[head[i]];
        else
            j = parent[head[j]];
 
    return depth[i] < depth[j] ? i : j;
}
 
int edge[M];

LL path(int v) {
    if (v < 0) return 0;
    return path(parent[head[v]]) + bits[chain[v]].sum(depth[v] - depth[head[v]] + 1);
}

int main() {
    DRI(N);
    adj.resize(N);
    REP1(i, 1, N-1) {
        DRIII(u, v, w);
        --u; --v;
        edge[i] = w;
        adj[u].PB((Edge){v, w, i});
        adj[v].PB((Edge){u, w, i});
    }
    heavylight_DFS(N);
    CASET {
        DRI(t);
        if (t == 1) {
            DRII(i, c);
            int v = down[i];
            bits[chain[v]].add(depth[v] - depth[head[v]] + 1, c - edge[i]);
            edge[i] = c;
        } else {
            DRII(u, v);
            u--; v--;
            PL(path(u) + path(v) - 2 * path(lca(u, v)));
        }
    }    
    return 0;
}
