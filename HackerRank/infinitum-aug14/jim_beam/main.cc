#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <unordered_map>
#include <unordered_set>
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
    return abs(this->x - p.x) < EPS * (abs(this->x) + abs(p.x))
     && abs(this->y - p.y) < EPS * (abs(this->y) + abs(p.y));
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
  // int rel_pos(const P &p1, const P &p2) const {
  //   return sign((p1 - *this).cross(p2 - *this));
  // }
};

P intersection(const P &p1, const P &p2, const P &q1, const P &q2) {
  return p1 + (p2 - p1) * ((q2 - q1).cross(q1 - p1) / (q2 - q1).cross(p2 - p1));
}

bool intersect(const P &p1, const P &p2, const P &q1, const P &q2) {
  if((q2 - q1).cross(p2 - p1) != 0) {
    P r = intersection(p1, p2, q1, q2);
    return r.on_seg(p1, p2) && r.on_seg(q1, q2);
  } else {
    return p1.on_seg(q1, q2) || p2.on_seg(q1, q2) || q2.on_seg(p1, p2) || q1.on_seg(p1, p2);
  }
}

int main() {
  DRI(T);
  while(T--) {
    P p1(0, 0), p2, q1, q2;
    // double X1, Y1, X2, Y2, Xm, Ym;
    // scanf("%lf%lf%lf%lf%lf%lf", &X1, &Y1, &X2, &Y2, &Xm, &Ym);
    cin >> q1.x >> q1.y >> q2.x >> q2.y >> p2.x >> p2.y;
    // if(intersect(P(0, 0), P(Xm, Ym), P(X1, Y1), P(X2, Y2)))
    // cout << (q2-q1).cross(p2-p1);
    if(intersect(p1, p2, q1, q2))
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}