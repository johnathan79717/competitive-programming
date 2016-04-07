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
    double th = 0;
    while(N--) {
      double x, y, r, h;
      scanf("%lf%lf%lf%lf", &x, &y, &r, &h);
      double d = sqrt(x*x+y*y), s, dd, rr;
      if(h < H) {
        dd = d / (H-h) * H;
        rr = r / (H-h) * H;
        s = sqrt(dd * dd - rr * rr);
      }
      if(h >= H || s >= R) {
        th = 2 * asin(r / d);
      } else if(dd + rr < R) {
        th = 0;
      } else {
        double x = (R*R + dd * dd - rr * rr) / (2*dd);
        th = 2*acos(x / R);
      }
    }
    cout << th / 2 << endl;
    printf("Case %d: ", t);
    printf("%.7lf\n", 1 - th / (2*pi));
  }
  return 0;
}
