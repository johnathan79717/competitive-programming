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
void print(LL i);
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
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)

int guess(int a, int b, int c) {
    printf("1 %d %d %d\n", a+1, b+1, c+1);
    fflush(stdout);
    DRI(x);
    return x;
}

void solve(int n, vector<int> &a, int &b) {
    int x[7] = {};
    REP(i, n) {
        x[i] = guess(b+i, b + (i+1) % n, b + (i+n-1) % n);
    }
    REP(i, n) {
        if (n == 5)
            a[b+i] = x[i] ^ x[(i+2) % n] ^ x[(i+3) % n];
        else if (n == 4)
            a[b+i] = x[(i+1)%n] ^ x[i] ^ x[(i+3)%n];
        else
            a[b+i] = x[i] ^ x[(i+1)%n] ^ x[(i+6)%n] ^ x[(i+3)%n] ^ x[(i+4)%n];
    }
    b += n;
}

int main() {
    CASET {
        DRI(N);
        vector<int> a(N);
        int i = 0;
        switch (N % 4) {
            case 0:
                REP(j, N / 4) {
                    solve(4, a, i);
                }
                break;
            case 1:
                solve(5, a, i);
                REP(j, N / 4 - 1) {
                    solve(4, a, i);
                }
                break;
            case 2:
                solve(5, a, i);
                solve(5, a, i);
                REP(j, N / 4 - 2) {
                    solve(4, a, i);
                }
                break;
            case 3:
                solve(7, a, i);
                REP(j, N / 4 - 1) {
                    solve(4, a, i);
                }
                break;
        }

        assert(i == N);

        PIS(2);
        PV(a);
        fflush(stdout);
        DRI(x);
    }
    return 0;
}
