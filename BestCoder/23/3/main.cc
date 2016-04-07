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

struct Edge
{
    int to, len;
};

V(V(Edge)) edge;

LL ans = 1e18;

int n, K;
LL *dfs(int u, int p) {
    // V(LL) ret(K+1, 1e18);
    LL *ret = new LL[K+1];
    ret[1] = 0;
    FOR(e, edge[u]) {
        if (e->to != p) {
            LL *a = dfs(e->to, u);
            PER1(i, K, 0) {
                REP1(j, 1, K-i) {
                    ret[i+j] = min(ret[i+j], ret[i] + a[j] + e->len);
                }
            }
            delete a;
        }
    }
    ans = min(ans, ret[K]);
    return ret;
}

int main() {
    CASET {
        RII(n, K);
        edge = V(V(Edge))(n+1);
        REP(i, n-1) {
            DRIII(a, b, c);
            edge[a].PB((Edge){b, c});
            edge[b].PB((Edge){a, c});
        }
        dfs(1, -1);
        cout << ans << endl;
    }
    return 0;
}
