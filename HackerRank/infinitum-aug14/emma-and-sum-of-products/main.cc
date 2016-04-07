#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <set>
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

const int MOD = 100003;
struct Z {
  int i;
  Z():i(0) {}
  Z(int i): i(i >= 0 ? i : i + MOD) {}
  void operator +=(const Z& z) { i += z.i; if(i >= MOD) i -= MOD; }
  void operator -=(const Z& z) { i -= z.i; if(i < 0) i += MOD; }
  void operator *=(const Z& z) { i = (LL) i * z.i % MOD; }
  void operator /=(const Z& z) { (*this) *= z.inverse(); }
  Z operator +(const Z& z) const { Z ret(i); ret += z; return ret; }
  Z operator -(const Z& z) const { Z ret(i); ret -= z; return ret; }
  Z operator *(const Z& z) const { Z ret(i); ret *= z; return ret; }
  Z operator /(const Z& z) const { return (*this) * z.inverse(); }
  // Z operator -() const { return Z(-i); }
  Z inverse() const {
    int a = i, d = MOD, x = 0, s = 1;
    while(a) {
      int q = d / a, r = d % a, t = x - q * s;
      d = a, a = r, x = s, s = t;
    }
    if (d != 1) return -1;
    return x < 0 ? x + MOD : x;
  }
  Z pow(int b) {
    Z x=1,y=*this; // ll is taken to avoid overflow of intermediate results
    while(b > 0){
      if(b%2 == 1)
        x *= y;
      y *= y; // squaring the base
      b /= 2;
    }
    return x;
  }
};

const int MAX = 32768;
Z pool[9999999];
int p = 0;

Z *alloc(int n) {
  Z *ans = pool + p;
  p += n;
  return ans;
}

Z* poly_mul(Z *x, Z *y, int n) {
  if(n == 1) {
    // Z* ans = new Z[1];
    Z *ans = alloc(1);
    ans[0] = x[0] * y[0];
    return ans;
  } else {
    // Z *ans = new Z[n*2-1];
    Z *ans = alloc(n*2-1);
    for(int i = 0; i < n*2-1; i++)
      ans[i] = 0;
    int l = (n+1)/2;
    Z *z0 = poly_mul(x, y, l);
    Z *z2 = poly_mul(x+l, y+l, n-l);
    // Z *temp1 = new Z[l];
    // Z *temp2 = new Z[l];
    Z *temp1 = alloc(l), *temp2 = alloc(l);
    for(int i = 0; i < l; i++) {
      temp1[i] = x[i];
      temp2[i] = y[i];
    }
    for(int i = 0; i < n-l; i++) {
      temp1[i] += x[i+l];
      temp2[i] += y[i+l];
    }
    Z *z1 = poly_mul(temp1, temp2, l);
    for(int i = 0; i < l*2-1; i++) {
      z1[i] -= z0[i];
    }
    for(int i = 0; i < (n-l)*2-1; i++) {
      z1[i] -= z2[i];
    }
    for(int i = 0; i < l*2-1; i++) {
      ans[i] += z0[i];
      ans[i+l] += z1[i];
    }
    for(int i = 0; i < (n-l)*2-1; i++) {
      ans[i+l*2] += z2[i];
    }
    // delete[] temp1;
    // delete[] temp2;
    // delete[] z0;
    // delete[] z1;
    // delete[] z2;
    p -= l + l + (2*l-1) + (2*l-1) + (2*(n-l)-1);
    return ans;
  }
}

Z A[MAX][2];

Z *product(int l, int r) {
  if(l + 1 == r) return A[l];
  Z *a = product(l, (l+r)/2);
  Z *b = product((l+r)/2, r);
  // p -= 
  return poly_mul(a, b, (r-l)/2+1);
}

int main() {
  DRI(N);
  REP(i, N) {
    RI(A[i][0].i);
    // A[i][0].i = 1;
    A[i][1] = 1;
  }
  int M = 1;
  while(M < N) M *= 2;
  REP1(i, N, M-1) {
    A[i][0] = 1;
  }
  Z *poly = product(0, M);
  // PI(poly[N-1].i);
  // REP(i, N) {
  //   PI(poly[i].i);
  // }
  DRI(Q);
  while(Q--) {
    DRI(K);
    PI(poly[N-K].i);
  }
  // delete[] poly;
  return 0;
}