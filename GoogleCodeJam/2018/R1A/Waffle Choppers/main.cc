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

#include <array>
#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)

char a[105][105];

int main() {
    DRI(T);
    REP1(t, 1, T) {
        printf("Case #%d: ", t);
        DRI(R, C, H, V);
        VI row(R);
        REP(i, R) {
            RS(a[i]);
            if (i > 0) row[i] = row[i-1];
            REP(j, C) {
                if (a[i][j] == '@') {
                    row[i]++;
                }
            }
        }
        bool fail = false;
        if (row.back() % (H+1)) {
            puts("IMPOSSIBLE");
            continue;
        }
        int x = row.back() / (H+1);
        if (x % (V+1)) {
            puts("IMPOSSIBLE");
            continue;
        }
        VI h(H+2);
        REP1(i, 1, H) {
            h[i] = lower_bound(ALL(row), i * x) - row.begin();
            if (row[h[i]] != i * x) {
                fail = true;
                break;
            }
        }
        h[0] = -1;
        h.back() = R-1;
        if (fail) {
            puts("IMPOSSIBLE");
            continue;
        }
        V(VI) col(H+1, VI(C));
        REP1(k, 0, H) {
            REP(j, C) {
                if (j > 0) col[k][j] = col[k][j-1];
                REP1(i, h[k]+1, h[k+1]) {
                    col[k][j] += (a[i][j] == '@');
                }
            }
            assert(col[k].back() == x);
        }
        int y = x / (V+1);
        REP1(v, 1, V) {
            int l = 0, r = C;
            REP1(k, 0, H) {
                int lb = lower_bound(ALL(col[k]), v * y) - col[k].begin();
                if (col[k][lb] != v * y) {
                    fail = true;
                    break;
                }
                l = max(l, lb);
                int ub = upper_bound(ALL(col[k]), v * y) - col[k].begin();
                r = min(r, ub);
            }
            if (l >= r) {
                fail = true;
            }
            if (fail) {
                break;
            }
        }
        if (fail) {
            puts("IMPOSSIBLE");
            continue;
        }
        puts("POSSIBLE");
    }
    return 0;
}
