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
#define V(x) vector<x>

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

V(VI) adj;

const int M = 100004;
LL dp1[M], dp2[M], dp3[M], dp4[M];
VI A;

void dfs(int v, int p) {
    dp1[v] = A[v];
    vector<pair<LL,int>> a1, a2, a3;
    int k = 0;
    for (int c: adj[v]) {
        if (c != p) {
            k++;
            dfs(c, v);
            MAX(dp1[v], dp1[c] + A[v]);
            MAX(dp2[v], dp2[c]);
            MAX(dp3[v], dp3[c] + A[v]);
            MAX(dp4[v], dp4[c]);
            a1.EB(dp1[c], c);
            a2.EB(dp2[c], c);
            a3.EB(dp3[c], c);
        }
    }
    auto comp = greater<pair<LL,int>>();
    sort(ALL(a1), comp);
    sort(ALL(a2), comp);
    sort(ALL(a3), comp);
    if (k > 1) {
        MAX(dp2[v], a1[0].X + a1[1].X + A[v]);
        MAX(dp4[v], a2[0].X + a2[1].X);
    }
    REP(i, min(3, k)) {
        REP(j, k) {
            if (a1[i].Y != a2[j].Y) {
                MAX(dp3[v], a1[i].X + a2[j].X + A[v]);
                break;
            }
        }
        REP(j, k) {
            if (a1[i].Y != a3[j].Y) {
                MAX(dp4[v], a1[i].X + a3[j].X + A[v]);
            }
        }
        LL s = 0, l = 0;
        REP(j, k) {
            if (a1[j].Y != a2[i].Y) {
                s += a1[j].X;
                if (++l == 2) break;
            }
        }
        MAX(dp4[v], a2[i].X + s + A[v]);
    }

    MAX(dp2[v], dp1[v]);
    MAX(dp3[v], dp2[v]);
    MAX(dp4[v], dp3[v]);
}

int main() 
{
    DRI(N);
    adj = V(VI)(N);
    A = VI(N);
    REP(i, N) RI(A[i]);
    REP(i, N-1) {
        DRI(u, v);
        u--; v--;
        adj[u].PB(v);
        adj[v].PB(u);
    }
    dfs(0, -1);
    cout << dp4[0] << endl;
}

