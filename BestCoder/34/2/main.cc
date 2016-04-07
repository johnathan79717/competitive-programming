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
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
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
    int N, W, H;
    while (RIII(N, W, H) != EOF) {
        VI A(N);
        LL total = 0;
        REP(i, N) {
            RI(A[i]);
            total += A[i];
        }
        if (total < (LL)W * H) {
            PI(-1);
            continue;
        }
        int l = 0, r = 0;
        LL neg = (LL)W * H, pos = 0, ans = neg;
        while (r < N) {
            if (A[r] >= H)
                pos += A[r] - H;
            else
                neg += H - A[r];
            r++;
            if (l < r - W) {
                if (A[l] >= H)
                    pos -= A[l] - H;
                else
                    neg -= H - A[l];
                l++;
            } else {
                neg -= H;
            }
            ans = min(ans, max(pos, neg));
        }
        while (l < N) {
            if (A[l] >= H)
                pos -= A[l] - H;
            else
                neg -= H - A[l];
            neg += H;
            l++;
            ans = min(ans, max(pos, neg));
        }
        cout << ans << '\n';
    }
    return 0;
}
