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
LL solve() {
    char D[50];
    R(D);
    debug(D);
    int N = LEN(D);
    int f[10] = {};
    VI a;
    REP(i, N) {
        f[D[i]-'0']++;
        a.PB(D[i] - '0');
    }
    pair<LL, pair<LL, LL>> bf = {LLONG_MAX, {0, 0}};
#ifdef DEBUG
    sort(ALL(a));
    do {
        if (!a[0] || !a[SZ(a) / 2]) continue;
        LL b1 = 0;
        REP(i, SZ(a) / 2) {
            b1 = b1 * 10 + a[i];
        }
        LL b2 = 0;
        REPP(i, SZ(a) / 2, SZ(a)) {
            b2 = b2 * 10 + a[i];
        }
        bf = min(bf, {abs(b2 - b1), {b1, b2}});
    } while (next_permutation(ALL(a)));
#endif
    LL a1 = 0, a2 = 0;
    if (N % 2) {
        REPP(i, 1, 10) {
            if (f[i]) {
                f[i]--;
                a1 = i;
                break;
            }
        }
        int cnt = N/2;
        REPP(i, 0, 10) {
            while (f[i] && cnt) {
                f[i]--;
                cnt--;
                a1 = 10 * a1 + i;
            }
        }
        cnt = N / 2;
        for (int i = 9; i >= 0; i--) {
            while (f[i] && cnt) {
                f[i]--;
                cnt--;
                a2 = 10 * a2 + i;
            }
        }
#ifdef DEBUG
        debug(bf, a1, a2);
        assert(abs(a1 - a2) == bf.F);
#endif
        return abs(a1 - a2);
    }
    if (all_of(f, f+10, [](int x) { return x % 2 == 0; })) {
#ifdef DEBUG
        debug(bf, 0);
        assert(bf.F == 0);
#endif
        return 0;
    }
    LL ans = LLONG_MAX;
    REPP(i2, 1, 10) {
        if (f[i2]) {
            f[i2]--;
            REP(j, i2) {
                if (f[j]) {
                    a1 = i2;
                    a2 = j;
                    f[j]--;

                    bool nzpair = any_of(f+1, f+10, [](int x) { return x % 2 == 0; });

                    if (j == 0 && !nzpair) {
                        continue;
                    }
                    int cnt = 0;
                    REPP(i, 0, 10) {
                        cnt += i == 0 && !nzpair ? f[i] : f[i] % 2;
                    }

                    int k = 0;
                    REPP(i, 0, 10) {
                        int x = i == 0 && !nzpair ? f[0] : f[i] % 2;
                        while (x-- && k++ < cnt / 2) {
                            a1 = 10 * a1 + i;
                        }
                    }
                    k = 0;
                    for (int i = 9; i >= 0; i--) {
                        int x = i == 0 && !nzpair ? f[0] : f[i] % 2;
                        while (x-- && k++ < cnt / 2) {
                            a2 = 10 * a2 + i;
                        }
                    }
                    ans = min(ans, abs(a1 - a2));
                    debug(ans, a1, a2);

                    f[j]++;
                }
            }
            f[i2]++;
        }
    }
#ifdef DEBUG
    debug(bf, ans);
        assert(ans == bf.F);
#endif
    return ans;
}

#undef int
int main() {
#if MULTITEST    
    CASET{
        printf("Case #%d: ", cs);
        LL ans = solve();
        W(ans);
    }
#else
    solve();
#endif
    return 0;
}
