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
template<typename T>
using V = std::vector<T>;
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

const double pi = acos(-1);

int main() 
{
    DRI(N);
    VI x(N), y(N);
    REP(i, N) {
        RI(x[i], y[i]);
    }
    VI a(N);
    REP(i, N) a[i] = i;
    sort(ALL(a), [&y,&x](int i, int j) {
        if (y[i] == 0 && x[i] > 0) {
            return true;
        }
        if (y[j] == 0 && x[j] > 0) {
            return false;
        }
        if (y[i] * y[j] < 0) {
            return y[i] > y[j];
        }
        return y[i] * x[j] < x[i] * y[j];
    });
    //REP(i, N) {
        //PIS(a[i]);
    //}
    //puts("");
    int ansi = 0, ansj = 1;
    a.PB(a[0]);
    REP(i, N) {
        LL q1 = x[a[i]]*x[a[i+1]] + y[a[i]]*y[a[i+1]], q2 = x[ansi]*x[ansj] + y[ansi]*y[ansj];
        LL p2 = (x[ansi]*x[ansi]+y[ansi]*y[ansi]) * 1ll * (x[ansj]*x[ansj]+y[ansj]*y[ansj]);
        LL p1 = (x[a[i]]*x[a[i]]+y[a[i]]*y[a[i]]) * 1ll * (x[a[i+1]]*x[a[i+1]]+y[a[i+1]]*y[a[i+1]]);
        //if (N == 6) {
            //PIS(a[i]); PIS(a[i+1]); PIS(ansi); PI(ansj);
            //PL(q1);
            //PL(q2);
        //}
        if (q1 * q2 <= 0) {
            if (q1 >= q2) {
                ansi = a[i];
                ansj = a[i+1];
            }
        } else {
            bool rev = false;
            if (q1 < 0) rev = true;
            q1 *= q1;
            q2 *= q2;
            auto mul = [](unsigned long long a, unsigned long long b) {
                pair<unsigned long long, unsigned long long> ans(0, 0);
                REP(i, 64) {
                    if (b & (1ll<<i)) {
                        ans.Y += (a << i);
                        if (i != 0)
                            ans.X += (a >> (64-i));
                    }
                }
                return ans;
            };
            auto pr1 = mul(q1, p2), pr2 = mul(q2, p1);
            //fprintf(stderr, "%lld %lld %lld %lld\n", q1, p2, pr1.X, pr1.Y);
            //fprintf(stderr, "%lld %lld %lld %lld\n", q2, p1, pr2.X, pr2.Y);
            if ((pr1 >= pr2) != rev) {
                ansi = a[i];
                ansj = a[i+1];
            }
        }
    }
    PIS(ansi+1); PI(1+ansj);
}

