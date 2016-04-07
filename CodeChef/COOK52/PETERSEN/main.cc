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
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <sstream>
#include <bitset>
using namespace std;
#define BG begin()
#define ED end()
#define FOR(i,c) for(auto &i: c)
#define SZ size()
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
#define LB lower_bound
#define UB upper_bound
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
// #define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000;

char S[100005];
bool adj[10][10];
char letter[] = "ABCDEABCDE";
char ans[100005];

bool check(char *S, int v) {
    ans[0] = v + '0';
    for (int i = 1; S[i]; i++) {
        if (adj[v][S[i] - 'A'] || adj[S[i] - 'A'][v]) {
            v = S[i] - 'A';
        } else if (adj[v][S[i] - 'A' + 5] || adj[S[i] - 'A' + 5][v]) {
            v = S[i] - 'A' + 5;
        } else {
            return false;
        }
        ans[i] = v + '0';
    }
    return true;
}

int main() {
    adj[0][1] = adj[1][2] = adj[2][3] = adj[3][4] = adj[4][0] = adj[0][5] = adj[1][6] = adj[2][7] = adj[3][8] = adj[4][9] = adj[5][7] = adj[7][9] = adj[9][6] = adj[6][8] = adj[8][5] = true;
    DRI(T);
    REP(t, T) {
        RS(S);
        MS0(ans);
        if (check(S, S[0] - 'A') || check(S, S[0] - 'A' + 5)) {
            puts(ans);
        } else {
            puts("-1");
        }
    }
    return 0;
}
