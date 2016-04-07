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
typedef long long LL;
typedef double LD;
typedef unsigned long long ULL;
const int INF = 1000000000;

// VI A, C;
// int n, k;

LD choose[21][21];

int main() {
  REP(i, 21) choose[i][0] = 1;
  REP1(i, 1, 20) REP1(j, 1, i) {
    choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
  }
  DRI(T);
  REP(t, T) {
    DRII(n, k);
    VI cnt(n+1);
    // A.clear(); C.clear();
    // A.resize(n); C.resize(n);
    VI A(n), C(n);
    LD ans = 0;
    REP(i, n) {
      RII(A[i], C[i]);
      cnt[C[i]]++;
      if(A[i] > k)
        ans += A[i] - k;
    }
    // REP1(i, 1, n) ans /= i;
    REP1(c, 1, n) {
      if(cnt[c] == 2) {
        V(V(LD)) dp(n-1, V(LD)(k));
        dp[0][0] = 1;
        int a1 = 0, a2 = 0;
        REP(i, n) {
          if(C[i] == c) {
            if(!a1) a1 = A[i];
            else a2 = A[i];
            continue;
          }
          PER(j, n-2) REP(s, k-A[i]) {
            dp[j+1][s+A[i]] += dp[j][s];
          }
        }
        int a = min(a1, a2);
        REP(j, n-1) {
          REP1(s, max(0, k+1-a1-a2), k-1) {
            if(dp[j][s] == 0) continue;
            ans += 2 * dp[j][s] * min(min(a1+a2+s-k, k-s), a) / (n-j) / choose[n][j];
          }
        }
      }
    }
    printf("%.07lf\n", ans);
  }
  return 0;
}
