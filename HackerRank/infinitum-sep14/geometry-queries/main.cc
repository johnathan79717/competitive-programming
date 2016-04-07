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

int m[100001], n[100001];

typedef vector<PII> Data;

long long f(const PII &p, long long x) {
  return p.F * x + p.S;
}

long long catchup(const PII &a, const PII &b) {
  return (b.S - a.S) / (a.F - b.F);
}

struct SegmentTree {
  int n;
  vector<Data> dat;

  SegmentTree(int n_) {
    n = 1;
    while(n < n_) n *= 2;
    dat.resize(2*n-1);
    init(0, 0, n);
  }

  void init(int k, int l, int r) {
    if(r - l == 1) {
      // leaf
      // setLeaf(k, l);
      dat[k].EB(m[l], n[l]);
    } else {
      // non-leaf
      int chl = k * 2 + 1, chr = k * 2 + 2;
      init(chl, l, (l + r) / 2);
      init(chr, (l + r) / 2, r);
      // dat[k] = combine(dat[chl], dat[chr]);
      int i = 0, j = 0;
      long long x = 1e10;
      auto &L = dat[chl], &R = dat[chr];
      while(i < L.size() && j < R.size()) {
        if(f(L[i], x) > f(R[j], x)) {
          dat[k].PB(L[i]);
          if(L[i].F >= R[j].F) {
            // no chance to catch up
            j++;
          } else {
            LL c = catchup(R[j], L[i]);
            
          }
        } else {
          dat[k].PB(R[j]);
        }
      }
    }
  }
};


int main() {
  DRI(N);
  REP(i, N) {
    RII(m[i], n[i]);
  }
  SegmentTree st();

  return 0;
}