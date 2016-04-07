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
const int INF = 1000000000;

int w[501][501], d[502][501];

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  DRI(N);
  REP(i, N) REP(j, N) RI(w[i][j]);
  int s = N++;
  REP(i, N) w[i][s] = INF, w[s][i] = 0;
  REP(i, N+1) REP(j, N) d[i][j] = INF;
  d[0][s] = 0;
  REP(k, N) REP(i, N) REP(j, N) {
    if(i == j) continue;
    d[k+1][j] = min(d[k+1][j], d[k][i] + w[i][j]);
  }
  int min_p = INF, min_q = 1;
  REP(i, N - 1) {
    int max_p = -INF, max_q = 1;
    REP(k, N) {
      if((LL)(d[N][i] - d[k][i]) * max_q > (LL)(N - k) * max_p)
        max_p = d[N][i] - d[k][i], max_q = N - k;
    }
    if((LL)max_p * min_q < (LL)min_p * max_q)
      min_p = max_p, min_q = max_q;
  }
  int g = gcd(min_p, min_q);
  printf("%d/%d\n", min_p / g, min_q / g);
  return 0;
}