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

double pi = acos(-1);

int main() {
  DRI(T);
  REP1(t, 1, T) {
    DRIII(R, H, N);
    vector<pair<double, double> > cover;
    while(N--) {
      double x, y, r, h;
      scanf("%lf%lf%lf%lf", &x, &y, &r, &h);
      double d = sqrt(x*x+y*y), s, dd, rr;
      double th = acos(x / d);
      if(y < 0) th = (2*pi) - th;
      if(h < H) {
        dd = d / (H-h) * H;
        rr = r / (H-h) * H;
        s = sqrt(dd * dd - rr * rr);
      }
      double delta = 0;
      if(h >= H || s >= R) {
        delta = asin(r/d);
      } else if(dd + rr < R) {
        delta = 0;
      } else {
        double x = (R*R + dd * dd - rr * rr) / (2*dd);
        delta = acos(x / R);
      }
      if(delta > 0) {
        if(th - delta < 0) {
          cover.PB(MP(0, th+delta));
          cover.PB(MP(2*pi + th - delta, 2*pi));
        } else if(th + delta > 2*pi) {
          cover.PB(MP(0, th + delta - 2*pi));
          cover.PB(MP(th-delta, 2*pi));
        } else {
          cover.PB(MP(th-delta, th+delta));
        }
      }
    }
    sort(ALL(cover));
    double ans = 0;
    double now = 0;
    REP(i, cover.size()) {
      if(cover[i].F > now) {
        ans += (cover[i].F - now);
      }
      now = max(now, cover[i].S);
    }
    ans += (2*pi - now);
    printf("Case %d: ", t);
    printf("%.7lf\n", ans / (2*pi));
  }
  return 0;
}
