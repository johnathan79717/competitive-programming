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
using namespace std;
#define BG begin()
#define ED end()
#define FOR(i,c) for(auto &i: c)
#define SZ size()
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define RL(x) scanf("%lld",&x)
#define DRI(x) int x;RI(x)
#define DRL(x) LL x;RL(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PL(x) printf("%lld\n",x)
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

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000;

#define MOD 1000000007
inline int add(int a, int b, int mod=MOD) { return a + b < mod ? a + b : a + b - mod; }
inline void addBy(int &a, int b, int mod=MOD) { a = add(a, b, mod); }
inline int sub(int a, int b, int mod=MOD) { return a - b < 0 ? a - b + mod : a - b; }
inline void subBy(int &a, int b, int mod=MOD) { a = sub(a, b, mod); }
inline int mul(int a, int b, int mod=MOD) { return (LL)a * b % mod; }
inline void mulBy(int &a, int b, int mod=MOD) { a = mul(a, b, mod); }

struct Query
{
  int L, R, i;
};

struct DisjointSet {
  VI par, rank;
  int count, n;

  DisjointSet(int n): par(n+1), rank(n+1), count(n), n(n) {
    init();
  }

  void init() {
    for(int i = 1; i <= n; i++) {
      par[i] = i;
      rank[i] = 0;
    }
    count = n;
  }

  int find(int x) {
    while(x != par[x]) x = par[x];
    return x;
  }

  void unite(const PII &p) {
    int x = find(p.F);
    int y = find(p.S);
    if(x == y) {
      stk.push(MP(-1, false));
      return;
    }
    count--;
    if(rank[x] < rank[y]) {
      par[x] = y;
      stk.push(MP(x, false));
    } else {
      par[y] = x;
      stk.push(MP(y, false));
      if(rank[x] == rank[y]) {
        rank[x]++;
        stk.top().S = true;
      }
    }
  }

  stack<pair<int, bool> > stk;

  void deunion() {
    int x = stk.top().F;
    if(x >= 0) {
      if(stk.top().S) rank[par[x]]--;
      par[x] = x;
      count++;
    }
    stk.pop();
  }

};

int main() {
  DRI(T);
  REP(t, T) {
    DRIII(N, M, Q);
    V(PII) edge(M+1);
    REP1(i, 1, M) {
      RII(edge[i].F, edge[i].S);
    }
    int B = sqrt(M);
    V(Query) query(Q);
    V(V(Query)) bucket((M+1) / B + 1);
    REP(i, Q) {
      RII(query[i].L, query[i].R);
      query[i].i = i;
      bucket[query[i].L / B].PB(query[i]);
    }
    VI ans(Q);
    FOR(b, bucket) {
      sort(ALL(b), [](Query const &q1, Query const &q2) {
        return q1.R < q2.R;
      });
      DisjointSet base(N);
      int baseL = 0;
      FOR(q, b) baseL = max(baseL, q.L);
      int baseR = baseL-1;
      FOR(q, b) {
        if(q.R < baseL) {
          REP1(i, q.L, q.R)
            base.unite(edge[i]);
          ans[q.i] = base.count;
          REP1(i, q.L, q.R)
            base.deunion();
        } else {
          while(baseR < q.R)
            base.unite(edge[++baseR]);
          PER1(l, baseL-1, q.L)
            base.unite(edge[l]);
          ans[q.i] = base.count;
          PER1(l, baseL-1, q.L)
            base.deunion();
        }
      }
    }
    REP(i, Q) PI(ans[i]);
  }
  return 0;
}