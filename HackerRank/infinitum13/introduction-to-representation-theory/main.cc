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

template<class T>
void PV(T const &v) {
    PV(v, SZ(v));
}

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(int x) { return __builtin_popcount(x); } 
int popcount(long long x) { return __builtin_popcountll(x); } 

#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define PL(x) printf("%lld\n", x)
#define RL(x) scanf("%lld\n", x)

template<class Float>
struct Complex {
    Float r, i;
    Complex() {}
    Complex(Float r, Float i): r(r), i(i) {}
    Complex& operator +=(Complex const &other) {
        r += other.r;
        i += other.i;
        return *this;
    }

    Complex& operator -=(Complex const &other) {
        r -= other.r;
        i -= other.i;
        return *this;
    }

    Complex operator-(Complex const &other) const {
        Complex ret(*this);
        ret -= other;
        return ret;
    }

    Complex operator*(Complex const &c2) const {
        return Complex(r * c2.r - i * c2.i, r * c2.i + c2.r * i);
    }

    Complex& operator*=(Complex const &other) {
        return *this = *this * other;
    }

    Complex& operator/=(Complex const &other) {
        return *this = *this * other.inverse();
    }

    Complex inverse() const {
        Float l = r * r + i * i;
        return Complex(r / l, -i / l);
    }
};

void print(Complex<long double> const &c) {
    printf("%Lf %Lf\n", c.r, c.i);
}

typedef Complex<long double> C;

int main() {
    DRI(N, M);
    V(C) b(M);
    REP(i, M) {
        scanf("%Lf%Lf", &b[i].r, &b[i].i);
    }
    auto d = b;
    assert(abs(d[0].r - N) < 1e-6);
    assert(abs(d[0].i) < 1e-6);
    int n = M-1;
    V(C) a(M);
    REP(i, M) {
        a[i] = C(cos(2 * M_PI * i / M), sin(2 * M_PI * i / M));
    }
    REP(k, n) {
        PER1(j, n, k+1) {
            d[j] -= a[k] * d[j-1];
        }
    }
    auto &x = d;
    PER(k, n) {
        REP1(j, k+1, n) {
            x[j] /= (a[j] - a[j-k-1]);
        }
        REP1(j, k, n-1) {
            x[j] -= x[j+1];
        }
    }

    //V(C) ak(M, C(1, 0));
    //REP(i, M) {
        //C sum(0, 0);
        //REP(j, M) {
            //sum += ak[j] * x[j];
        //}
        //REP(j, M) {
            //ak[j] *= a[j];
        //}
        ////assert(abs(sum.r - b[i].r) < 1e-6);
        ////assert(abs(sum.i - b[i].i) < 1e-6);
    //}

    REP(j, M) {
        //print(x[j]);
        //N -= round(x[j].r);
        //assert(abs(x[j].i) < 1e-6);
        REP(k, round(x[j].r)) {
            print(a[j]);
        }
    }
    //assert(N == 0);
    return 0;
}
