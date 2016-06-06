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

// #define MOD 1000000007
// inline int add(int a, int b, int mod=MOD) { return a + b < mod ? a + b : a + b - mod; }
// inline void addBy(int &a, int b, int mod=MOD) { a = add(a, b, mod); }
// inline int sub(int a, int b, int mod=MOD) { return a - b < 0 ? a - b + mod : a - b; }
// inline void subBy(int &a, int b, int mod=MOD) { a = sub(a, b, mod); }
// inline int mul(int a, int b, int mod=MOD) { return (LL)a * b % mod; }
// inline void mulBy(int &a, int b, int mod=MOD) { a = mul(a, b, mod); }

template<int MOD=1000000007>
class Z {
  int i;
public:
  Z():i(0) {}
  Z(int i): i(i < 0 ? i%MOD + MOD : i%MOD) {}
  void operator +=(const Z& z) {
    i += z.i;
    if(i >= MOD)
      i -= MOD;
  }
  void operator -=(const Z& z) {
    i -= z.i;
    if(i < 0)
      i += MOD;
  }
  void operator *=(const Z& z) {
    i = (LL) i * z.i % MOD;
  }
  Z operator +(const Z& z) const {
    Z ret(i);
    ret += z;
    return ret;
  }
  Z operator -(const Z& z) const {
    Z ret(i);
    ret -= z;
    return ret;
  }
  Z operator *(const Z& z) const {
    Z ret(i);
    ret *= z;
    return ret;
  }
  Z operator -() const {
    return Z(-i);
  }
  operator int() const {
    return i;
  }
};

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
};

V(VI) children;
int cnt = 1;
VI depth, in, out;
BIT<Z<> > bit1, bit2;

void dfs(int u, int d) {
  depth[u] = d;
  in[u] = cnt++;
  FOR(v, children[u]) {
    dfs(v, d+1);
  }
  out[u] = cnt++;
}

int main() {
  DRI(n);
  children.resize(n+1);
  REP1(i, 2, n) {
    DRI(p);
    children[p].PB(i);
  }
  depth.resize(n+1);
  in.resize(n+1);
  out.resize(n+1);
  dfs(1, 0);
  bit1.resize(cnt);
  bit2.resize(cnt);
  DRI(q);
  while(q--) {
    DRI(type);
    if(type == 1) {
      DRIII(v, x, k);
      bit1.add(in[v], Z<>(x) + Z<>(depth[v]) * Z<>(k));
      bit1.add(out[v], -(Z<>(x) + Z<>(depth[v]) * Z<>(k)));
      bit2.add(in[v], k);
      bit2.add(out[v], -k);
    } else {
      DRI(v);
      Z<> x = bit1.sum(in[v]);
      Z<> k = bit2.sum(in[v]);
      PI(int(x - Z<>(depth[v]) * k));
    }
  }
  return 0;
}
