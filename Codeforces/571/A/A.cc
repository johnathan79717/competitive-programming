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

int main() 
{
    DRI(a, b, c);
    DRI(L);
    LL ans = 0;
    REP1(l, 0, L) {
        LL Z = min(l, (a + b + l - c + 1) / 2-1);
        LL Y = min(l, (a + c - b + l + 1) / 2-1);
        LL X = min(l, (b+c-a+l+1) / 2-1);
     //   cout << X << ' ' << Y << ' ' << Z << endl;
        if (X < 0 || Y < 0 || Z < 0) {
            continue;
        }
        // 0 <= x <= X, 0 <= y <= Y, l - Z <= x + y <= l
        if (X < Y) swap(X, Y);
        LL m = l - Z, M = l;
        if (M <= Y) {
            ans += (M+1)*(M+2)/2 - m * (m+1) / 2;
        } else if (m >= X) {
            ans += (X+Y-m+1)*(X+Y-m+2)/2 - (X+Y-M)*(X+Y-M+1)/2;
        } else {
            ans += (X+1) * (Y+1);
            if (m <= Y) {
                ans -= m * (m+1) / 2;
            } else {
                ans -= (m+m-Y)*(Y+1)/2;
            }
            if (M >= X) {
                ans -= (X+Y-M)*(X+Y-M+1)/2;
            } else {
                ans -= (X-M+X-M+Y)*(Y+1)/2;
            }
        }
    //cout << ans << endl;
    }
    cout << ans << endl;
}

