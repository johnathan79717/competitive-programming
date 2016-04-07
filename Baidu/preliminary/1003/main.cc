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
#ifdef ONLINE_JUDGE
  #define RL(x) scanf("%I64d",&x)
  #define PL(x) printf("%I64d\n",x)
  typedef __int64 LL;
#else
  #define RL(x) scanf("%lld",&x)
  #define PL(x) printf("%lld\n",x)
  typedef long long LL;
#endif
#define DRI(x) int x;RI(x)
#define DRL(x) LL x;RL(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
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

typedef unsigned long long ULL;
const int INF = 1000000000;

struct E
{
  int date, earning;
};

struct I
{
  int start, finish, interest_rate;
};

int main() {
  DRI(T);
  REP1(cs, 1, T) {
    DRII(n, m);
    VI time;
    V(E) e(n);
    REP(i, n) {
      RII(e[i].date, e[i].earning);
      time.PB(e[i].date);
    }
    V(I) i(m);
    REP(j, m) {
      RIII(i[j].start, i[j].finish, i[j].interest_rate);
      time.PB(i[j].start);
      time.PB(i[j].finish);
    }
    sort(ALL(time));
    time.resize(unique(ALL(time)) - time.BG);
    VI earning(time.size());
    REP(i, n)
      earning[lower_bound(ALL(time), e[i].date) - time.BG] = e[i].earning;
    V(V(PII)) invest(time.size());
    REP(j, m) {
      int s = lower_bound(ALL(time), i[j].start) - time.BG;
      int f = lower_bound(ALL(time), i[j].finish) - time.BG;
      invest[s].PB(MP(f, i[j].interest_rate));
    }
    VI dp(time.size()+1);
    dp[time.size()] = 0;
    PER(j, time.size()) {
      dp[j] = dp[j+1];
      REP(i, invest[j].size()) {
        dp[j] = max(dp[j], invest[j][i].S + dp[invest[j][i].F]);
      }
    }
    LL ans = 0;
    REP(i, time.size())
      ans += (LL)earning[i] * dp[i];
    printf("Case #%d:\n%I64d.%02I64d\n", cs, ans / 100, ans % 100);
  }
  return 0;
}
