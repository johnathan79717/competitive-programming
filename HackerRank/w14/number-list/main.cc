#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
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
const int INF = 2000000000;

struct DisjointSet {
  VI par, _size;
  int N;

  DisjointSet(int N): par(N), _size(N), N(N) {
    init();
  }

  void init() {
    for(int i = 0; i < N; i++) {
      par[i] = i;
      _size[i] = 1;
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
    if(_size[x] < _size[y]) {
      par[x] = y;
      _size[y] += _size[x];
    } else {
      par[y] = x;
      _size[x] += _size[y];
    }
  }

  int size(int x) {
    return _size[find(x)];
  }
};


int main() {
    DRI(T);
    while(T--) {
        DRII(N, K);
        VI A(N);
        VI visited(N);
        vector<PII> B;
        REP(i, N) {
            RI(A[i]);
            B.EB(A[i], i);
        }
        sort(ALL(B));
        DisjointSet set(N);
        LL ans = 0;
        FOR(b, B) {
            int a = b.F, i = b.S;
            LL l = 1, r = 1;
            if (i > 0 && visited[i-1]) {
                l += set.size(i-1);
                set.unite(i, i-1);
            }
            if (i < N-1 && visited[i+1]) {
                r += set.size(i+1);
                set.unite(i, i+1);
            }
            visited[i] = true;
            if (a > K)
                ans += l * r;
        }
        PL(ans);
    }
  return 0;
}