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

void put(char A[], int a[], int N) {
    int la = strlen(A);
    REP(i, la) {
        int d;
        if (A[la-1-i] <= '9' && A[la-1-i] >= '0') {
            d = A[la-1-i] - '0';
        } else {
            d = A[la-1-i] - 'A' + 10;
        }
        REP(j, 4) {
            if ((d >> j) & 1) {
                a[(N-1-i)*4+(3-j)] = true;
            }
        }
    }
}

char A[50005], B[50005], C[50005];
int a[200002], b[200002], c[200002];

int need[200002];

int main() {
    CASET {
        DRI(K);
        RS(A); RS(B); RS(C);
        int la = strlen(A), lb = strlen(B), lc = strlen(C);
        int N = max(la, max(lb, lc));
        MS0(a); MS0(b); MS0(c);
        put(A, a, N);
        put(B, b, N);
        put(C, c, N);
        N *= 4;
        PER(i, N) {
            if ((a[i] || b[i]) != c[i]) {
                if (c[i]) {
                    need[i] = need[i+1] + 1;
                } else {
                    need[i] = need[i+1] + a[i] + b[i];
                }
            } else {
                need[i] = need[i+1];
            }
        }
        if (need[0] > K) {
            PI(-1);
            continue;
        }
        int left = K;
        REP(i, N) {
            if (c[i]) {
                if (b[i]) {
                    if (a[i] && left > need[i+1]) {
                        a[i] = false;
                        left--;
                    }
                } else {
                    if (a[i]) {
                        if (left - 2 >= need[i+1]) {
                            a[i] = false;
                            b[i] = true;
                            left -= 2;
                        }
                    } else {
                        b[i] = true;
                        left--;
                    }
                }
            } else {
                left -= (a[i] + b[i]);
                a[i] = b[i] = false;
            }
            assert((a[i] || b[i]) == c[i]);
        }
        REP(i, N) {
            if (a[i] && b[i]) {
                assert(left == 0);
            } else if (a[i] && !b[i]) {
                assert(left <= 1);
            }
        }
        bool p = false;
        REP(i, N/4) {
            int d = 0;
            REP(j, 4) {
                d = d * 2 + a[i*4+j];
            }
            if (d) p = true;
            if (d > 9) {
                printf("%c", d - 10 + 'A');
            } else if (d || p) {
                printf("%d", d);
            }
        }
        if (!p) printf("0");
        puts("");
        p = false;
        REP(i, N/4) {
            int d = 0;
            REP(j, 4) {
                d = d * 2 + b[i*4+j];
            }
            if (d) p = true;
            if (d > 9) {
                printf("%c", d - 10 + 'A');
            } else if (d || p) {
                printf("%d", d);
            }
        }
        if (!p) printf("0");
        puts("");
    }
    return 0;
}
