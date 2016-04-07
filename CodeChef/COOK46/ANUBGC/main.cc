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
#define REP1(i,a,b) for(auto i=(a);i<=(b);i++)
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
typedef long long LL;
typedef vector<LL> VI;
typedef unsigned long long ULL;
const int INF = 1000000000;

VI check(LL N) {
  VI ans(10);
  while(N) {
    ans[N%10] = 1;
    N /= 10;
  }
  return ans;
}

VI count(LL N) {
  VI ans(10);
  if(N < 10) {
    REP1(i, 1, N)
      ans[i] = 1;
    return ans;
  }
  LL M = N - N % 10;
  REP1(i, M, N) {
    auto c = check(i);
    REP(j, 10)
      ans[j] += c[j];
  }
  M /= 10;
  auto c = count(M - 1);
  REP(j, 10)
    ans[j] += c[j] * 10 + (M - c[j]);
  ans[0]--;
  return ans;
}

LL gcd(LL a, LL b) {
  if(a)
    return gcd(b%a, a);
  return b;
}

int main() {
  DRI(T);
  REP(t, T) {
    DRL(N);
    VI a = count(N);
    // FOR(i, a) PL(i);
    // puts("");
    LL num = 0;
    FOR(i, a) num += i;
    LL den = 10*N;
    // PL(num);
    // PL(den);
    LL g = gcd(num, den);
    printf("%lld/%lld\n", num/g, den/g);
  }
  return 0;
}
