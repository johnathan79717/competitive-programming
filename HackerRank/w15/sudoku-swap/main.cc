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
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
#define ALL(x) (x).begin(),(x).end()
#define CASET2 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d:\n", case_n++) : 0), ___T-- > 0)
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
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
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define F first
#define S second
#define V(x) vector<x >

int popcount(unsigned x) { return __builtin_popcount(x); } 
int popcount(unsigned long long x) { return __builtin_popcountll(x); } 

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

#include <unordered_set>
#include <unordered_map>
#define PL(x) printf("%lld\n",x)
#define EB emplace_back
#define RL(x) scanf("%lld",&x)
#define DRL(x) LL x;RL(x)

int a[9][9];

bool valid() {
    REP(x, 9) REP(y1, 9) REP(y2, 9) {
        if (y1 != y2 && (a[x][y1] == a[x][y2] || a[y1][x] == a[y2][x]))
            return false;
    }
    REP(x, 3) REP(y, 3) {
        REP(i1, 3) REP(j1, 3) REP(i2, 3) REP(j2, 3) {
            if (MP(i1, j1) != MP(i2, j2)) {
                if (a[3*x+i1][3*y+j1] == a[3*x+i2][3*y+j2]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    CASET2 {    
        REP(i, 9) REP(j, 9) {
            RI(a[i][j]);
        }
        V(PII) cand;
        REP(x, 9) REP(y1, 9) REP(y2, y1) {
            if (a[x][y1] == a[x][y2]) {
                cand.EB(x, y1);
                cand.EB(x, y2);
            }
            if (a[y1][x] == a[y2][x]) {
                cand.EB(y1, x);
                cand.EB(y2, x);
            }
        }
        sort(ALL(cand));
        cand.resize(unique(ALL(cand)) - cand.begin());
        vector<pair<PII, PII>> ans;
        FOR(c1, cand) FOR(c2, cand) {
            if (c2 == c1) break;
            swap(a[c1->F][c1->S], a[c2->F][c2->S]);
            if (valid()) {
                ans.EB(*c1, *c2);
                if (ans.back().F > ans.back().S) {
                    swap(ans.back().F, ans.back().S);
                }
            }
            swap(a[c1->F][c1->S], a[c2->F][c2->S]);
        }
        sort(ALL(ans));
        ans.resize(unique(ALL(ans)) - ans.begin());
        FOR(a, ans) {
            printf("(%d,%d) <-> (%d,%d)\n", a->F.F+1, a->F.S+1, a->S.F+1, a->S.S+1);
        }
        if (ans.empty()) {
            puts("Serendipity");
        }
    }
    return 0;
}