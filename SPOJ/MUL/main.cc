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
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)
#include <vector>
#include <complex>

using namespace std;

typedef complex<double> cd;
typedef vector<cd> vcd;

vcd fft(const vcd &as) {
  int n = as.size();
  int k = 0;
  while ((1 << k) < n) k++;
  n = (1 << k);
  vector<int> rev(n);
  rev[0] = 0;
  int high1 = -1;
  for (int i = 1; i < n; i++) {
    if ((i & (i - 1)) == 0)
      high1++;
    rev[i] = rev[i ^ (1 << high1)];
    rev[i] |= (1 << (k - high1 - 1));
  }

  vcd roots(n);
  for (int i = 0; i < n; i++) {
    double alpha = 2 * M_PI * i / n;
    roots[i] = cd(cos(alpha), sin(alpha));
  }

  vcd cur(n);
  for (int i = 0; i < n; i++) {
    if (rev[i] < (int)as.size())
      cur[i] = as[rev[i]];
  }

  for (int len = 1; len < n; len *= 2) {
    int rstep = roots.size() / (len * 2);
    for (int p = 0; p < n; p += len * 2) {
      for (int i = 0; i < len; i++) {
        cd val = roots[i * rstep] * cur[p + len + i];
        auto c = cur[p + i];
        cur[p + i] = c + val;
        cur[p + len + i] = c - val;
      }
    }
  }
  return cur;
}

vcd mul(const vcd& a1, const vcd& a2) {
    vcd f1 = fft(a1), f2 = fft(a2);
    assert(f1.size() == f2.size());
    int L = f1.size();
    vcd p(L);
    REP(i, L) {
        p[i] = conj(f1[i] * f2[i]) / cd(L);
    }
    return fft(p);
}

char l1[300003], l2[300003];
char ans[600009];

int main() {
    CASET {
        RS(l1);
        RS(l2);
        MS0(ans);
        
        int L1 = strlen(l1), L2 = strlen(l2), L = L1 + L2 - 1;
        vcd a1(L), a2(L);

        REPL(i, l1) {
            a1[L1 - 1 - i] = cd(l1[i] - '0');
        }
        REPL(i, l2) {
            a2[L2 - 1 - i] = cd(l2[i] - '0');
        }

        vcd r = mul(a1, a2);
        while (int(r.back().real() + 0.5) == 0 && r.size() > 1) {
            r.pop_back();
        }
        L = r.size();
        int carry = 0;
        REP(i, L) {
            carry += int(r[i].real() + 0.5);
            ans[i] = carry % 10 + '0';
            carry /= 10;
        }
        if (carry) {
            printf("%d", carry);
        }
        reverse(ans, ans + strlen(ans));
        puts(ans);
    }
    return 0;
}
