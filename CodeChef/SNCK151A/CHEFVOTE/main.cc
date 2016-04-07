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
#include <deque>
#include <stack>
#include <cassert>
using namespace std;
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
#define ALL(x) (x).begin(),(x).end()
#define CASET2 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d:\n", case_n++) : 0), ___T-- > 0)
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define RI1(x) scanf("%d",&x)
#define RI2(x,y) RI1(x), RI1(y)
#define RI3(x,y...) RI1(x), RI2(y)
#define RI4(x,y...) RI1(x), RI3(y)
#define RI5(x,y...) RI1(x), RI4(y)
#define RI6(x,y...) RI1(x), RI5(y)
#define GET_MACRO(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define RI(argv...) GET_MACRO(argv, RI6, RI5, RI4, RI3, RI2, RI1)(argv)
#define DRI(argv...) int argv;RI(argv)
#define WRI(argv...) while (RI(argv) != EOF)
#define DWRI(x...) int x; WRI(x)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define F first
#define S second
#define V(x) vector<x >

int popcount(unsigned x) { return __builtin_popcount(x); } 
int popcount(unsigned long long x) { return __builtin_popcountll(x); } 

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

#include <unordered_set>
#include <unordered_map>
#define PL(x) printf("%lld\n",x)
#define EB emplace_back
#define RL(x) scanf("%lld",&x)
#define DRL(x) LL x;RL(x)

class Graph {
public:
  struct edge { int to, cap, rev; };
  vector<vector<edge> > G;
private:
  int V;
  vector<bool> used;
  VI level, iter;
  void bfs() {
    fill(ALL(level), -1);
    queue<int> que;
    level[source] = 0;
    que.push(source);
    while(!que.empty()) {
      int v = que.front(); que.pop();
      FOR(e, G[v]) {
        if(e->cap > 0 && level[e->to] < 0) {
          level[e->to] = level[v] + 1;
          que.push(e->to);
        }
      }
    }
  }
  int dfs(int v, int f) {
    if(v == sink) return f;
    for(int &i = iter[v]; i < G[v].size(); i++) {
      edge &e = G[v][i];
      if(e.cap > 0 && level[v] < level[e.to]) {
        int d = dfs(e.to, min(f, e.cap));
        if(d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
public:
  int source, sink;
  Graph() { V = 0; source = addVertex(); sink = addVertex(); }
  int addVertex() {
    G.resize(V+1);
    return V++;
  }
  void addEdge(int from, int to, int cap) {
    G[from].push_back((edge){to, cap, (int)G[to].size()});
    G[to].push_back((edge){from, 0, (int)G[from].size() - 1});
  }
  int maxFlow() {
    int flow = 0;
    level.resize(V);
    iter.resize(V);
    for (;;) {
      bfs();
      if(level[sink] < 0) return flow;
      fill(ALL(iter), 0);
      int f;
      while((f = dfs(source, INT_MAX)) > 0) {
        flow += f;
      }
    }
    return flow;
  }
};

int main() {
    DRI(T);
    while(T--) {
        DRI(N);
        Graph g;
        VI left(N), right(N);
        int sum = 0;
        REP(i, N) {
            left[i] = g.addVertex();
            right[i] = g.addVertex();
            g.addEdge(g.source, left[i], 1);
            DRI(c);
            sum += c;
            g.addEdge(right[i], g.sink, c);
        }
        if (sum != N) {
            PI(-1);
            continue;
        }
        REP(i, N) {
            REP(j, N) {
                if (i != j) {
                    g.addEdge(left[i], right[j], 1);
                }
            }
        }
        if (g.maxFlow() != sum) {
            PI(-1);
            continue;
        }
        REP(i, N) {
            FOR(e, g.G[left[i]]) {
                if (e->cap == 0) {
                    if (i == N-1)
                        PI(e->to/2);
                    else
                        PIS(e->to/2);
                    break;
                }
            }
        }
    }
    return 0;
}