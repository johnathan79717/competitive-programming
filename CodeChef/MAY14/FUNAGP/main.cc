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
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000;



struct Z1 {
  static int MOD;
  int i;
  Z1():i(0) {}
  Z1(int i): i(i) {}
  void operator +=(const Z1& z) { i += z.i; if(i >= MOD) i -= MOD; }
  void operator -=(const Z1& z) { i -= z.i; if(i < 0) i += MOD; }
  void operator *=(const Z1& z) { i = (LL) i * z.i % MOD; }
  void operator /=(const Z1& z) { (*this) *= z.inverse(); }
  Z1 operator +(const Z1& z) const { Z1 ret(i); ret += z; return ret; }
  Z1 operator -(const Z1& z) const { Z1 ret(i); ret -= z; return ret; }
  Z1 operator *(const Z1& z) const { Z1 ret(i); ret *= z; return ret; }
  Z1 operator /(const Z1& z) const { return (*this) * z.inverse(); }
  // Z1 operator -() const { return Z1(-i); }
  Z1 inverse() const {
    int a = i, d = MOD, x = 0, s = 1;
    while(a) {
      int q = d / a, r = d % a, t = x - q * s;
      d = a, a = r, x = s, s = t;
    }
    if (d != 1) return -1;
    return x < 0 ? x + MOD : x;
  }
  Z1 pow(int b) {
    Z1 x=1,y=*this; // ll is taken to avoid overflow of intermediate results
    while(b > 0){
      if(b%2 == 1)
        x *= y;
      y *= y; // squaring the base
      b /= 2;
    }
    return x;
  }
};

struct Z2 {
  static int MOD;
  int i;
  Z2():i(0) {}
  Z2(int i): i(i) {}
  void operator +=(const Z2& z) { i += z.i; if(i >= MOD) i -= MOD; }
  void operator -=(const Z2& z) { i -= z.i; if(i < 0) i += MOD; }
  void operator *=(const Z2& z) { i = (LL) i * z.i % MOD; }
  void operator /=(const Z2& z) { (*this) *= z.inverse(); }
  Z2 operator +(const Z2& z) const { Z2 ret(i); ret += z; return ret; }
  Z2 operator -(const Z2& z) const { Z2 ret(i); ret -= z; return ret; }
  Z2 operator *(const Z2& z) const { Z2 ret(i); ret *= z; return ret; }
  Z2 operator /(const Z2& z) const { return (*this) * z.inverse(); }
  // Z2 operator -() const { return Z2(-i); }
  Z2 inverse() const {
    int a = i, d = MOD, x = 0, s = 1;
    while(a) {
      int q = d / a, r = d % a, t = x - q * s;
      d = a, a = r, x = s, s = t;
    }
    if (d != 1) return -1;
    return x < 0 ? x + MOD : x;
  }
  Z2 pow(int b) {
    Z2 x=1,y=*this; // ll is taken to avoid overflow of intermediate results
    while(b > 0){
      if(b%2 == 1)
        x *= y;
      y *= y; // squaring the base
      b /= 2;
    }
    return x;
  }
};


int p1, p2;
vector<Z1> R1;
vector<Z2> R2;
Z1 r1; Z2 r2;

// index starts with 1
template<class T>
class BIT {
  vector<T> bit;
public:
  BIT() {}
  BIT(int n): bit(n+1) {}
  Z1 sum(int i) {
    i = min(i, (int)bit.size()-1);
    Z1 s = 0;
    while(i > 0) {
      s += bit.at(i);
      i &= i - 1;
    }
    return s;
  }
  void add(int i, Z1 x) {
    while(i < bit.size()) {
      bit.at(i) += x;
      i += i & -i;
    }
  }
  void resize(int n) {
    bit.resize(n+1);
    fill(ALL(bit), 0);
  }
  Z1 get(int i) {
    return sum(i) - sum(i-1);
  }
};

BIT<Z1> bit;
VI A;

int Z1::MOD;
int Z2::MOD;

struct SegmentTree {
  int n;
  vector<Z2> Sp2, Dp2;
  vector<Z1> Sp1, Dp1;

  SegmentTree(int n_) {
    n = 1;
    while(n < n_) n *= 2;
    Sp2.resize(2*n-1);
    Dp2.resize(2*n-1);
    Sp1.resize(2*n-1);
    Dp1.resize(2*n-1);
  }

  void op0(int a, int b, Z1 const& S1, Z1 const& D1, Z2 const& S2, Z2 const& D2) {
    return update(a, b, S1, D1, S2, D2, 0, 0, n);
  }

  void update(int a, int b, Z1 const& S1, Z1 const& D1, Z2 const& S2, Z2 const& D2, int k, int l, int r) {
    // if [a, b) and [l, r) are disjoint
    if(r <= a || b <= l) return;
    // if [l, r) is contained in [a, b)
    if(a <= l && r <= b) {
      Z2 r2 = R2[l-a]; Z1 r1 = R1[l-a];
      Sp2[k] += (S2 + D2 * (l - a)) * r2;
      Dp2[k] += D2 * r2;
      Sp1[k] += (S1 + D1 * (l - a)) * r1;
      Dp1[k] += D1 * r1;
    } else {
      update(a, b, S1, D1, S2, D2, k * 2 + 1, l, (l + r) / 2);
      update(a, b, S1, D1, S2, D2, k * 2 + 2, (l + r) / 2, r);
    }
  }

