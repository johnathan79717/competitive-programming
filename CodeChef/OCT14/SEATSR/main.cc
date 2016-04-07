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

char str[2][100001];

int main() {
  DRI(T);
  REP(t, T) {
    RS(str[0]);
    RS(str[1]);
    DRIII(a, b, k);
    if(!a) {
      PI(0);
      continue;
    }
    char *s = str[0], *w = str[1];
    int m = strlen(s), n = strlen(w);
    if (m > n) {
      swap(s, w);
      swap(m, n);
    }
    VI next(n+1, 1e9), prev = next;
    int i = 0;
    REP1(j, max(0, i + n - m - k), min(n, i + k)) {
      prev[j] = a * j;
    }
    REP1(i, 1, m) {
      REP1(j, max(0, i + n - m - k), min(n, i + k)) {
        next[j] = prev[j] + a;
        if (j > 0) {
          next[j] = min(next[j], prev[j-1] + (s[i-1] == w[j-1] ? 0 : b));
          if (j > max(0, i + n - m - k))
            next[j] = min(next[j], next[j-1] + a);
        }
      }
      swap(prev, next);
      // REP1(j, 0, n) {
      //   PIS(prev[j]);
      // }
      // puts("");
    }
    if (prev[n] <= k)
      cout << prev[n] << endl;
    else
      PI(-1);
  }
  return 0;
}
