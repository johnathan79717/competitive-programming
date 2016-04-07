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
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
#define ALL(x) (x).begin(),(x).end()
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define RI1(x) scanf("%d",&x)
#define RI2(x,y) RI1(x), RI1(y)
#define RI3(x,y...) RI1(x), RI2(y)
#define RI4(x,y...) RI1(x), RI3(y)
#define RI5(x,y...) RI1(x), RI4(y)
#define RI6(x,y...) RI1(x), RI5(y)
#define GET_MACRO(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define RI(argv...) GET_MACRO(argv, RI6, RI5, RI4, RI3, RI2, RI1)(argv)
#define DRI(argv...) int argv;RI(argv)
#define WRI(argv...) while (RI(argv) != EOF)
#define DWRI(x...) int x; WRI(x)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define F first
#define S second
#define V(x) vector<x >

int popcount(unsigned x) { return __builtin_popcount(x); } 
int popcount(unsigned long long x) { return __builtin_popcountll(x); } 

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

#define PZ(x) PI((x).i);
int MOD = 100007;
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

LL pow(LL a, LL b, LL c=MOD){
  LL x=1,y=a; // ll is taken to avoid overflow of intermediate results
  while(b > 0){
    if(b%2 == 1){
      x=mul(x, y, c);
    }
    y = mul(y, y, c); // squaring the base
    b /= 2;
  }
  return x%c;
}

struct Z {
    int i;
    Z():i(0) {}
    Z(int i): i(i >= 0 ? i : i + MOD) {}
    Z(long long i): i(i % MOD) {}
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
        factorial.push_back(factorial.back() * SZ(factorial));
    return factorial.at(n);
}

Z inv_fact(int n) {
    if (n < inv_factorial.size())
        return inv_factorial.at(n);
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

pair<Z,int> factModExp(int n) {
        if (n == 0) return MP(Z(1), 0);
        int e = n / MOD;
        pair<Z,int> pr = factModExp(e);
        if (e % 2) {
                return MP(Z(0) - pr.F * fact(n % MOD), pr.S + e);
        } else {
                return MP(pr.F * fact(n % MOD), pr.S + e);
        }
}

Z choose2(int n, int k) {
    pair<Z,int> p1 = factModExp(n), p2 = factModExp(k), p3 = factModExp(n-k);
    if (p1.S > p2.S + p3.S) return 0;
    assert(p1.S == p2.S + p3.S);
    return p1.F / (p2.F * p3.F);
}

char str[2000];
Z dp[2000][2000];

int main() {
  DRI(T);
  REP1(t, 1, T) {

    printf("Case #%d: ", t);
    RS(str);
    int N = LEN(str);
    REP1(l, 0, N) {
        REP(i, N+1-l) {
            if (l < 2) {
                dp[l][i] = l+1;
                continue;
            }
            dp[l][i] = dp[l-1][i] + dp[l-1][i+1] - dp[l-2][i+1];
            assert(i+l-1 < N);
            if (str[i] == str[i+l-1]) {
                dp[l][i] += dp[l-2][i+1];
            }
        }
    }
    PZ(dp[N][0]-1);
  }
  return 0;
}
