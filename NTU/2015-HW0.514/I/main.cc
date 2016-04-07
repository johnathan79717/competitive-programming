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
#define X first
#define Y second
#define V(x) vector<x >
#define PV(v) REP(i, SZ(v)) if(i < SZ(v)-1) PIS(v[i]); else PI(v[i]);

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(unsigned x) { return __builtin_popcount(x); } 
int popcount(unsigned long long x) { return __builtin_popcountll(x); } 

typedef long double LD;
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

int N;

char s[4001][256];       // 4001個字串，長度皆可達到256-1。
char* sa[4001 * 256];    // suffix array
int c[4001];              // 紀錄目前出現的後綴是位於哪幾個字串。
 
int cmp(const void* a, const void* b)
{
    return strcmp(*(char**)a, *(char**)b);
}
 
// 找出一個後綴所附屬的字串
inline int pos(int n)
{
    return (sa[n] - s[0]) / 256;
}
 
// 求出兩個字串的Longest Common Prefix長度
int lcp(char* s, char* t)
{
    int n = 0;
    while (s[n] && t[n] && s[n] == t[n]) n++;
    return n;
}
 
PII longest_common_substring()
{
    // 建立後綴陣列
    int M = 0;
    for (int i=0; i<N; ++i)
        for (int j=0; s[i][j]; ++j)
            sa[M++] = s[i] + j;
 
    qsort(sa, M, sizeof(char*), cmp);
 
    // 尋找連續後綴
    PII ans = MP(0, 0);
    memset(c, 0, sizeof(c));
    for (int i=0, j=0, n=0; j<M; )
    {
        // 往右移動j，直到涵蓋每一種字串的後綴。
        // 並且隨時紀錄每一種字串的後綴的出現次數。
        while (n < N && j < M) if (!c[pos(j++)]++) n++;
        if (n < N) break;
        // 往右移動i，直到無法涵蓋每一種字串的後綴。
        while (n == N) if (!--c[pos(i++)]) n--;
 
        // 計算共同子字串，並且紀錄最長者。
        // ans = max(ans, MP(lcp(sa[i], sa[j-1]), i));
        int l = lcp(sa[i-1], sa[j-1]);
        if (l > ans.X) {
            ans = MP(l, i-1);
        } else if (l == ans.X && strncmp(sa[i-1], sa[ans.Y], l) < 0) {
            ans = MP(l, i-1);
        }
 
    }
 
    return ans;
}

int main() {
    WRI(N) {
        if (!N) break;
        REP(i, N) {
            RS(s[i]);
        }
        PII ans = longest_common_substring();
        // PIS(ans.X); PI(ans.Y);
        if (ans.X)
            printf("%.*s\n", ans.X, sa[ans.Y]);
        else
            puts("IDENTITY LOST");
    }
    return 0;
}