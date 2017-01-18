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

#include <unordered_set>
#include <unordered_map>
#define RL(x) scanf("%lld",&x)
#define DRL(x) LL x;RL(x)
#define PL(x) printf("%lld\n",x)

struct Edge {
  int to, cost;
};

struct State {
  int delivered, carrying, town;
  LL cost;
  bool operator< (const State& rhs) const {
    return cost > rhs.cost;
  }
};

LL cost[5005][3][5005];

LL solve() {
  DRI(N, M, K);
  vector<vector<Edge>> adj(N+1);
  REP(i, M) {
    DRI(A, B, G);
    adj[A].PB((Edge){B, G});
    adj[B].PB((Edge){A, G});
  }
  VI S(K), D(K);
  REP(i, K) {
    RI(S[i], D[i]);
  }
  priority_queue<State> pq;
  {
    int d1 = 0, c1 = 0, t1 = 1;
    while (c1 < 2 && d1 + c1 < K && S[d1 + c1] == t1) {
      c1++;
    }
    pq.push((State){d1, c1, t1, 0});
  }
  REP(i, 5005) REP(j, 3) REP(k, 5005) cost[i][j][k] = LLONG_MAX;
  while (pq.size()) {
    const int d = pq.top().delivered;
    const int c = pq.top().carrying;
    const int t = pq.top().town;
    const LL co = pq.top().cost;
    pq.pop();
    if (cost[d][c][t] < co) {
      continue;
    }
    for (Edge& e : adj[t]) {
      int t1 = e.to;
      LL co1 = co + e.cost;
      int c1 = c;
      int d1 = d;
      while (c1 >= 1 && D[d1] == t1) {
        c1--;
        d1++;
      }
      while (c1 < 2 && d1 + c1 < K && S[d1 + c1] == t1) {
        c1++;
      }
      if (cost[d1][c1][t1] > co1) {
        cost[d1][c1][t1] = co1;
        pq.push((State){d1, c1, t1, co1});
        //printf("%d %d %d %lld\n", d1, c1, t1, co1);
      }
      if (d1 == K) {
        return co1;
      }
    }
  }
  return -1;
}

int main() {
  int T, cas = 1;
  scanf("%d", &T);
  while(T--) {
    printf("Case #%d: %lld\n", cas++, solve());
  }
}
