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
  DRI(N);
  vector<vector<pair<int, bool>>> adj(N+1);
  REP(n, N-1) {
    DRII(a, b);
    char s[2];
    RS(s);
    adj[a].EB(b, s[0] == 'r');
    adj[b].EB(a, s[0] == 'r');
  }
  queue<int> q;
  VI bfs, depth(N+1);
  int root = 1;
  q.push(root); bfs.PB(root); depth[root] = 1;
  while(!q.empty()) {
    int u = q.front(); q.pop();
    FOR(e, adj[u]) {
      if(!depth[e.F]) {
        depth[e.F] = depth[u] + 1;
        q.push(e.F);
        bfs.PB(e.F);
      }
    }
  }
  VI up(N+1), size(N+1), red(N+1);
  reverse(ALL(bfs));
  FOR(r, bfs) {
    size[r] = 1;
    red[r] = 0;
    FOR(e, adj[r]) {
      if(depth[e.F] < depth[r]) continue;
      size[r] += size[e.F];
      if(e.S) {
        red[r] += size[e.F];
      } else {
        red[r] += red[e.F];
      }
    }
  }
  PER(i, bfs.size()) {
    int r = bfs[i];
    FOR(e, adj[r]) {
      if(depth[e.F] < depth[r]) continue;
      if(e.S) up[e.F] = N - size[e.F];
      else up[e.F] = red[r] - red[e.F] + up[r];
    }
  }
  Z ans = 0;
  Z half = Z(2).inverse(), third = Z(3).inverse();
  FOR(r, bfs) {
    V(Z) u, s;
    u.PB(up[r]);
    s.PB(N - size[r]);
    FOR(e, adj[r]) {
      if(depth[e.F] < depth[r]) continue;
      s.PB(size[e.F]);
      if(e.S) {
        u.PB(size[e.F]);
      } else {
        u.PB(red[e.F]);
      }
    }
    Z sum = 0, sqr = 0, cub = 0;
    FOR(x, u) {
      sum += x;
      sqr += x * x;
      cub += x * x * x;
    }
    Z uiuj = (sum * sum - sqr) * half;
    Z uisi = 0, sk = 0, uiuisi = 0;
    REP(i, u.size()) {
      sk += s[i];
      uisi += u[i] * s[i];
      uiuisi += u[i] * u[i] * s[i];
    }
    Z uiujsj = uisi * sum - uiuisi;
    Z uiujsk = uiuj * sk - uiujsj;
    Z uiuiuj = sqr * sum - cub;
    Z uiujuk = (uiuj * sum - uiuiuj) * third;
    ans += uiujsk - uiujuk * 2 + uiuj;
  }
  PI(ans.i);
  return 0;
}