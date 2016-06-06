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
#define PL(x) printf("%lld\n", x)
#define RL(x) scanf("%lld", &x)
#define DRL(x) LL x; RL(x);
struct Permutation {
    static int N;
    VI p;
    Permutation() : p(N) {
        REP(i, N) {
            p[i] = i;
        }
    }
    Permutation(VI& other): p(other) {}
    bool operator!=(const Permutation& other) const {
        REP(i, N) {
            if (p[i] != other[i]) {
                return true;
            }
        }
        return false;
    }

    int& operator[](int i) {
        return p[i];
    }

    int operator[](int i) const {
        return p[i];
    }

    Permutation operator*(const Permutation& other) const {
        Permutation ans;
        for (int i = 0; i < N; i++) {
            ans[i] = p[other[i]];
        }
        return ans;
    }
};

int Permutation::N;

VI perm, refl;
int base = 0;

void f(int N) {
    REP1(i, 1, N-1) {
        perm.PB(base + i);
    }
    perm.PB(base);

    REP(i, N) {
        refl.PB(base + N - i - 1);
    }

    base += N;
}

int main() {
    CASET {
        base = 0;
        perm.clear(); refl.clear();
        DRI(N);
        int n = N;
        for (int p = 2; p * p <= N; p++) {
            if (N % p == 0) {
                int k = 0;
                int a = N;
                while (a % p == 0) {
                    a /= p;
                    k++;
                }
                f(N / a);
                N = a;
            }
        }
        if (N > 1) f(N);


        Permutation::N = base;
        Permutation r(perm), s(refl);
        //printf("N = %d, srsr = ", Permutation::N);
        //PV((s * r * s * r).p);
        //printf("ss = ");
        //PV((s * s).p);
        Permutation e;
        V(Permutation) v;
        REP(i, n) {
            //printf("r^%d = ", i+1);
            e = e * r;
            v.PB(e);
            //PV(e.p);
            //printf("sr^%d = ", i+1);
            v.PB(s*e);
            //PV((s*e).p);
        }
        REP(i, 2*n) REP(j, i) {
            assert(v[i] != v[j]);
        }

        PI(SZ(perm));
        for (int &a: perm) {
            a++;
        }
        for (int &a: refl) {
            a++;
        }
        PV(perm);
        PV(refl);

    }
    return 0;
}
