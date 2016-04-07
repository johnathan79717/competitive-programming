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
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
#define ALL(x) (x).begin(),(x).end()
#define CASET2 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d:\n", case_n++) : 0), ___T-- > 0)
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
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
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define X first
#define Y second
#define V(x) vector<x >
#define PV(v) REP(i, SZ(v)) if(i < SZ(v)-1) PIS(v[i]); else PI(v[i]);

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(unsigned x) { return __builtin_popcount(x); } 
int popcount(unsigned long long x) { return __builtin_popcountll(x); } 

typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

#include <unordered_set>
#include <unordered_map>
#define PL(x) printf("%lld\n",x)
#define EB emplace_back
#define RL(x) scanf("%lld",&x)
#define DRL(x) LL x;RL(x)


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

bool visit[1000001];

int main() {
//    DRI(T);
//    while(T--) {
        DRI(N, M);
        VI A(N);
        priority_queue<PII,vector<PII>,greater<PII>> pq;
        REP(i, N) {
            RI(A[i]);
            pq.emplace(A[i], i);
        }
        sort(ALL(A));
        A.resize(unique(ALL(A)) - A.begin());
        MS0(visit);
        DisjointSet ds(N);
        V(LL) cnt(SZ(A)), less(SZ(A)), greater(SZ(A));
        while (SZ(pq)) {
            int a = pq.top().X, i = pq.top().Y;
            pq.pop();
            visit[i] = true;
            LL l = 1, r = 1;
            if (i > 0 && visit[i-1]) {
                l += ds.size(i-1);
                ds.unite(i, i-1);
            }
            if (i+1 < N && visit[i+1]) {
                r += ds.size(i+1);
                ds.unite(i, i+1);
            }
            cnt[lower_bound(ALL(A), a) - A.begin()] += l * r;
        }
        less[0] = cnt[0];
        REP(i, SZ(A)-1) {
            less[i+1] = less[i] + cnt[i+1];
        }
        greater[SZ(A)-1] = cnt[SZ(A)-1];
        PER(i, SZ(A)-1) {
            greater[i] = cnt[i] + greater[i+1];
        }
        while (M--) {
            char c[2], x[2];
            RS(c); DRI(K); RS(x);
            int p = 0;
            if (c[0] == '=') {
                int i = lower_bound(ALL(A), K) - A.begin();
                if (A[i] == K) {
                    p = cnt[i] % 2;
                }
            } else if (c[0] == '<') {
                int i = lower_bound(ALL(A), K) - A.begin() - 1;
                if (i >= 0) {
                    p = less[i] % 2;
                }
            } else {
                int i = upper_bound(ALL(A), K) - A.begin();
                if (i < N) {
                    p = greater[i] % 2;
                }
            }
            if (!p) {
                x[0] ^= ('C'^'D');
            }
            printf("%c", x[0]);
        }
        puts("");
//    }
    return 0;
}
