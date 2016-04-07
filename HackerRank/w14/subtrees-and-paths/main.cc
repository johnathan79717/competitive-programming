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
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
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
const LL INF = 1e18;

V(VI) adj;     // adjacency list

void add_edge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

VI parent, depth;
VI heavy; // the heaviest child
VI size; // size of subtree

VI chain; // chain id
VI head; // the topmost node of the chain

void init(int n) {
  parent.resize(n);
  depth.resize(n);
  heavy.resize(n);
  size.resize(n);
  chain.resize(n);
  head.resize(n);
} 
 
void DFS(int i)
{
    if(parent[i] < 0) depth[i] = 0;
    size[i] = 1;
    for (int j: adj[i])
    {
        if (j == parent[i]) continue;
        parent[j] = i;
        depth[j] = depth[i] + 1;
 
        DFS(j);
 
        size[i] += size[j];
        if (heavy[i] == -1 || size[j] > size[heavy[i]]) 
            heavy[i] = j;
    }
}

template<class T>
struct SegmentTree {
  // static T identity;
  int n;
  int size;
  vector<T> dat;
  vector<T> lazy;

  SegmentTree(int n_) {
    n = 1;
    size = n_;
    while(n < n_) n *= 2;
    dat.resize(2*n-1);
    lazy.resize(2*n-1);
    fill(ALL(dat), 0);
    fill(ALL(lazy), 0);
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

    } else {
      // non-leaf
      init(chl(k), l, (l + r) / 2);
      init(chr(k), (l + r) / 2, r);
      dat[k] = combine(dat[chl(k)], dat[chr(k)]);
    }
  }
  void update(int a, int b, LL d) {
    update(a, b+1, 0, 0, n, d);
  }

  void propagate(int k, LL &d) {
    dat[k] += d;
    if (chr(k) < lazy.size()) {
        lazy[chl(k)] += d;
        lazy[chr(k)] += d;
    }
    if ((&d) == &lazy[k]) {
        d = 0;
    }
  }

  void update(int a, int b, int k, int l, int r, LL d) {
    if (lazy[k]) {
        propagate(k, lazy[k]);
    }
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
        propagate(k, d);
    } else {
        update(a, b, chl(k), l, (l+r)/2, d);
        update(a, b, chr(k), (l+r)/2, r, d);
        dat[k] = combine(dat[chl(k)], dat[chr(k)]);
    }
  }

  T query(int a, int b) {
    return query(a, b+1, 0, 0, n);
  }

  T query(int a, int b, int k, int l, int r) {
    // if [a, b) and [l, r) are disjoint
    if(r <= a || b <= l) return -INF;
    if (lazy[k]) {
        propagate(k, lazy[k]);
    }
    // if [l, r) contains [a, b)
    if(a <= l && r <= b) {
        return dat[k];
    } else {
        T vl = query(a, b, chl(k), l, (l + r) / 2);
        T vr = query(a, b, chr(k), (l + r) / 2, r);
        return combine(vl, vr);
    }
  }

  T combine(T vl, T vr) {
    return max(vl, vr);
  }
};

V(SegmentTree<LL>) segTrees;

void heavylight_DFS(int N, int root=0)
{
    init(N);
    fill(heavy.begin(), heavy.end(), -1);
 
    parent[root] = -1;
    depth[root] = 0;
    DFS(root);
 
    int c = 0;  
    for (int i=0; i<N; ++i)
        if (parent[i] == -1 || heavy[parent[i]] != i)
        {
            int l = 0;
            for (int k = i; k != -1; k = heavy[k])
                chain[k] = c, head[k] = i, l++;
            segTrees.EB(l);
            c++;
        }
}

int q[200000], *qf, *qb; // BFS queue
 
void heavylight_BFS(int N, int root = 0)
{
    init(N);
    qf = qb = q;
    parent[root] = -1;
    depth[root] = 0;
    *qb++ = root;
    while (qf < qb)
        for (int i=*qf++, k=0; k<adj[i].size(); ++k)
        {
            int j = adj[i][k];
            if (j == parent[i]) continue;
            parent[j] = i;
            depth[j] = depth[i] + 1;
            *qb++ = j;
        }
    fill(size.begin(), size.end(), 0);
    fill(heavy.begin(), heavy.end(), -1);
    for (int k=N-1; k>0; --k)   
    {
        int j = q[k], i = parent[q[k]];
        size[j]++;
        size[i] += size[j];
        if (heavy[i] == -1 || size[j] > size[heavy[i]])
            heavy[i] = j;
    }
    size[0]++;
 
    int c = 0;
    for (int i=0; i<N; ++i)
        if (parent[i] == -1 || heavy[parent[i]] != i)
        {
            int l = 0;
            for (int k = i; k != -1; k = heavy[k])
                chain[k] = c, head[k] = i, l++;
            segTrees.EB(l);
            c++;
        }
}
 
int lca(int i, int j)
{
    while (chain[i] != chain[j])
        if (depth[head[i]] > depth[head[j]])
            i = parent[head[i]];
        else
            j = parent[head[j]];
 
    return depth[i] < depth[j] ? i : j;
}
 
LL max_path(int v, int p) {
    LL ans = 0;
    while (chain[v] != chain[p]) {
        assert(depth[v] >= depth[p]);
        SegmentTree<LL> &stree = segTrees[chain[v]];
        int i = depth[v] - depth[head[v]];
        assert(i >= 0 && i < stree.size);
        LL q1 = stree.query(0, i), q2 = stree.query(i, i);
        assert(q1 >= q2);
        ans = max(q1, q2 + ans);
        v = parent[head[v]];
    }
    SegmentTree<LL> &stree = segTrees[chain[v]];
    int i = depth[v] - depth[head[v]], j = depth[p] - depth[head[p]];
    assert(i >= j && i < stree.size && j >= 0 && j < stree.size);
    LL q1 = stree.query(j, i), q2 = stree.query(i, i);
    assert(q1 >= q2);
    return max(q1, q2 + ans);
}

LL value(int v) {
    LL ans = 0;
    while (v >= 0) {
        int i = depth[v] - depth[head[v]];
        ans += segTrees[chain[v]].query(i, i);
        v = parent[head[v]];
    }
    return ans;
}

int main() {
    DRI(N);
    adj.resize(N);
    REP(i, N-1) {
        DRII(u, v);
        add_edge(u-1, v-1);
    }
    // heavylight_DFS(N);
    heavylight_BFS(N);
    CASET {
        char cmd[5];
        RS(cmd);
        if (strcmp(cmd, "add") == 0) {
            DRII(t, v);
            t--;
            SegmentTree<LL> &tree = segTrees[chain[t]];
            tree.update(depth[t] - depth[head[t]], tree.size, v);
        } else {
            assert(strcmp(cmd, "max") == 0);
            DRII(a, b);
            a--, b--;
            int p = lca(a, b);
            assert(depth[p] <= depth[a] && depth[p] <= depth[b]);
            // PL(max_path(a, p));
            // PL(max_path(b, p));
            // PL(value(parent[head[p]]));
            LL ans = value(parent[head[p]]) + max(max_path(a, p), max_path(b, p));
            assert(ans >= -1000000000 && ans <= 1000000000);
            PL(ans);
        }
    }
  return 0;
}