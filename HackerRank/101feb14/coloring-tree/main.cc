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
#include <unordered_set>
#include <unordered_map>
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

int N;
V(VI) adj;
VI color, ans;
unordered_map<int, int> last;

void dfs(int root) {
  stack<int> stack;
  VI parent(N), L(N);
  BIT<int> bit(N);
  parent[root] = -1;
  stack.push(root);
  int cnt = 1;
  while(!stack.empty()) {
    int u = stack.top();
    if(!L[u]) {
      L[u] = cnt++;
      if(last.count(color[u]))
        bit.add(last[color[u]], -1);
      bit.add(L[u], 1);
      last[color[u]] = L[u];
      FOR(v, adj[u])
        if(parent[u] != v) {
          parent[v] = u;
          stack.push(v);
        }
    } else {
      ans[u] = bit.sum(cnt-1) - bit.sum(L[u]-1);
      stack.pop();
    }
  }
}

int main() {
  RI(N);
  DRII(M, root);
  root--;
  adj.resize(N);
  REP(i, N-1) {
    DRII(a, b);
    adj[a-1].PB(b-1);
    adj[b-1].PB(a-1);
  }
  color.resize(N);
  REP(i, N) RI(color[i]);
  ans.resize(N);
  dfs(root);
  while(M--) {
    DRI(s);
    PI(ans[s-1]);
  }
  return 0;
}