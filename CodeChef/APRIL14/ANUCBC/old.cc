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

#define MOD 1000000009
inline int add(int a, int b, int mod=MOD) { return a + b < mod ? a + b : a + b - mod; }
inline void addBy(int &a, int b, int mod=MOD) { a = add(a, b, mod); }
inline int sub(int a, int b, int mod=MOD) { return a - b < 0 ? a - b + mod : a - b; }
inline void subBy(int &a, int b, int mod=MOD) { a = sub(a, b, mod); }
inline int mul(int a, int b, int mod=MOD) { return (LL)a * b % mod; }
inline void mulBy(int &a, int b, int mod=MOD) { a = mul(a, b, mod); }

/* a*x âĄ 1 (mod m) */
int inverse(int a, int mod = MOD)
{
    int d = mod, x = 0, s = 1, q, r, t;
    while (a != 0)
    {
        q = d / a, r = d % a;
        d = a, a = r;
        t = x - q * s, x = s, s = t;
    }
    if (d != 1) return -1;
    return (x + mod) % mod;
}
inline int divide(int a, int b, int mod=MOD) { return mul(a, inverse(b, mod), mod); }

vector<int> factorial(1, 1);

int fact(int n) {
  while(factorial.size() <= n)
    factorial.push_back(mul(factorial.back(), factorial.size()));
  return factorial[n];
}

vector<int> inv_factorial(1, 1);

int inv_fact(int n) {
  while(inv_factorial.size() <= n)
    inv_factorial.push_back(divide(inv_factorial.back(), inv_factorial.size()));
  return inv_factorial.at(n);
}

int choose(int n, int k) {
  if(n < k) return 0;
  return mul(fact(n), mul(inv_fact(k), inv_fact(n-k)));
}

int a[100000];
int cnt1[100], cnt2[100];
int ways1[100][100];
int dp1[101][100];
int ways2[100][100];
int dp2[101][100];

int main() {
  DRI(T);
  REP(t, T) {
    DRII(N, Q);
    REP(i, N) RI(a[i]);
    while(Q--) {
      DRI(M);
      MS0(cnt1); MS0(cnt2);
      REP(i, N) if(a[i] >= 0) cnt1[a[i]%M]++; else cnt2[-a[i]%M]++;
      MS0(ways1);
      REP(i, M) REP1(j, 0, cnt1[i])
        addBy(ways1[i][i*j%M], choose(cnt1[i], j));
      MS0(dp1);
      dp1[0][0] = 1;
      REP(i, M) REP(j, M) REP(k, M)
        addBy(dp1[i+1][j+k<M?j+k:j+k-M], mul(dp1[i][j], ways1[i][k]));

      MS0(ways2);
      REP(i, M) REP1(j, 0, cnt2[i])
        addBy(ways2[i][i*j%M], choose(cnt2[i], j));
      MS0(dp2);
      dp2[0][0] = 1;
      REP(i, M) REP(j, M) REP(k, M)
        addBy(dp2[i+1][j+k<M?j+k:j+k-M], mul(dp2[i][j], ways2[i][k]));
      int ans = 0;
      REP(i, M)
        addBy(ans, mul(dp1[M][i], dp2[M][i]));
      PI(ans);
    }
  }
  return 0;
}
