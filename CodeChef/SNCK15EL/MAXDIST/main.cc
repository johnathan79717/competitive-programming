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
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
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
#define PV(v) REP(i, SZ(v)) if(i < SZ(v)-1) PIS(v[i]); else PI(v[i]);

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

V(VI) adj;
int depth[10005];
int parent[10006];
int height[10005];

void dfs(int v, int p) {
    parent[v] = p;
    for(int u: adj[v]) {
        if (u != p) {
            depth[u] = depth[v]+1;
            dfs(u, v);
            MAX(height[v], height[u]+1);
        }
    }
}

void dfs(int root) {
    MS1(depth);
    MS1(parent);
    // MS0(height);
    depth[root] = 0;
    dfs(root, -1);
}

int main() {
    DRI(T);
    while(T--) {
        DRI(N);
        adj = V(VI)(N+1);
        REP(i, N-1) {
            DRI(A, B);
            adj[A].PB(B);
            adj[B].PB(A);
        }
        if (N == 2) {
            puts("NO");
            continue;
        }
        int root = 1;
        dfs(root);
        REP1(i, 1, N) {
            if (depth[i] > depth[root])
                root = i;
        }
        dfs(root);
        int leaf = 1;
        REP1(i, 1, N) {
            if (depth[i] > depth[leaf])
                leaf = i;
        }
        int d = depth[leaf];
        if (d % 2) {
            int p1 = leaf;
            REP(i, d / 2) {
                p1 = parent[p1];
            }
            int p2 = parent[p1];
            adj[p1].erase(find(ALL(adj[p1]), p2));
            adj[p2].erase(find(ALL(adj[p2]), p1));
            MS0(height);
            dfs(p1);
            dfs(p2);
            // assert(height[p1] == d/2 && height[p2] == d/2);
            int h = max(height[p1], height[p2]);
            // assert(h == d/2);
            int cnt1 = 0, cnt2 = 0;
            for(int v: adj[p1]) {
                if (height[v] == h-1)
                    cnt1++;
            }
            for(int v: adj[p2]) {
                if (height[v] == h-1)
                    cnt2++;
            }
            if (cnt1 == 1 || cnt2 == 1) {
                puts("YES");
            } else {
                puts("NO");
            }
        } else {
            int center = leaf;
            REP(i, d / 2) {
                center = parent[center];
            }
            MS0(height);
            dfs(center);
            int cnt = 0;
            // assert(height[center] == d/2);
            for(int v: adj[center]) {
                if (height[v] == height[center]-1) {
                    cnt++;
                }
            }
            if (cnt == 2) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }
    return 0;
}