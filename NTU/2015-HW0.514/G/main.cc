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
#define FOR(i,c) for(__typeof((c).bg()) i=(c).bg();i!=(c).ed();i++)
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
#define ALL(x) (x).begin(),(x).end()
#define CASET2 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d:\n", case_n++) : 0), ___T-- > 0)
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
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
#define X first
#define Y second
#define V(x) vector<x >
#define PV(v) REP(i, SZ(v)) if(i < SZ(v)-1) PIS(v[i]); else PI(v[i]);

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(unsigned x) { return __builtin_popcount(x); } 
int popcount(unsigned long long x) { return __builtin_popcountll(x); } 

typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

#include <unordered_set>
#include <unordered_map>
#define PL(x) printf("%lld\n",x)
#define EB emplace_back
#define RL(x) scanf("%lld",&x)
#define DRL(x) LL x;RL(x)

template<class Data, class Lazy>
struct SegmentTree {
  // static Data identity;
  int n;
  int size;
  vector<Data> dat;
  vector<Lazy> lazy;

  SegmentTree(int n_) {
    n = 1;
    size = n_;
    while(n < n_) n *= 2;
    dat.resize(2*n-1);
    lazy.resize(2*n-1);
    fill(ALL(dat), 0);
    fill(ALL(lazy), Lazy());
    init(0, 0, n);
  }

  int chl(int k) const {
    return k * 2 + 1;
  }

  int chr(int k) const {
    return k * 2 + 2;
  }

  void init(int k, int l, int r) {
    if(r - l == 1) {
      // set dat[k] of leaf
    } else {
      // non-leaf
      init(chl(k), l, (l + r) / 2);
      init(chr(k), (l + r) / 2, r);
      dat[k] = combine(dat[chl(k)], dat[chr(k)]);
    }
  }
  void update(int a, int b, Lazy d) {
    update(a, b+1, 0, 0, n, d);
  }

  void propagate(int k, Lazy &d, int l, int r) {
    dat[k] += d;
    if (chr(k) < lazy.size()) {
        lazy[chl(k)] += d;
        lazy[chr(k)] += d;
    }
    if ((&d) == &lazy[k]) {
        d = Lazy();
    }
  }

  void update(int a, int b, int k, int l, int r, Lazy d) {
    propagate(k, lazy[k], l, r);
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
        propagate(k, d, l, r);
    } else {
        update(a, b, chl(k), l, (l+r)/2, d);
        update(a, b, chr(k), (l+r)/2, r, d);
        dat[k] = combine(dat[chl(k)], dat[chr(k)]);
    }
  }

  Data query(int a, int b) {
    return query(a, b+1, 0, 0, n);
  }

  Data query(int a, int b, int k, int l, int r) {
    // if [a, b) and [l, r) are disjoint
    if(r <= a || b <= l) return 0;
    propagate(k, lazy[k], l, r);
    // if [l, r) contains [a, b)
    if(a <= l && r <= b) {
        return dat[k];
    } else {
        Data vl = query(a, b, chl(k), l, (l + r) / 2);
        Data vr = query(a, b, chr(k), (l + r) / 2, r);
        return combine(vl, vr);
    }
  }

  Data combine(Data vl, Data vr) {
    return vl + vr;
  }
};

V(VI) adj;
int bg[100005], ed[100005], parent[100005];
int c;

void dfs(int u, int p) {
    parent[u] = p;
    bg[u] = c++;
    for (int v: adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    ed[u] = c++;
}

int main() {
    DRI(T);
    while(T--) {
        DRI(N);
        adj = V(VI)(N);
        REP(i, N-1) {
            DRI(u, v);
            adj[u].PB(v);
            adj[v].PB(u);
        }
        c = 0;
        dfs(0, -1);
        SegmentTree<int,int> st1(N*2), st2(N*2);
        CASET {
            char cmd[3];
            RS(cmd);
            switch(cmd[0]) {
                case 's': {
                    DRI(x, y);
                    st1.update(bg[x], bg[x], 1);
                    if (y != 0) {
                        st1.update(bg[y], bg[y], -1);
                    }
                    break;
                }
                case 'h': {
                    DRI(x);
                    st2.update(bg[x], ed[x], 1);
                    // PIS(bg[x]); PI(ed[x]);
                    break;
                }
                case 'n': {
                    DRI(x);
                    st1.update(bg[x], bg[x], 1);
                    break;
                }
                case 'q': {
                    DRI(u, v);
                    if (u == parent[v]) {
                        swap(u, v);
                    }
                    // PIS(bg[u]); PIS(ed[u]); PIS(bg[v]); PI(ed[v]);

                    int a1 = st1.query(bg[u], ed[u]);
                    int a2 = st2.query(bg[v], bg[v]);
                    // PIS(a1); PI(a2);
                    PI(a1 + a2);
                    break;
                }
                default: {
                    assert(false);
                }
            }
        }
    }
    return 0;
}