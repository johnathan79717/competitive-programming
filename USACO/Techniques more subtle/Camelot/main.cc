/*
ID: johnath2
PROG: camelot
LANG: C++11
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
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <stack>
#include <functional>
using namespace std;
#define NAME "camelot"
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
#define PLL(x) printf("%lld\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#define EB emplace_back
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 2000000000;

struct Square {
  int r, c;
  Square() {}
  Square(int r, int c) : r(r), c(c) {}
  Square(FILE* file) {
    char c[2]; int r;
    if(fscanf(file, "%s%d", c, &r) == EOF)
      throw 0;
    this->c = c[0] - 'A';
    this->r = r - 1;
  }
  bool operator<(const Square &s) const {
    return false;
  }
};

#define MAX_V 2000

struct edge { int to, cost; edge(int to, int cost) : to(to), cost(cost) {} };
typedef pair<int, int> P;

int V;
vector<edge> G[MAX_V];
LL d[MAX_V];

void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d + V, INF);
  d[s] = 0;
  que.push(P(0, s));

  while(!que.empty()) {
    P p = que.top(); que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    for(int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

int dr[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

int R, C;

int v(int r, int c, bool withKing) {
  return r * C + c + (withKing ? R*C : 0);
}

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  RII(R, C);
  Square king(stdin);
  vector<Square> knights;
  try {
    while(true)
      knights.PB(stdin);
  } catch(int e) {}

  if(knights.empty()) {
    PI(0);
    return 0;
  }

  V = R * C * 2;
  REP(r, R) REP(c, C) {
    REP(i, 8) {
      int rr = r + dr[i], cc = c + dc[i];
      if(rr < 0 || rr >= R || cc < 0 || cc >= C) continue;
      G[v(r, c, false)].EB(v(rr, cc, false), 1);
      G[v(r, c, true)].EB(v(rr, cc, true), 1);
      G[v(rr, cc, false)].EB(v(r, c, false), 1);
      G[v(rr, cc, true)].EB(v(r, c, true), 1);
    }
    G[v(r, c, false)].EB(v(r, c, true), max(abs(r - king.r), abs(c - king.c)));
  }

  LL ans = INT_MAX;
  REP(r, R) REP(c, C) {
    dijkstra(v(r, c, false));
    LL sum = INT_MAX;
    FOR(k, knights) sum = min(sum, d[v(k->r, k->c, true)] - d[v(k->r, k->c, false)]);
    FOR(k, knights) sum += d[v(k->r, k->c, false)];
    ans = min(ans, sum);
  }

  PI(ans);

  return 0;
}