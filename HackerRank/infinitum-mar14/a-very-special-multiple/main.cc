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

LL phi(LL n) {
  LL ans = 1;
  for(LL p = 2; p * p <= n; p++) {
    LL k = 1;
    while(n % p == 0) {
      k *= p;
      n /= p;
    }
    ans *= (k - k / p);
  }
  if(n > 1)
    ans *= (n - 1);
  return ans;
}

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

int main() {
  DRI(T);
  while(T--) {
    DRL(X);
    int k2 = 0, k5 = 0;
    while(X % 2 == 0) {
      X /= 2;
      k2++;
    }
    while(X % 5 == 0) {
      X /= 5;
      k5++;
    }
    int b = max(k2 - 2, k5);
    // cout << "b: " << b << endl;
    X *= 9;
    LL n = phi(X);
    assert(pow(10LL, n, X) == 1);
    LL a = n;
    // cout << "phi: " << n << endl;
    for(LL p = 1; p * p <= n; p++) {
      if(n % p == 0) {
        if(pow(10LL, p, X) == 1)
          a = min(a, p);
        if(pow(10LL, n / p, X) == 1)
          a = min(a, n / p);
      }
    }
    // cout << "a: " << a << endl;
    cout << 2 * a + b << endl;
  }
  return 0;
}