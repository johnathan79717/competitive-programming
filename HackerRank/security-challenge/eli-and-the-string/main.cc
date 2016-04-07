#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;
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
#define RL(x) scanf("%lld",&x)
#define DRI(x) int x;RI(x)
#define DRL(x) LL x;RL(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PL(x) printf("%lld\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define PQ priority_queue
#define E emplace
#define EB emplace_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#define V(x) vector<x >
#define MAX(x, a) x = max(x, a);
#define MIN(x, a) x = min(x, a);

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 2000000000;

char s[2000];
int cost[26][26];
pair<int, int> dp[2000][26];

int main() {
    DRI(T);
    while(T--) {
        RS(s);
        int N = LEN(s);
        REP(i, 26) REP(j, 26) RI(cost[i][j]);
        REP(i, 2000) REP(j, 26) dp[i][j].F = INF;
        REP(j, 26) dp[N-1][j].F = cost[s[N-1]-'a'][j];
        PER(i, N-1) {
            REP(j, 26) {
                REP(k, j+1) {
                    MIN(dp[i][k], MP(dp[i+1][j].F + cost[s[i]-'a'][k], j));
                }
            }
        }
        int best = 0;
        REP(j, 26) {
            if (dp[0][j] < dp[0][best]) {
                best = j;
            }
        }
        PIS(dp[0][best].F);
        REP(i, N) {
            printf("%c", best + 'a');
            best = dp[i][best].S;
        }
        puts("");
    }
  return 0;
}