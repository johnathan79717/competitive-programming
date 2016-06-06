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
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
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
#define GET_4TH(_1, _2, _3, NAME, ...) NAME
#define RI(argv...) GET_4TH(argv, RI3, RI2, RI1)(argv)
#define RI1(x) scanf("%d",&x)
#define RI2(x,y) RI1(x), RI1(y)
#define RI3(x,y,z) RI1(x), RI2(y, z)
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
#define V(x) vector<x>
#define DRA(A, N) VI A(N); REP(i, N) RI(A[i])
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

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

V(LL) s;

bool check1(bool inv, int i1, int i2, int i3) {
    LL a1 = -i1, b1 = s[i1];
    LL a2 = -i2, b2 = s[i2];
    LL a3 = -i3, b3 = s[i3];
    return ((a2 - a1) * (b3 - b2) >= (b2 - b1) * (a3 - a2)) == inv;
}

double intersection(int i, int j) {
    // s[i] - i*x = s[j] - j*x
    return (s[i] - s[j]) * 1.0 / (i-j);
}

double eval(int i, double x) {
    return s[i] - i * x;
}

int main() 
{
    DRI(N);
    s = V(LL)(N+1);
    REP(i, N) {
        DRI(a);
        s[i+1] = s[i] + a;
    }
    deque<int> top, bottom;
    PER1(i, N, 0) {
        int L = SZ(top);
        while (L >= 2 && check1(true, top[L-2], top[L-1], i)) {
            top.pop_back();
            L = SZ(top);
        }
        top.push_back(i);
    }

    REP1(i, 0, N) {
        int L = SZ(bottom);
        while (L >= 2 && check1(true, bottom[L-2], bottom[L-1], i)) {
            bottom.pop_back();
            L = SZ(bottom);
        }
        bottom.push_back(i);
    }

    double ans = 1e18;
    int i = 0, j = 0;
    while (i+1<SZ(top) && j+1<SZ(bottom)) {
        double x1 = intersection(top[i], top[i+1]);
        double x2 = intersection(bottom[j], bottom[j+1]);
        double x;
        if (x1 < x2) {
            i++;
            x = x1;
        } else {
            j++;
            x = x2;
        }
        ans = min(ans, eval(top[i], x) - eval(bottom[j], x));
    }
    printf("%.15f\n", ans);
}


