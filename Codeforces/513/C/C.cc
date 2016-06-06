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

int main() 
{
    DRI(n);
    VI L(n), R(n);
    REP(i, n) {
        RII(L[i], R[i]);
    }
    double ans = 0;
    REP1(b, 1, 10000) {
        double total = 0;
        REP(mask, 1 << n) {
            if (!mask) continue;
            int cnt = 0;
            REP(i, n) {
                if ((mask >> i) & 1) {
                    cnt++;
                }
            }
            if (cnt >= 2) {
                double ways = 1;
                REP(i, n) {
                    if ((mask >> i) & 1) {
                        ways *= (L[i] <= b && b <= R[i]);
                    } else {
                        ways *= max(0, min(R[i], b-1) - L[i] + 1);
                    }
                }
                total += ways;
            }
            REP(j, n) {
                if ((mask >> j) & 1) {
                    continue;
                }
                double ways = max(0, R[j] - max(b+1, L[j]) + 1);
                REP(i, n) {
                    if (i == j) continue;
                    if ((mask >> i) & 1) {
                        ways *= (L[i] <= b && b <= R[i]);
                    } else {
                        ways *= max(0, min(R[i], b-1) - L[i] + 1);
                    }
                }
                total += ways;
            }
        }
        ans += total * b;
    }
    REP(i, n) {
        ans /= (R[i] - L[i] + 1);
    }
    printf("%.10f\n", ans);
}

