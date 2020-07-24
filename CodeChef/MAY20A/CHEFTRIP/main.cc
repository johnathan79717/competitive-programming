#include <functional>
#include <list>
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
#define ALL(x) (x).begin(),(x).end()
#define CASET2 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d:\n", case_n++) : 0), ___T-- > 0)
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define REP(i,n) for(int i=0;i<int(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=int(b);i++)
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
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define X first
#define Y second
#define V(x) vector<x >

typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

void print(int i) { printf("%d", i); }
void print(LL i);
template<class T> void PI(T i) { print(i); puts(""); }
template<class T> void PIS(T i) { print(i); printf(" "); }

template<class T>
void PV(T const &v, int N) {
    REP(i, N) {
        print(v[i]);
        printf("%c", i == N-1 ? '\n' : ' ');
    }
}

template<class T> void PV(T const &v) { PV(v, SZ(v)); }

template<class T, class S> bool has_bit(T mask, S i) { return (mask >> i) & 1; }
long long shift(int i) { return 1ll << i; }

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(int x) { return __builtin_popcount(x); } 
int popcount(long long x) { return __builtin_popcountll(x); } 

#define MAX_LOG_V 18

struct LCA {
    VI depth;
    V(VI) parent;
    LCA(const V(VI)& adj) {
        int N = adj.size();
        depth = VI(N, -1);
        parent = V(VI)(MAX_LOG_V, VI(N, -1));

        queue<int> q;
        q.push(0);
        depth[0] = 0;
        while (!q.empty()) {
            for (int v : adj[q.front()]) {
                if (depth[v] < 0) {
                    depth[v] = depth[q.front()] + 1;
                    parent[0][v] = q.front();
                    q.push(v);
                }
            }
            q.pop();
        }
        for(int k = 0; k + 1 < MAX_LOG_V; k++) {
            for(int v = 0; v < N; v++) {
                if(parent[k][v] < 0)
                    parent[k+1][v] = -1;
                else
                    parent[k + 1][v] = parent[k][parent[k][v]];
            }
        }
    }
    
    int lca(int u, int v) {
        if(depth[u] > depth[v]) swap(u, v);
        for(int k = 0; k < MAX_LOG_V; k++) {
            if((depth[v] - depth[u]) >> k & 1) {
                v = parent[k][v];
            }
        }
        if(u == v) return u;
        for(int k = MAX_LOG_V - 1; k >= 0; k--) {
            if(parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};



#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)

VI decrease, increase, beautiful, A;

V(VI) adj;

void dfs(int u, int p) {
    for (int v: adj[u]) {
        if (p != v) {
            if (A[u] < A[v]) {
                decrease[v] = decrease[u] + 1;
            }
            if (A[u] > A[v]) {
                increase[v] = increase[u] + 1;
                beautiful[v] = max(beautiful[u] + 1, decrease[u] + 1);
            }

            dfs(v, u);
        }
    }
}

bool isBeautiful(LCA& lca, int x, int y) {
    int a = lca.lca(x, y);
    int dx = lca.depth[x] - lca.depth[a] + 1, dy = lca.depth[y] - lca.depth[a] + 1;
    if (increase[x] >= dx && (increase[y] >= dy || decrease[y] >= dy || beautiful[y] >= dy)) {
        return true;
    }
    if (increase[y] >= dy && (increase[x] >= dx || decrease[x] >= dx || beautiful[x] >= dx)) {
        return true;
    }
    return false;
}

void solve() {
    DRI(N, Q);
    adj = V(VI)(N);
    REP(i, N-1) {
        DRI(u, v);
        u--; v--;
        adj[u].PB(v);
        adj[v].PB(u);
    }
    A = VI(N);
    REP(i, N) {
        RI(A[i]);
    }
    LCA lca(adj);
    decrease = increase = beautiful = VI(N, 1);
    dfs(0, -1);
    while (Q--) {
        DRI(x, y);
        x--; y--;
        printf("%d", isBeautiful(lca, x, y));
    }
    puts("");
}

int main() {
    CASET {
        solve();
    }
    return 0;
}
