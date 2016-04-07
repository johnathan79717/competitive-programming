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
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
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

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(int x) { return __builtin_popcount(x); } 
int popcount(long long x) { return __builtin_popcountll(x); } 

#include <unordered_set>
#include <unordered_map>
#define EB emplace_back

int N, M;

V(VI) A, ur, ul, dr, dl;
bool ok(int m) {
    V(VI) B(N+2, VI(M+2));
    V(VI) dl1(N+2, VI(M+2));
    V(VI) dr1(N+2, VI(M+2));
    V(VI) ul1(N+2, VI(M+2));
    V(VI) ur1(N+2, VI(M+2));
    PER1(i, N, 1) REP1(j, 1, M) {
        if (ur[i][j] >= m) {
            ur1[i][j] = m;
        }
        if (ur1[i][j] > 0) {
            B[i][j] = true;
            maxi(ur1[i-1][j], ur1[i][j] - 1);
            maxi(ur1[i][j+1], ur1[i][j] - 1);
        }
    }
    REP1(i, 1, N) PER1(j, M, 1) {
        if (dl[i][j] >= m) {
            dl1[i][j] = m;
        }
        if (dl1[i][j] > 0) {
            B[i][j] = true;
            maxi(dl1[i+1][j], dl1[i][j] - 1);
            maxi(dl1[i][j-1], dl1[i][j] - 1);
        }
    }
    PER1(i, N, 1) PER1(j, M, 1) {
        if (ul[i][j] >= m) {
            ul1[i][j] = m;
        }
        if (ul1[i][j] > 0) {
            B[i][j] = true;
            maxi(ul1[i-1][j], ul1[i][j] - 1);
            maxi(ul1[i][j-1], ul1[i][j] - 1);
        }
    }
    REP1(i, 1, N) REP1(j, 1, M) {
        if (dr[i][j] >= m) {
            dr1[i][j] = m;
        }
        if (dr1[i][j] > 0) {
            B[i][j] = true;
            maxi(dr1[i+1][j], dr1[i][j] - 1);
            maxi(dr1[i][j+1], dr1[i][j] - 1);
        }
    }
    REP1(i, 1, N) REP1(j, 1, M) {
        if (B[i][j] != A[i][j])
            return false;
    }
    return true;
}

char s[1005];
int main() {
    RI(N, M);
    A = V(VI)(N+2, VI(M+2));
    dl = V(VI)(N+2, VI(M+2));
    dr = V(VI)(N+2, VI(M+2));
    ul = V(VI)(N+2, VI(M+2));
    ur = V(VI)(N+2, VI(M+2));
    REP(i, N) {
        RS(s);
        REP(j, M) {
            if (s[j] == '#') {
                A[i+1][j+1] = true;
            }
        }
    }
    PER1(i, N, 1) REP1(j, 1, M) {
        if (A[i][j]) {
            dl[i][j] = 1 + min(dl[i+1][j], dl[i][j-1]);
        }
    }
    REP1(i, 1, N) PER1(j, M, 1) {
        if (A[i][j]) {
            ur[i][j] = 1 + min(ur[i-1][j], ur[i][j+1]);
        }
    }
    REP1(i, 1, N) REP1(j, 1, M) {
        if (A[i][j]) {
            ul[i][j] = 1 + min(ul[i-1][j], ul[i][j-1]);
        }
    }
    PER1(i, N, 1) PER1(j, M, 1) {
        if (A[i][j]) {
            dr[i][j] = 1 + min(dr[i+1][j], dr[i][j+1]);
        }
    }
            
    int lb = 1, ub = min(N, M) + 1;
    while (ub - lb > 1) {
        int m = (lb + ub) / 2;
        if (ok(m)) {
            lb = m;
        } else {
            ub = m;
        }
    }
    PI(lb);
    return 0;
}
