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

struct Edge {
    int to, cost;
};

int d[10001][1001];

typedef pair<int, PII> PIII;

int main() {
    DRI(N, E, K);
    V(V(Edge)) edge(N+1), shortcut(N+1);
    REP(i, N-1) {
        DRI(a, b, w);
        edge[a].PB(Edge({b, w}));
        edge[b].PB(Edge({a, w}));
    }
    REP(i, E) {
        DRI(a, b, w);
        shortcut[a].PB(Edge({b, w}));
        shortcut[b].PB(Edge({a, w}));
    }
    priority_queue<PIII, vector<PIII>, greater<PIII>> q;
    REP1(i, 1, N) {
        REP1(k, 0, K) {
            d[i][k] = INF;
        }
    }
    REP1(i, 1, N) {
        if (edge[i].size() <= 1) {
            q.emplace(0, MP(i, 0));
            d[i][0] = 0;
        }
    }
    while (!q.empty()) {
        int dd = q.top().F, v = q.top().S.F, k = q.top().S.S;
        q.pop();
        if (d[v][k] < dd) continue;
        for (auto const &e: edge[v]) {
            if (d[v][k] + e.cost < d[e.to][k]) {
                d[e.to][k] = d[v][k] + e.cost;
                q.emplace(d[e.to][k], MP(e.to, k));
            }
        }
        if (k < K) {
            for (auto const &e: shortcut[v]) {
                if (d[v][k] + e.cost < d[e.to][k+1]) {
                    d[e.to][k+1] = d[v][k] + e.cost;
                    q.emplace(d[e.to][k+1], MP(e.to, k+1));
                }
            }
            if (d[v][k] < d[v][k+1]) {
                d[v][k+1] = d[v][k];
                q.emplace(d[v][k+1], MP(v, k+1));
            }
        }

    }
    REP1(i, 1, N) {
        PI(d[i][K]);
    }
}