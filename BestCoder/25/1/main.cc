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
#include <deque>
#include <stack>
using namespace std;
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(x) (x).begin(),(x).end()
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
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
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

V(VI) adj;
bool visited[101];
bool inStack[101];

bool dfs(int v) {
    inStack[v] = true;
    visited[v] = true;
    FOR(i, adj[v]) {
        int u = *i;
        if (inStack[u]) {
            inStack[v] = false;
            return false;
        }
        if (!visited[u] && !dfs(u)) {
            inStack[v] = false;
            return false;
        }
    }
    inStack[v] = false;
    return true;
}

int main() {
    int N, M;
    while (RII(N, M) != EOF) {
        adj = V(VI)(N+1);
        MS0(visited);
        MS0(inStack);
        while (M--) {
            DRII(a, b);
            adj[a].PB(b);
        }
        int i;
        for (i = 1; i <= N; i++) {
            if (!visited[i])
                if(!dfs(i)) {
                    puts("NO");
                    break;
                }
        }
        if (i > N) puts("YES");
    }
    return 0;
}
