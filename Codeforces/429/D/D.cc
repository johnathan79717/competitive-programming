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

typedef pair<LL, LL> P;
P A[100000];

bool compare_y(P const &a, P const &b) {
  return a.second < b.second;
}

LL closest_pair(P *a, int n) {
  if(n <= 1) return LLONG_MAX;
  int m = n / 2;
  LL x = a[m].first;
  LL d = min(closest_pair(a, m), closest_pair(a+m, n-m));
  inplace_merge(a, a+m, a+n, compare_y);
  vector<P> b;
  REP(i, n) {
    if((a[i].first - x) * (a[i].first - x) >= d) continue;
    REP(j, b.size()) {
      LL dx = a[i].first - b[b.size()-j-1].first;
      LL dy = a[i].second - b[b.size() - j - 1].second;
      if(dy * dy >= d) break;
      d = min(d, dx * dx + dy * dy);
    }
    b.PB(a[i]);
  }
  return d;
}

int main() {
  DRI(n);
  LL sum = 0;
  REP(i, n) {
    DRI(a);
    sum += a;
    A[i] = MP(i, sum);
  }
  cout << closest_pair(A, n) << endl;
  return 0;
}
