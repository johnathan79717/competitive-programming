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

#include <unordered_set>
#include <unordered_map>

#define PL(x) printf("%lld\n", x);

const double EPS = 1e-10;

double add(double a, double b) {
    if (abs(a + b) < EPS * (abs(a) + abs(b))) return 0;
    return a + b;
}

struct P {
    double x, y;
    P() {}
    P(double x, double y) : x(x), y(y) {}
    double det(P p) {
        return add(x * p.y, -y * p.x);
    }
    P operator - (P p) {
        return P(add(x, -p.x), add(y, -p.y));
    }
    bool operator == (P p) {
        return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
    }
};

bool cmp_x(const P& p, const P& q) {
    if (p.x != q.x) return p.x < q.x;
    return p.y < q.y;
}

vector<P> convex_hull(vector<P> &ps) {
    // sort(ps, ps+n, cmp_x);
    int n = ps.size();
    sort(ALL(ps), cmp_x);
    int k = 0;
    vector<P> qs(n * 2);
    REP(i, n) {
        while (k > 1 && (qs[k-1] - qs[k-2]).det(ps[i] - qs[k-1]) < 0) k--;
        // while (k > 1 && (qs[k-1] - qs[k-2]).det(ps[i] - qs[k-1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    for (int i = n-2, t = k; i >= 0; i--) {
        while (k > t && (qs[k-1] - qs[k-2]).det(ps[i] - qs[k-1]) < 0) k--;
        // while (k > t && (qs[k-1] - qs[k-2]).det(ps[i] - qs[k-1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    qs.resize(k-1);
    return qs;
}

int main() {
  DRI(T);
  REP1(t, 1, T) {
    printf("Case #%d: ", t);
    V(P) p;
    REP(i, N) {
        scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    auto qs = convex_hull(ps);
    int Q = qs.size();
    REP(i, Q) {
        REP(j, i) {
            
        }
    }
  }
  return 0;
}
