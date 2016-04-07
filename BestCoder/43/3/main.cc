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
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
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
#define F first
#define S second
#define V(x) vector<x >
#define PV(v) REP(i, SZ(v)) if(i < SZ(v)-1) PIS(v[i]); else PI(v[i]);

int popcount(unsigned x) { return __builtin_popcount(x); } 
int popcount(unsigned long long x) { return __builtin_popcountll(x); } 

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

#define MAX_LOG_V 20
V(VI) G;
int parent[MAX_LOG_V][300001];
int depth[300001];

int N;

void init() {
    MS1(depth);
    queue<int> q;
    q.push(0);
    depth[0] = 0;
    while (!q.empty()) {
        FOR(it, G[q.front()]) {
            int v = *it;
            if (depth[v] < 0) {
                depth[v] = depth[q.front()] + 1;
                parent[0][v] = q.front();
                q.push(v);
            }
        }
        q.pop();
    }
    for(int k = 0; k + 1 < MAX_LOG_V; k++) {
        for(int v = 0; v < N; v++) {
          if(parent[k][v] < 0)
            parent[k+1][v] = -1;
          else
            parent[k + 1][v] = parent[k][parent[k][v]];
        }
    }
}

int lca(int u, int v) {
  if(depth[u] > depth[v]) swap(u, v);
  for(int k = 0; k < MAX_LOG_V; k++) {
    if((depth[v] - depth[u]) >> k & 1) {
      v = parent[k][v];
    }
  }
  if(u == v) return u;
  for(int k = MAX_LOG_V - 1; k >= 0; k--) {
    if(parent[k][u] != parent[k][v]) {
      u = parent[k][u];
      v = parent[k][v];
    }
  }
  return parent[0][u];
}

typedef int T;

struct SegmentTree {
    int n;
    vector<T> dat;

    void update(int k, T const& a) {
        // starting from leaf node
        k += n - 1;
        dat[k] = a;
        while(k > 0) {
            k = (k - 1) / 2;
            dat[k] = combine(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    T query(int a, int b) {
        return query(a, b, 0, 0, n);
    }

    T query(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) {
            // if [a, b) and [l, r) are disjoint
            return -1;
        } else if(a <= l && r <= b) {
            // if [l, r) contains [a, b)
            return dat[k];
        } else {
            T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return combine(vl, vr);
        }
    }

    int real_size;
    SegmentTree(int n_) {
        real_size = n_;
        n = 1;
        while(n < n_) n *= 2;
        // dat.resize(2*n-1);
        dat = VI(2*n-1, -1);
        init(0, 0, n);
    }

    void init(int k, int l, int r) {
        if(r - l == 1) {
            // leaf
            if (l >= real_size)
                return;
            // TODO set leaf
            dat[k] = l;
        } else {
            // non-leaf
            init(k*2+1, l, (l + r) / 2);
            init(k*2+2, (l + r) / 2, r);
            dat[k] = combine(dat[k*2+1], dat[k*2+2]);
        }
    }
    T combine(T vl, T vr);
};

int SegmentTree::combine(int vl, int vr) {
    if (vl < 0) return vr;
    if (vr < 0) return vl;
    return lca(vl, vr);
}

// template<>
// int SegmentTree<int>::identity = -1;

int main() {
    while (RI(N) != EOF) {
        G = V(VI)(N);
        REP(i, N-1) {
            DRI(b, c);
            G[b-1].PB(c-1);
            G[c-1].PB(b-1);
        }
        init();
        SegmentTree s(N);
        CASET {
            DRI(l, r);
            PI(s.query(l-1, r)+1);
        }
    }
    return 0;
}
