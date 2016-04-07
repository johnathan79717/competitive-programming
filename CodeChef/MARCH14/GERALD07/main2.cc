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

#define MOD 1000000007
inline int add(int a, int b, int mod=MOD) { return a + b < mod ? a + b : a + b - mod; }
inline void addBy(int &a, int b, int mod=MOD) { a = add(a, b, mod); }
inline int sub(int a, int b, int mod=MOD) { return a - b < 0 ? a - b + mod : a - b; }
inline void subBy(int &a, int b, int mod=MOD) { a = sub(a, b, mod); }
inline int mul(int a, int b, int mod=MOD) { return (LL)a * b % mod; }
inline void mulBy(int &a, int b, int mod=MOD) { a = mul(a, b, mod); }

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
 
using namespace std;
 
template<class T> struct splnode {
  typedef splnode<T> node_t;
 
  splnode() : P(NULL), flip(0), pp(NULL) {
    C[0] = C[1] = NULL;
    fix();
  }
 
  node_t* P;
  node_t* C[2];
 
  int flip;
  node_t* pp;
 
  /* Fix the parent pointers of our children.  Additionally if we have any
   * extra data we're tracking (e.g. sum of subtree elements) now is the time to
   * update them (all of the children will already be up to date). */
  void fix() {
    if(C[0]) C[0]->P = this;
    if(C[1]) C[1]->P = this;
  }
 
  /* Push the flip bit down the tree. */
  void push_flip() {
    if(!flip) return;
    flip = 0;
    swap(C[0], C[1]);
    if(C[0]) C[0]->flip ^= 1;
    if(C[1]) C[1]->flip ^= 1;
  }
 
  /* Return the direction of this relative its parent. */
  int up() {
    return !P ? -1 : (P->C[0] == this ? 0 : 1);
  }
 
  /* Simple zig step in the 'c' direction when we've reached the root. */
  void zig(int c) {
    node_t* X = C[c];
    if(X->P = P) P->C[up()] = X;
    C[c] = X->C[1 - c];
    X->C[1 - c] = this;
    fix(); X->fix();
    if(P) P->fix();
    swap(pp, X->pp);
  }
 
  /* Zig zig in the 'c' direction both times. */
  void zigzig(int c) {
    node_t* X = C[c];
    node_t* Y = X->C[c];
    if(Y->P = P) P->C[up()] = Y;
    C[c] = X->C[1 - c];
    X->C[c] = Y->C[1 - c];
    Y->C[1 - c] = X;
    X->C[1 - c] = this;
    fix(); X->fix(); Y->fix();
    if(P) P->fix();
    swap(pp, Y->pp);
  }
 
  /* Zig zag first in the 'c' direction then in the '1-c' direciton. */
  void zigzag(int c) {
    node_t* X = C[c];
    node_t* Y = X->C[1 - c];
    if(Y->P = P) P->C[up()] = Y;
    C[c] = Y->C[1 - c];
    X->C[1 - c] = Y->C[c];
    Y->C[1 - c] = this;
    Y->C[c] = X;
    fix(); X->fix(); Y->fix();
    if(P) P->fix();
    swap(pp, Y->pp);
  }
 
  /* Splay this up to the root.  Always finishes without flip set. */
  node_t* splay() {
    for(push_flip(); P; ) {
      /* Reorganize flip bits so we can rotate as normal. */
      if(P->P) P->P->push_flip();
      P->push_flip();
      push_flip();
 
      int c1 = up();
      int c2 = P->up();
      if(c2 == -1) {
        P->zig(c1);
      } else if(c1 == c2) {
        P->P->zigzig(c1);
      } else {
        P->P->zigzag(c2);
      }
    }
    return this;
  }
 
  /* Return the max element of the subtree rooted at this. */
  node_t* last() {
    push_flip();
    return C[1] ? C[1]->last()  : splay();
  }
 
  /* Return the min element of the subtree rooted at this. */
  node_t* first() {
    push_flip();
    return C[0] ? C[0]->first() : splay();
  }
};
 
 
template<class T>
struct linkcut {
typedef splnode<T> node_t;
 
linkcut(int N) : node(N) {
}
 
void link(int u, int v) {
  make_root(v);
  node[v].pp = &node[u];
}
 
void cut(int u, int v) {
  make_root(u);
  node[v].splay();
  if(node[v].pp) {
    node[v].pp = NULL;
  } else {
    node[v].C[0]->P = NULL;
    node[v].C[0] = NULL;
    node[v].fix();
  }
}
 
bool connected(int u, int v) {
  node_t* nu = access(u)->first();
  node_t* nv = access(v)->first();
  return nu == nv;
}
 
/* Move u to root of represented tree. */
void make_root(int u) {
  access(u);
  node[u].splay();
  if(node[u].C[0]) {
    node[u].C[0]->P = NULL;
    node[u].C[0]->flip ^= 1;
    node[u].C[0]->pp = &node[u];
 
    node[u].C[0] = NULL;
    node[u].fix();
  }
}
 
/* Move u to root aux tree.  Return the root of the root aux tree. */
splnode<T>* access(int u) {
  node_t* x,* pp;
  for(x = node[u].splay(); x->pp; x = pp) {
    pp = x->pp->splay();
    x->pp = NULL;
    if(pp->C[1]) {
      pp->C[1]->P = NULL;
      pp->C[1]->pp = pp;
    }
    pp->C[1] = x;
    pp->fix();
  }
  return x;
}
 
vector<node_t> node;
};
 
 
struct Query
{
  int L, R, i;
};

int main() {
  DRI(T);
  REP(t, T) {
    DRIII(N, M, Q);
    V(PII) edge(M);
    REP(i, M) {
      RII(edge[i].F, edge[i].S);
      edge[i].F--;
      edge[i].S--;
    }
    int B = sqrt(M);
    V(Query) query(Q);
    V(V(Query)) bucket(M / B + 1);
    REP(i, Q) {
      RII(query[i].L, query[i].R);
      query[i].L--; query[i].R--;
      query[i].i = i;
      bucket[query[i].L / B].PB(query[i]);
    }
    VI ans(Q);
    FOR(b, bucket) {
      sort(ALL(b), [](Query const &q1, Query const &q2) {
        return q1.R < q2.R;
      });
      linkcut<int> tr(N);
      int cc = N;
      FOR(q, b) {
        static int L = q.L, R = q.L-1;
        while(R < q.R) {
          ++R;
          if(edge[R].F != edge[R].S && !tr.connected(edge[R].F, edge[R].S)) {
            cc--;
            tr.link(edge[R].F, edge[R].S);
          }
        }
        while(q.L < L) {
          --L;
          if(edge[R].F != edge[R].S && !tr.connected(edge[L].F, edge[L].S)) {
            tr.link(edge[L].F, edge[L].S);
            cc--;
          }
        }
        while(L < q.L) {
          if(edge[L].F != edge[L].S && tr.connected(edge[L].F, edge[L].S)) {
            tr.cut(edge[L].F, edge[L].S);
            cc++;
          }
          L++;
        }
        ans[q.i] = cc;
      }
    }
    REP(i, Q) PI(ans[i]);
  }
  return 0;
}