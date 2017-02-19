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

#include <unordered_set>
#include <unordered_map>
#define RL(x) scanf("%lld",&x)
#define DRL(x) LL x;RL(x)
#define PL(x) printf("%lld\n",x)

int main() {
  int T, cas = 1;
  scanf("%d", &T);
  while(T--) {
    printf("Case #%d: ", cas++);
    DRI(N);
    DRL(X);
    DRI(Ax, Bx, Cx);
    DRL(H);
    DRI(Ah, Bh, Ch);
    set<pair<LL,LL>> s;
    double sum = 0;
    double ans = 0;
    REP(i, N) {
      //printf("%lld %lld\n", X-H, X+H);
      LL l2, r1;
      auto it = s.upper_bound(MP(X-H, 0)), jt = s.end(), kt = s.end();
      if (it != s.begin() && (--it)->second >= X+H) {
        goto END;
      }
      it = s.lower_bound(MP(X - H, 0));
      while (it != s.end() && it->second <= X+H) {
        auto jt = it;
        it++;
        l2=jt->first; r1=jt->second;
        if (jt != s.begin()) {
          auto kt = jt;
          --kt;
          if (kt->second > jt->first) {
            l2 = kt->second;
          }
        }
        auto kt = jt;
        kt++;
        if (kt != s.end()) {
          if (kt->first < jt->second) {
            r1 = kt->first;
          }
        }
        ans -= 0.25 * pow(jt->second - jt->first, 2);
        ans += 0.25 * pow(l2 - jt->first, 2);
        ans += 0.25 * pow(jt->second - r1, 2);
        if (l2 > r1) {
          ans -= 0.25 * pow(l2 - r1, 2);
        }
        s.erase(jt);
      }
      s.emplace(X - H, X + H);
      jt = s.find(MP(X-H, X+H));
      assert(jt != s.end());
      l2=jt->first; r1=jt->second;
      if (jt != s.begin()) {
        auto kt = jt;
        --kt;
        if (kt->second > jt->first) {
          l2 = kt->second;
        }
      }
      kt = jt;
      kt++;
      if (kt != s.end()) {
        if (kt->first < jt->second) {
          r1 = kt->first;
        }
      }
      ans += 0.25 * pow(jt->second - jt->first, 2);
      ans -= 0.25 * pow(l2 - jt->first, 2);
      ans -= 0.25 * pow(jt->second - r1, 2);
      if (l2 > r1) {
        ans += 0.25 * pow(l2 - r1, 2);
      }
END:
      //printf("%f\n", ans);
      sum += ans;
      //double x = 0;
      //for (auto xt = s.begin(); xt != s.end(); xt++) {
        //x += 0.25 * pow(xt->second - xt->first, 2);
        //if (xt != s.begin()) {
          //auto yt = xt;
          //yt--;
          //assert(yt->second < xt->second);
          //assert(yt->first < xt->first);
          //if (yt->second > xt->first) {
            //x -= 0.25 * pow(yt->second - xt->first, 2);
          //}
        //}
      //}
      //printf("%f\n", x);
      X = (Ax * X + Bx) % Cx + 1;
      H = (Ah * H + Bh) % Ch + 1;
    }
    printf("%f\n", sum);
  }
}
