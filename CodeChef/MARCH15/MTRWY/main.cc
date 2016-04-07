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

struct DisjointSet {
  VI par, rank, size;
  int N, max_size;

  DisjointSet(int N): par(N), rank(N), size(N), N(N) {
    max_size = 1;
    init();
  }

  void init() {
    for(int i = 0; i < N; i++) {
      par[i] = i;
      // rank[i] = 0;
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
    if(size[x] < size[y]) {
      par[x] = y;
      size[y] += size[x];
    } else {
      par[y] = x;
      size[x] += size[y];
      // if(rank[x] == rank[y])
      //   rank[x]++;
    }
    max_size = max(max_size, max(size[x], size[y]));
  }
};


struct Query {
    int t, x1, y1, x2, y2;
};

bool wall[1001][1001][3];

int N, M;

int number(int x, int y) {
    int ans = (x-1) * M + y - 1;
    assert(0 <= ans && ans < N*M);
    return ans;
}

int main() {
    DRI(T);
    REP(t, T) {
        RII(N, M);
        DRI(Q);
        stack<Query> query;
        MS0(wall);
        REP(i, Q) {
            Query q;
            RI(q.t);
            if (q.t <= 3) {
                RII(q.x1, q.y1);
            }
            if (q.t == 3) {
                RII(q.x2, q.y2);
            }
            if (q.t <= 2) {
                if (wall[q.x1][q.y1][q.t]) {
                    continue;
                } else {
                    wall[q.x1][q.y1][q.t] = true;
                }
            }
            query.push(q);
        }
        DisjointSet set(N*M);
        REP1(i, 1, N) REP1(j, 1, M-1) {
            if (!wall[i][j][1]) {
                set.unite(number(i, j), number(i, j+1));
            }
        }
        REP1(i, 1, N-1) REP1(j, 1, M) {
            if (!wall[i][j][2]) {
                set.unite(number(i, j), number(i+1, j));
            }
        }
        LL ans = 0;
        while (!query.empty()) {
            Query q = query.top();
            if (q.t == 1) {
                set.unite(number(q.x1, q.y1), number(q.x1, q.y1+1));
            } else if (q.t == 2) {
                set.unite(number(q.x1, q.y1), number(q.x1+1, q.y1));
            } else if (q.t == 3) {
                // PI(set.find(number(q.x1, q.y1)) == set.find(number(q.x2, q.y2)));
                if (set.find(number(q.x1, q.y1)) == set.find(number(q.x2, q.y2)))
                    ans++;
            } else {
                assert(q.t == 4);
                // PI(max_size);
                ans += set.max_size;
            }
            query.pop();
        }
        PL(ans);
    }
    return 0;
}
