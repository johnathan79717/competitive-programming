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

#define PL(x) printf("%lld\n", x);

char a[200][200];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char mark[] = "v>^<";

int R, C;

bool in(int i, int j) {
    return i >= 0 && j >= 0 && i < R && j < C;
}

int main() {
  DRI(T);
  REP1(t, 1, T) {
    printf("Case #%d: ", t);
    RI(R, C);
    REP(i, R) {
        RS(a[i]);
    }
    int ans = 0;
    bool fail = false;
    REP(i, R) {
        REP(j, C) {
            if (a[i][j] != '.') {
                bool ok = false;
                REP(k, 4) {
                    int ii = i+dx[k], jj = j+dy[k];
                    while (in(ii, jj)) {
                        if (a[ii][jj] != '.') {
                            if (a[i][j] == mark[k]) {
                                ans--;
                            }
                            ok = true;
                            break;
                        }
                        ii += dx[k];
                        jj += dy[k];
                    }
                }
                if (ok) {
                    ans++;
                } else {
                    fail = true;
                    break;
                }
            }
        }
        if (fail) {
            break;
        }
    }
    if (fail) {
        puts("IMPOSSIBLE");
    } else {
        PI(ans);
    }
  }
  return 0;
}
