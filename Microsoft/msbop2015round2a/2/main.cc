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

double dp[1005][1005];

struct Pyramid {
    int x, y, w;
    bool operator< (const Pyramid &other) const {
        if (x - y != other.x - other.y) {
            return x - y < other.x - other.y;
        }
        return x + y < other.x + other.y;
    }
} p[1005];

double overlap(int i, int j) {
    assert(p[j].x - p[j].y <= p[i].x - p[i].y);
    if (p[j].x + p[j].y <= p[i].x - p[i].y) {
        return 0;
    }
    if (p[i].x + p[i].y <= p[j].x + p[j].y) {
        return p[i].y * p[i].y;
    }
    return pow(double(p[j].x + p[j].y - p[i].x + p[i].y) / 2, 2);
}

int main() {
  DRI(T);
  REP1(t, 1, T) {
    DRI(N);
    REP1(i, 1, N) {
        RI(p[i].x, p[i].y, p[i].w);
    }
    sort(p + 1, p + N +1);
    MS0(dp);
    REP1(i, 1, N) {
        REP(j, i) {
            dp[i][j] = dp[i-1][j];
        }
        dp[i][i] = (double)p[i].w - p[i].y * p[i].y;
        REP1(j, 1, i-1) {
            dp[i][i] = max(dp[i][i], dp[i-1][j] + p[i].w - p[i].y * p[i].y + overlap(i, j));
        }
    }
    double ans = 0;
    REP1(j, 0, N) {
        ans = max(ans, dp[N][j]);
    }
    
    printf("Case #%d: %.02f\n", t, ans);
  }
  return 0;
}
