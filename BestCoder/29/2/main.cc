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
using namespace std;
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(x) (x).begin(),(x).end()
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
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
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

const int MOD = 10000007;
struct Z {
  int i;
  Z():i(0) {}
  Z(int i): i(i >= 0 ? i : i + MOD) {}
  void operator +=(const Z& z) { i += z.i; if(i >= MOD) i -= MOD; }
  void operator -=(const Z& z) { i -= z.i; if(i < 0) i += MOD; }
  void operator *=(const Z& z) { i = (long long) i * z.i % MOD; }
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
  Z pow(long long b) {
    Z x=1,y=*this;
    while(b > 0){
      if(b%2 == 1)
        x *= y;
      y *= y; // squaring the base
      b /= 2;
    }
    return x;
  }
};

vector<Z> factorial(1, 1), inv_factorial(1, 1);

Z fact(int n) {
  while(factorial.size() <= n)
    factorial.push_back(factorial.back() * factorial.size());
  return factorial.at(n);
}

Z inv_fact(int n) {
  int old_size = inv_factorial.size();
  inv_factorial.resize(n+1);
  inv_factorial.at(n) = fact(n).inverse();
  for (int i = n-1; i >= old_size; i--) {
    inv_factorial[i] = inv_factorial.at(i+1) * (i+1);
  }
  return inv_factorial.at(n);
}

Z choose(int n, int k) {
  if(n < k) return 0;
  return fact(n) * (inv_fact(k) * inv_fact(n-k));
}

struct Matrix {
  static int M;

  Z a[2][2];
  Matrix() {
    MS0(a);
  }

  Matrix operator* (const Matrix &other) const {
    Matrix ret;
    REP(i, M) REP(j, M) REP(k, M) {
      ret.a[i][j] += a[i][k] * other.a[k][j];
    }
    return ret;
  }

  Matrix pow(int n) {
    if(n % 2) {
      return *this * pow(n-1);
    } else {
      if(n)
        return (*this * *this).pow(n / 2);
      else {
        Matrix ret;
        REP(i, M) {
          ret.a[i][i] = 1;
        }
        return ret;
      }
    }
  }
};
int Matrix::M;

int main() {
    int N, K;
    while(RII(N, K) != EOF) {
        VI A(N);
        Z sum = 0;
        REP(i, N) {
            RI(A[i]);
            sum += A[i];
        }
        sort(ALL(A), greater<int>());
        sum -= A[0] + A[1];
        Matrix::M = 2;
        Matrix f;
        f.a[0][0] = 0;
        f.a[0][1] = f.a[1][0] = f.a[1][1] = 1;
        Matrix fn = f.pow(K+3);
        PI((fn.a[0][0] * A[1] + fn.a[0][1] * A[0] - A[0] + sum).i);
    }
    return 0;
}
