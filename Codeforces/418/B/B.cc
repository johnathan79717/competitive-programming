// Create your own template by modifying this file!

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
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <stack>
#include <functional>
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
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define LB lower_bound
#define UB upper_bound
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
const int INF = 1000000000;

#define MOD 1000000007
inline int add(int a, int b, int mod=MOD) { return a + b < mod ? a + b : a + b - mod; }
inline void addBy(int &a, int b, int mod=MOD) { a = add(a, b, mod); }
inline int sub(int a, int b, int mod=MOD) { return a - b < 0 ? a - b + mod : a - b; }
inline void subBy(int &a, int b, int mod=MOD) { a = sub(a, b, mod); }
inline int mul(int a, int b, int mod=MOD) { return (LL)a * b % mod; }
inline void mulBy(int &a, int b, int mod=MOD) { a = mul(a, b, mod); }

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

vector<int> factorial(1, 1);

int fact(int n) {
  while(factorial.size() <= n)
    factorial.push_back(mul(factorial.back(), factorial.size()));
  return factorial[n];
}

int choose(int n, int k) {
  if(n < k) return 0;
  return divide(fact(n), mul(fact(k), fact(n-k)));
}

struct Friend
{
  int x, k, p;
};

int main() {
  DRIII(n, m, b);
  V(Friend) f(n);
  REP(i, n) {
    DRIII(x, k, m);
    f[i].x = x;
    f[i].k = k;
    f[i].p = 0;
    while(m--) {
      DRI(p);
      f[i].p |= (1 << (p-1));
    }
  }
  sort(ALL(f), [](const Friend& f1, const Friend &f2) {
    return f1.k > f2.k;
  });
  V(LL) prev(1 << m, LLONG_MAX), next(1 << m, LLONG_MAX);
  next[0] = 0;
  REP(i, n) {
    swap(prev, next);
    fill(ALL(next), LLONG_MAX);
    REP(k, 1<<m) {
      if(prev[k] == LLONG_MAX) continue;
        next[k] = min(next[k], prev[k]);
      if(k)
        next[k|f[i].p] = min(next[k|f[i].p], prev[k] + f[i].x);
      else
        next[k|f[i].p] = min(next[k|f[i].p], prev[k] + f[i].x + (LL)f[i].k * b);
    }
  }
  if(next[(1<<m)-1] == LLONG_MAX)
    PI(-1);
  else
    cout << next[(1<<m)-1] << endl;
  return 0;
}
