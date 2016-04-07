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

#include <unordered_set>
#include <unordered_map>
#define RL(x) scanf("%lld",&x)
#define DRL(x) LL x;RL(x)
#define PL(x) printf("%lld\n",x)

int W[16][16];
bool dp[1<<16][16];
int main() {
    int T, cas = 1;
    scanf("%d", &T);
    while(T--) {
        fprintf(stderr, "Case #%d: \n", cas);
        printf("Case #%d: \n", cas++);
        DRI(N);
        REP(i, N) REP(j, N) RI(W[i][j]);
        MS0(dp);
        REP(i, N) dp[1<<i][i] = true;
        int ans[16] = {};
        REP(i, 16) {
            ans[i] = 1;
        }
        int cnt = 0;
        REP(mask, 1<<N) {
            int p = popcount(mask);
            if (p == 2 || p == 4 || p == 8 || p == 16) {
                int sub = mask;
                do {
                    if (popcount(sub) == p / 2) {
                        cnt++;
                        REP(i, N) if (dp[sub][i]) REP(j, N) if (dp[mask ^ sub][j]) {
                            if (W[i][j]) dp[mask][i] = true;
                            else dp[mask][j] = true;
                        }
                    }
                    sub = (sub - 1) & mask;
                } while (sub + sub > mask);
                REP(i, N) {
                    if (dp[mask][i]) {
                        ans[i] = max(ans[i], p);
                    }
                }
            }
        }
        fprintf(stderr, "%d\n", cnt);
        REP(i, N) {
            if (ans[i] == N) {
                PIS(1);
            } else if (ans[i] == N / 2) {
                PIS(2);
            } else if (ans[i] == N / 4) {
                PIS(3);
            } else if (ans[i] == N / 8) {
                PIS(5);
            } else {
                assert(ans[i] == N / 16);
                PIS(9);
            }
            int a = 1;
            REP(j, N) {
                if (W[j][i]) {
                    a = N / 2 + 1;
                }
            }
            PI(a);
        }
    }
}