  void op1(int X, int g) {
    int k = X + n - 1, l = X, r = X+1;
    Z1 Ap1 = A[X] % p1; Z2 Ap2 = A[X] % p2;
    while(true) {
      Z1 r1 = R1[X-l]; Z2 r2 = R2[X-l];
      Z1 sd1 = Sp1[k] + Dp1[k] * (X-l);
      Z2 sd2 = Sp2[k] + Dp2[k] * (X-l); 
      Ap1 += sd1 * r1;
      Ap2 += sd2 * r2;
      if(l < X)
        op0(l, X, Sp1[k], Dp1[k], Sp2[k], Dp2[k]);
      if(X+1 < r) {
        Z1 rr1 = R1[X-l+1]; Z2 rr2 = R2[X-l+1];
        op0(X+1, r, (sd1 + Dp1[k]) * rr1, Dp1[k] * rr1, (sd2 + Dp2[k]) * rr2, Dp2[k] * rr2);
      }
      Sp2[k] = Dp2[k] = 0; Sp1[k] = Dp1[k] = 0;
      if(k == 0) break;
      else {
        if(k%2) r = r * 2 - l;
        else l = l * 2 - r;
        k = (k-1)/2;
      }
    }
    Ap2 = Ap2.pow(g);
    bit.add(X+1, Z1(Ap2.i % p1) - Ap1);
    A[X] = Ap2.i;
  }
};

Z1 den, den2;

struct SegmentTree2 {
  int n;
  vector<Z1> Sp1, Dp1, sum;

  SegmentTree2(int n_) {
    n = 1;
    while(n < n_) n *= 2;
    Sp1.resize(2*n-1);
    Dp1.resize(2*n-1);
    sum.resize(2*n-1);
  }

  void op0(int a, int b, Z1 const& S, Z1 const& D) {
    return update(a, b, S, D, 0, 0, n);
  }

  void update(int X, int Y, Z1 const& S, Z1 const& D, int k, int l, int r) {
    if(l >= r) return;
    if(X <= l && r <= Y) {
      Z1 r1 = R1[l-X];
      Sp1[k] += (S + D * (l-X)) * r1;
      Dp1[k] += D * r1;
    } else if(l < Y && X < r) {
      int offset = max(l, X) - X;
      sum[k] += agp(S + D * offset, D, min(r, Y) - max(l, X)) * R1[offset];
      update(X, Y, S, D, k * 2 + 1, l, (l + r) / 2);
      update(X, Y, S, D, k * 2 + 2, (l + r) / 2, r);
    }
  }

  Z1 op2(int X, int Y) {
    return bit.sum(Y) - bit.sum(X) + query(X, Y, 0, 0, n);
  }

  Z1 query(int X, int Y, int k, int l, int r) {
    if(Y <= l || r <= X) return 0;
    else if(X <= l && r <= Y) {
      return sum[k] + agp(Sp1[k], Dp1[k], r - l);
    } else {
      int offset = max(l, X) - l;
      Z1 res = agp(Sp1[k] + Dp1[k] * offset, Dp1[k], min(r, Y) - max(l, X)) * R1[offset];
      res += query(X, Y, k * 2 + 1, l, (l + r) / 2);
      res += query(X, Y, k * 2 + 2, (l + r) / 2, r);
      return res;
    }
  }

  Z1 agp(Z1 const &a, Z1 const &d, int n) {
    if(r1.i == 1) {
      if(Z1::MOD == 2) {
        if(d.i == 0) {
          if(a.i == 0) return 0;
          else return Z1(n%2);
        } else {
          if(a.i == 0) return Z1(int(n%4 >= 2));
          else return Z1(int(n%4 == 1 || n%4 == 2));
        }
      } else {
        int ans = (a.i*2 + (LL)d.i*(n-1)) * n % p1;
        if(ans & 1) return (ans + p1) / 2;
        else return ans / 2;
        // return (a.i*2 + (LL)d.i*(n-1)) * n / 2;
      }
    } else {
      return (a - (a + d*(n-1)) * R1[n]) * den
            + (d * r1 * (Z1(1) - R1[n-1])) * den2;
    }
  }
};

int main() {
  DRI(T);
  REP(t, T) {
    DRIII(N, Q, R);
    RII(p1, p2);
    Z1::MOD = p1;
    Z2::MOD = p2;
    r1 = R % p1; r2 = R % p2;
    den = (Z1(1) - r1).inverse();
    den2 = den * den;
    R1.resize(N+1); R2.resize(N+1);
    R1[0] = 1; R2[0] = 1;
    REP(i, N) {
      R1[i+1] = R1[i] * r1;
      R2[i+1] = R2[i] * r2;
    }
    bit.resize(N);
    A.resize(N);
    REP(i, N) {
      RI(A[i]);
      bit.add(i+1, A[i] % p1);
    }
    SegmentTree st(N);
    SegmentTree2 st2(N);
    REP(q, Q) {
      DRI(t);
      if(t == 0) {
        DRII(S, D); DRII(X, Y);
        st.op0(X-1, Y, Z1(S % p1), Z1(D % p1), Z2(S % p2), Z2(D % p2));
        st2.op0(X-1, Y, Z1(S % p1), Z1(D % p1));
      } else if(t == 1) {
        DRII(X, g);
        st.op1(X-1, g);
      } else {
        DRII(X, Y);
        PI(st2.op2(X-1, Y).i);
      }
    }
  }
  return 0;
}
