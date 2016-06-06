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

#define DRL(x) LL x; RL(x)
#ifdef ONLINE_JUDGE
    #define PL(x) printf("%I64d\n",x)
    #define RL(x) scanf("%I64d\n",&x)
#else
    #define PL(x) printf("%lld\n",x)
    #define RL(x) scanf("%lld\n",&x)
#endif

int dp[20001][101];

int main() {
#ifdef CPP11
    static_assert(false, "CPP11");
#endif
    CASET {
        DRI(N, K);
        VI d(N+1), a(N+1), r(N+1), b(N+1);
        REP1(i, 2, N) {
            RI(d[i]);
            d[i] += d[i-1];
        }
        REP1(i, 1, N) {
            RI(a[i], r[i], b[i]);
        }
        REP(i, N+1) REP(j, K+1) dp[i][j] = 2e9+1;
        dp[0][0] = 0;
        vector<priority_queue<PII,vector<PII>,greater<PII> > > pq(K+1);
        REP1(i, 1, N) {
            int ll = lower_bound(d.begin()+1, d.end(), d[i] - r[i]) - d.begin() - 1;
            int rr = upper_bound(d.begin()+1, d.end(), d[i] + r[i]) - d.begin() - 1;
            assert(ll < i && rr >= i);
            PER(j, K+1) {
                if (j < K) {
                    //mini(dp[rr][j+1], dp[ll][j] + a[i]);
                    pq[j+1].push(MP(dp[ll][j] + a[i], rr));
                }
                mini(dp[i][j], dp[i-1][j] + b[i]);
            }
            PER(j, K+1) {
                while (pq[j].size() && pq[j].top().second < i) {
                    pq[j].pop();
                }
                if (pq[j].size()) {
                    mini(dp[i][j], pq[j].top().first);
                }
            }
        }
        int ans = INT_MAX;
        REP(j, K+1) {
            mini(ans, dp[N][j]);
        }
        PI(ans);
    }
    return 0;
}
