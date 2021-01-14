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
#include <bitset>
#include <numeric>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB emplace_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
template<class T> void _R(T &x) { cin >> x;  }
void _R(int &x) { scanf("%d", &x);  }
void _R(int64_t &x) { scanf("%lld", &x);  }
void _R(double &x) { scanf("%lf", &x);  }
void _R(char &x) { scanf(" %c", &x);  }
void _R(char *x) { scanf("%s", x);  }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...);  }
template<class T> void _W(const T &x) { cout << x;  }
void _W(const int &x) { printf("%d", x);  }
void _W(const int64_t &x) { printf("%lld", x);  }
void _W(const double &x) { printf("%.16f", x);  }
void _W(const char &x) { putchar(x);  }
void _W(const char *x) { printf("%s", x);  }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' ');  }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...);  }
#ifdef DEBUG
 #define debug(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define debug(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
template<class T> void MIN(T& a, const T& b) { a = min(a, b); }
template<class T> void MAX(T& a, const T& b) { a = max(a, b); }

#include <atcoder/all>
#define MULTITEST 0

using namespace atcoder;
using Mint = modint1000000007;

char S[SIZE];
int a[550];

void solve() {
    a['A'] = 1;
    a['B'] = 2;
    a['C'] = 3;
 
    int N;
    string S;
    cin >> N >> S;
    {
        set<char> st;
        for (auto s : S) {
            st.insert(s);
        }
        if (st.size() == 1) {
            cout << 1 << endl;
            return;
        }
    }
 
    vector<Mint> dp(N + 1);
    vector<array<Mint, 4>> pref(N + 1);
 
    dp[0] = 1;
    pref[0][0] = 1;
 
    vector<int> prex(N + 1);
    vector<int> la(4, -1);
 
    REP(i, N) {
        int c = a[S[i]];
 
        prex[i + 1] = prex[i] ^ c;
        int cur = prex[i + 1];
 
        debug(i, la);
 
        for (int j = 1; j <= 3; ++j) {
            //dp[i + 1] += pref[i][cur ^ j];
            //if (la[cur] > 0) dp[i + 1] -= pref[la[cur] - 1][cur ^ j];
            for (int k = max(la[cur], 0); k <= i; k++) {
                if (prex[k] == (cur ^ j)) {
                    dp[i+1] += dp[k];
                }
            }
        }
 
        REP(j, 4) pref[i + 1][j] = pref[i][j];
        pref[i + 1][cur] += dp[i + 1];
 
        la[cur] = i + 1;
    }
 
    Mint ans = 0;
    REP(i, N) {
        if (prex[N] == prex[i + 1]) {
            ans += dp[i + 1];
        }
    }
 
    cout << ans.val() << endl;
    //int N;
    //R(N);
    //R(S);
    //VI A(N);
    //VI p(N+1); // p[i] = xor of A[0..i-1]
    //VI diffs;
    //vector<VI> x(4);
    //int pr = 0;
    //REP(i, N) {
        //A[i] = S[i] - 'A' + 1;
        //if (i && A[i] != A[i-1]) {
            //diffs.PB(i);
        //}
        //p[i+1] = p[i] ^ A[i];
        //x[p[i+1]].PB(i+1);
    //}
    //vector<mint> dp(N+1);
    //dp[N] = 0;
    //int d = N;
    //for (int i = N-1; i >= 0; i--) {
        //FOR(k, 1, 3) {
            //if (A[i] == k) {
                //dp[i] += dp[i+1];
                //continue;
            //}
            //auto it = lower_bound(ALL(diffs), i+1);
            //if (it == diffs.end()) {
                //continue;
            //}
            //int d = *it; // first d s.t. A[d] != A[d-1]
            //int xo = p[i] ^ k;
            //it = lower_bound(ALL(x[xo]), d);
            //if (it == x[xo].end()) {
                //continue;
            //}
            //int b2 = 
        //}
    //}
}

int main() {
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}
