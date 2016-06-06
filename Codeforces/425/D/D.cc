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
typedef vector<VI> VVI;
typedef long long LL;
const int INF = 1000000000;

struct Point
{
  int x, y;
};

int main() {
  DRI(n);
  V(Point) p;
  multimap<int, int> m;
  set<pair<int, pair<int, int>>> ans;
  set<pair<int, int>> set;
  VI xs;
  REP(i, n) {
    DRII(x, y);
    set.insert(MP(x, y));
    xs.PB(x);
    m.insert(MP(x, y));
  }
  sort(ALL(xs));
  xs.resize(unique(ALL(xs)) - xs.begin());

  FOR(x, xs) {
    int c = m.count(x);
    if(c * c > n) continue;
    auto pr = m.equal_range(x);
    for(auto i = pr.first; i != pr.second; i++) {
      int y1 = i->second;
      for(auto j = pr.first; j != i; j++) {
        int y2 = j->second;
        if(set.count(MP(y1, x + y2 - y1)) && set.count(MP(y2, x + y2 - y1)))
          ans.insert(MP(abs(y2-y1), MP(min(x, x + y2 - y1), min(y1, y2))));
        if(set.count(MP(y1, x + y1 - y2)) && set.count(MP(y2, x + y1 - y2)))
          ans.insert(MP(abs(y2-y1), MP(min(x, x + y1 - y2), min(y1, y2))));
      }
    }
    m.erase(pr.first, pr.second);
  }
  V(PII) ps;
  FOR(pr, m) {
    ps.PB(pr);
  }
  sort(ALL(ps), [](const PII &p1, const PII &p2) {
    return p1.second < p2.second;
  });
  int prev = 0;
  REP(i, ps.size()) {
    int y = ps[i].second, x1 = ps[i].first;
    REP1(j, prev, i-1) {
      if(y != ps[j].second) {
        j = prev = i;
        break;
      }
      int x2 = ps[j].first;
      if(set.count(MP(x1, y + x2 - x1)) && set.count(MP(x2, y + x2 - x1)))
        ans.insert(MP(abs(x2-x1), MP(min(y, y + x2 - x1), min(x1, x2))));
      if(set.count(MP(x1, y + x1 - x2)) && set.count(MP(x2, y + x1 - x2)))
        ans.insert(MP(abs(x2-x1), MP(min(y, y + x1 - x2), min(x1, x2))));
    }
  }
  PI(ans.size());
  return 0;
}
