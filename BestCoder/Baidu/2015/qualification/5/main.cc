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

int dx1[4] = {-1, 0, 1, 0};
int dy1[4] = {0, 1, 0, -1};

int dx2[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy2[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int N, M;

bool in(int x, int y) {
    return x >= 1 && x <= N && y >= 1 && y <= M;
}

int main() {
    CASET2 {
        int K;
        RI(N, M, K);
        DRI(x1, y1, x2, y2);
        set<PII> p1, n1, p2, n2;
        int ans = 0;
        n1.insert(MP(x1, y1));
        n2.insert(MP(x2, y2));
        REP(k, K) {
            swap(p1, n1);
            n1.clear();
            FOR(pr, p1) {
                int x = pr->F, y = pr->S;
                REP(i, 4) {
                    if (in(x + dx1[i], y + dy1[i])) {
                        n1.insert(MP(x + dx1[i], y + dy1[i]));
                    }
                }
            }
            swap(p2, n2);
            n2.clear();
            FOR(pr, p2) {
                int x = pr->F, y = pr->S;
                REP(i, 8) {
                    int xx = x + dx2[i], yy = y + dy2[i];
                    if (n1.count(MP(xx, yy))) {
                        ans = k+1;
                        break;
                    }
                    if (in(xx, yy)) {
                        n2.insert(MP(xx, yy));
                    }
                }
                if (ans) {
                    break;
                }
            }
            if (ans) {
                break;
            }
        }
        if (ans) {
            PI(ans);
        } else {
            puts("OH,NO!");
        }
    }
    return 0;
}
