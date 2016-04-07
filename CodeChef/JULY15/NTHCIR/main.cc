#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <iomanip>
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
#define RL1(x) scanf("%lld",&x)
#define RL2(x,y) RL1(x), RL1(y)
#define RL3(x,y...) RL1(x), RL2(y)
#define RL4(x,y...) RL1(x), RL3(y)
#define RL5(x,y...) RL1(x), RL4(y)
#define RL6(x,y...) RL1(x), RL5(y)
#define RL(argv...) GET_MACRO(argv, RL6, RL5, RL4, RL3, RL2, RL1)(argv)
#define DRI(argv...) int argv;RI(argv)
#define DRL(argv...) LL argv;RL(argv)
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

typedef double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

#include <unordered_set>
#include <unordered_map>
#define PL(x) printf("%lld\n",x)
#define EB emplace_back

LD k[5];

int main() {
    DRI(T);
    DRL(N, P, M, B);
    REP1(i, 1, 4) {
        double R;
        cin >> R;
        k[i] = 1 / R;
    }
    LD a = 2 * (k[2] - k[1]);
    LD ans = 0;
    while(T--) {
        N = (P * N) % M + B;
        if (N <= 4) {
            ans += 1 / k[N];
        } else {
            LL n = N - 4;
            ans += 1 / ((n + 1) * k[4] - n * k[3] + n * (n + 1) / 2 * a);
        }
    }
    printf("%.6f\n", ans);
    return 0;
}