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
#define REP1(i,prev,b) for(int i=(prev);i<=(b);i++)
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

double der(V(double) &x, V(double) &y, double a) {
  double ans = 0;
  REP(i, x.size()) {
    double p = (a - x[i]) * (a - x[i]) + y[i] * y[i];
    p *= sqrt(p);
    ans += y[i] * y[i] / p;
  }
  return ans;
}

double f(V(double) &x, V(double) &y, double a) {
  double ans = 0;
  REP(i, x.size()) {
    ans += (a - x[i]) / sqrt((a - x[i]) * (a - x[i]) + y[i] * y[i]);
  }
  return ans;
}

int main() {
  DRI(T);
  REP1(t, 1, T) {
    DRI(N);
    V(double) x(N), y(N);
    REP(i, N) {
      scanf("%lf%lf", &x[i], &y[i]);
    }
    double lb = *min_element(ALL(x));
    double ub = *max_element(ALL(x));
    while(ub - lb > 1e-6) {
      double m = (ub + lb) / 2;
      // cout << f(x, y, m) << endl;
      if(f(x, y, m) > 0)
        ub = m;
      else
        lb = m;
      // cout << m << endl;
    }
    // double next = (lb + ub) / 2;
    // double prev;
    // do {
    //   prev = next;
    //   next = prev - f(x, y, prev) / der(x, y, prev);
    //   // cout << prev << ' ' << f(x, y, prev) << ' ' << der(x, y, prev) << endl;
    // } while(abs(next - prev) > 1e-6 * abs(prev));
    // cout << f(x, y, next) << endl;
    printf("Case %d: %.6lf\n", t, (ub + lb) / 2);
  }
  return 0;
}
