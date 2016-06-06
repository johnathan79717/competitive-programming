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
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <deque>
#include <stack>
#include <functional>
#define X first
#define Y second
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
#define CASET int ___T; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define FOR(i,c) for(auto &i: c)
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI1(x) scanf("%d",&x)
#define RI2(x,y) RI1(x), RI1(y)
#define RI3(x,y...) RI1(x), RI2(y)
#define RI4(x,y...) RI1(x), RI3(y)
#define RI5(x,y...) RI1(x), RI4(y)
#define RI6(x,y...) RI1(x), RI5(y)
#define GET_MACRO(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define RI(argv...) GET_MACRO(argv, RI6, RI5, RI4, RI3, RI2, RI1)(argv)
#define DRI(argv...) int argv;RI(argv)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define DRL(x) LL x; RL(x)
#ifdef ONLINE_JUDGE
    #define PL(x) printf("%I64d\n",x)
    #define RL(x) scanf("%I64d\n",&x)
#else
    #define PL(x) printf("%lld\n",x)
    #define RL(x) scanf("%lld\n",&x)
#endif
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define DRA(A, N) VI A(N); REP(i, N) RI(A[i])
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;
template<typename T>
using V = std::vector<T>;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;

int main() 
{
    DRI(N, A, cf, cm);
    DRL(m);
    V<PII> a(N);
    REP(i, N) {
        RI(a[i].first);
        a[i].second = i;
    }
    sort(ALL(a));
    V<LL> b(N);
    LL sum = 0;
    REP(i, N) {
        sum += a[i].first;
        b[i] = a[i].first * (i+1ll) - sum;
    }
    LL ans = -1;
    if (A * 1ll * N - sum <= m) {
        PL(N * 1ll * cf + A * 1ll * cm);
        REP(i, N) PIS(A);
        puts("");
        return 0;
    }
    sum = 0;
    int i1 = -1, i2 = -1;
    int tt;
    REP(i, N) {
        if (m < sum) break;
        int j = upper_bound(b.begin(), b.begin() + N - i, m - sum) - b.begin() - 1;
        assert(j >= 0);
        assert(b[j] <= m - sum);
        LL t = a[j].first + (m - sum - b[j]) / (j+1);
        LL tmp = i * 1ll * cf + (t) * cm;
        if (tmp > ans) {
            tt = t;
            i1 = j;
            i2 = N - i;
            ans = tmp;
        }
        sum += A - a[N-1-i].first;
    }
    assert(i1 >= 0 && i2 >= 0);
    PL(ans);
    VI aa(N);
    REP1(i, 0, i1) {
        aa[a[i].second] = tt;
    }
    REP1(i, i1+1, i2-1) {
        aa[a[i].second] = a[i].first;
    }
    REP1(i, i2, N-1) {
        aa[a[i].second] = A;
    }
    REP(i, N) {
        PIS(aa[i]);
    }
    puts("");
}


