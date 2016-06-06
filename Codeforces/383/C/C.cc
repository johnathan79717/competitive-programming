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

V(VI) adj;     // adjacency list

void add_edge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

VI parent, depth;
VI heavy; // the heaviest child
VI size; // size of subtree 
 
void init(int n) {
  adj.resize(n);
  parent.resize(n);
  depth.resize(n);
  heavy.resize(n);
  size.resize(n);
}

VI start, finish;
int number = 1;

void DFS(int i)
{
    if(parent[i] < 0) depth[i] = 0;
    size[i] = 1;
    start[i] = number++;
    for (int k=0; k<adj[i].size(); ++k)
    {
        int j = adj[i][k];
        if (j == parent[i]) continue;
 
        parent[j] = i;
        depth[j] = depth[i] + 1;
 
        DFS(j);
 
        size[i] += size[j];
        if (heavy[i] == -1 || size[j] > size[heavy[i]]) 
            heavy[i] = j;
    }
    finish[i] = number++;
}

// index starts with 1
template<class T>
class BIT {
  vector<T> bit;
public:
  BIT() {}
  BIT(int n): bit(n+1) {}
  T sum(int i) {
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


int main() {
  DRII(n, m);
  VI a(n);
  REP(i, n) {
    RI(a[i]);
  }
  init(n);
  REP(i, n-1) {
    DRII(v, u);
    --u; --v;
    add_edge(u, v);
  }
  start.resize(n);
  finish.resize(n);
  DFS(0);
  BIT<int> bit[2];
  bit[0].resize(number);
  bit[1].resize(number);
  while(m--) {
    DRII(type, x);
    x--;
    if(type == 1) {
      DRI(val);
      bit[depth.at(x) % 2].add(start.at(x), val);
      bit[depth.at(x) % 2].add(finish.at(x), -val);
    } else {
      PI(a.at(x) + bit[depth.at(x) % 2].sum(start.at(x)) - bit[1-depth.at(x)%2].sum(start.at(x)));
    }
  }
  return 0;
}
