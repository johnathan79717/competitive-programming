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
using namespace std;
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define SZ(x) ((int)(x).size())
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
#define PLL(x) printf("%lld\n",x)
#define PIS(x) printf("%d ",x)
#define CASET int ___T,cas=1;scanf("%d ",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int MOD = 1000000007;
const int INF = 1000000000;
inline int add(int a, int b) { return a + b < MOD ? a + b : a + b - MOD; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + MOD : a - b; }
inline int mul(int a, int b) { return (LL)a * b % MOD; }

#define MAX_S 101
int dp[MAX_S + 1];

int inverse(int a, int m)
{
    int d = m, x = 0, s = 1, q, r, t;
    while (a != 0)
    {
        q = d / a, r = d % a;
        d = a, a = r;
        t = x - q * s, x = s, s = t;
    }
    if (d != 1) return -1;  // 沒有倒數、無法整除
    return (x + m) % m;
}

int choose(int n, int k) {
  if(k == 0) return 1;
  if(n == 0) return 0;
  return mul(choose(n-1, k-1), mul(n, inverse(k, MOD)));
}

int main() {
  DRI(T);
  while(T--) {
    DRII(A0, A1); DRIII(A2, A3, S);
    MS0(dp);
    dp[0] = 1;
    REP1(i, 1, S) {
      // dp[j] uses i k times
      int F = A0 + i * (A1 + i * (A2 + i * A3));
      PER1(j, S, i) {
        int ways = F;
        int k = 1;
        while(j - k*i >= 0) {
          dp[j] = add(dp[j], mul(dp[j - k * i], ways));
          ways = mul(ways, mul(F + k, inverse(k + 1, MOD)));
          k++;
        }
      }
    }
    PI(dp[S]);
  }
  return 0;
}