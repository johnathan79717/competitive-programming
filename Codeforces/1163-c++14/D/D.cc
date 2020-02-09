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
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <deque>
#include <stack>
#include <functional>
#define X first
#define Y second
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
#define CASET int ___T; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define FOR(i,c) for(auto &i: c)
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI1(x) scanf("%d",&x)
#define RI2(x,y) RI1(x), RI1(y)
#define RI3(x,y...) RI1(x), RI2(y)
#define RI4(x,y...) RI1(x), RI3(y)
#define RI5(x,y...) RI1(x), RI4(y)
#define RI6(x,y...) RI1(x), RI5(y)
#define GET_MACRO(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define RI(argv...) GET_MACRO(argv, RI6, RI5, RI4, RI3, RI2, RI1)(argv)
#define DRI(argv...) int argv;RI(argv)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define DRL(x) LL x; RL(x)
#ifdef ONLINE_JUDGE
    #define PL(x) printf("%I64d\n",x)
    #define RL(x) scanf("%I64d\n",&x)
#else
    #define PL(x) printf("%lld\n",x)
    #define RL(x) scanf("%lld\n",&x)
#endif
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define DRA(A, N) VI A(N); REP(i, N) RI(A[i])
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;
template<typename T>
using V = std::vector<T>;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;

// Building the partial match table
// table[0] = -1, table[i+1] is the length of the longest
// proper suffix of W[0..i] which is a prefix of W
// time complexity O(|W|)
void kmp_table(char *W, int *T) {
    T[0] = -1;
    int lw = strlen(W);
    int pos = 1, cnd = 0;
    while(pos < lw) {
        if(W[pos] == W[cnd]) {
            T[pos] = T[cnd];
        } else {
            T[pos] = cnd;
            cnd = T[cnd];
            while (cnd >= 0 && W[pos] != W[cnd]) {
                cnd = T[cnd];
            }
        }
        pos++;
        cnd++;
    }
    T[lw] = cnd;
}

int advance(char *str, int l, int *kmp, char ch, int j) {
    while (j == l || ch != str[j]) {
        if (kmp[j] < 0) {
            return 0;
        }
        j = kmp[j];
    }
    // j < ls && c[i] == str[j]
    return j + 1;
}

char c[1005], s[51], t[51];
int kmps[51], kmpt[51];
int lc, ls, lt;

int dp[1002][51][51];

int solve(int i, int j, int k) {
    if (i == lc) return 0;
    int &ans = dp[i][j][k];
    if (ans > -INF) {
        return ans;
    }
    if (c[i] != '*') {
        j = advance(s, ls, kmps, c[i], j);
        k = advance(t, lt, kmpt, c[i], k);
        return ans = solve(i+1, j, k) + (j == ls) - (k == lt);
    }
    for (char ch = 'a'; ch <= 'z'; ch++) {
        int jj = advance(s, ls, kmps, ch, j);
        int kk = advance(t, lt, kmpt, ch, k);
        ans = max(ans, solve(i+1, jj, kk) + (jj == ls) - (kk == lt));
    }
    return ans;
}

int main() 
{
    RS(c); RS(s); RS(t);
    lc = LEN(c);
    ls = LEN(s);
    lt = LEN(t);
    kmp_table(s, kmps);
    kmp_table(t, kmpt);
    REP(i, lc) {
        REP(j, ls+1) {
            REP(k, lt+1) {
                dp[i][j][k] = -INF;
            }
        }
    }
    int ans = solve(0, 0, 0);
    PI(ans);
}
