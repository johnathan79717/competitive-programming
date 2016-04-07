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

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 2000000000;

LL bit[101][101][101];

int N;

void add(int x, int y, int z, LL w) {
  for(int i = x; i <= N; i += i & -i)
    for(int j = y; j <= N; j += j & -j)
      for(int k = z; k <= N; k += k & -k)
        bit[i][j][k] += w;
}

LL sum(int x, int y, int z) {
  LL ans = 0;
  for(int i = x; i > 0; i &= i - 1)
    for(int j = y; j > 0; j &= j - 1)
      for(int k = z; k > 0; k &= k - 1)
        ans += bit[i][j][k];
  return ans;
}

LL sum(int x1, int y1, int z1, int x2, int y2, int z2) {
  x1--; y1--; z1--;
  return sum(x2, y2, z2) - sum(x1, y2, z2) - sum(x2, y1, z2) - sum(x2, y2, z1)
  + sum(x1, y1, z2) + sum(x1, y2, z1) + sum(x2, y1, z1) - sum(x1, y1, z1);
}

LL query(int x, int y, int z) {
  return sum(x, y, z, x, y, z);
}

int main() {
  DRI(T);
  while(T--) {
    MS0(bit);
    RI(N); DRI(M);
    while(M--) {
      char str[10];
      RS(str);
      if(str[0] == 'U') {
        DRIII(x, y, z); DRL(W);
        add(x, y, z, W - query(x, y, z));
      } else {
        DRIII(x1, y1, z1); DRIII(x2, y2, z2);
        PL(sum(x1, y1, z1, x2, y2, z2));
      }
    }
  }
  return 0;
}