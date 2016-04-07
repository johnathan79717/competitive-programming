#include <list>
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
#define CASET2 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d:\n", case_n++) : 0), ___T-- > 0)
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define REP(i,n) for(int i=0;i<int(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=int(b);i++)
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
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define X first
#define Y second
#define V(x) vector<x >

typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

void print(int i) { printf("%d", i); }
template<class T> void PI(T i) { print(i); puts(""); }
template<class T> void PIS(T i) { print(i); printf(" "); }

template<class T>
void PV(T const &v, int N) {
    REP(i, N) {
        print(v[i]);
        printf("%c", i == N-1 ? '\n' : ' ');
    }
}

template<class T> void PV(T const &v) { PV(v, SZ(v)); }

template<class T, class S> bool has_bit(T mask, S i) { return (mask >> i) & 1; }
long long shift(int i) { return 1ll << i; }

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(int x) { return __builtin_popcount(x); } 
int popcount(long long x) { return __builtin_popcountll(x); } 

#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)

char A[1004], B[1004];
int dp[1004][1004][26], sum[1005][1005];

int lcs[1004][1004], lcsk[1004][1004][26];

string ans;
int N;

void solve(int i, int j, int K) {
    if (lcs[i][j] == 0) {
        if (K == 1) {
            cout << ans << endl;
        } else {
            PI(-1);
        }
        return;
    }
    REP(c, 26) {
        if (lcsk[i][j][c] != lcs[i][j]) {
            continue;
        }
        if (K <= dp[i][j][c]) {
            while (A[i] != c+'a') i++;
            while (B[j] != c+'a') j++;
            ans.PB(c+'a');
            solve(i+1, j+1, K);
            return;
        }
        K -= dp[i][j][c];
    }
    PI(-1);
}

int main() {
    RI(N);
    DRI(K);
    RS(A);
    RS(B);

    PER(i, N) PER(j, N) {
        REP(k, 26) {
            if (A[i] == 'a' + k) {
                if (B[j] == 'a' + k) {
                    dp[i][j][k] = max(1, sum[i+1][j+1]);
                    lcsk[i][j][k] = 1 + lcs[i+1][j+1];
                } else {
                    dp[i][j][k] = dp[i][j+1][k];
                    lcsk[i][j][k] = lcsk[i][j+1][k];
                }
            } else {
                if (B[j] == 'a' + k) {
                    dp[i][j][k] = dp[i+1][j][k];
                    lcsk[i][j][k] = lcsk[i+1][j][k];
                } else {
                    dp[i][j][k] = dp[i+1][j+1][k];
                    lcsk[i][j][k] = lcsk[i+1][j+1][k];
                }
            }
            lcs[i][j] = max(lcs[i][j], lcsk[i][j][k]);
        }
        REP(k, 26) {
            if (lcsk[i][j][k] == lcs[i][j]) {
                sum[i][j] += dp[i][j][k];
                if (sum[i][j] > K) {
                    sum[i][j] = K+1;
                }
            }
        }
    }
    fprintf(stderr, "%d\n", sum[0][0]);

    if (lcs[0][0] == 0) {
        puts("");
        return 0;
    }

    solve(0, 0, K);

    return 0;
}
