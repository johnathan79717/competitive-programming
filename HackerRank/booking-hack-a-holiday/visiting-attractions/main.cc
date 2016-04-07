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

char str[1000000];
double distance(const PII &p1, const PII &p2) {
    double x = p1.X - p2.X, y = p1.Y - p2.Y;
    return sqrt(1.0 * x * x + 1.0 * y * y);
}

double d[120][120];

int main() {
    REP(i, 120) {
        REP(j, 120) d[i][j] = 1e18;
        d[i][i] = 0;
    }
    V(PII) p;
    auto update = [&p](int a, int b, double v) {
        double dis = distance(p[a], p[b]) / v;
        mini(d[a][b], dis);
        mini(d[b][a], dis);
    };
    DRI(Xh, Yh);
    p.EB(Xh, Yh);
    DRI(N);
    REP1(i, 1, N) {
        DRI(x, y);
        p.EB(x, y);
        REP(j, i) {
            update(i, j, 5);
        }
    }
    DRI(S);
    REP1(i, 1, S) {
        DRI(x, y);
        p.EB(x, y);
        REP(j, N+1) {
            update(N+i, j, 5);
        }
    }

    DRI(L);
    fgets(str, 100000, stdin);
    REP(i, L) {
        char *data = str;
        fgets(str, 1000000, stdin);
        int a;
        VI B;
        int offset;
        while(sscanf(data, "%d%n", &a, &offset) == 1) {
            data += offset;
            for (int b: B) {
                update(a+N, b+N, 25);
            }
            B.PB(a);
        }
    }

    REP(k, 1+N+S) {
        REP(i, 1+N+S) {
            REP(j, 1+N+S) {
                mini(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    VI A(N);
    REP(i, N) A[i] = i+1;
    VI ans;
    do {
        VI B;
        double time = 0;
        int prev = 0;
        for (int a: A) {
            if (time + d[prev][a] <= 12 + 1e-6) {
                time += d[prev][a] + 1;
                prev = a;
                B.PB(a);
            } else {
                break;
            }
        }
        if (SZ(B) > SZ(ans)) {
            ans = B;
        }
    } while (next_permutation(ALL(A)));
    PI(SZ(ans));
    PV(ans);
    return 0;
}
