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
double EPS = 1e-10;

double add(double a, double b) {
  //if(abs(a + b) < EPS * (abs(a) + abs(b))) return 0;
  return a + b;
}

LL add(LL a, LL b) {
    return a + b;
}

template<class T>
struct P {
  T x, y, z;
  P() {}
  P(LL x, LL y, LL z) : x(x), y(y), z(z) {}
  void read() {
      scanf("%lld%lld%lld", &x, &y, &z);
  }
  //void print() {
      //printf("%f %f %f\n", x, y, z);
  //}
  P operator + (const P &p) const {
    return P(add(x, p.x), add(y, p.y), add(z, p.z));
  }
  P operator - (const P &p) const {
    return P(add(x, -p.x), add(y, -p.y), add(z, -p.z));
  }
  P operator * (LL d) const {
    return P(x * d, y * d, z * d);
  }
  bool operator == (const P &p) const {
    return abs(this->x - p.x) < EPS * (abs(this->x) + abs(p.x))
     && abs(this->y - p.y) < EPS * (abs(this->y) + abs(p.y))
     && abs(this->z - p.z) < EPS * (abs(this->z) + abs(p.z));
  }
  //bool operator < (const P &p) const {
    //if(abs(this->x - p.x) > EPS) return this->x < p.x;
    //return this->y < p.y;
  //}
  LL dot(const P &p) const {
    return add(add(x * p.x, y * p.y), z * p.z);
  }
  P cross(const P &p) const {
      return P(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
  }
  //bool on_seg(const P &p1, const P &p2) const {
    //return (p1 - *this).cross(p2 - *this) == 0 && (p1 - *this).dot(p2 - *this) <= 0;
  //}
  // int rel_pos(const P &p1, const P &p2) const {
  //   return sign((p1 - *this).det(p2 - *this));
  // }
};

bool sorted(P<LL> &p1, P<LL> &p2, P<LL> &p3, P<LL> &p4) {
    P<LL> norm = (p2 - p1).cross(p3 - p1);
    assert(norm.dot(p2) == norm.dot(p3));
    auto p0 = p4;
    p0.z = 0;
    LL d = norm.dot(p1);
    assert(norm.dot(p2) == d && norm.dot(p3) == d);
    LL d4 = norm.dot(p4) - d;
    LL d0 = norm.dot(p0) - d;
    return d4 / llabs(d4) != d0 / llabs(d0);
}

int main() {
    DRI(T);
    REP1(t, 1, T) {
        printf("Case #%d: ", t);
        DRI(N);
        vector<pair<P<LL>, int>> p(N);
        REP(i, N) {
            p[i].X.read();
            p[i].Y = i;
        }
        while (true) {
            bool change = false;
            REP1(i, 3, N-1) {
                if (!sorted(p[i-3].X, p[i-2].X, p[i-1].X, p[i].X)) {
                    change = true;
                    swap(p[i-3], p[i]);
                }
            }
            if (!change) break;
            REP(i, N) {
                printf("%d%c", p[i].Y + 1, i == N - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}
