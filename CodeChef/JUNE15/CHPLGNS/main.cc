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

bool inPolygon(int x, int y, const V(PII) &poly) {
    int n = SZ(poly);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        // PIS(i); PI(j);
        int x1 = poly[j].F, y1 = poly[j].S, x2 = poly[i].F, y2 = poly[i].S;
        if (y1 > y2) {
            swap(y1, y2);
            swap(x1, x2);
        }
        if (y == y1) {
            assert(x1 != x);
        } else if (y == y2) {
            assert(x2 != x);
            if (x2 > x) {
                cnt1 = !cnt1;
            } else {
                cnt2 = !cnt2;
            }
        } else if (y1 < y && y < y2) {
            // assert((LL)(x - x1) * (y2 - y1) != (LL)(x2 - x1) * (y - y1));
            if ((long double)(x2 - x1) * (y2 - y) < (long double)(x2 - x) * (y2 - y1)) {
                cnt1 = !cnt1;
            } else {
                cnt2 = !cnt2;
            }
        }
    }
    assert(cnt1 == cnt2);
    return cnt1;
}

// V(V(Segment)) s;
V(V(PII)) v;

bool comp(int i, int j) {
    assert(i != j);
    bool in1 = false, in2 = false;
    PER(k, min(SZ(v[i]), 10000))
        in1 = in1 || inPolygon(v[i][k].F, v[i][k].S, v[j]);
    PER(k, min(SZ(v[j]), 10000))
        in2 = in2 || inPolygon(v[j][k].F, v[j][k].S, v[i]);
    // assert(in1 || in2);
    return in1 || !in2;
}

int main() {
    int x = -0, y = 1;
    // V(PII)a = {{2, 0}, {4, 0}, {4, 4}, {-4, 4}, {-4, 0}, {-2, 0}, {-2, 2}, {2, 2}};
    V(PII)a = {{0, 0}, {-2, 2}, {0, 2}, {2, 0}};
    // cout << inPolygon(x, y, a) << endl;
    DRI(T);
    while(T--) {
        DRI(N);
        // v.resize(N);
        v = V(V(PII))(N);
        REP(i, N) {
            DRI(M);
            v[i].resize(M);
            REP(j, M) {
                DRL(x); DRL(y);
                assert(max(abs(x), abs(y)) <= 1000000000);
                // RI(v[i][j].F, v[i][j].S);
                v[i][j].F = x, v[i][j].S = y;
            }
        }
        VI a(N);
        REP(i, N) a[i] = i;
        sort(ALL(a), comp);
        VI ans(N);
        REP(i, SZ(a)) {
            ans[a[i]] = i;
        }
        REP(i, SZ(ans)) {
            if (i == SZ(ans) - 1)
                PI(ans[i]);
            else
                PIS(ans[i]);
        }
    }
    return 0;
}