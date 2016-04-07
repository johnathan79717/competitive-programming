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

LL gcd(LL x, LL y) {
  if(x) return gcd(y % x, x);
  return y;
}

LL lcm(int x, int y, int z) {
  LL l = (LL) x * y / gcd(x, y);
  return l * z / gcd(l, z);
}

int main() {
  DRI(N);
  VI X(N), Y(N), Z(N);
  REP(i, N) {
    RI(X[i]);
    X[i]--;
  }
  REP(i, N) {
    RI(Y[i]);
    Y[i]--;
  }
  REP(i, N) {
    RI(Z[i]);
    Z[i]--;
  }
  V(bool) visited(N);
  // map<int, int> fx, fy, fz;
  unordered_map<int, int> fx, fy, fz;
  REP(i, N) {
    if(!visited[i]) {
      int cnt = 0;
      int j = i;
      do {
        visited[j] = true;
        cnt++;
        j = X[j];
      } while(!visited[j]);
      fx[cnt]++;
    }
  }
  fill(ALL(visited), false);
  REP(i, N) {
    if(!visited[i]) {
      int cnt = 0;
      int j = i;
      do {
        visited[j] = true;
        cnt++;
        j = Y[j];
      } while(!visited[j]);
      fy[cnt]++;
    }
  }
  fill(ALL(visited), false);
  REP(i, N) {
    if(!visited[i]) {
      int cnt = 0;
      int j = i;
      do {
        visited[j] = true;
        cnt++;
        j = Z[j];
      } while(!visited[j]);
      fz[cnt]++;
    }
  }
  LL ans = 0;
  FOR(x, fx) FOR(y, fy) FOR(z, fz) {
    ans += (LL) x.F * y.F * z.F / lcm(x.F, y.F, z.F) * x.S * y.S * z.S;
  }
  PL(ans);
  return 0;
}
