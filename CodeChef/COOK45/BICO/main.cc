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
typedef unsigned long long ULL;
const int INF = 1000000000;



int main() {
  V(V(LL)) choose(50);
  REP1(i, 2, 49) {
    choose[i].PB(1);
    int k = 1;
    while(choose[i].back() < LL(1e12)) {
      choose[i].PB(choose[i].back() * (i+k) / k);
      k++;
    }
  }
  DRI(T);
  REP(t, T) {
    DRII(R, C); DRL(G);
    V(LL) ans;
    while(G) {
      // LL c = 1, k = 1;
      // while(c * (C+k) / k <= G) {
      //   c = c * (C+k) / k;
      //   k++;
      // }
      if(C == 0) {
        ans.PB(1);
        break;
      }
      if(C == 1) {
        ans.PB(G);
        break;
      }
      auto it = upper_bound(ALL(choose[C]), G);
      --it;
      G -= *it;
      ans.PB(*it);
      C--;
    }
    PI(ans.size());
    REP(i, ans.size()) {
      printf("%lld%c", ans[i], SEP(i == ans.size()-1));
    }
  }
  return 0;
}
