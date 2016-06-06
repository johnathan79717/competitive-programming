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
#include <deque>
#include <stack>
#include <cassert>
#include <functional>
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
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
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

int pp[101];
double dp[201][30][30];

int main() 
{
    DRII(N, K);
    VI p(N);
    REP(i, N) {
        RI(p[i]);
    }
    REP(i, N) {
        REP(j, i) {
            if (p[j] > p[i]) {
                dp[0][i][j] = 1;
            }
        }
    }
    REP1(k, 1, K) {
        REP(i, N) {
            REP(j, i) {
                dp[k][i][j] = 0;
                REP(r, N) {
                    REP(l, r+1) {
                        int ii = (l <= i && i <= r) ? r + l - i : i, jj = (l <= j && j <= r) ? r + l - j : j;
                        if (ii > jj)
                            dp[k][i][j] += dp[k-1][ii][jj];
                        else
                            dp[k][i][j] += 1 - dp[k-1][jj][ii];
                    }
                }
                dp[k][i][j] /= (N * (N+1) / 2);
            }
        }
    }
    double ans = 0;
    REP(i, N) {
        REP(j, i) {
            ans += dp[K][i][j];
        }
    }
    printf("%.10f\n", ans);
}

