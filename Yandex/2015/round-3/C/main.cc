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

int tl[5005], tr[5005], l[5005], r[5005], h[5005];
bool mp[5005][5005];
int N, M;

int largest_empty_rectangle()
{
    int area = 0;   // 最大矩形面積，初始化為最小值
    
    for (int i=1; i<=N; ++i)   // 以每一個橫條當做長方形底部
    {
        // 往左可延伸的長度
        for (int j=1; j<=M; ++j)
            if (mp[i][j])
                tl[j] = tl[j-1] + 1;
            else
                tl[j] = 0;
 
        // 往右可延伸的長度
        for (int j=M; j>=1; --j)
            if (mp[i][j])
                tr[j] = tr[j+1] + 1;
            else
                tr[j] = 0;
 
        // 計算長方形往上可延伸的距離
        for (int j=1; j<=M; ++j)
            if (mp[i][j])
                h[j] = h[j] + 1;
            else
                h[j] = 0;
 
        // 計算長方形往上延伸到底後，往左可延伸的距離
        for (int j=1; j<=M; ++j)
            if (l[j] == 0)
                l[j] = tl[j];
            else
                l[j] = min(tl[j], l[j]);
 
        // 計算長方形往上延伸到底後，往右可延伸的距離
        for (int j=1; j<=M; ++j)
            if (r[j] == 0)
                r[j] = tr[j];
            else
                r[j] = min(tr[j], r[j]);
 
        // 計算 Largest Empty Rectangle 並紀錄之
        for (int j=1; j<=M; ++j)
            area = max(area, (l[j] + r[j] - 1) * h[j]);
    }
    
    return area;
}

int main() {
    RI(N, M);
    REP1(i, 1, N) {
        REP1(j, 1, M) {
            mp[i][j] = true;
        }
    }
    DRI(K);
    int ans = 0;
    while (K--) {
        DRI(X1, Y1, X2, Y2);
        if (X1 > X2) swap(X1, X2);
        if (Y1 > Y2) swap(Y1, Y2);
        MAX(ans, (X2 - X1) * (Y2 - Y1));
        REP1(i, X1, X2+1) {
            REP1(j, Y1, Y2+1) {
                mp[i][j] = false;
            }
        }
    }
    // REP1(i, 0, N+1) {
    //     REP1(j, 0, M+1) {
    //         PIS(mp[i][j]);
    //     } 
    //     puts("");
    // }
    PI(max(ans, largest_empty_rectangle()));
    return 0;
}