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
#include <sstream>
#include <bitset>
using namespace std;
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define BG begin()
#define ED end()
#define FOR(i,c) for(auto &i: c)
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

const int MOD = 1000000007;
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

vector<Z> factorial(1, 1), inv_factorial(1, 1);

Z inv_fact(int n) {
  while(inv_factorial.size() <= n)
    inv_factorial.push_back(inv_factorial.back() / inv_factorial.size());
  return inv_factorial.at(n);
}

Z fact(int n) {
  while(factorial.size() <= n)
    factorial.push_back(factorial.back() * factorial.size());
  return factorial.at(n);
}

Z choose(int n, int k) {
  if(n < k) return 0;
  return fact(n) * (inv_fact(k) * inv_fact(n-k));
}

int main() {
    DRI(T);
    REP(t, T) {
        DRII(N, M); DRII(L, R);
        Z total = 0;
        REP1(D, L, R) {
            int n = D;
            VI factors;
            for (int p = 2; p * p <= n; p++) {
                int f = 1;
                while (n % p == 0) {
                    n /= p;
                    f *= p;
                }
                if (f > 1) {
                    factors.PB(f);
                }
            }
            if (n > 1) factors.PB(n);
            int k = SZ(factors);
            Z ans = 0;
            REP(mask, 1 << k) {
                VI mfactor;
                int odd = 1;
                REP(i, k) {
                    if ((mask >> i) & 1) {
                        mfactor.PB(factors[i]);
                        odd = -odd;
                    }
                }
                int k2 = SZ(mfactor);
                int m = 0;
                REP(mask2, 1 << k2) {
                    int f = 1, odd2 = 1;
                    REP(i, k2) {
                        if ((mask2 >> i) & 1) {
                            f *= mfactor[i];
                            odd2 = -odd2;
                        }
                    }
                    m += (M / f) * odd2;
                }
                ans += Z(m).pow(N) * odd;
            }
            total += ans;
            // PI(ans.i);
        }
        PI(total.i);
    }
    return 0;
}
