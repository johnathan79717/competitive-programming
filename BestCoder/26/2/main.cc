// Create your own template by modifying this file!

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
using namespace std;
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(x) (x).begin(),(x).end()
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

double S[6][100001];

int main() {
    REP1(i, 1, 100000) {
        S[1][i] = S[1][i-1] + i;
    }
    REP1(i, 1, 100000) {
        S[2][i] = S[2][i-1] + S[1][i-1] + double(i-1) * i;
    }
    REP1(i, 1, 100000) {
        S[3][i] = S[3][i-1] + S[2][i-1] + double(i-2) * (i-1) * i / 2;
    }
    REP1(i, 1, 100000) {
        S[4][i] = S[4][i-1] + S[3][i-1] + double(i) * (i-1) * (i-2) * (i-3) / 6;
    }
    REP1(i, 1, 100000) {
        S[5][i] = S[5][i-1] + S[4][i-1] + double(i) * (i-1) * (i-2) * (i-3) * (i-4) / 24;
    }
    CASET {
        DRII(x, b);
        int a1 = 1;
        double ans = a1 * S[1][x];
        if (b >= 2) {
            int a2 = (1 << b) - 2 * a1;
            ans += a2 * S[2][x];
            if (b >= 3) {
                int p3 = 1;
                REP(i, b) p3 *= 3;
                int a3 = p3 - 3 * a2 - 3 * a1;
                ans += a3 * S[3][x];
                if (b >= 4) {
                    int a4 = (1 << (2*b)) - 4 * a3 - 6 * a2 - 4 * a1;
                    ans += a4 * S[4][x];
                    if (b >= 5) {
                        int p5 = 1;
                        REP(i, b) p5 *= 5;
                        int a5 = p5 - 5 * a4 - 10 * a3 - 10 * a2 - 5 * a1;
                        ans += a5 * S[5][x];
                    }
                }
            }
        }
        printf("Case #%d: %.3f\n", case_n++, ans / pow(double(x), b));
    }
    return 0;
}
