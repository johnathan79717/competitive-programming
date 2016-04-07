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
const int INF = 1000000000;
int MOD = 1000000007;
inline int addM(int a, int b) { return a + b < MOD ? a + b : a + b - MOD; }
inline int subM(int a, int b) { return a - b < 0 ? a - b + MOD : a - b; }
inline int mulM(int a, int b) { return (LL)a * b % MOD; }
/* a*x ≡ 1 (mod m) */
int inverseM(int a)
{
    int d = MOD, x = 0, s = 1, q, r, t;
    while (a != 0)
    {
        q = d / a, r = d % a;
        d = a, a = r;
        t = x - q * s, x = s, s = t;
    }
    if (d != 1) return -1;  // 沒有倒數、無法整除
    return (x + MOD) % MOD;
}
inline int divM(int a, int b) {
  LL tmp = a;
  while(tmp % b) tmp += MOD;
  return tmp / b;
}

int main() {
  int N, K, tmp;
  scanf("%d%d%d", &N, &K, &MOD);
  tmp = N;
  LL phi = N, a = 1;
  for(int p = 2; p * p <= tmp; p++) {
    if(tmp % p == 0) {
      while(tmp % p == 0) tmp /= p;
      phi = phi / p * (p - 1);
      a = mulM(a, subM(1, p % MOD));
    }
  }
  if(tmp > 1) {
    phi = phi / tmp * (tmp - 1);
    a = mulM(a, subM(1, tmp % MOD));
  }
  phi %= MOD;
  N %= MOD;
  PLL(phi);
  PI(N);
  PLL(a);
  PI(divM(mulM(mulM(N, N), phi), 3));
  if(K == 1) {
    PI(divM(mulM(phi, N), 2));
  } else if(K == 2) {
    if(N == 1) PI(1);
    else PI(addM(divM(mulM(mulM(N, N), phi), 3), divM(mulM(N, a), 6)));
  }
  return 0;
}