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
  V(VI) a(n, VI(m));
  V(V(LL)) tl(n, V(LL)(m));
  REP(i, n) REP(j, m) {
    RI(a[i][j]);
    tl[i][j] = a[i][j];
  }
  V(V(LL)) tr = tl;
  V(V(LL)) bl = tl;
  V(V(LL)) br = tl;
  REP(i, n) REP(j, m) {
    if(i > 0) tl[i][j] = max(tl[i][j], a[i][j] + tl[i-1][j]);
    if(j > 0) tl[i][j] = max(tl[i][j], a[i][j] + tl[i][j-1]);
  }
  REP(i, n) PER(j, m) {
    if(i > 0) tr[i][j] = max(tr[i][j], a[i][j] + tr[i-1][j]);
    if(j+1<m) tr[i][j] = max(tr[i][j], a[i][j] + tr[i][j+1]);
  }
  PER(i, n) REP(j, m) {
    if(i+1<n) bl[i][j] = max(bl[i][j], a[i][j] + bl[i+1][j]);
    if(j > 0) bl[i][j] = max(bl[i][j], a[i][j] + bl[i][j-1]);
  }
  PER(i, n) PER(j, m) {
    if(i+1<n) br[i][j] = max(br[i][j], a[i][j] + br[i+1][j]);
    if(j+1<m) br[i][j] = max(br[i][j], a[i][j] + br[i][j+1]);
  }
  LL ans = LLONG_MIN;
  REP1(i, 1, n-2) REP1(j, 1, m-2) {
    ans = max(ans, tl[i-1][j]+br[i+1][j]+bl[i][j-1]+tr[i][j+1]);
    ans = max(ans, tl[i][j-1]+br[i][j+1]+bl[i+1][j]+tr[i-1][j]);
  }
  cout << ans << endl;
  return 0;
}
