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
#define LB lower_bound
#define UB upper_bound
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
const int INF = 1000000000;

struct DisjointSet {
  VI par, rank, size;
  int N;

  DisjointSet(int N): par(N), rank(N), size(N), N(N) {
    init();
  }

  void init() {
    for(int i = 0; i < N; i++) {
      par[i] = i;
      rank[i] = 0;
      size[i] = 1;
    }
  }

  int find(int x) {
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(rank[x] < rank[y]) {
      par[x] = y;
      size[y] += size[x];
    } else {
      par[y] = x;
      size[x] += size[y];
      if(rank[x] == rank[y])
        rank[x]++;
    }
  }
};


int main() 
{
  DRI(n);
  V(VI) d(n, VI(n));
  typedef pair<int, PII> P;
  priority_queue<P, VI(P), greater<P>> pq;
  REP(i, n) {
    REP(j, n) {
      RI(d[i][j]);
      pq.emplace(d[i][j], MP(i, j));
    }
  }
  DisjointSet s(n);
  V(PII) e(n);
  while(true) {
    int d = pq.top().first, i = pq.top().second.first, j = pq.top().second.second;
    if (i == j) {
      if (d != 0) {
        puts("NO");
        return 0;
      }
      continue;
    }
    if (s.find(i) == s.find(j)) {
      continue;
    } else {
      s.unite(i, j);
      e[i].emplace(j, d);
      e[j].emplace(i, d);
    }
  }
  REP(i, n) {
    queue<int> q;
    q.emplace(i);
    VI distance(n, -1);
    distance[i] = 0;
    while(!q.empty()) {
      int i = q.front();
      FOR(j, e[i]) {
        if (distance[j.first] < 0) {
          distance[j.first] = distance[i] + j.second;
          q.emplace(j.first, distance[j.first]);
        }
      }
    }
    REP(j, n) {
      if(d[i][j] != distance[j]) {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
  return 0;
}

