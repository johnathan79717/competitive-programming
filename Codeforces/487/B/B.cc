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

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

// template<typename T>
typedef int T;
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
      // dat[k] = combine(k, k * 2 + 1, k * 2 + 2);
      dat[k] = min(dat[k*2+1], dat[k*2+2]);
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
      return min(vl, vr);
    }
  }

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
        dat[k] = INF;
    } else {
      // non-leaf
      int chl = k * 2 + 1, chr = k * 2 + 2;
      init(chl, l, (l + r) / 2);
      init(chr, (l + r) / 2, r);
      dat[k] = min(dat[chl], dat[chr]);
    }
  }
  // void setLeaf(int k, int l);
  // T combine(const T& vl, const T& vr);
};

typedef int Data;

// template<>
// void SegmentTree<Data>::setLeaf(int k, int l) {

// }

// template<>
// Data SegmentTree<Data>::combine(const Data &vl, const Data &vr) {

// }

Data SegmentTree::identity = INF;


int main() {
    DRIII(n, s, len);
    VI a(n);
    REP(i, n) RI(a[i]);
    multiset<int> set;
    set.insert(a[0]);
    // set.insert(1);
    // PI(*--set.end());
    int l = 0, r = 1, m = a[0], M = a[0];
    VI farthest(n);
    while(l < n) {
        while (r < n && (set.empty() || (abs(*--set.end() - a[r]) <= s && abs(*set.begin() - a[r]) <= s))) {
        // while (r < n && (abs(a[r] - m) <= s && abs(a[r] - M) <=  s)) {
            set.insert(a[r]);
            r++;
        }
        farthest[l] = r;
        set.erase(set.find(a[l]));
        l++;
        // ans++;
        // l = r;
        // r = l + 1;
        // m = M = a[l];
    }
    // BIT<int> bit;
    // bit.add(n, 1);
    // PER1(i, n-1, 1) {
    //     if (bit.sum(farthest[i])) {
    //         bit.add(i, 1);
    //     }
    // }
    // if (bit.sum(farthest[0])) {
    //     PI()
    // }
    SegmentTree st(n+1);
    st.update(n, 0);
    PER1(i, n-len, 0) {
        // PIS(i); PIS(min(i+len, n)); PIS(farthest[i]+1); PI(st.query(min(i+len, n), farthest[i]+1) + 1);
        st.update(i, st.query(min(i + len, n), farthest[i] + 1) + 1);
    }
    int ans = st.query(0, 1);
    if (ans < INF)
        PI(st.query(0, 1));
    else
        PI(-1);
  return 0;
}
