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

# define MULTITEST 1
void solve() {
    int N, K;
    R(N, K);
    VI A(N), B(N);
    set<int> unused;
    int cnt[1005] = {};
    FOR(s, 1, 1000) {
        unused.insert(s);
    }
    REP(i, N) {
        R(A[i]);
        cnt[A[i]]++;
        unused.erase(A[i]);
    }
    REP(i, N) {
        R(B[i]);
        cnt[B[i]]++;
        unused.erase(B[i]);
    }
    VI oa = A, ob = B;
    REPP(i, N - K, K) {
        REPP(j, i, K) {
            if (A[i] == A[j] && B[i] != B[j] || A[i] != A[j] && B[i] == B[j]) {
                puts("NO");
                return;
            }
        }
    }
    puts("YES");
    vector<VI> a;
    FOR(l, 0, N-K) {
        map<int, int> m;
        a.PB(VI{l+1});
        REPP(i, l, l+K) {
            if (!m.count(A[i])) {
                int n = *unused.begin();
                m[A[i]] = n;
                unused.erase(n);
            }
            if (--cnt[A[i]] == 0) {
                unused.insert(A[i]);
            }
            A[i] = m[A[i]];
            cnt[A[i]]++;
            a.back().PB(A[i]);
        }
    }
    vector<VI> b;
    FOR(l, 0, N-K) {
        map<int, int> m;
        b.PB(VI{l+1});
        REPP(i, l, l+K) {
            if (!m.count(B[i])) {
                int n = *unused.begin();
                m[B[i]] = n;
                unused.erase(n);
            }
            if (--cnt[B[i]] == 0) {
                unused.insert(B[i]);
            }
            b.back().PB(B[i]);
            B[i] = m[B[i]];
            cnt[B[i]]++;
        }
    }
    FOR(l, 0, N-K) {
        a.PB(VI({l+1}));
        REPP(i, l, l+K) {
            a.back().PB(B[i]);
        }
    }
    for (auto it = b.rbegin(); it != b.rend(); it++) {
        a.PB(*it);
    }
    W(SZ(a));
    for (VI &a : a) {
        W(a);
    }
#ifdef DEBUG
    assert(SZ(a) <= N * 3);
    A = oa, B = ob;
    for (VI &a : a) {
        int l = a[0] - 1;
        REP(i, K) {
            REPP(j, i, K) {
                if (A[l+i] == A[l+j]) {
                    assert(a[1+i] == a[1+j]);
                }
                if (A[l+i] != A[l+j]) {
                    assert(a[1+i] != a[1+j]);
                }
            }
        }
        REP(i, K) {
            A[l+i] = a[1+i];
        }
    }
    assert(A == B);
#endif
}

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
