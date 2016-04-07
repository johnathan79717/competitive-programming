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

int MOD = 19101995;
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

struct Edge {
    int to, id;
};

V(VI) adj;

int mask, bound;

Z dp[100005][20];

Z dfs(int v, int p, int b) {
    if (b == 0) {
        assert(v != 1);
        if (adj[v].size() == 1) {
            return Z(1);
        } else if (adj[v].size() == 2) {
            FOR(u, adj[v]) {
                if (u != p) {
                    return dfs(u, v, b);
                }
            }
        } else {
            return Z(0);
        }
    }
    if (v != 1 && adj[v].size() == 1) {
        return Z(1);
    }
    if (dp[v][b].i >= 0) {
        return dp[v][b];
    }
    V(Z) fb, fb1;
    
    FOR(u, adj[v]) {
        if (u == p) continue;
        fb.PB(dfs(u, v, b));
        fb1.PB(dfs(u, v, b-1));
    }
    int n = fb.size();
    V(Z) prefix(n), suffix(n);
    prefix[0] = 1; suffix[n-1] = 1;
    REP1(i, 1, n-1) {
        prefix[i] = prefix[i-1] * fb1[i-1];
    }
    PER1(i, n-2, 0) {
        suffix[i] = suffix[i+1] * fb1[i+1];
    }
    Z ans = 0;
    REP(i, n) {
        ans += fb[i] * suffix[i] * prefix[i];
    }
    return (dp[v][b] = ans);
}

int main() {
    DRI(N);
    if (N == 1) {
        PI(1);
        return 0;
    }
    adj.resize(N+1);
    REP(i, N-1) {
        DRII(a, b);
        adj[a].PB(b);
        adj[b].PB(a);
    }
    while (1 << (bound+1) <= N) bound++;
    MS1(dp);
    PI(dfs(1, -1, bound).i);
    return 0;
}
