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



int main() {
  DRII(n, m);
  if(!n) {
    PIS(0); PI(1);
    PIS(0); PI(m);
    PIS(0); PI(0);
    PIS(0); PI(m-1);
    return 0;
  }
  if(!m) {
    PIS(1); PI(0);
    PIS(n); PI(0);
    PIS(0); PI(0);
    PIS(n-1); PI(0);
    return 0;
  }
  if(m <= n) {
    if(2 * sqrt((m-1)*(m-1) + n * n) > sqrt(m*m+n*n) + n) {
      PIS(0); PI(1);
      PIS(n); PI(m);
      PIS(0); PI(0);
      PIS(n); PI(m-1);
    } else {
      PIS(n); PI(m);
      PIS(0); PI(0);
      PIS(n); PI(0);
      PIS(0); PI(m);
    }
  } else {
    if(2 * sqrt((n-1)*(n-1) + m * m) > sqrt(m*m+n*n) + m) {
      PIS(1); PI(0);
      PIS(n); PI(m);
      PIS(0); PI(0);
      PIS(n-1); PI(m);
    } else {
      PIS(n); PI(m);
      PIS(0); PI(0);
      PIS(0); PI(m);
      PIS(n); PI(0);
    }

  }
  return 0;
}
