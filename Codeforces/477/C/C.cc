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
using namespace std;
#define FOR(i,c) for(auto i=(c).begin();i!=(c).end();i++)
#define SZ size()
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

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

char s[2001], p[501];
// bool match[2001];
// int dp[2001][2001];

int main() {
  RS(s); RS(p);
  int S = strlen(s), P = strlen(p);
  // REP(i, S) {
  //   if (strcmp(s+i, p) == 0) {
  //     match[i] = true;
  //   }
  // }
  V(VI) dp(S+1, VI(S+1, -INF));
  dp[S][0] = 0;
  PER(i, S) {
    REP1(j, 0, S) {
      dp[i][j] = dp[i+1][j];
    }
    REP(j, S)
      dp[i][j+1] = max(dp[i][j+1], dp[i+1][j]);
    int pp = 0, ss = i;
    while(pp < P) {
      while(ss < S && s[ss] != p[pp]) {
        ss++;
      }
      if (ss == S) {
        break;
      }
      ss++;
      pp++;
    }
    if (pp == P) {
      REP1(j, ss-i-P, S)
        dp[i][j] = max(dp[i][j], 1 + dp[ss][j-(ss-i-P)]);
    }
    // if (strncmp(s + i, p, P) == 0) {
    // }
  }
  REP1(i, 0, S) {
    if (i < S)
      PIS(dp[0][i]);
    else
      PI(dp[0][i]);
  }
  return 0;
}
