/*
ID: johnath2
PROG: ratios
LANG: C++11
*/
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
using namespace std;
#define NAME "ratios"
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define SZ(x) ((int)(x).size())
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
#define PLL(x) printf("%lld\n",x)
#define PIS(x) printf("%d ",x)
#define CASET int ___T,cas=1;scanf("%d ",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000;
int det(int a[3], int b[3], int c[3]) {
  return a[0]*(b[1]*c[2]-b[2]*c[1])-a[1]*(b[0]*c[2]-b[2]*c[0])+a[2]*(b[0]*c[1]-b[1]*c[0]);
}
int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}
int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  int a[4][3];
  REP(i, 4) REP(j, 3) RI(a[i][j]);
  int D = det(a[1], a[2], a[3]);
  int D1 = det(a[0], a[2], a[3]);
  int D2 = det(a[1], a[0], a[3]);
  int D3 = det(a[1], a[2], a[0]);
  if(LL(D) * D1 < 0 || LL(D) * D2 < 0 || LL(D) * D3 < 0)
    puts("NONE");
  // PI(D), PI(D1), PI(D2), PI(D3);
  else {
    D = abs(D), D1 = abs(D1), D2 = abs(D2), D3 = abs(D3);
    int d = gcd(gcd(D, D1), gcd(D2, D3));
    PIS(D1 / d), PIS(D2 / d), PIS(D3 / d), PI(D / d);
  }
  return 0;
}