#include <list>
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
#define ALL(x) (x).begin(),(x).end()
#define CASET2 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d:\n", case_n++) : 0), ___T-- > 0)
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T; scanf("%d ", &___T); while (___T-- > 0)
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
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define X first
#define Y second
#define V(x) vector<x >

typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

void print(int i) { printf("%d", i); }
template<class T> void PI(T i) { print(i); puts(""); }
template<class T> void PIS(T i) { print(i); printf(" "); }

template<class T>
void PV(T const &v, int N) {
    REP(i, N) {
        print(v[i]);
        printf("%c", i == N-1 ? '\n' : ' ');
    }
}

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(int x) { return __builtin_popcount(x); } 
int popcount(long long x) { return __builtin_popcountll(x); } 

#include <unordered_set>
#include <unordered_map>
#define EB emplace_back

class Graph {
  typedef pair<int, int> P;
  int V;
  struct edge { int to, cost; };
  vector<vector<edge> > G;
public:
  Graph() { V = 0; }
  Graph(int N) { V = N; G = V(V(edge))(N); }
  int addVertex() {
    G.resize(V+1);
    return V++;
  }
  void addEdge(int from, int to, int cost) {
    G[from].push_back((edge){to, cost});
    G[to].push_back((edge){from, cost});
  }
  VI dijkstra(int s) {
    VI d(V, INF);
    priority_queue<P, vector<P>, greater<P> > que;
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()) {
      P p = que.top(); que.pop();
      int v = p.second;
      if(d[v] < p.first) continue;
      for(int i = 0; i < SZ(G[v]); i++) {
        edge e = G[v][i];
        if(d[e.to] > d[v] + e.cost) {
          d[e.to] = d[v] + e.cost;
          que.push(P(d[e.to], e.to));
        }
      }
    }
    return d;
  }
};

// index starts with 1
template<class T>
class BIT {
  vector<T> bit;
public:
  BIT() {}
  BIT(int n): bit(n+1) {}
  T sum(int i) {
    assert(i>=0);
    i = min(i, (int)bit.size()-1);
    T s = 0;
    while(i > 0) {
      s += bit.at(i);
      i &= i - 1;
    }
    return s;
  }
  T sum(int l, int r) {
      return sum(r) - sum(l-1);
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

int main() {
    DRI(N, M);
    Graph g(N);
    REP(i, M) {
        DRI(x, y, z);
        g.addEdge(x-1, y-1, z);
    }
    VI d1 = g.dijkstra(0);
    VI d2 = g.dijkstra(N-1);
    VI v;
    REP(i, N) {
        d1[i] = d2[0] - 1 - d1[i];
        v.PB(d1[i]);
        v.PB(d2[i]);
    }
    sort(ALL(v));
    v.resize(unique(ALL(v)) - v.begin());
    VI v1(N), v2(N);
    REP(i, N) {
        v1[i] = lower_bound(ALL(v), d1[i]) - v.begin() + 1;
        v2[i] = lower_bound(ALL(v), d2[i]) - v.begin() + 1;
    }
    LL ans = 0;
    BIT<LL> bit(v.size()+1), bitd(v.size()+1);
    REP(i, N) {
        bit.add(v2[i], 1);
        bitd.add(v2[i], d2[i]);
    }
    REP(i, N) {
        ans += bit.sum(v1[i]-1) * d1[i] - bitd.sum(v1[i]-1);
    }
    //BIT<LL> bit1(v.size() + 1), bit2(v.size()+1);
    //BIT<LL> bit1d(v.size()+1), bit2d(v.size()+1);
    //REP(i, N) {
        //ans += bit2.sum(v1[i]-1) * d1[i] - bit2d.sum(v1[i]-1);
        //ans += bit1d.sum(v2[i]+1, v.size()) - d2[i] * bit1.sum(v2[i]+1,v.size());
        //bit2.add(v2[i], 1);
        //bit2d.add(v2[i], d2[i]);
        //bit1.add(v1[i], 1);
        //bit1d.add(v1[i], d1[i]);
    //}
    cout << ans << endl;
    return 0;
}
