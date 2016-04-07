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
#include <deque>
#include <stack>
using namespace std;
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(x) (x).begin(),(x).end()
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
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
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

struct Edge
{
    int a, b;
    unsigned long long c;
    Edge (int a, int b, unsigned long long c): a(a), b(b), c(c) {}
    bool operator<(const Edge &other) const {
        return c < other.c;
    }
};

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

int main() {
    int N;
    int cas = 1;
    while(RI(N) != EOF) {
        V(Edge) es;
        REP(i, N-1) {
            DRIII(a, b, c);
            es.PB(Edge(a, b, c));
        }
        sort(ALL(es));
        DisjointSet s(N+1);
        unsigned long long m = 0, M = 0;
        FOR(e, es) {
            M += e->c * s.size[s.find(e->a)] * s.size[s.find(e->b)];
            s.unite(e->a, e->b);
        }
        s.init();
        PER(i, SZ(es)) {
            m += es[i].c * s.size[s.find(es[i].a)] * s.size[s.find(es[i].b)];
            s.unite(es[i].a, es[i].b);
        }
        printf("Case #%d: ", cas++);
        cout << M - m << endl;
    }
    return 0;
}
