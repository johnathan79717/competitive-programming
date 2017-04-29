#include <functional>
#include <list>
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
#include <deque>
#include <stack>
#include <cassert>
using namespace std;
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(x) (x).begin(),(x).end()
#define CASET2 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d:\n", case_n++) : 0), ___T-- > 0)
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define REP(i,n) for(int i=0;i<int(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=int(b);i++)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define RI1(x) scanf("%d",&x)
#define RI2(x,y) RI1(x), RI1(y)
#define RI3(x,y...) RI1(x), RI2(y)
#define RI4(x,y...) RI1(x), RI3(y)
#define RI5(x,y...) RI1(x), RI4(y)
#define RI6(x,y...) RI1(x), RI5(y)
#define GET_MACRO(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define RI(argv...) GET_MACRO(argv, RI6, RI5, RI4, RI3, RI2, RI1)(argv)
#define DRI(argv...) int argv;RI(argv)
#define WRI(argv...) while (RI(argv) != EOF)
#define DWRI(x...) int x; WRI(x)
#define RS(x) scanf("%s",x)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define X first
#define Y second
#define V(x) vector<x >

typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

void print(int i) { printf("%d", i); }
void print(LL i);
template<class T> void PI(T i) { print(i); puts(""); }
template<class T> void PIS(T i) { print(i); printf(" "); }

template<class T>
void PV(T const &v, int N) {
    REP(i, N) {
        print(v[i]);
        printf("%c", i == N-1 ? '\n' : ' ');
    }
}

template<class T> void PV(T const &v) { PV(v, SZ(v)); }

template<class T, class S> bool has_bit(T mask, S i) { return (mask >> i) & 1; }
long long shift(int i) { return 1ll << i; }

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(int x) { return __builtin_popcount(x); } 
int popcount(long long x) { return __builtin_popcountll(x); } 

#include <array>
#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)

int B, D, Hd;
unordered_map<int, int> dp;

int solve(int hd, int ad, int hk, int ak, bool justCured, bool buffed, bool attacked) {
  //PIS(hd); PIS(ad); PIS(hk); PIS(ak); PIS(justCured); PIS(buffed); PI(attacked);
  int hash = ad;
  hash = hash * 101 + hd;
  hash = hash * 101 + ak;
  hash = hash * 101 + hk;
  hash = hash * 2 + justCured;
  hash = hash * 2 + buffed;
  hash = hash * 2 + attacked;
  if (dp.count(hash)) {
    return dp[hash];
  }
  if (hd <= 0) {
    return INF;
  }
  if (ad >= hk) {
    return 1;
  }
  int ans = INF;
  // Attack
  ans = min(ans, 1+solve(hd - ak, ad, hk - ad, ak, false, buffed, true));
  // Buff
  if (B && !attacked) {
    ans = min(ans, 1+solve(hd - ak, ad + B, hk, ak, false, true, attacked));
  }
  // Cure
  if (!justCured) {
    ans = min(ans, 1+solve(Hd - ak, ad, hk, ak, true, buffed, attacked));
  }
  if (D && ak && !buffed && !attacked) {
    ak = max(ak - D, 0);
    ans = min(ans, 1+solve(hd - ak, ad, hk, ak, false, buffed, attacked));
  }
  return dp[hash] = ans;
}

int main() {
  DRI(T);
  REP1(t, 1, T) {
    dp.clear();
    printf("Case #%d: ", t);
    RI(Hd);
    DRI(Ad, Hk, Ak);
    RI(B, D);
    int ans = solve(Hd, Ad, Hk, Ak, false, false, false);
    if (ans < INF) {
      PI(ans);
    } else {
      puts("IMPOSSIBLE");
    }
    fflush(stdout);
  }
  return 0;
}
