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
#define X first
#define Y second
#define V(x) vector<x >
#define PV(v) REP(i, SZ(v)) if(i < SZ(v)-1) PIS(v[i]); else PI(v[i]);

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(unsigned x) { return __builtin_popcount(x); } 
int popcount(unsigned long long x) { return __builtin_popcountll(x); } 

typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

V(VI) adj;
bool visited[100000];
int cnt[2];

void dfs(int v, int p, int c) {
    if (visited[v]) return;
    visited[v] = true;
    cnt[c]++;
    for (int u: adj[v]) {
        if (u != p) {
            dfs(u, v, c ^ 1);
        }
    }
}

bool dp[2][5001];

int main() {
    CASET {
        DRI(N, M);
        adj = V(VI)(N);
        REP(i, M) {
            DRI(u, v);
            adj[u-1].PB(v-1);
            adj[v-1].PB(u-1);
        }
        MS0(visited);
        int p = 0, n = 1;
        MS0(dp);
        dp[n][0] = true;
        REP(i, N) {
            if (!visited[i]) {
                MS0(cnt);
                dfs(i, -1, 0);
                // PIS(cnt[0]); PI(cnt[1]);
                swap(n, p);
                MS0(dp[n]);
                PER1(j, N/2, 0) {
                    REP(k, 2) {
                        if (j >= cnt[k] && dp[p][j-cnt[k]]) {
                            dp[n][j] = true;
                        }
                    }
                }
            }
        }
        PER1(j, N/2, 0) {
            if (dp[n][j]) {
                PI(j * (N-j) - M);
                break;
            }
        }
    }
    return 0;
}
