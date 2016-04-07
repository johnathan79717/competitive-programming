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
const int INF = 2000000000;

#define MOD 1000000007

inline int add(int a, int b, int mod=MOD) { return a + b < mod ? a + b : a + b - mod; }
inline int sub(int a, int b, int mod=MOD) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b, int mod=MOD) { return (LL)a * b % mod; }
/* a*x ≡ 1 (mod m) */
int inverse(int a, int mod = MOD)
{
    int d = mod, x = 0, s = 1, q, r, t;
    while (a != 0)
    {
        q = d / a, r = d % a;
        d = a, a = r;
        t = x - q * s, x = s, s = t;
    }
    if (d != 1) return -1;  // 沒有倒數、無法整除
    return (x + mod) % mod;
}
inline int divide(int a, int b, int mod=MOD) { return mul(a, inverse(b, mod), mod); }

LL mul(LL a,LL b,LL mod=MOD){
  LL x = 0,y=a%mod;
  while(b > 0){
    if(b%2 == 1){
      x = x+y;
      if(x >= mod) x -= mod;
    }
    y = y*2;
    if(y >= mod) y -= mod;
    b /= 2;
  }
  return x%mod;
}

template<class T>
T pow(T a, T b, T c=MOD){
  T x=1,y=a; // ll is taken to avoid overflow of intermediate results
  while(b > 0){
    if(b%2 == 1){
      x=mul(x, y, c);
    }
    y = mul(y, y, c); // squaring the base
    b /= 2;
  }
  return x%c;
}

int choose(int n, int k) {
  if(n < k) return 0;
  int ans = 1;
  while(k > 0)
    ans = divide(mul(ans, n), k);
  return ans;
}

int x[11];

int main() {
  DRI(T);
  while(T--) {
    DRIII(N, M, K);
    x[0] = 1;
    REP(i, 10) x[i+1] = mul(x[i], K);
    int n = max(N, M);
    if(min(N, M) == 1) {
      int ans = K;
      REP(i, n-1) ans = mul(ans, K-1);
      PI(ans);
    } else if(min(N, M) == 2) {
      int ans = mul(K, K-1);
      int e = sub(mul(K, K), mul(3, K)) + 3;
      REP(i, n-1) ans = mul(ans, e);
      PI(ans);
    } else if(N == 3 && M == 3) {
      int ans = x[7];
      ans = sub(ans, mul(11, x[6]));
      ans = add(ans, mul(55, x[5]));
      ans = sub(ans, mul(161, x[4]));
      ans = add(ans, mul(298, x[3]));
      ans = sub(ans, mul(350, x[2]));
      ans = add(ans, mul(244, x[1]));
      ans = sub(ans, 79);
      ans = mul(ans, mul(K, K-1));
      PI(ans);
    } else {
      PI(0);
    }
  }
  return 0;
}