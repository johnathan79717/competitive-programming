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

#define MULTITEST 1
# define MULTITEST 1

VI ps;
bool isPrime[1500];

VI ret(16);

void f(VI& A, VI& ans) {
    if (A.empty() && ans.size() < ret.size()) {
        ret = ans;
    }
    while (A.size()) {
        int x = A.back();
        for (int p : ans) {
            if (x % p == 0) {
                A.pop_back();
                break;
            }
        }
    }
}

void solve() {
    int N, C;
    R(N, C);
    int ans = (1<<15) - 1;
    VI A(N);
    REP(i, N) {
        R(A[i]);
    }
    if (C <= 50) {
        vector<int> ans;
        f(A, ans);
        //REPP(mask, 1, 1 << 15) {
            //if (__builtin_popcount(mask) >= __builtin_popcount(ans)) continue;
            //bool fail = false;
            //for (int a : A) {
                //bool success = false;
                //REP(i, 15) {
                    //if (((mask >> i) & 1) && a % ps[i] == 0) {
                        //success = true;
                        //break;
                    //}
                //}
                //if (!success) fail = true;
            //}
            //if (!fail)
            //ans = mask;
        //}
        //W(__builtin_popcount(ans));
        //debug(ans);
        //REP(i, 15) {
            //if ((ans >> i) & 1) {
                //printf("%d ", ps[i]);
            //}
        //}
        //puts("");
    } else if (C <= 1500) {
        for (int p : ps) {
            bool fail = false;
            for (int a : A) {
                if (a % p) {
                    fail = true;
                    break;
                }
            }
            if (!fail) {
                W(1);
                W(p);
                return;
            }
        }
        for (int p1 : ps) {
            for (int p2 : ps) {
                bool fail = false;
                for (int a : A) {
                    if (a % p1 && a % p2) {
                        fail = true;
                        break;
                    }
                }
                if (!fail) {
                    W(2);
                    W(p1, p2);
                    return;
                }
            }
        }
    }
}

#undef int
int main() {
    MS1(isPrime);
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p < 1500; p++) {
        if (isPrime[p]) {
            ps.PB(p);
            for (int k = p+p; k < 1500; k += p) {
                isPrime[k] = false;
            }
        }
    }
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}
