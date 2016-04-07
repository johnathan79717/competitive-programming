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
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000;



int main() {
  DRI(T);
  REP(t, T) {
    DRL(N);
    DRL(K);
    vector<pair<LL,LL> > a(N);
    REP(i, N) {
        RL(a[i].F);
    }
    REP(i, N) RL(a[i].S);
    LL sum = 0;
    sort(ALL(a));
    V(LL) dp(N+1, 1e18);
    dp[0] = 0;
    REP(i, N) {
        LL task = K;
        PER1(j, i, 0) {
            task += a[j].S;
            dp[i+1] = min(dp[i+1], dp[j] + a[i].F * task);
        }
    }
    PL(dp[N]);
    // REP(i, N) {
    //     sum += a[i].F * (a[i].S + K);
    // }
    // LL ans = sum;
    // LL tasks = 0;
    // REP(i, N-1) {
    //     tasks += a[i].S;
    //     sum -= a[i].F * (a[i].S + K);
    //     sum += a[i+1].F * tasks;
    //     ans = min(ans, sum);
    // }
    // PL(ans);
  }
  return 0;
}
