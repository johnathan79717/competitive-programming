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

int S[10001];
int N;

struct DisjointSet {
  VI par, rank, winner;
  int N;

  DisjointSet(int N): par(N), rank(N), winner(N), N(N) {
    init();
  }

  void init() {
    for(int i = 0; i < N; i++) {
      par[i] = i;
      rank[i] = 0;
      winner[i] = i;
    }
  }

  int find(int x) {
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(S[winner[x]] == S[winner[y]]) return;
    int w = S[winner[x]] < S[winner[y]] ? winner[y] : winner[x];
    if(x == y) return;
    if(rank[x] < rank[y]) {
      par[x] = y;
      winner[y] = w;
    } else {
      par[y] = x;
      winner[x] = w;
      if(rank[x] == rank[y])
        rank[x]++;
    }
  }
};


int main() {
  DRI(T);
  REP(t, T) {
    RI(N);
    REP(i, N) RI(S[i]);
    DRI(Q);
    DisjointSet s(N);
    while(Q--) {
      DRI(type);
      if(type == 0) {
        DRII(x, y);
        x--; y--;
        if(s.find(x) == s.find(y))
          puts("Invalid query!");
        else
          s.unite(x, y);
      } else {
        DRI(x);
        PI(s.winner[s.find(x-1)]+1);
      }
    }
  }
  return 0;
}
