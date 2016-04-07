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

int diff(int s1, int s2) {
  int ans = abs(s1 - s2);
  return ans <= 180 ? ans : 360 - ans;
}

int main() {
  DRI(M);
  REP1(t, 1, M) {
    DRI(N);
    VI T(N+1), S(N+1);
    REP1(i, 1, N) {
      RII(T[i], S[i]);
    }
    V(VI) dp(N+1, VI(N, 1e9));
    dp[0][0] = 0;
    dp[1][0] = diff(S[0], S[1]);
    REP1(i, 2, N) {
      REP(j, i-1) {
        dp[i][j] = dp[i-1][j] + diff(S[i], S[i-1]);
        dp[i][i-1] = min(dp[i][i-1], dp[i-1][j] + diff(S[i], S[j]));
      }
    }
    int ans = INT_MAX;
    REP(i, N) ans = min(ans, dp[N][i] + diff(S[i], S[N]));
    // printf("Case #%d:\n", t);
    PI(ans + 10 * N + *max_element(ALL(T)) * 800);
  }
  return 0;
}
