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
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define RI(argv...) GET_MACRO(argv, RI3, RI2, RI1)(argv)
#define RI1(x) scanf("%d",&x)
#define RI2(x,y) RI1(x), RI1(y)
#define RI3(x,y,z) RI1(x), RI2(y, z)
#define DRI(argv...) int argv;RI(argv)
#define RII(x,y) scanf("%d%d",&x,&y)
#define RIL(args...) while (RI(x, y) != EOF)
#define DRIL(x...) int x; RIL(x)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define F first
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;


int main() {
    VI A;
    DRI(N);
    while (N--) {
        DRI(t);
        if (t == 1) {
            DRI(w);
            A.PB(w);
        } else {
            assert(t == 2);
            LL L, R, k;
            scanf("%I64d%I64d%I64d", &L, &R, &k);
            // scanf("%lld%lld%lld", &L, &R, &k);
            vector<pair<int, LL> > b;
            int i = SZ(A)-1;
            while (L < R) {
                assert(i >= 0);
                b.PB(MP(A[i--], (R - L + 1) / 2));
                if (L % 2 && R % 2) b.back().second++;
                if (L % 2) {
                    L++;
                }
                L /= 2;
                R /= 2;
            }
            if (L == R) {
                while (L % 2 == 0) {
                    L /= 2;
                    i--;
                }
                assert(i >= 0);
                b.PB(MP(A[i], 1));
            }
            sort(ALL(b));
            // PI(b[k-1]);
            bool end = false;
            REP(i, SZ(b)) {
                if (k <= b[i].S) {
                    PI(b[i].F);
                    end = true;
                    break;
                }
                k -= b[i].S;
            }
            assert(end);
        }
    }
    return 0;
}
