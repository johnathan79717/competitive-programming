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
typedef long long LL;
const int INF = 1000000000;

template<int MOD=1000000007>
struct Z {
  int i;
  Z():i(0) {}
  Z(int i): i(i%MOD < 0 ? i%MOD + MOD : i%MOD) {}
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

V(Z<>) fact;

Z<> inversion(int n) {
  return fact[n] * n * (n-1) / 4;
}

// index starts with 1
template<class T>
class BIT {
  vector<T> bit;
public:
  BIT() {}
  BIT(int n): bit(n+1) {}
  T sum(int i) {
    T s = 0;
    while(i > 0) {
      s += bit.at(i);
      i &= i - 1;
    }
    return s;
  }
  void add(int i, T x) {
    while(i < bit.size()) {
      bit.at(i) += x;
      i += i & -i;
    }
  }
  void resize(int n) {
    bit.resize(n+1);
  }
  void clear() {
    fill(bit.begin(), bit.end(), 0);
  }
};


BIT<int> bit;

Z<> smaller(int p) {
  return p - 1 - bit.sum(p-1);
}

int main() {
  DRI(n);
  VI p(n);
  fact.resize(n+1);
  fact[0] = 1;
  REP(i, n)
    fact[i+1] = fact[i] * (i+1);
  bit.resize(n);

  Z<> cnt = 1;
  REP(i, n) {
    RI(p[i]);
    bit.add(p[i], 1);
    cnt += smaller(p[i]) * fact[n-i-1];
  }

  Z<> ans = 0;
  bit.clear();
  REP(i, n) {
    bit.add(p[i], 1);
    Z<> s = smaller(p[i]);
    cnt -= s * fact[n-i-1];
    ans += cnt * s;
    ans += s * inversion(n-i-1);
    ans += fact[n-i-1] * s * (s-1) / 2;
  }
  PI(ans.i);
  return 0;
}
