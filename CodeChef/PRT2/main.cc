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
#ifdef HOME
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;

int closest = MOD;
vector<VI> adj;

int dfs(int v, int p) {
    VI h;
    for (int u : adj[v]) {
        if (u != p) {
            h.PB(dfs(u, v));
        }
    }
    if (h.empty()) {
        return 1;
    }
    sort(ALL(h));
    if (p == -1 && SZ(h) == 1) {
        closest = min(closest, h[0] + 1);
    } else if (SZ(h) >= 2) {
        closest = min(closest, h[0] + h[1] + 1);
    }
    return h[0] + 1;
}

void solve() {
    closest = MOD;
    int N, K;
    R(N, K);
    VI A(N);
    REP(i, N) {
        R(A[i]);
    }
    sort(ALL(A), greater<int>());
    adj = vector<VI>(N);
    REP(i, N-1) {
        int u, v;
        R(u, v);
        adj[u-1].PB(v-1);
        adj[v-1].PB(u-1);
    }
    dfs(0, -1);

    LL sum = 0;
    VI B;
    REP(i, closest) {
        sum += A[i] * 2;
        B.PB(A[i]);
        B.PB(A[i]);
    }
    closest *= 2;
    sum *= (K / closest);
    if (K % closest == 2) {
        sum += A[0] + A[1];
    } else {
        REP(i, K % closest) {
            sum += B[i];
        }
    }
    W(sum);
}

int main() {
#define MULTITEST 1
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}
