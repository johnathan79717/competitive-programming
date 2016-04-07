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

#define MOD 1000000007
inline int add(int a, int b, int mod=MOD) { return a + b < mod ? a + b : a + b - mod; }
inline void addBy(int &a, int b, int mod=MOD) { a = add(a, b, mod); }
inline int sub(int a, int b, int mod=MOD) { return a - b < 0 ? a - b + mod : a - b; }
inline void subBy(int &a, int b, int mod=MOD) { a = sub(a, b, mod); }
inline int mul(int a, int b, int mod=MOD) { return (LL)a * b % mod; }
inline void mulBy(int &a, int b, int mod=MOD) { a = mul(a, b, mod); }

int dp[1002][1002];

int main() {
  REP1(i, 1, 1001) {
    dp[i][i] = 1;
    PER1(j, i-1, 1)
      dp[i][j] = add(dp[i][j+1], dp[i-j][j+1]);
  }
  // REP1(j, 1, 1000) REP1(i, 1, 1000) addBy(dp[i][j], dp[i-1][j]);
  DRI(T);
  while(T--) {
    DRII(A, B);
    if(B == 0) {
      PI(A);
    } else if(A == 0) {
      int sum = 0;
      REP1(j, 1, B) addBy(sum, dp[j][1]);
      PI(sum);
    } else {
      int n = 1;
      while((1<<n) <= A) n++;
      if(B < n) {
        PI(((1 << B) + A) % MOD);
      } else {
        int ans = (1 << n) - 1;
        if(B < 31) ans = min(ans, (1 << B) + A);
        ans %= MOD;
        REP1(b, n, B) {
          if(B-b == 0)
            addBy(ans, mul(dp[b][n], min(1 << n, A + 1)));
          else if(B-b < 31)
            addBy(ans, mul(dp[b][n], min(1 << n, (1 << (B-b)) + A + 1)));
          else
            addBy(ans, mul(dp[b][n], 1 << n));
        }
        int k = n-1;
        while(k > 0 && A + (1<<k) >= (1<<n)) {
          addBy(ans, mul(dp[B-k][n+1], A + (1<<k) - (1<<n) + 1));
          k--;
        }
        PI(ans);
      }
    }
  }
  return 0;
}