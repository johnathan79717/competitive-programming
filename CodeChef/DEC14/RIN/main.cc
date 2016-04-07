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

V(VI) edge;
VI topology;
V(bool) visited;

void dfs(int u) {
    visited[u] = true;
    FOR(v, edge[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
    topology.PB(u);
}

int main() {
    DRIII(N, M, K);
    V(VI) X(N+1, VI(M));
    edge.resize(N+1);
    REP1(i, 1, N) REP(j, M) {
        RI(X[i][j]);
    }
    while (K--) {
        DRII(A, B);
        edge[A].PB(B);
    }
    visited.resize(N+1);
    // PER1(i, N, 1) {
    REP1(i, 1, N) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ALL(topology));
    // FOR(i, topology) {
    //     PI(i);
    // }
    V(VI) dp(N+1, VI(M+1, -INF));
    REP1(i, 0, M) dp[0][i] = 0;
    REP1(i, 1, N) {
        int course = topology[i-1];
        REP1(j, 1, M) {
            dp[i][j] = dp[i][j-1];
            if (X[course][j-1] != -1) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + X[course][j-1]);
            }
        }
    }
    PI(dp[N][M]);
    return 0;
}
