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
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef unsigned long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000;

struct Balloon {
  int C, P;
};

int main() {
  DRI(T);
  REP(t, T) {
    DRII(N, M);
    V(Balloon) b(N);
    REP(i, N) RII(b[i].C, b[i].P);
    sort(ALL(b), [](const Balloon& b1, const Balloon& b2) {return b1.C < b2.C;});
    V(V(V(LL))) dp(N+1, V(V(LL))(M+1, V(LL)(2, 0)));
    V(V(V(LL))) cnt(N+1, V(V(LL))(M+1, V(LL)(2, 0)));
    cnt[0][0][0] = 1;
    REP(i, N) {
      REP1(j, 0, M) {
        dp[i+1][j][0] += dp[i][j][0];
        cnt[i+1][j][0] += cnt[i][j][0];
        bool same = (i+1<N && b[i].C == b[i+1].C);
        dp[i+1][min(j+1, M)][same] += (dp[i][j][0] + cnt[i][j][0] * b[i].P);
        cnt[i+1][min(j+1, M)][same] += cnt[i][j][0];
        dp[i+1][j][same] += (dp[i][j][1] * 2 + cnt[i][j][1] * b[i].P);
        cnt[i+1][j][same] += cnt[i][j][1] * 2;
      }
    }
    // PL(dp[N][M][0]);
    // PL(cnt[N][M][0]);
    printf("%.9LF\n", (long double)dp[N][M][0] / cnt[N][M][0]);
  }
  return 0;
}
