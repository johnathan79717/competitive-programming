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
  bool operator ==(const Z& z) const { return i == z.i; }
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

typedef pair<Z,Z> Data;
Data identity = MP(Z(1), Z(0));

Data compose(Data const &a, Data const &b) {
  return MP(a.F * b.F, a.F * b.S + a.S);
}

Data pow(Data const &a, int n) {
  if (!n) return identity;
  return compose(pow(compose(a, a), n / 2), n % 2 ? a : identity);
}

template <typename Combine>
struct SegmentTree {
  int n;
  vector<Data> dat, lazy;
  vector<bool> prop;

  void update(int a, int b, const Data &d) {
    update(a, b, 0, 0, n, d);
  }

  void update(int a, int b, int k, int l, int r, const Data &d) {
    // if [a, b) and [l, r) are disjoint
    if(r <= a || b <= l) {
      return;
    // if [l, r) contains [a, b)
    } else if(a <= l && r <= b) {
      lazy[k] = d;
      prop[k] = true;
      dat[k] = pow(d, r - l);
    } else {
      if (prop[k]) {
        lazy[k*2+1] = lazy[k*2+2] = lazy[k];
        dat[k*2+1] = dat[k*2+2] = pow(lazy[k], (r-l)/2);
        prop[k*2+1] = prop[k*2+2] = true;
        prop[k] = false;
      }
      update(a, b, k * 2 + 1, l, (l + r) / 2, d);
      update(a, b, k * 2 + 2, (l + r) / 2, r, d);
      dat[k] = combine(dat[k * 2 + 1], dat[k * 2 + 2]);
    }    
  }

  // void update(int k, pair<Z,Z> const& a) {
  //   // starting from leaf node
  //   k += n - 1;
  //   dat[k] = a;
  //   while(k > 0) {
  //     k = (k - 1) / 2;
  //     dat[k] = combine(dat[k * 2 + 1], dat[k * 2 + 2]);
  //   }
  // }

  pair<Z,Z> query(int a, int b) {
    return query(a, b, 0, 0, n);
  }

  pair<Z,Z> query(int a, int b, int k, int l, int r) {
    if(r <= a || b <= l) return identity;
    // if [l, r) contains [a, b)
    if(a <= l && r <= b) return dat[k];
    else {
      assert(k * 2 + 2 < dat.size());
      if (prop[k]) {
        lazy[k*2+1] = lazy[k*2+2] = lazy[k];
        dat[k*2+1] = dat[k*2+2] = pow(lazy[k], (r-l)/2);
        prop[k*2+1] = prop[k*2+2] = true;
        prop[k] = false;
      }
      pair<Z,Z> vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      pair<Z,Z> vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      dat[k] = combine(dat[k * 2 + 1], dat[k * 2 + 2]);
      return combine(vl, vr);
    }
  }

  // SegmentTree(int n_) {
  //   n = 1;
  //   while(n < n_) n *= 2;
  //   dat.resize(2*n-1);
  //   init(0, 0, n);
  // }
  SegmentTree(const vector<Data>& number) {
    n = 1;
    while (n < number.size()) n <<= 1;
    dat.resize(2*n-1);
    lazy.resize(2*n-1);
    prop = V(bool)(2*n-1);
    init(0, 0, n, number);
  }

  void init(int k, int l, int r, V(Data) const &number) {
    if(r - l == 1) {
        dat[k] = number[l];
    } else {
      // non-leaf
      int chl = k * 2 + 1, chr = k * 2 + 2;
      init(chl, l, (l + r) / 2, number);
      init(chr, (l + r) / 2, r, number);
      dat[k] = combine(dat[chl], dat[chr]);
    }
  }
  Combine combine;
};

struct Upward {
  Data operator()(Data const &up, Data const &down) {
    return compose(down, up);
  }
};

struct Downward {
  Data operator()(Data const &up, Data const &down) {
    return compose(up, down);
  }
};

V(VI) adj;     // adjacency list

void add_edge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

VI parent, depth;
VI heavy; // the heaviest child
VI size; // size of subtree

void init(int n) {
  parent.resize(n);
  depth.resize(n);
  heavy.resize(n);
  size.resize(n);
} 
 
