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
#include <cassert>
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
#define LB lower_bound
#define UB upper_bound
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

#define MOD 1000000007
inline int add(int a, int b, int mod=MOD) { return a + b < mod ? a + b : a + b - mod; }
inline void addBy(int &a, int b, int mod=MOD) { a = add(a, b, mod); }
inline int sub(int a, int b, int mod=MOD) { return a - b < 0 ? a - b + mod : a - b; }
inline void subBy(int &a, int b, int mod=MOD) { a = sub(a, b, mod); }
inline int mul(int a, int b, int mod=MOD) { return (LL)a * b % mod; }
inline void mulBy(int &a, int b, int mod=MOD) { a = mul(a, b, mod); }

struct Event {
  int x, y, l, t, c;
  Event(int x, int y, int l, int t, int c): x(x), y(y), l(l), t(t), c(c) {}
  bool operator(Event const &e1) {
    return e1.c < e2.c;
  }
};

int main() {
  DRII(n, m);
  vector<pair<int, Tract> > events;
  REP(i, n) {
    DRIII(x, y, l);
    events.EB(x, y, l, y+l, 0);
    events.EB(x, y, l, y, 1);
  }
  int ans = 0;
  REP(j, m) {
    DRIII(x, y, l);
    events.EB(x, y, l, y, 2);
  }
  sort(ALL(events));
  set<int> v;
  set<int, greater<int> > r;
  FOR(e, events) {
    if(e.c == 0) {
      v.erase(e.x);
      r.erase(e.x);
    } else if(e.c == 1) {
      v.insert(e.x);
      r.insert(e.x);
    } else {
      int lb = lower_bound(ALL(v), e.x + e.l / 2);
      ans = max(ans, min(lb-x, x+l-lb));
      int ub = lower_bound(ALL(r), e.x + e.l / 2);
      ans = max(ans, min(ub-x, x+l-ub));
    }
  }
  PI(ans);
  return 0;
}
