/*
ID: johnath2
PROG: shopping
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
#include <stack>
#include <functional>
using namespace std;
#define NAME "shopping"
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

int numOffer, numProduct;
int offerQuant[100][1000], offerPrice[100];
int product[5], desired[5], productPrice[5], ok[100];
int dp[100000];

int solve(int target) {
  if(dp[target] >= 0) return dp[target];
  int kk[5];
  int tmp = target;
  PER(i, numProduct) {
    kk[i] = tmp % 10;
    tmp /= 10;
  }
  int ans = INT_MAX;
  REP(i, numOffer) {
    if(!ok[i]) continue;
    bool offerOK = true;
    REP(j, numProduct)
      if(offerQuant[i][product[j]] > kk[j])
        offerOK = false;
    if(!offerOK) continue;
    int newTarget = 0;
    REP(j, numProduct)
      newTarget = newTarget * 10 + (kk[j] - offerQuant[i][product[j]]);
    ans = min(ans, solve(newTarget) + offerPrice[i]);
  }
  REP(i, numProduct) {
    if(kk[i] == 0) continue;
    kk[i]--;
    int newTarget = 0;
    REP(j, numProduct)
      newTarget = newTarget * 10 + kk[j];
    kk[i]++;
    ans = min(ans, solve(newTarget) + productPrice[i]);
  }
  return dp[target] = ans;
}

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  RI(numOffer);
  REP(i, numOffer) {
    DRI(n);
    REP(j, n) {
      DRI(product);
      RI(offerQuant[i][product]);
    }
    RI(offerPrice[i]);
  }
  RI(numProduct);
  int target = 0;
  REP(i, numProduct) {
    RIII(product[i], desired[i], productPrice[i]);
    target = 10 * target + desired[i];
  }
  
  REP(i, numOffer) {
    ok[i] = true;
    REP(j, 1000) if(offerQuant[i][j] && count(product, product+numProduct, j) == 0) ok[i] = false;
  }

  MS1(dp);
  dp[0] = 0;
  PI(solve(target));

  return 0;
}