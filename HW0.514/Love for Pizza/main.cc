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

struct Topping
{
  int pref, x, y;
  bool operator<(Topping const &other) const {
    return (LL)y * other.x < (LL)other.y * x;
  }
};

int gcd(int x, int y) {
  if(x == 0) return y;
  return gcd(y % x, x);
}

int main() {
  DRI(T);
  REP(t, T) {
    DRI(N);
    V(Topping) toppings[4];
    LL sum = 0;
    while(N--) {
      DRIII(pref, x, y);
      sum += pref;
      int d = gcd(abs(x), abs(y));
      x /= d; y /= d;
      if(y > 0) {
        if(x > 0) toppings[0].PB(Topping({pref, x, y}));
        else toppings[1].PB(Topping({pref, x, y}));
      } else {
        if(x < 0) toppings[2].PB(Topping({pref, x, y}));
        else toppings[3].PB(Topping({pref, x, y}));
      }
    }
    int prevx = 0, prevy = 0;
    V(LL) prefs;
    REP(i, 4) {
      sort(ALL(toppings[i]));
      FOR(tt, toppings[i]) {
        if(tt.x == prevx && tt.y == prevy) {
          prefs.back() += tt.pref;
        } else {
          prefs.PB(tt.pref);
        }
        prevx = tt.x, prevy = tt.y;
      }
    }
    LL pos_max = 0, pos_tail = 0, neg_max = 0, neg_tail = 0;
    FOR(p, prefs) {
      pos_tail = max(0ll, pos_tail + p);
      neg_tail = max(0ll, neg_tail - p);
      pos_max = max(pos_max, pos_tail);
      neg_max = max(neg_max, neg_tail);
    }
    PL(max(pos_max, sum + neg_max));
  }
  return 0;
}
