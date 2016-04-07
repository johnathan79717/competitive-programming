#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <set>
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
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
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

V(V(PII)) edge;
LL ans[1000000];
int size[1000000];
int N;

void dfs1(int u, int p) {
    size[u] = 1;
    FOR(e, edge[u]) {
        if (e.F == p) continue;
        dfs1(e.F, u);
        ans[u] += ans[e.F] + (LL)e.S * size[e.F];
        size[u]+=size[e.F];
    }
}

void dfs2(int u, int p, LL pe) {
    if (p > 0) {
        LL up = ans[p] - ans[u] - pe * size[u];
        ans[u] += up + pe * (N - size[u]);
    }
    FOR(e, edge[u]) {
        if (e.F == p) {
            continue;
        }
        dfs2(e.F, u, e.S);
    }
}

int main() {
    DRI(T);
    while(T--) {
        RI(N);
        edge = V(V(PII))(N+1);
        REP(i, N-1) {
            DRIII(x, y, z);
            edge[x].EB(y, z);
            edge[y].EB(x, z);
        }
        MS0(ans);
        dfs1(1, -1);
        dfs2(1, -1, -1);
        REP1(i, 1, N) {
            PL(ans[i]);
        }
    }
  return 0;
}