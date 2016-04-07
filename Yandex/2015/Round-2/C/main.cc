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

char s[100055];

int main() {
    CASET {
        RS(s);
        int f[26] = {};
        REPL(i, s) {
            f[s[i]-'a']++;
        }
        int nonzero = 0, mx = 0, mn = 26, nimber = 0;
        REP(i, 26) {
            nimber ^= f[i];
            if (f[i]) {
                nonzero++;
                MIN(mn, i);
            }
            MAX(mx, f[i]);
        }
        int twoplus = 0;
        REP(i, 26) {
            if (f[i] >= 2) {
                twoplus++;
            }
        }
        if (mx == 1) {
            if (nonzero % 2) {
                PI(2);
            } else {
                PIS(1);
                printf("%c\n", 'a'+mn);
            }
        } else if (twoplus == 1) {
            PIS(1);
            REP(i, 26) {
                if (f[i] >= 2) {
                    int c = (nonzero % 2) ? f[i]-1 : f[i];
                    REP(j, c) {
                        printf("%c", 'a'+i);
                    }
                    puts("");
                }
            }
        } else if (nimber == 0) {
            PI(2);
        } else {
            PIS(1);
            REP(i, 26) {
                if (f[i]) {
                    int need = nimber ^ f[i];
                    if (need < f[i]) {
                        REP(j, f[i] - need) {
                            printf("%c", 'a'+i);
                        }
                        puts("");
                        break;
                    }
                }
            }
        }
    }
    return 0;
}