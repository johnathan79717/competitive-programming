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
using namespace std;
#define FOR(i,c) for(auto i=(c).begin();i!=(c).end();i++)
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

#define MAX_N 200000

int A[MAX_N];

template<class T>
struct SegmentTree {
  static T identity;
  int n;
  vector<T> dat;

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

  SegmentTree(int n) : n(n) {
    int len = 1;
    while(len < n) len *= 2;
    dat.resize(2 * len - 1);
    init(0, 0, n);
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

struct Large {
  int threshold, sum;
  Large() {}
  Large(int a) : threshold(a), sum(a) {}
};

struct Data {
  int sum;
  vector<Large> large;
  Data() : sum(0) {}
};

template<>
void
SegmentTree<Data>::setLeaf(int k, int l) {
  if(A[l] == 1)
    dat[k].sum = 1;
  else {
    dat[k].sum = 0;
    dat[k].large.PB(A[l]);
  }
}

void process(Data& ret, const Large &i) {
  if(i.threshold <= ret.sum + 1)
    ret.sum += i.sum;
  else if(ret.large.empty()) {
    ret.large.PB(i);
  } else {
    auto &l = ret.large.back();
    if(i.threshold <= l.threshold + l.sum)
      l.sum += i.sum;
    else
      ret.large.PB(i);
  }
}

template<>
Data
SegmentTree<Data>::combine(const Data &vl, const Data &vr) {
  Data ret;
  ret.sum = vl.sum + vr.sum;
  auto il = vl.large.begin(), ir = vr.large.begin();
  while(il != vl.large.end() && ir != vr.large.end())
    process(ret, il->threshold < ir->threshold ? *il++ : *ir++);
  while(il != vl.large.end())
    process(ret, *il++);
  while(ir != vr.large.end())
    process(ret, *ir++);
  return ret;
}

template<>
Data SegmentTree<Data>::identity = Data();

int main() {
  DRI(N);
  REP(i, N) RI(A[i]);
  SegmentTree<Data> segment_tree(N);
  DRI(M);
  while(M--) {
    DRII(L, R);
    PI(segment_tree.query(L-1, R).sum + 1);
  }
  return 0;
}