void DFS(int i)
{
    if(parent[i] < 0) depth[i] = 0;
    size[i] = 1;
    for (int k=0; k<adj[i].size(); ++k)
    {
        int j = adj[i][k];
        if (j == parent[i]) continue;
 
        parent[j] = i;
        depth[j] = depth[i] + 1;
 
        DFS(j);
 
        size[i] += size[j];
        if (heavy[i] == -1 || size[j] > size[heavy[i]]) 
            heavy[i] = j;
    }
}

VI chain; // chain id
VI head; // the topmost node of the chain
V(SegmentTree<Upward>) ups;
V(SegmentTree<Downward>) downs;
vector<pair<Z, Z>> f;
 
void heavylight_DFS(int N)
{
    fill(heavy.begin(), heavy.end(), -1);
    
    parent[0] = -1;
    depth[0] = 0;
    DFS(0);
 
    int c = 0;  
    for (int i=0; i<N; ++i)
        if (parent[i] == -1 || heavy[parent[i]] != i)
        {
            V(Data) number;
            for (int k = i; k != -1; k = heavy[k]) {
                chain[k] = c, head[k] = i;
                number.EB(f[k].F, f[k].S);
            }
            ups.emplace_back(number);
            downs.emplace_back(number);
            c++;
        }
}
 
int main() {
  DRI(N);
  f.resize(N);
  REP(i, N) RII(f[i].F.i, f[i].S.i);
  adj.resize(N);
  parent.resize(N);
  heavy.resize(N);
  depth.resize(N);
  size.resize(N);
  chain.resize(N);
  head.resize(N);
  REP(i, N-1) {
    DRII(u, v);
    u--; v--;
    add_edge(u, v);
  }
  heavylight_DFS(N);
  // heavylight_BFS(N, 0);
  DRI(Q);
  while(Q--) {
    DRIII(t, to, from);
    to--; from--;
    if (t == 2) {
      DRI(x);
      Data up = MP(Z(1), Z(0)), down = up;
      while (chain[from] != chain[to]) {
        if (depth[head[from]] > depth[head[to]]) {
          up = compose(up, ups[chain[from]].query(0, depth[from] - depth[head[from]] + 1));
          from = parent[head[from]];
        } else {
          down = compose(downs[chain[to]].query(0, depth[to] - depth[head[to]] + 1), down);
          to = parent[head[to]];
        }
      }
      Data mid;
      if (depth[from] < depth[to]) {
        mid = downs[chain[to]].query(depth[from] - depth[head[from]], depth[to] - depth[head[to]] + 1);
      } else {
        mid = ups[chain[from]].query(depth[to] - depth[head[to]], depth[from] - depth[head[from]] + 1);
      }
      Data ans = compose(up, compose(mid, down));
      // PIS(up.F.i); PIS(up.S.i); PIS(mid.F.i); PIS(mid.S.i);  PIS(down.F.i); PI(down.S.i);
      // PIS(ans.F.i); PI(ans.S.i);
      PI((ans.F * x + ans.S).i);
    } else {
      DRII(a, b);
      Data y = MP(Z(a), Z(b));
      while (chain[from] != chain[to]) {
        if (depth[head[from]] > depth[head[to]]) {
          ups[chain[from]].update(0, depth[from] - depth[head[from]] + 1, y);
          downs[chain[from]].update(0, depth[from] - depth[head[from]] + 1, y);
          from = parent[head[from]];
        } else {
          ups[chain[to]].update(0, depth[to] - depth[head[to]] + 1, y);
          downs[chain[to]].update(0, depth[to] - depth[head[to]] + 1, y);
          to = parent[head[to]];
        }
      }      
      if (depth[from] < depth[to]) {
        downs[chain[to]].update(depth[from] - depth[head[from]], depth[to] - depth[head[to]] + 1, y);
        ups[chain[to]].update(depth[from] - depth[head[from]], depth[to] - depth[head[to]] + 1, y);
      } else {
        ups[chain[from]].update(depth[to] - depth[head[to]], depth[from] - depth[head[from]] + 1, y);
        downs[chain[from]].update(depth[to] - depth[head[to]], depth[from] - depth[head[from]] + 1, y);
      }
    }
  }
  return 0;
}