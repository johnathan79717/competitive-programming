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

char S[100001];
int d[100001];

int main() {
  RS(S);
  int N = strlen(S);
  REP(i, N) {
    S[i] -= '0';
  }
  REP(i, N) d[i] = INF;
  d[0] = 0;
  REP1(i, 1, N-1)
    if(S[i] == S[0])
      d[i] = 1;
  REP(l, 20) {
    REP(i, N) {
      if(d[i] == l) {
        if(i > 0) {
          if(d[i-1] == INF) {
            REP(j, N)
              if(S[j] == S[i-1])
                d[j] = min(d[j], l+2);
          }
          d[i-1] = min(d[i-1], l+1);
        }
        if(i+1 < N) {
          if(d[i+1] == INF) {
            REP(j, N)
              if(S[j] == S[i+1])
                d[j] = min(d[j], l+2);
          }
          d[i+1] = min(d[i+1], l+1);
        }
      }
    }
  }
  PI(d[N-1]);
  return 0;
}
