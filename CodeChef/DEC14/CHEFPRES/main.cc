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
#define BG begin()
#define ED end()
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

#define MAX_LOG_V 15
VI G[10001];
int parent[MAX_LOG_V][10001];
int depth[10001];
int has[10001][101];

int N, K;

void dfs(int v, int p, int d) {
  parent[0][v] = p;
  depth[v] = d;
  for(int i = 0; i < G[v].size(); i++) {
    if(G[v][i] != p) dfs(G[v][i], v, d+1);
  }
    if (p >= 0) {
        REP1(i, 1, K) {
            has[p][i] = min(has[p][i], has[v][i]);
        }
    }
}

void init(int root) {
  dfs(root, -1, 0);
  for(int k = 0; k + 1 < MAX_LOG_V; k++) {
    REP1(v, 1, N) {
      if(parent[k][v] < 0) parent[k+1][v] = -1;
      else parent[k + 1][v] = parent[k][parent[k][v]];
    }
  }
}



int main() {
    RII(N, K);
    DRI(B);
    REP(i, N-1) {
        DRII(X, Y);
        G[X].PB(Y);
        G[Y].PB(X);
    }
    REP1(i, 1, N) REP1(j, 1, K) has[i][j] = INF;
    REP1(i, 1, N) {
        DRI(F);
        has[i][F] = min(has[i][F], i);
    }
    init(B);
    DRI(Q);
    while (Q--) {
        DRII(A, P);
        if (has[A][P] < INF) {
            PI(has[A][P]);
            continue;
        }
        PER(k, MAX_LOG_V) {
            if (parent[k][A] >= 0 && has[parent[k][A]][P] == INF) {
                A = parent[k][A];
            }
        }
        if (parent[0][A] == -1) {
            PI(-1);
        } else {
            PI(has[parent[0][A]][P]);
        }
    }
    return 0;
}
