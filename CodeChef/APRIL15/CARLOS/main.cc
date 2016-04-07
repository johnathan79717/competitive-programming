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
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define BG begin()
#define ED end()
#define FOR(i,c) for(auto &i: c)
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define GET_4TH(_1, _2, _3, NAME, ...) NAME
#define RI(argv...) GET_4TH(argv, RI3, RI2, RI1)(argv)
#define RI1(x) scanf("%d",&x)
#define RI2(x,y) RI1(x), RI1(y)
#define RI3(x,y,z) RI1(x), RI2(y, z)
#define DRI(argv...) int argv;RI(argv)
#define RL(x) scanf("%lld",&x)
#define DRL(x) LL x;RL(x)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PL(x) printf("%lld\n",x)
#define PZ(x) PI((x).i);
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
#define MIN(x, y) x = min(x, y);
#define MAX(x, y) x = max(x, y);
#define DRA(A, N) VI A(N); REP(i, N) RI(A[i])

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000;

struct DisjointSet {
  VI par, _size;
  int N;

  DisjointSet(int N): par(N), _size(N), N(N) {
    init();
  }

  void init() {
    for(int i = 0; i < N; i++) {
      par[i] = i;
      _size[i] = 1;
    }
  }

  int find(int x) {
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(_size[x] < _size[y]) {
      par[x] = y;
      _size[y] += _size[x];
    } else {
      par[y] = x;
      _size[x] += _size[y];
    }
  }

  int size(int x) {
    return _size[find(x)];
  }
};

V(VI) adj;
int dp[200001][201];

int main() {
    DRI(T);
    REP(t, T) {
        DRI(M, K, N);
        adj = V(VI)(M+1);
        DisjointSet ds(M+1);
        while (K--) {
            DRI(x, y);
            ds.unite(x, y);
        }
        DRA(A, N);
        REP1(i, 1, M) {
            VI A;
            REP1(j, 1, M) {
                if (ds.find(j) == i) {
                    A.PB(j);
                }
            }
            FOR(a, A) {
                FOR(b, A) {
                    if (b == a) continue;
                    adj[a].PB(b);
                }
            }
        }
        // V(VI) dp(N+1, VI(M+1, INF));
        REP1(i, 0, N) REP1(j, 0, M) dp[i][j] = INF;
        dp[0][A[0]] = 0;
        if (!adj[A[0]].empty())
            dp[0][adj[A[0]].front()] = 1;
        REP1(i, 1, N-1) {
            auto it = adj[A[i]].begin();
            REP1(j, 1, M) {
                if (dp[i-1][j] == INF) continue;
                while (it != adj[A[i]].end() && *it < j) {
                    it++;
                }
                if (j <= A[i]) {
                    MIN(dp[i][A[i]], dp[i-1][j]);
                }
                if (it != adj[A[i]].end()) {
                    MIN(dp[i][*it], dp[i-1][j] + 1);
                }
            }
        }
        int ans = INF;
        REP1(j, 1, M) {
            MIN(ans, dp[N-1][j]);
        }
        PI(ans < INF ? ans : -1);
    }
    return 0;
}
