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

#define MOD 1000000007
inline int add(int a, int b, int mod=MOD) { return a + b < mod ? a + b : a + b - mod; }
inline void addBy(int &a, int b, int mod=MOD) { a = add(a, b, mod); }
inline int sub(int a, int b, int mod=MOD) { return a - b < 0 ? a - b + mod : a - b; }
inline void subBy(int &a, int b, int mod=MOD) { a = sub(a, b, mod); }

int dp[100000001];

int lose(int n) {
  if(dp[n])
    return dp[n];
  for(int p = 2; p * p <= n; p++) {
    if(n % p == 0 && lose(p) < 0)
      return dp[n] = 1;
  }
  for(int p = 2; p * p <= n; p++) {
    if(n % p == 0 && lose(n / p) < 0)
      return dp[n] = 1;
  }
  if(lose(n-1) < 0)
    return dp[n] = 1;
  return dp[n] = -1;
}

#include <iostream>
using namespace std;

typedef long long ll;

ll mul(ll a,ll b,ll c){
  ll x = 0,y=a%c;
  while(b > 0){
    if(b%2 == 1){
      x = (x+y)%c;
    }
    y = (y*2)%c;
    b /= 2;
  }
  return x%c;
}

ll mul(ll a, ll b, int c) {
  return (a%c) * (b%c) % c;
}

int mul(int a, int b, int c) {
  ll temp = ll(a) * b;
  return temp % c;
}

template<class T>
T pow(T a, T b, T c){
  ll x=1,y=a; // ll is taken to avoid overflow of intermediate results
  while(b > 0){
    if(b%2 == 1){
      x=mul(x, y, c);
    }
    y = mul(y, y, c); // squaring the base
    b /= 2;
  }
  return x%c;
}

template<class T>
bool isprime(T n)
{
  // 預先判斷偶數與1，節省一點時間。
  if (n == 2) return true;
  if (n < 2 || n % 2 == 0) return false;
 
  T u = n - 1, t = 0;
  while (u % 2 == 0) {u >>= 1; t++;}
 
  // 推定是質數，就實施下一次測試；
  // 確定是合數，就馬上結束。

  T sprpl[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
  T sprpi[] = {2, 7, 61};

  T *sprp;
  int test;
  if(sizeof(T) > 4) {
    sprp = sprpl;
    test = 7;
  }
  else {
    sprp = sprpi;
    test = 3;
  }



  for (int k=0; k<test; ++k)
  {
    // a沒有大於1、小於n-1的限制，
    // 沒有測試意義的數字，當作是通過測試。
    // （a是質數時，模n後不會等於零，不必特別判斷。）
    T a = sprp[k] % n;
    if (a == 0 || a == 1 || a == n-1) continue;
 
    ll x = pow(a, u, n);
    if (x == 1 || x == n-1) continue;
 
    for (int i = 0; i < t-1; i++)
    {
      x = mul(x, x, n);
      if (x == 1) return false;
      if (x == n-1) break;
    }
    if (x == n-1) continue;
 
    return false;
  }
  // 通過全部測試，確定是質數。
  return true;
}


int main() {
  dp[2] = 1;
  DRI(T);
  while(T--) {
    DRI(N);
    if(N == 2 || N == 17)
      puts("Mike");
    else if(N == 34 || N == 16 || N == 289 || isprime(N))
      puts("Tom");
    else
      puts("Mike");
  }
  return 0;
}