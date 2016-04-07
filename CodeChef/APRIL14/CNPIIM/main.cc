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

int num_factors[1250*1250];

int main() {
  for(int p = 1; p < 1250*1250; p++)
    num_factors[p] = 1;
  for(int p = 2; p < 1250*1250; p++) {
    if(num_factors[p] == 1) {
      num_factors[p] = 2;
      for(int k = p+p; k < 1250*1250; k += p) {
        int c = 1, tmp = k;
        do {
          c++;
          tmp /= p;
        } while(tmp % p == 0);
        num_factors[k] *= c;
      }
    }
  }
  for(int i = 1; i < 1250*1250; i++)
    num_factors[i] += num_factors[i-1];
  DRI(T);
  REP(t, T) {
    DRI(N);
    LL ans = 0;
    REP1(i, 1, N/2)
      ans += num_factors[i * (N-i) - 1] * 2;
    if(N % 2 == 0)
      ans -= num_factors[(N/2)*(N/2) - 1];
    PL(ans);
  }
  return 0;
}
