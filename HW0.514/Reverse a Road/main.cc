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

#define MAX_V 1000

typedef pair<int, int> P;

int N;
VI bfs(int s, V(VI) &G) {
  VI d(N, INF);
  queue<int> q;
  q.push(s);
  d[s] = 0;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    FOR(v, G[u]) {
      if(d[v] == INF) {
        q.push(v);
        d[v] = d[u] + 1;
      }
    }
  }
  return move(d);
};

int main() {
  while(true) {
    RI(N);
    if(!N) break;
    V(vector<int>) G1(N), G2(N);
    DRII(S, T);
    S--; T--;
    DRI(M);
    V(PII) edges;
    while(M--) {
      DRII(A, B);
      A--; B--;
      edges.EB(A, B);
      G1[A].PB(B);
      G2[B].PB(A);
    }

    auto d1 = bfs(S, G1);
    auto d2 = bfs(T, G2);
    int distance = d1[T], number = 0;
    assert(distance == d2[S]);
    REP(i, edges.size()) {
      int A = edges[i].F, B = edges[i].S;
      if(d1[B] == d1[A] + 1) continue;
      if(d2[A] == d2[B] + 1) continue;
      if(d1[B] + 1 + d2[A] < distance) {
        distance = d1[B] + 1 + d2[A];
        number = i+1;
      }
    }
    PIS(distance); PI(number);
  }
  return 0;
}
