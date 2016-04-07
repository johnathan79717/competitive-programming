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
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
#define ALL(x) (x).begin(),(x).end()
#define CASET2 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d:\n", case_n++) : 0), ___T-- > 0)
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
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
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define X first
#define Y second
#define V(x) vector<x >
#define PV(v) REP(i, SZ(v)) if(i < SZ(v)-1) PIS(v[i]); else PI(v[i]);

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(unsigned x) { return __builtin_popcount(x); } 
int popcount(unsigned long long x) { return __builtin_popcountll(x); } 

typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

#include <unordered_set>
#include <unordered_map>
#define PL(x) printf("%lld\n",x)
#define EB emplace_back
#define RL(x) scanf("%lld",&x)
#define DRL(x) LL x;RL(x)

const int p = (1 << 31);
struct Rational {
    double a;
    int k;
    void normalize() {
        if (abs(a) < 1e-9) return;
        while (a >= p) {
            a /= p;
            k++;
        }
        while (a < 1) {
            a *= p;
            k--;
        }
    }

    Rational& operator*=(const Rational& other) {
        a *= other.a;
        k += other.k;
        normalize();
        return *this;
    }

    Rational& operator/=(const Rational& other) {
        a /= other.a;
        k -= other.k;
        normalize();
        return *this;
    }

    Rational& operator+=(Rational const &other) {
        if (k < other.k) {
            k = other.k;
            a *= pow(p, k - other.k);
            a += other.a;
        } else {
            a += other.a * pow(p, other.k - k);
        }

        normalize();
        return *this;
    }

    Rational (double a) : a(a), k(0) {
        normalize();
    }

    void print() {
        printf("%.6f\n", a * pow(p, k));
    }
};

int main() {
    DRI(T);
    while(T--) {
        DRI(N, M);
        V(Rational) a(N, 1);
        Rational sum = 0;
        REP(i, N) {
            REP(j, M) {
                double p;
                scanf("%lf", &p);
                a[i] *= p;
            }
            sum += a[i];
        }
        if (a[0].a < 1e-9) {
            puts("0.000000");
        } else {
            a[0] /= sum;
            a[0].print();
        }
    }
    // (Rational(123.456) /= Rational(0.789)).print();
    return 0;
}