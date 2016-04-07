/*
ID: johnath2
PROG: kimbits
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
#define NAME "kimbits"
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

LL sumC[33][33];

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  DRII(N, L);
  LL I;
  scanf("%lld", &I);
  sumC[0][0] = 1;
  REP1(i, 0, N) REP1(j, 0, i) {
    sumC[i+1][j] += sumC[i][j];
    sumC[i+1][j+1] += sumC[i][j];
  }
  REP1(i, 0, N) REP1(j, 0, i) {
    sumC[i][j+1] += sumC[i][j];
  }
  while(N--) {
    L = min(L, N);
    if(I > sumC[N][L])
      printf("1"), I -= sumC[N][L--];
    else
      printf("0");
  }
  puts("");
  return 0;
}