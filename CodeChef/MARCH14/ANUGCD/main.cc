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
#define F first
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000;

template<typename T>
struct SegmentTree {
  static T identity;
  int n;
  vector<T> dat;
  vector<int> *m;

  void update(int k, T const& a) {
    // starting from leaf node
    k += n - 1;
    dat[k] = a;
    while(k > 0) {
      k = (k - 1) / 2;
      combine(k, k * 2 + 1, k * 2 + 2);
    }
  }

  T query(int a, int b) {
    return query(a, b, 0, 0, n);
  }

  T query(int a, int b, int k, int l, int r) {
    // if [a, b) and [l, r) are disjoint
    if(r <= a || b <= l) return identity;
    // if [l, r) contains [a, b)
    if(a <= l && r <= b) return dat[k];
    else {
      T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return combine(vl, vr);
    }
  }
  SegmentTree() {}

  void resize(int n) {
    this->n = n;
    int len = 1;
    while(len < n) len *= 2;
    dat.resize(2*len+1);
    init(0, 0, n);
  }

  SegmentTree(int n) : n(n) {
    resize(n);
  }

  void init(int k, int l, int r) {
    if(r - l == 1) {
      // leaf
      setLeaf(k, l);
    } else {
      // non-leaf
      int chl = k * 2 + 1, chr = k * 2 + 2;
      init(chl, l, (l + r) / 2);
      init(chr, (l + r) / 2, r);
      dat[k] = combine(dat[chl], dat[chr]);
    }
  }
  void setLeaf(int k, int l);
  T combine(const T& vl, const T& vr);
};

VI A;

template<>
void SegmentTree<PII>::setLeaf(int k, int l) {
  dat[k] = MP(A[m->at(l)], 1);
}

template<>
PII SegmentTree<PII>::combine(const PII &vl, const PII &vr) {
  if(vl.first < vr.first) return vr;
  if(vl.first > vr.first) return vl;
  return MP(vl.first, vl.second + vr.second);
}

template<>
PII SegmentTree<PII>::identity = MP(-1, -1);

VI prime_factors[100001];
VI multiples[100001];
SegmentTree<pair<int, int> > seg_trees[100001];

int main() {
  REP1(p, 2, 100000)
    if(prime_factors[p].empty())
      for(int k = p; k <= 100000; k += p)
        prime_factors[k].PB(p);
  DRII(N, M);
  A.resize(N);
  REP(i, N) {
    RI(A[i]);
    FOR(p, prime_factors[A[i]])
      multiples[p].PB(i);
  }

  REP(p, 100001) {
    if(multiples[p].empty()) continue;
    seg_trees[p].m = &multiples[p];
    seg_trees[p].resize(multiples[p].size());
  }

  while(M--) {
    DRIII(G, x, y);
    PII ans(-1, -1);
    FOR(p, prime_factors[G]) {
      int a = LB(ALL(multiples[p]), x-1) - multiples[p].BG;
      int b = UB(ALL(multiples[p]), y-1) - multiples[p].BG;
      ans = max(ans, seg_trees[p].query(a, b));
    }
    PIS(ans.F); PI(ans.S);
  }
  return 0;
}