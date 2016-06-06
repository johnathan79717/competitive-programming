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
#include <deque>
#include <stack>
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

VI a;
LL inv[21];

int tmp[1 << 20];
pair<LL, LL> merge(int k, int q) {
  int i = k, j = k + q / 2, ni = i, nj = j;
  int t = 0;
  LL ans = 0;
  while(i < k + q / 2 && j < k + q) {
    if(a[i] <= a[j]) {
      tmp[t++] = a[i++];
    }
    else {
      tmp[t++] = a[j++];
      ans += k + q / 2 - i;
    }
  }
  while(i < k + q / 2) tmp[t++] = a[i++];
  while(j < k + q) tmp[t++] = a[j++];
  REP(i, t) a[k + i] = tmp[i];
  LL diff = 0;
  int ii = 0;
  while(ii < t) {
    int jj = ii;
    while(jj < t && tmp[jj] == tmp[ii]) jj++;
    diff += (LL) (jj-ii) * (t - jj);
    ii = jj;
  }
  return MP(diff, ans);
}

LL pr[21];

int main() {
  DRI(n);
  int N = 1 << n;
  a.resize(N);
  REP(i, N) RI(a[i]);
  REP1(q, 1, n) {
    int s = 1 << q;
    for(int i = 0; i < N; i += s) {
      auto p = merge(i, s);
      pr[q] += p.first;
      inv[q] += p.second;
    }
  }
  PER1(q, n, 1) pr[q] -= pr[q-1];
  DRI(m);
  while(m--) {
    DRI(q);
    REP1(i, 1, q)
      inv[i] = pr[i] - inv[i];
    LL ans = 0;
    REP1(i, 1, n)
      ans += inv[i];
    printf("%lld\n", ans);
  }
  return 0;
}
