// Create your own template by modifying this file!
#include <array>
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
typedef vector<int> VVI;
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

void solve() {
    int N;
    R(N);
    VI A(N);
    VI f(2500001);
    VPII B;
    REP(i, N) {
        R(A[i]);
        f[A[i]]++;
        if (f[A[i]] == 1) {
            B.PB(A[i], i+1);
        }
    }
    int p2 = -1;
    vector<PII> f2(5000001, {-1, -1});
    FOR(a, 1, 2500000) {
        if (f[a] >= 4) {
            puts("YES");
            int cnt = 0;
            REP(i, N) {
                if (A[i] == a) {
                    printf("%d ", i+1);
                    cnt++;
                    if (cnt == 4) {
                        puts("");
                        return;
                    }
                }
            }
        }
        if (f[a] >= 2) {
            if (p2 < 0) {
                p2 = a;
            } else {
                VI v1, v2;
                REP(i, N) {
                    if (SZ(v1) < 2 && A[i] == a) {
                        v1.PB(i+1);
                    }
                    if (SZ(v2) < 2 && A[i] == p2) {
                        v2.PB(i+1);
                    }
                }
                W("YES");
                W(v1[0], v2[0], v1[1], v2[1]);
                return;
            }
        }
    }
    if (p2 >= 0) {
        VI v;
        REP(i, N) {
            if (SZ(v) < 2 && A[i] == p2) {
                v.PB(i+1);
            }
        }
        f2[p2 + p2] = {v[0], v[1]};
    }
    REP(i, SZ(B)) {
        REP(j, i) {
            if (f2[B[i].F + B[j].F].F >= 0) {
                auto pr = f2[B[i].F + B[j].F];
                W("YES");
                W(pr.F, pr.S, B[i].S, B[j].S);
                return;
            } else {
                f2[B[i].F + B[j].F] = {B[i].S, B[j].S};
            }
        }
    }
    W("NO");
}

int main() {
    solve();
    return 0;
}
