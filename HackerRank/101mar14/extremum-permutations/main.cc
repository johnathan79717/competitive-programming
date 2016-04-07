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
#include <unordered_map>
#include <unordered_set>
#include <cassert>
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
#define VV(x, dp, n, m) V(V(x)) dp(n, V(x)(m))

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 2000000000;

const int MOD = 1000000007;

struct Z {
  int i;
  Z():i(0) {}
  Z(LL i): i(i%MOD < 0 ? i%MOD + MOD : i%MOD) {}
  void operator +=(const Z& z) { i += z.i; if(i >= MOD) i -= MOD; }
  void operator -=(const Z& z) { i -= z.i; if(i < 0) i += MOD; }
  void operator *=(const Z& z) { i = (LL) i * z.i % MOD; }
  void operator /=(const Z& z) { (*this) *= z.inverse(); }
  Z operator +(const Z& z) const { Z ret(i); ret += z; return ret; }
  Z operator -(const Z& z) const { Z ret(i); ret -= z; return ret; }
  Z operator *(const Z& z) const { Z ret(i); ret *= z; return ret; }
  Z operator /(const Z& z) const { return (*this) * z.inverse(); }
  Z operator -() const { return Z(-i); }
  Z inverse() const {
    int a = i, d = MOD, x = 0, s = 1;
    while(a) {
      int q = d / a, r = d % a, t = x - q * s;
      d = a, a = r, x = s, s = t;
    }
    if (d != 1) return -1;  // 
    return x;    
  }
  template<class T>
  Z pow(T b){
    Z x=1, y=i; // ll is taken to avoid overflow of intermediate results
    while(b > 0) {
      if(b%2 == 1)
        x *= y;
      y *= y;
      b /= 2;
    }
    return x;
  }
};

vector<Z> factorial(1, 1), inv_factorial(1, 1);

Z inv_fact(int n) {
  while(inv_factorial.size() <= n)
    inv_factorial.PB(inv_factorial.back() / inv_factorial.size());
  return inv_factorial.at(n);
}

Z fact(int n) {
  while(factorial.size() <= n)
    factorial.PB(factorial.back() * factorial.size());
  return factorial.at(n);
}

Z choose(int n, int k) {
  if(n < k) return 0;
  return fact(n) * (inv_fact(k) * inv_fact(n-k));
}

Z choose2(Z n, int k) {
  Z ans = 1;
  while(k) {
    ans *= (n / k);
    k -= 1;
    n -= 1;
  }
  return ans;
}


int type[5002];

int main() {
  DRIII(N, K, L);
  REP(i, K) {
    DRI(a);
    type[a] = -1;
    if(type[a-1] || type[a+1]) {
      PI(0);
      return 0;
    }
  }
  REP(i, L) {
    DRI(b);
    if(type[b] < 0 || type[b-1] > 0 || type[b+1] > 0) {
      PI(0);
      return 0;
    }
    type[b] = 1;
  }
  VV(Z, dp, N+1, N+1);
  VV(Z, below, N+1, N+1);
  below[1][1] = 1;
  dp[1][1] = 1;
  REP1(n, 2, N) {
    REP1(k, 1, n) {
      if(type[n-1] < 0 || type[n] > 0) {
        dp[n][k] = below[n-1][k-1];
      } else if(type[n-1] > 0 || type[n] < 0) {
        dp[n][k] = below[n-1][n-1] - below[n-1][k-1];
      } else {
        dp[n][k] = below[n-1][n-1];
      }
      below[n][k] = below[n][k-1] + dp[n][k];
    }
  }
  PI(below[N][N].i);
  return 0;
}