#include <functional>
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
#define REP(i,n) for(int i=0;i<int(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=int(b);i++)
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
void print(LL i);
template<class T> void PI(T i) { print(i); puts(""); }
template<class T> void PIS(T i) { print(i); printf(" "); }

template<class T>
void PV(T const &v, int N) {
    REP(i, N) {
        print(v[i]);
        printf("%c", i == N-1 ? '\n' : ' ');
    }
}

template<class T> void PV(T const &v) { PV(v, SZ(v)); }

template<class T, class S> bool has_bit(T mask, S i) { return (mask >> i) & 1; }
long long shift(int i) { return 1ll << i; }

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(int x) { return __builtin_popcount(x); } 
int popcount(long long x) { return __builtin_popcountll(x); } 

#include <array>
#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)

int R, C;
char a[55][55];

pair<pair<int, int>, int> go(int i, int j, int di, int dj) {
  i += di;
  j += dj;
  if (i < 0 || i >= R || j < 0 || j >= C || a[i][j] == '#') {
    return MP(MP(-1, -1), -1);
  }
  if (a[i][j] == '-' || a[i][j] == '|') {
    return MP(MP(i, j), di == 0);
  }
  if (a[i][j] == '/') {
    if (dj < 0) {
      di = 1;
      dj = 0;
    } else if (di < 0) {
      di = 0;
      dj = 1;
    } else if (di > 0) {
      di = 0;
      dj = -1;
    } else {
      dj = 0;
      di = -1;
    }
  } else if (a[i][j] == '\\') {
    if (dj < 0) {
      di = -1;
      dj = 0;
    } else if (di > 0) {
      di = 0;
      dj = 1;
    } else if (di < 0) {
      di = 0;
      dj = -1;
    } else {
      dj = 0;
      di = 1;
    }
  }
  return go(i, j, di, dj);
}

int c = 0;
int num[55][55][2];

VI adj[2505];
VI adj2[2505];
bool marked[2505];

void addEdge(int c1, int c2) {
  adj[c1^1].PB(c2);
  adj[c2^1].PB(c1);
  adj2[c2].PB(c1^1);
  adj2[c1].PB(c2^1);
}

stack<int> s;
void dfsFirst(int v) {
  marked[v] = true;
  for (int u : adj[v]) {
    if (!marked[u]) {
      dfsFirst(u);
    }
  }
  s.push(v);
}

int counter;
int component[2505];
void dfsSecond(int v) {
  marked[v] = true;
  for (int u : adj2[v]) {
    if (!marked[u]) {
      dfsSecond(u);
    }
  }
  component[v] = counter;
}

bool scc() {
  REP(i, c) {
    if (!marked[i]) {
      dfsFirst(i);
    }
  }

  MS0(marked);
  counter = 0;

  while (s.size()) {
    int v = s.top();
    s.pop();
    if (!marked[v]) {
      counter = counter + 1;
      dfsSecond(v);
    }
  }

  REP(i, R) {
    REP(j, C) {
      if (a[i][j] != '-' && a[i][j] != '|') {
        continue;
      }
      int n = num[i][j][0];
      if (component[n] == component[n^1]) {
        return false;
      }
      if (component[n] > component[n^1]) {
        a[i][j] = '|';
      } else {
        a[i][j] = '-';
      }
    }
  }
  return true;
}

bool solve() {
  REP(i, 2505) {
    adj[i].clear();
    adj2[i].clear();
  }
  MS0(marked);
  s = stack<int>();
  REP(i, R) {
    REP(j, C) {
      if (a[i][j] == '.' || a[i][j] == '-' || a[i][j] == '|') {
        auto down = go(i, j, 1, 0);
        auto up = go(i, j, -1, 0);
        auto right = go(i, j, 0, 1);
        auto left = go(i, j, 0, -1);
        auto p = max(down, up);
        auto q = max(left, right);
        if (a[i][j] == '.') {
          if (p.Y >= 0 && q.Y >= 0) {
            addEdge(num[p.X.X][p.X.Y][p.Y], num[q.X.X][q.X.Y][q.Y]);
          } else if (p.Y >= 0) {
            addEdge(num[p.X.X][p.X.Y][p.Y], num[p.X.X][p.X.Y][p.Y]);
          } else if (q.Y >= 0) {
            addEdge(num[q.X.X][q.X.Y][q.Y], num[q.X.X][q.X.Y][q.Y]);
          } else {
            return false;
          }
        } else {
          if (p.Y >= 0) {
            addEdge(num[i][j][1], num[i][j][1]);
          }
          if (q.Y >= 0) {
            addEdge(num[i][j][0], num[i][j][0]);
          }
        }
      }
    }
  }
  return scc();
}

int main() {
  DRI(T);
  REP1(t, 1, T) {
    printf("Case #%d: ", t);
    RI(R, C);
    c = 0;
    REP(i, R) {
      RS(a[i]);
      REP(j, C) {
        if (a[i][j] == '-' || a[i][j] == '|') {
          num[i][j][0] = c++;
          num[i][j][1] = c++;
        }
      }
    }
    if (!solve()) {
      puts("IMPOSSIBLE");
    } else {
      puts("POSSIBLE");
      REP(i, R) {
        puts(a[i]);
      }
    }
  }
  return 0;
}
