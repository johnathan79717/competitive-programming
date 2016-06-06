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
#ifdef ONLINE_JUDGE
    #define PL(x) printf("%I64d\n",x);
#else
    #define PL(x) printf("%lld\n",x)
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

int mp1[1000005], mp2[1000005];



int main() 
{
    MS1(mp1); MS1(mp2);
    DRI(m);
    DRI(h1, a1); DRI(x1, y1);
    DRI(h2, a2); DRI(x2, y2);
    int h = h1;
    int i = 0;
    while (mp1[h] < 0) {
        mp1[h] = i++;
        h = ((LL)h * x1 + y1) % m;
    }
    if (mp1[a1] < 0) {
        PI(-1);
        return 0;
    }
    LL d1 = mp1[a1]; int c1 = i - mp1[h];
    if (mp1[a1] < mp1[h]) {
        c1 = 0;
    }

    h = h2;
    i = 0;
    while (mp2[h] < 0) {
        mp2[h] = i++;
        h = ((LL)h * x2 + y2) % m;
    }
    if (mp2[a2] < 0) {
        PI(-1);
        return 0;
    }
    LL d2 = mp2[a2]; int c2 = i - mp2[h];
    if (mp2[a2] < mp2[h]) {
        c2 = 0;
    }
    if (d1 == d2) {
        PL(d1);
        return 0;
    }

    if (c1 == 0 && c2 == 0) {
        PI(-1);
        return 0;
    }

    if (abs(d1 - d2) % __gcd(c1, c2) != 0) {
        PI(-1);
        return 0;
    }

    if (c1 == 0) {
        if (d1 > d2) {
            PL(d1);
        } else {
            PI(-1);
        }
        return 0;
    }

    if (c2 == 0) {
        if (d2 > d1) {
            PL(d2);
        } else {
            PI(-1);
        }
        return 0;
    }

    while (d1 != d2) {
        if (d1 < d2) {
            d1 += c1;
        } else {
            d2 += c2;
        }
    }
    PL(d1);
}

