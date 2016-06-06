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
#include <cassert>
using namespace std;
#define FOR(i,c) for(auto &i: c)
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
#define LB lower_bound
#define UB upper_bound
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
const int INF = 1000000000;

int small[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

// #define MAX_P 1000
// bool isprime[MAX_P];

// void Eratosthenes() {
//   memset(isprime, true, sizeof isprime);
//   for(int i = 2; i < MAX_P; i++)
//     if(isprime[i]) {
//       if((LL)i*i < MAX_P) 
//         for(int j = i*i; j < MAX_P; j+=i)
//           isprime[j] = false;
//     }
// }

int geti(int p) {
  return lower_bound(small, small + sizeof small / sizeof(int), p) - small;
}

VI primes(int n) {
  VI ans;
  for(int p = 2; p * p <= n; p++) {
    if(n % p != 0) continue;
    ans.PB(geti(p));
    do n /= p; while(n % p == 0);
  }
  if(n > 1) ans.PB(geti(n));
  return move(ans);
}

pair<int, PII> dp[101][1<<16];

int main() {
  // Eratosthenes();
  REP(i, 101) REP(j, 1<<16) dp[i][j] = MP(INF, MP(-1, -1));
  DRI(n);
  VI a(n);
  // VI prev(1 << 16, INF), next = prev;
  // vector<vector<pair<int, PII>>> dp(n+1, vector<pair<int, PII>>(1 << 16, MP(INF, MP(-1, -1))));
  // prev[0] = 0;
  dp[0][0] = MP(0, MP(-1, -1));
  V(VI) ps(59);
  REP1(i, 1, 58) {
    ps[i] = move(primes(i));
    // FOR(p, ps[i]) PIS(p);
    // puts("");
  }
  REP(i, n) {
    DRI(a);
    REP(k, 1 << 16) {
      if(dp[i][k].first == INF) continue;
      REP1(j, 1, 58) {
        bool fail = false;
        int kk = k;
        FOR(g, ps[j]) {
          if(k & (1 << g)) {
            fail = true;
            break;
          }
          kk |= (1 << g);
        }
        if(fail) continue;
        dp[i+1][kk] = min(dp[i+1][kk], MP(dp[i][k].first + abs(j - a), MP(j, k)));
      }
    }
    // prev = next;
    // next = VI(1 << 16, INF);
  }
  stack<int> ans;
  int mink = 0;
  REP(k, 1 << 16) {
    if(dp[n][k] < dp[n][mink]) mink = k;
  }
  PER1(i, n, 1) {
    ans.push(dp[i][mink].second.first);
    mink = dp[i][mink].second.second;
  }
  while(!ans.empty()) {
    PIS(ans.top());
    ans.pop();
  }
  puts("");
  return 0;
}
