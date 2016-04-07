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

char A[100005];
struct Data {
    int arr[3];
    int &operator[] (int i) {
        return arr[i];
    }
} identity;
int cum[200005];

template<typename T>
struct SegmentTree {
  // static T identity;
  int n;
  vector<T> dat;
  vector<int> lazy;

  SegmentTree(int n_) {
    n = 1;
    while(n < n_) n *= 2;
    dat.resize(2*n-1);
    lazy.resize(2*n-1);
    init(0, 0, n);
  }

  void init(int k, int l, int r) {
    if(r - l == 1) {
        dat[k][cum[l]] = 1;
    } else {
      // non-leaf
      int chl = k * 2 + 1, chr = k * 2 + 2;
      init(chl, l, (l + r) / 2);
      init(chr, (l + r) / 2, r);
      // dat[k] = combine(dat[chl], dat[chr]);
      REP(i, 3) {
        dat[k][i] = dat[chl][i] + dat[chr][i];
      }
    }
  }
  void update(int a, int b, int d) {
    update(a, b, 0, 0, n, d);
  }

  static void rotate(Data &dat, int r) {
    switch(r) {
        case 1: {
            int temp = dat[2];
            dat[2] = dat[1];
            dat[1] = dat[0];
            dat[0] = temp;
            break;
        }
        case 2: {
            int temp = dat[0];
            dat[0] = dat[1];
            dat[1] = dat[2];
            dat[2] = temp;
            break;
        }
        case 0: break;
        default: assert(false);
    }
  }

  void propagate(int k, int d) {
    lazy[k*2+1] += d;
    if (lazy[k*2+1] >= 3) lazy[k*2+1] -= 3;
    lazy[k*2+2] += d;
    if (lazy[k*2+2] >= 3) lazy[k*2+2] -= 3;
    assert(lazy[k*2+1] < 3 && lazy[k*2+1] >= 0);
    assert(lazy[k*2+2] < 3 && lazy[k*2+2] >= 0);
  }

  void update(int a, int b, int k, int l, int r, int d) {
    if (lazy[k]) {
        rotate(dat[k], lazy[k]);
        if (r - l > 1) {
            propagate(k, lazy[k]);
        }
        lazy[k] = 0;
    }
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
        rotate(dat[k], d);
        if (r - l > 1) {
            propagate(k, d);
        }
    } else {
        update(a, b, k*2+1, l, (l+r)/2, d);
        update(a, b, k*2+2, (l+r)/2, r, d);
        REP(i, 3) dat[k][i] = dat[k*2+1][i] + dat[k*2+2][i];
    }
  }

  T query(int a, int b) {
    return query(a, b, 0, 0, n);
  }

  T query(int a, int b, int k, int l, int r) {
    // if [a, b) and [l, r) are disjoint
    if(r <= a || b <= l) return identity;
    if (lazy[k]) {
        rotate(dat[k], lazy[k]);
        if (r - l > 1) propagate(k, lazy[k]);
        lazy[k] = 0;
    }
    // if [l, r) contains [a, b)
    if(a <= l && r <= b) {
        return dat[k];
    }
    else {
        T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        Data ans;
        REP(i, 3) ans[i] = vl[i] + vr[i];
        return ans;
    }
  }
};

int main() {
    DRII(N, M);
    RS(A+1);
    REP1(i, 1, N) {
        cum[i] = (cum[i-1] + A[i] - '0') % 3;
    }
    SegmentTree<Data> st(N+1);
    while (M--) {
        DRI(t);
        if (t == 1) {
            DRII(X, Y);
            st.update(X, N+1, (Y + '0' - A[X] + 12) % 3);
            A[X] = Y + '0';
        } else {
            DRII(C, D);
            Data ans = st.query(C-1, D+1);
            // PIS(ans[0]); PIS(ans[1]); PI(ans[2]);
            PL(LL(ans[0]-1)*ans[0]/2+LL(ans[1]-1)*ans[1]/2+LL(ans[2]-1)*ans[2]/2);
        }
    }
    return 0;
}
