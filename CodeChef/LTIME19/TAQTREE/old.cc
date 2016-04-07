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
#include <sstream>
#include <bitset>
using namespace std;
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define BG begin()
#define ED end()
#define FOR(i,c) for(auto &i: c)
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

struct Edge {int to, cost, i;};
#define M 100005
V(V(Edge)) adj;
V(VI) occur;
int edge[M], up[M], first[M], last[M];
// VI order;
int cnt = 0;

BIT<LL> bit;

void dfs(int u, int i = -1) {
    occur[u].PB(cnt);
    FOR(e, adj[u]) {
        if (e.i != i) {
            ++cnt;
            bit.add(cnt, e.cost);
            first[e.i] = cnt;
            dfs(e.to, e.i);
            ++cnt;
            occur[u].PB(cnt);
            up[e.to] = e.i;
            bit.add(cnt, e.cost);
            last[e.i] = cnt;
        }
    }
}

int main() {
    DRI(N);
    adj.resize(N+1);
    occur.resize(N+1);
    bit.resize(N*2+1);
    REP1(i, 1, N-1) {
        DRIII(u, v, w);
        edge[i] = w;
        adj[u].PB((Edge){v, w, i});
        adj[v].PB((Edge){u, w, i});
    }
    dfs(1);
    CASET {
        DRI(t);
        if (t == 1) {
            DRII(i, c);
            bit.add(first[i], c - edge[i]);
            bit.add(last[i], c - edge[i]);
            edge[i] = c;
        } else {
            DRII(u, v);
            if (occur[v][0] < occur[u][0])
                swap(u, v);
            // u before v
            // PL(bit.sum(first[up[v]]) - bit.sum(last[up[u]] - 1));
            PL(bit.sum(occur[v][0]) - bit.sum(*--lower_bound(ALL(occur[u]), occur[v][0])));
        }
    }    
    return 0;
}
