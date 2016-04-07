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
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
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
template<class T> void PI(T i) { print(i); puts(""); }
template<class T> void PIS(T i) { print(i); printf(" "); }

template<class T>
void PV(T const &v, int N) {
    REP(i, N) {
        print(v[i]);
        printf("%c", i == N-1 ? '\n' : ' ');
    }
}

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(int x) { return __builtin_popcount(x); } 
int popcount(long long x) { return __builtin_popcountll(x); } 
// index starts with 1
template<class T>
class BIT {
  vector<T> bit;
public:
  BIT() {}
  BIT(int n): bit(n+1) {}
  T sum(int i, int j) {
      return sum(j) - sum(i-1);
  }
  T sum(int i) {
    assert(i>=0);
    i = min(i, (int)bit.size()-1);
    T s = 0;
    while(i > 0) {
      s += bit.at(i);
      i &= i - 1;
    }
    return s;
  }
  void add(int i, T x) {
    while(i < bit.size()) {
      bit.at(i) += x;
      i += i & -i;
    }
  }
  void resize(int n) {
    bit.resize(n+1);
  }
};

int a[50005], b[50005];
int main() {
    CASET {
        DRI(N);
        LL A = 0, B = 0;
        REP1(i, 1, N) {
            RI(a[i]);
            A += a[i];
        }
        sort(a+1, a+N+1, greater<int>());
        BIT<LL> bit(N+1);
        REP1(k, 1, N) {
            b[k] = N - 1 - a[k];
            bit.add(k, b[k]);
            B += b[k];
        }

        if (A != B) {
            puts("The data have been tampered with!");
        } else {
            bool fail = false;
            A = 0;
            REP1(k, 1, N) {
                A += a[k];
                int i = upper_bound(b+1, b+1+k, k-1) - b;
                LL bk1 = (k+1 - i) * 1ll * (k-1) + bit.sum(i-1);
                i = upper_bound(b+k+1, b+N+1, k) - b;
                LL bk = (N+1 - i) * 1ll * k + bit.sum(k+1, i-1);
                if (A > bk1 + bk) {
                    fail = true;
                    break;
                }
            }
            if (fail) {
                puts("The data have been tampered with!");
            } else {
                puts("It seems to have no problem.");
            }

        }
    }
    return 0;
}
