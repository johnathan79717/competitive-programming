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
#ifdef ONLINE_JUDGE
  #define RL(x) scanf("%I64d",&x)
  #define PL(x) printf("%I64d\n",x)
  typedef __int64 LL;
#else
  #define RL(x) scanf("%lld",&x)
  #define PL(x) printf("%lld\n",x)
  typedef long long LL;
#endif
#define DRI(x) int x;RI(x)
#define DRL(x) LL x;RL(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
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

typedef unsigned long long ULL;
const int INF = 1000000000;

// index starts with 1
template<class T>
class BIT {
  vector<T> bit;
public:
  BIT() {}
  BIT(int n): bit(n+1) {}
  T sum(int i) {
    i = min(i, (int)bit.size()-1);
    T s = 0;
    while(i > 0) {
      s += bit.at(i);
      i &= i - 1;
    }
    return s;
  }
  void add(int i, T x) {
    while(i < bit.size()) {
      bit.at(i) += x;
      i += i & -i;
    }
  }
  void resize(int n) {
    bit.resize(n+1);
  }
};


V(VI) adj, occ;
int c;

void dfs(int v) {
  occ[v].PB(++c);
  REP(i, adj[v].size()) {
    int u = adj[v][i];
    if(occ[u].empty()) {
      dfs(u);
      occ[v].PB(++c);
    }
  }
}

int offset;

typedef vector<int>::iterator I;

PII bound(int v) {
  I it = lower_bound(ALL(occ[v]), offset);
  int first, last;
  if(it != occ[v].end())
    first = *it;
  else
    first = occ[v].front();
  if(it != occ[v].begin())
    last = *(--it);
  else
    last = occ[v].back();
  return MP(first, last);
}

int main() {
  DRI(T);
  REP1(t, 1, T) {
    printf("Case #%d:\n", t);
    DRI(N);
    adj.resize(N+1);
    REP1(i, 1, N) adj[i].clear();
    REP(i, N-1) {
      DRII(x, y);
      adj[x].PB(y);
      adj[y].PB(x);
    }
    occ.resize(N+1);
    REP1(i, 1, N) occ[i].clear();
    offset = 0;
    c = 0;
    dfs(1);
    BIT<int> bit(c);
    VI w(N+1);
    REP1(i, 1, N) {
      RI(w[i]);
      bit.add(bound(i).F, w[i]);
    }
    DRI(Q);
    while(Q--) {
      char s[10];
      RS(s);
      if(s[0] == 'Q') {
        DRI(x);
        PII p = bound(x);
        int first = p.F, last = p.S;
        if(first == offset) {
          PI(bit.sum(c));
        } else if(first <= last){
          PI(bit.sum(last) - bit.sum(first-1));
        } else {
          PI(bit.sum(last) + bit.sum(c) - bit.sum(first-1));
        }
      } else if(s[0] == 'R') {
        DRI(x);
        offset = bound(x).F;
      } else {
        assert(s[0] == 'C');
        DRII(x, y);
        bit.add(bound(x).F, y - w[x]);
        w[x] = y;
      }
    }
  }
  return 0;
}
