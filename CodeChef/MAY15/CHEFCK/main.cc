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
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
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
#define F first
#define S second
#define V(x) vector<x >

int popcount(unsigned x) { return __builtin_popcount(x); } 
int popcount(unsigned long long x) { return __builtin_popcountll(x); } 

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

LL A[20000001];

int main() {
    DRL(N); DRL(K); DRL(Q);
    DRL(a); DRL(b); DRL(c); DRL(d); DRL(e); DRL(f);
    DRL(r); DRL(s); DRL(t); DRL(m);
    RL(A[1]);
    LL tx = t;
    REP1(x, 2, N) {
        tx = tx * t % s;
        if (tx <= r) {
            A[x] = ((a * A[x-1] + b) % m * A[x-1] + c) % m;
        } else {
            A[x] = ((d * A[x-1] + e) % m * A[x-1] + f) % m;
        }
    }
    // A[1] = 4, A[2] = 3, A[3] = 2, A[4] = 1;
    // K = 3;
    LL l = 1;
    while (l * 2 <= K) {
        REP1(i, 1, N-l) {
            A[i] = min(A[i], A[i+l]);
        }
        l *= 2;
    }
    assert(l <= K && l + l >= K);
    REP1(i, 1, N - K + 1) {
        A[i] = min(A[i], A[i + K - l]);
    }
    DRL(L1); DRL(La); DRL(Lc); DRL(Lm);
    DRL(D1); DRL(Da); DRL(Dc); DRL(Dm);
    LL sum = 0, product = 1;
    while (Q--) {
        L1 = (La * L1 + Lc) % Lm;
        D1 = (Da * D1 + Dc) % Dm;
        LL L = L1 + 1, R = min(L + K - 1 + D1, N);
        // L = 1, R = 3;
        assert(R - L + 1 >= K && R - L + 1 <= 2*K);
        // int v = INT_MAX;
        // REP1(i, L, R) {
        //     v = min(v, A[i]);
        // }
        // assert(L + l >= R - l + 1);
        LL v = min(A[L], A[R - K + 1]);
        sum += v;
        product = product * v % 1000000007;
    }
    printf("%lld %lld\n", sum, product);
    return 0;
}