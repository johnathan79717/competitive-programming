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
#include <cassert>
#include <deque>
#include <stack>
#include <functional>
#define X first
#define Y second
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
#define CASET int ___T; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define FOR(i,c) for(auto &i: c)
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI1(x) scanf("%d",&x)
#define RI2(x,y) RI1(x), RI1(y)
#define RI3(x,y...) RI1(x), RI2(y)
#define RI4(x,y...) RI1(x), RI3(y)
#define RI5(x,y...) RI1(x), RI4(y)
#define RI6(x,y...) RI1(x), RI5(y)
#define GET_MACRO(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define RI(argv...) GET_MACRO(argv, RI6, RI5, RI4, RI3, RI2, RI1)(argv)
#define DRI(argv...) int argv;RI(argv)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define DRL(x) LL x; RL(x)
#ifdef ONLINE_JUDGE
    #define PL(x) printf("%I64d\n",x)
    #define RL(x) scanf("%I64d\n",&x)
#else
    #define PL(x) printf("%lld\n",x)
    #define RL(x) scanf("%lld\n",&x)
#endif
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define DRA(A, N) VI A(N); REP(i, N) RI(A[i])
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;
template<typename T>
using V = std::vector<T>;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;

V<VI> adj;
int c[5005], d[5005];

LL use[5005][5005], all[5005][5005];

void dfs(int v, int p) {
  if (p >= 0) {
    REP(i, 5001) {
      use[v][i+1] = min(use[v][i+1], use[p][i] + d[i]);
      all[v][i+1] = min(all[v][i+1], all[p][i] + c[i]);
      all[v][i] = min(all[v][i], all[p][i]);
    }
    REP(i, 5001) {
      all[v][i] = min(all[v][i], use[v][i]);
    }
  }
  for (int u : adj[v]) {
    dfs(u, v);
  }
  if (p >= 0) {
    REP(i, 5001) {
      use[v][
    }
  }
}

int main() 
{
  DRI(N, B);
  adj.resize(N);
  REP(i, N) {
    RI(c[i], d[i]);
    if (i) {
      DRI(x);
      adj[x-1].PB(i);
    }
  }
  REP(i, 5001) REP(j, 5001) {
    use[i][j] = 1e18;
    notuse[i][j] = 1e18;
  }
  notuse[0][0] = 0;
  notuse[0][1] = c[0];
  use[0][0] = d[0];
  dfs(0, -1);
}

