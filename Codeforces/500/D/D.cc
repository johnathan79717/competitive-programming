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

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

struct Edge
{
    int to, index;
};

int N;
LL total;
vector<LL> w, cnt;
vector<vector<Edge>> adj;
int dfs(int v, int p) {
    int ans = 1;
    FOR(e, adj[v]) {
        if (e.to != p) {
            int c = dfs(e.to, v);
            cnt[e.index] = (LL)c * (N-c);
            total += cnt[e.index] * w[e.index];
            ans += c;
        }
    }
    return ans;
}

int main() {
    RI(N);
    adj.resize(N+1);
    w.resize(N);
    cnt.resize(N);
    REP1(i, 1, N-1) {
        DRIII(a, b, l);
        adj[a].PB((Edge){b, i});
        adj[b].PB((Edge){a, i});
        w[i] = l;
    }
    dfs(1, -1);
    LL prs = LL(N) * (N-1);
    CASET {
        DRII(r, wt);
        total += (wt - w[r]) * cnt[r];
        w[r] = wt;
        printf("%.10f\n", total * 6.0 / prs);
    }
  return 0;
}
