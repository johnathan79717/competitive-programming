#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define FOR(i, c) \
    for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ALL(x) (x).begin(), (x).end()
#define CASET2            \
    int ___T, case_n = 1; \
    scanf("%d ", &___T);  \
    while ((___T > 0 ? printf("Case #%d:\n", case_n++) : 0), ___T-- > 0)
#define CASET1            \
    int ___T, case_n = 1; \
    scanf("%d ", &___T);  \
    while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET            \
    int ___T;            \
    scanf("%d ", &___T); \
    while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REP1(i, a, b) for (int i = (a); i <= int(b); i++)
#define PER1(i, a, b) for (int i = (a); i >= (b); i--)
#define REPL(i, x) for (int i = 0; x[i]; i++)
#define PER(i, n) for (int i = (n)-1; i >= 0; i--)
#define RI1(x) scanf("%d", &x)
#define RI2(x, y) RI1(x), RI1(y)
#define RI3(x, y...) RI1(x), RI2(y)
#define RI4(x, y...) RI1(x), RI3(y)
#define RI5(x, y...) RI1(x), RI4(y)
#define RI6(x, y...) RI1(x), RI5(y)
#define GET_MACRO(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define RI(argv...)                               \
    GET_MACRO(argv, RI6, RI5, RI4, RI3, RI2, RI1) \
    (argv)
#define DRI(argv...) \
    int argv;        \
    RI(argv)
#define WRI(argv...) while (RI(argv) != EOF)
#define DWRI(x...) \
    int x;         \
    WRI(x)
#define RS(x) scanf("%s", x)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x, 0, sizeof(x))
#define MS1(x) memset(x, -1, sizeof(x))
#define X first
#define Y second
#define V(x) vector<x>

typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

void print(int i) { printf("%d", i); }
void print(LL i);
template <class T>
void PI(T i) {
    print(i);
    puts("");
}
template <class T>
void PIS(T i) {
    print(i);
    printf(" ");
}

template <class T>
void PV(T const &v, int N) {
    REP(i, N) {
        print(v[i]);
        printf("%c", i == N - 1 ? '\n' : ' ');
    }
}

template <class T>
void PV(T const &v) {
    PV(v, SZ(v));
}

template <class T, class S>
bool has_bit(T mask, S i) {
    return (mask >> i) & 1;
}
long long shift(int i) { return 1ll << i; }

template <class C>
void mini(C &a4, C b4) {
    a4 = min(a4, b4);
}
template <class C>
void maxi(C &a4, C b4) {
    a4 = max(a4, b4);
}
int popcount(int x) { return __builtin_popcount(x); }
int popcount(long long x) { return __builtin_popcountll(x); }

#include <unordered_map>
#include <unordered_set>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) \
    LL x;      \
    RL(x)

const int MAX = 100000;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    DRI(N, M);
    unordered_set<int> xs, ys;
    REP(i, N) {
        DRI(x);
        xs.insert(x);
    }
    REP(j, M) {
        DRI(y);
        ys.insert(y);
    }
    LL ans = 0;
    if (xs.count(0) || ys.count(0)) {
        xs.erase(0);
        ys.erase(0);
        ans += 1ll * xs.size() * ys.size();
    }
    REP1(g, 1, MAX) {
        int b = 1;
        while (g * b * b <= MAX) {
            REP1(a, 1, b) {
                if (gcd(a, b) > 1) {
                    continue;
                }
                int x1 = g * a * a, x2 = g * b * b, y = g * a * b;
                int cx = (xs.count(x1) && xs.count(-x2)) + (x1 != x2 && xs.count(-x1) && xs.count(x2));
                int cy = ys.count(y) + ys.count(-y);
                ans += cx * cy;
                cx = (ys.count(x1) && ys.count(-x2)) + (x1 != x2 && ys.count(-x1) && ys.count(x2));
                cy = xs.count(y) + xs.count(-y);
                ans += cx * cy;
            }
            b++;
        }
    }
    PL(ans);
}

int main() {
    CASET { solve(); }
    return 0;
}