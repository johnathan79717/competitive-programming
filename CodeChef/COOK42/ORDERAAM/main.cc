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
using namespace std;
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
#define BG begin()
#define ED end()
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
const int INF = 2000000000;

struct Order
{
  int begin, items, end, penalty;
  Order(int b, int i, int e, int p):
    begin(b), items(i), end(e), penalty(p) {}
};

struct Segment
{
  int begin, end, quota;
  Segment(int q, int b, int e):
    begin(b), end(e), quota(q) {}
};

bool ComparePenalty(const Order &o1, const Order &o2) {
  return o1.penalty > o2.penalty;
}

LL solve(V(Order) &orders, int n) {
  sort(orders.BG, orders.BG+n, [](const Order &o1, const Order &o2) {
    return o1.end < o2.end;
  });
  VI events;
  REP(i, n) {
    events.PB(orders[i].begin);
    events.PB(orders[i].end);
  }
  sort(ALL(events));
  events.resize(unique(ALL(events)) - events.BG);
  V(Segment) segments;
  REP(i, events.SZ - 1)
    segments.EB(events[i+1] - events[i], events[i], events[i+1]);
  LL ans = 0;
  REP(i, n) {
    int items = orders[i].items;
    FOR(s, segments) {
      if(orders[i].begin <= s.begin && s.end <= orders[i].end) {
        if(items <= s.quota) {
          s.quota -= items;
          items = 0;
          break;
        } else {
          items -= s.quota;
          s.quota = 0;
        }
      }
    }
    ans += items;
  }
  sort(orders.BG, orders.BG+n, ComparePenalty);
  orders[n-1].items -= ans;
  return ans;
}

int main() {
  DRI(T);
  while(T--) {
    DRI(N);
    V(Order) orders;
    REP(i, N) {
      DRII(S, X); DRII(D, P);
      orders.EB(S, X, D, P);
    }
    sort(ALL(orders), ComparePenalty);
    LL ans = 0;
    REP1(n, 2, orders.SZ)
      ans += solve(orders, n) * orders[n-1].penalty;
    PL(ans);
  }
  return 0;
}