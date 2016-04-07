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

struct Node {
  Node(int v): above(v) {}
};

Node *maketree(int value) {
  Node *v = new Node(value);
}

long long path_agg(Node *v) {
  access(v);
  return 
}

void link(Node *v, Node *w) {
  access(v);
  access(w);
  w->delta += v->above - w->above;
  v->left = w;
  w->parent = v;
}

int main() {
  DRI(N);
  V(VI) adj(N);
  vector<Node*> nodes;
  REP(i, N) {
    DRI(v);
    nodes[i] = maketree(v);
  }
  REP(i, N-1) {
    DRII(u, v);
    adj[u].PB(v);
    adj[v].PB(u);
  }
  VI q(N);
  int qf = 0, qb = 0;
  q[qb++] = 0;
  while(f != b) {
    int u = q[qf++];
    FOR(v, adj[u]) {
      if(nodes[v]) continue;
      link(nodes[v], nodes[u]);
      q[qb++] = v;
    }
  }
  int SPECIAL = 0;
  DRI(M);
  while(M--) {
    DRI(t);
    if(t == 1) {
      DRII(k, v);
      k += SPECIAL;
      nodes.PB(maketree(v));
      link(nodes.back(), nodes[k]);
    } else if(t == 2) {
      DRII(k, v);
      k += SPECIAL;
      access(nodes[k]);
      nodes[k]->all += v;
      if(nodes[k]->left)
        nodes[k]->left->delta += v * nodes[k].subtree;
    } else if(t == 3) {
      DRI(k);
      k += SPECIAL;
      access(nodes[k]);
      nodes[k]->left->delta -= path_agg(nodes[k]);
      nodes[k]->left->parent = NULL;
      nodes[k]->left = NULL;
    } else {
      assert(t == 4);
      DRI(k);
      k += SPECIAL;
      access(nodes[k]);
      PL(path_agg(nodes[k]));
    }
  }
  return 0;
}
