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

#include <unordered_set>
#include <unordered_map>
#define PL(x) printf("%lld\n",x)
#define EB emplace_back
#define RL(x) scanf("%lld",&x)
#define DRL(x) LL x;RL(x)

#define MAX_LOG_V 20
V(VI) G;
int parent[MAX_LOG_V][300001];
int depth[300001];

int N;

void init() {
    MS1(depth);
    queue<int> q;
    q.push(0);
    depth[0] = 0;
    while (!q.empty()) {
        FOR(it, G[q.front()]) {
            int v = *it;
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

int main() {
    DRI(T);
    while(T--) {
        RI(N);
        G = V(VI)(N);
        REP(i, N-1) {
            DRI(u, v);
            G[u-1].PB(v-1);
            G[v-1].PB(u-1);
        }
        init();
        CASET {
            DRI(K);
            VI A(K);
            REP(i, K) {
                RI(A[i]);
                A[i]--;
            }
            int a = A[0];
            REP1(i, 1, K-1) {
                a = lca(a, A[i]);
            }
            sort(ALL(A), [](int i, int j) {
                return depth[i] < depth[j];
            });
            while (K >= 2 && lca(A[K-1], A[K-2]) == A[K-2]) {
                K--;
                A.pop_back();
            }
            if (K == 1) {
                puts("Yes");
            } else {
                int a1 = A[K-1], a2 = A[K-2];
                if (lca(a1, a2) != a) {
                    puts("No");
                    continue;
                }
                bool fail = false;
                PER(i, K) {
                    if (lca(A[i], a1) == A[i]) {
                        a1 = A[i];
                    } else if (lca(A[i], a2) == A[i]) {
                        a2 = A[i];
                    } else {
                        fail = true;
                        break;
                    }
                }
                puts(fail ? "No" : "Yes");
            }
        }
    }
    return 0;
}