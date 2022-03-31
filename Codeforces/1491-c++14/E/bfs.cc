// Create your own template by modifying this file!
#include <ctime>
#include <array>
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
typedef vector<int> VVI;
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

vector<VI> adj;
VI sz;
vector<bool> forbidden;
bool fibs[200005];

bool isFib(int, int);


bool isFib(int r, int N) {
    if (!fibs[N]) {
        return false;
    }
    if (N <= 3) {
        return true;
    }
    queue<int> q;
    q.push(r);
    q.push(-1);
    VPII a;
    while (q.size()) {
        int r = q.front(); q.pop();
        int p = q.front(); q.pop();
        sz[r] = 1;
        a.PB(r, p);
        for (int v : adj[r]) {
            if (v != p && !forbidden[v]) {
                q.push(v);
                q.push(r);
            }
        }
    }
    reverse(ALL(a));
    for (auto &pr : a) {
        int r = pr.F, p = pr.S;
        if (p >= 0) {
            sz[p] += sz[r];
        }
        if (p < 0) continue;

        forbidden[r] = true;
        bool res = isFib(p, N - sz[r]);
        forbidden[r] = false;
        if (!res) {
            continue;
        }

        forbidden[p] = true;
        res = isFib(r, sz[r]);
        forbidden[p] = false;
        if (!res) {
            continue;
        }

        debug(r, p, N, "true");
        return true;
    }
    return false;
}

void solve() {
    int N;
    R(N);
    srand(time(0));
    adj = vector<VI>(N);
    sz = VI(N);
    forbidden = vector<bool>(N);
    REP(i, N-1) {
        int u, v;
        R(u, v);
        u--;
        v--;
        adj[u].PB(v);
        adj[v].PB(u);
    }
    int a = 1, b = 2;
    fibs[a] = fibs[b] = true;
    while (a + b <= N) {
        fibs[a+b] = true;
        a += b;
        swap(a, b);
    }

    W(isFib(0, N) ? "YES" : "NO");
}

int main() {
    solve();
    return 0;
}
