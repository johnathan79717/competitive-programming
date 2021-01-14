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
void _R(int &x) { scanf("%d", &x);  }
void _R(int64_t &x) { scanf("%lld", &x);  }
void _R(double &x) { scanf("%lf", &x);  }
void _R(char &x) { scanf(" %c", &x);  }
void _R(char *x) { scanf("%s", x);  }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...);  }
template<class T> void _W(const T &x) { cout << x;  }
void _W(const int &x) { printf("%d", x);  }
void _W(const int64_t &x) { printf("%lld", x);  }
void _W(const double &x) { printf("%.16f", x);  }
void _W(const char &x) { putchar(x);  }
void _W(const char *x) { printf("%s", x);  }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' ');  }
void W() { fflush(stdout); }
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

# define MULTITEST 1
void solve() {
    int N;
    R(N);
    VL A(N);
    R(A[0]);
    R(A[N-1]);
    VL d(N-1);
    int prev = -1;
    REP(i, N-1) {
        W('Q', i+1, i+2, i+1, i+2);
        R(d[i]);
        if (d[i] > 0) {
            if (prev >= 0) {
                W('Q', prev+1, i+2, prev+1, i+2);
                int dd;
                R(dd);
                if (dd == d[i] + abs(d[prev])) {
                    d[i] *= d[prev] / abs(d[prev]);
                } else {
                    d[i] *= -d[prev] / abs(d[prev]);
                }
            }
            prev = i;
        }
    }
    VL B(N), C(N);
    B[0] = C[0] = A[0];
    REP(i, N-1) {
        B[i+1] = B[i] + d[i];
        C[i+1] = C[i] - d[i];
    }
    if (B == C || C[N-1] != A[N-1]) {
        W('!', B);
        return;
    }
    if (B[N-1] != A[N-1]) {
        W('!', C);
        return;
    }
    REP(i, N) {
        if (B[i] != B[i+2]) {
            for (int l1 : {i, i+1}) {
                LL Mb = B[i], Mc = C[i];
                for (int r1 = l1+1; r1 <= i+2; r1++) {
                    Mb = max(Mb, B[r1]);
                    Mc = max(Mc, C[r1]);
                    LL mb = B[i], mc = C[i];
                    for (int l2 : {i, i+1}) {
                        for (int r2 = l2+1; r2 <= i+2; r2++) {
                            mb = min(mb, B[r2]);
                            mc = min(mc, C[r2]);
                            if (Mb - mb != Mc - mc) {
                                W('Q', l1+1, r1+1, l2+1, r2+1);
                                int x;
                                R(x);
                                if (x == Mb - mb) {
                                    W('!', B);
                                } else {
                                    W('!', C);
                                }
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
#if 0    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}
