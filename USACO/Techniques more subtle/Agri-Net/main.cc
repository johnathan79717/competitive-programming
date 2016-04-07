/*
ID: johnath2
PROG: agrinet
LANG: C++
*/
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
using namespace std;
#define NAME "agrinet"
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define SZ(x) ((int)(x).size())
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
#define CASET int ___T,cas=1;scanf("%d ",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int MOD = 1000000007;
const int INF = 1000000000;
inline int add(int a, int b) { return a + b < MOD ? a + b : a + b - MOD; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + MOD : a - b; }
inline int mul(int a, int b) { return (LL)a * b % MOD; }
#define MAX_QUEUE 10000000
template<class T>
struct Queue {
  T arr[MAX_QUEUE];
  int f, b;
  Queue() : f(0), b(0) {}
  void push(const T& val) { arr[b++] = val; }
  bool empty() { return f == b; }
  T& pop() { return arr[f++]; }
};

#define MAX_V 100
#define MAX_E MAX_V*(MAX_V-1)/2

struct edge {int u, v, cost; };

bool comp(const edge& e1, const edge& e2) {
  return e1.cost < e2.cost;
}

edge es[MAX_E];
int V, E;

void init(int), unite(int, int);
int find(int);
bool same(int, int);

int kruskal() {
  sort(es, es + E, comp);
  init(V);
  int res = 0;
  for(int i = 0; i < E; i++) {
    edge e = es[i];
    if(!same(e.u, e.v)) {
      unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}

#define MAX_N MAX_V

int par[MAX_N];
int depth[MAX_N];

void init(int n) {
  for(int i = 0; i < n; i++) {
    par[i] = i;
    depth[i] = 0;
  }
}

int find(int x) {
  if(par[x] == x) {
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if(x == y) return;
  if(depth[x] < depth[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if(depth[x] == depth[y]) depth[x]++;
  }
}

bool same(int x, int y) {
  return find(x) == find(y);
}

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  RI(V);
  E = 0;
  REP(i, V) REP(j, V) {
    DRI(cost);
    if(i < j && cost > 0) {
      es[E].u = i;
      es[E].v = j;
      es[E].cost = cost;
      E++;
    }
  }
  PI(kruskal());
  return 0;
}