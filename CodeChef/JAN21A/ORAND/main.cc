// Create your own template by modifying this file!
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
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <deque>
#include <stack>
#include <functional>
#include <bitset>
#include <numeric>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB emplace_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
template<class T> void _R(T &x) { cin >> x;  }
void _R(int64_t &x) { scanf("%lld", &x);  }
void _R(double &x) { scanf("%lf", &x);  }
void _R(char &x) { scanf(" %c", &x);  }
void _R(char *x) { scanf("%s", x);  }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...);  }
template<class T> void _W(const T &x) { cout << x;  }
void _W(const int64_t &x) { printf("%lld", x);  }
void _W(const double &x) { printf("%.16f", x);  }
void _W(const char &x) { putchar(x);  }
void _W(const char *x) { printf("%s", x);  }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' ');  }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...);  }
#ifdef DEBUG
 #define debug(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define debug(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
template<class T> void MIN(T& a, const T& b) { a = min(a, b); }
template<class T> void MAX(T& a, const T& b) { a = max(a, b); }

void T(VI &a, void (*f)(int &, int &)) {
    for (int len = 1; len < SZ(a); len *= 2) {
        for (int i = 0; i < SZ(a); i += 2 * len) {
            for (int j = 0; j < len; j++) {
                f(a[i + j], a[i + j + len]);
            }
        }
    }
}

void A1(int &a0, int &a1) {
    a0 += a1;
}

// [1 1]
// [0 1]
void AND_T(VI &a) {
    T(a, A1);
}

void A2(int &a0, int &a1) {
    a0 -= a1;
}

// [1 -1]
// [0 1]
void AND_T_INV(VI &a) {
    T(a, A2);
}

void O1(int &a0, int &a1) {
    a1 += a0;
}

void O2(int &a0, int &a1) {
    a1 -= a0;
}

// [1 0]
// [1 1]
void OR_T(VI &a) {
    T(a, O1);
}

// [1 0]
// [-1 1]
void OR_T_INV(VI &a) {
    T(a, O2);
}

int V[SIZE];

# define MULTITEST 1
void solve() {
    int N, M;
    R(N, M);
    VI A(N), B(M);
    int n = 1;
    for (int& a : A) {
        R(a);
        while ((1<<n) <= a) {
            n++;
        }
    }
    for (int& b : B) {
        R(b);
        while ((1<<n) <= b) {
            n++;
        }
    }
    VI a(1<<n), b(1<<n), v(1<<n);
    for (int A : A) {
        a[A] = 1;
    }
    for (int B : B) {
        b[B] = 1;
    }
    v[0] = 1;
    a[0] = 1;
    b.back() = 1;
    OR_T(a);
    AND_T(b);
    REP(k, n) {
        OR_T(v);
        REP(i, 1<<n) {
            v[i] *= a[i];
        }
        OR_T_INV(v);
        REP(i, 1<<n) {
            if (v[i] > 1) v[i] = 1;
        }
        AND_T(v);
        REP(i, 1<<n) {
            v[i] *= b[i];
        }
        AND_T_INV(v);
        REP(i, 1<<n) {
            if (v[i] > 1) v[i] = 1;
        }
    }
    int ans = 0;
    REP(i, 1<<n) {
        if (v[i]) {
            ans++;
        }
    }
    W(ans);
}

#undef int
int main() {
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}
