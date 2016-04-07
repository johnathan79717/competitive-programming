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

#define MOD 1000000007
inline int add(int a, int b, int mod=MOD) { return a + b < mod ? a + b : a + b - mod; }
inline void addBy(int &a, int b, int mod=MOD) { a = add(a, b, mod); }
inline int sub(int a, int b, int mod=MOD) { return a - b < 0 ? a - b + mod : a - b; }
inline void subBy(int &a, int b, int mod=MOD) { a = sub(a, b, mod); }
inline int mul(int a, int b, int mod=MOD) { return (LL)a * b % mod; }
inline void mulBy(int &a, int b, int mod=MOD) { a = mul(a, b, mod); }

int main() {
  DRI(N);
  VI A(N);
  REP(i, N)
    RI(A[i]);
  VI B = A;
  int L = 0;
  V(PII) ans1, ans2;
  int S1 = 0, S2 = 0;
  while(L < N) {
    int R = min_element(A.BG + L, A.ED) - A.BG;
    if(L < R) {
      ans1.EB(L+1, R+1);
      S1 += (R - L + 1);
      int l = L, r = R;
      while(l < r) swap(A[l++], A[r--]);
    }
    L++;
  }
  L = 0;
  while(L < N) {
    int R = max_element(B.rbegin() + L, B.rend()) - B.rbegin();
    if(L < R) {
      ans2.EB(N - R, N - L);
      S2 += (R - L + 1);
      int l = N - 1 - L, r = N - 1 - R;
      while(l > r) swap(B[l--], B[r++]);
    }
    L++;
  }
  if(S1 + N * ans1.size() < S2 + N * ans2.size()) {
    PI(ans1.size());
    FOR(p, ans1) {
      PIS(p.F); PI(p.S);
    }
  } else {
    PI(ans2.size());
    FOR(p, ans2)  {
      PIS(p.F); PI(p.S);
    }
  }
  return 0;
}