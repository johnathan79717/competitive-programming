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
using namespace std;
#define FOR(i,c) for(auto i=(c).begin();i!=(c).end();i++)
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
#define CASET int ___T,cas=1;scanf("%d ",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define PQ priority_queue
#define BG begin()
#define ED end()
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

double EPS = 1e-10;

double add(double a, double b) {
  if(abs(a + b) < EPS * (abs(a) + abs(b))) return 0;
  return a + b;
}

struct P {
  double x, y;
  P() {}
  P(double x, double y) : x(x), y(y) {}
  P operator + (const P &p) const {
    return P(add(x, p.x), add(y, p.y));
  }
  P operator - (const P &p) const {
    return P(add(x, -p.x), add(y, -p.y));
  }
  P operator * (double d) const {
    return P(x * d, y * d);
  }
  bool operator == (const P &p) const {
    return abs(this->x - p.x) <= EPS * (abs(this->x) + abs(p.x))
     && abs(this->y - p.y) <= EPS * (abs(this->y) + abs(p.y));
  }
  bool operator < (const P &p) const {
    if(abs(this->x - p.x) > EPS) return this->x < p.x;
    return this->y < p.y;
  }
  double dot(const P &p) const {
    return add(x * p.x, y * p.y);
  }
  double cross(const P &p) const {
    return add(x * p.y, -y * p.x);
  }
  bool on_seg(const P &p1, const P &p2) const {
    return (p1 - *this).cross(p2 - *this) == 0 && (p1 - *this).dot(p2 - *this) <= 0;
  }
  int rel_pos(const P &p1, const P &p2) const {
    double pos = (p1 - *this).cross(p2 - *this);
    return (pos > 0) - (pos < 0);
  }
};

P intersection(const P &p1, const P &p2, const P &q1, const P &q2) {
  return p1 + (p2 - p1) * ((q2 - q1).cross(q1 - p1) / (q2 - q1).cross(p2 - p1));
}

bool intersect(const P &p1, const P &p2, const P &q1, const P &q2) {
  P r = intersection(p1, p2, q1, q2);
  return r.on_seg(p1, p2) && r.on_seg(q1, q2);
}

P p[301];
double area[301];

int main() {
  DRII(n, k);
  vector<P> prev, next;
  REP1(j, 0, k)
    next.EB(j, 0);
  REP(i, n) {
    swap(prev, next);
    next.clear();
    auto it = prev.begin();
    REP1(j, 0, k) {
      p[j].x = j; scanf("%lf", &p[j].y);
      while(it->x + EPS < j) {
        int pos = it->rel_pos(p[j-1], p[j]);
        if(pos >= 0)
          next.PB(*it);
        if(pos * (it+1)->rel_pos(p[j-1], p[j]) < 0)
          next.PB(intersection(*(it), *(it+1), p[j-1], p[j]));
        it++;
      }
      if(p[j].y >= it->y)
        next.PB(p[j]);
      else
        next.PB(*it);
    }
    next.resize(unique(ALL(next)) - next.begin());
    FOR(it, next) {
      if(it != next.BG)
        area[i] += ((it-1)->y + it->y) * (it->x - (it-1)->x) / 2;
    }
    printf("%lf\n", area[i] - (i>0 ? area[i-1] : 0));
  }
  return 0;
}