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
#ifdef DEBUG
 #define debug(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define debug(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;

char s[1005][1005];
int d[1005][1005];

void solve() {
    int H, WW, Ch, Cw, Dh, Dw;
    R(H, WW, Ch, Cw, Dh, Dw);
    Ch--; Cw--; Dh--; Dw--;
    REP(i, H) {
        R(s[i]);
        REP(j, WW) {
            d[i][j] = MOD;
        }
    }
    priority_queue<pair<int, PII>, vector<pair<int, PII>>, greater<pair<int, PII>>> pq;
    pq.emplace(0, MP(Ch, Cw));
    d[Ch][Cw] = 0;
    while (!pq.empty()) {
        auto pr = pq.top();
        pq.pop();
        int h = pr.S.F, w = pr.S.S;
        if (h == Dh && w == Dw) {
            W(pr.F);
            return;
        }
        if (pr.F > d[h][w]) {
            continue;
        }
        int dh[] = {1, 0, -1, 0}, dw[] = {0, 1, 0, -1};
        REP(k, 4) {
            int h1 = h + dh[k];
            if (h1 < 0 || h1 >= H) {
                continue;
            }
            int w1 = w + dw[k];
            if (w1 < 0 || w1 >= WW || s[h1][w1] != '.' || d[h1][w1] <= d[h][w]) {
                continue;
            }
            pq.emplace(d[h1][w1] = d[h][w], MP(h1, w1));
        }
        FOR(dh, -2, 2) {
            int h1 = h + dh;
            if (h1 < 0 || h1 >= H) {
                continue;
            }
            FOR(dw, -2, 2) {
                int w1 = w + dw;
                if (w1 < 0 || w1 >= WW || s[h1][w1] != '.' || d[h1][w1] <= d[h][w] + 1) {
                    continue;
                }
                pq.emplace(d[h1][w1] = d[h][w] + 1, MP(h1, w1));
            }
        }
    }
    W(-1);
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

