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

#include <atcoder/dsu>
#include <atcoder/modint>

#define MULTITEST 1
# define MULTITEST 1
void solve() {
    int C, N, M;
    R(C, N, M);
    vector<VI> l(C), r(C);
    VI ps = {1, N+1};
    REP(i, C) {
        int x;
        R(x);
        l[i].resize(x);
        r[i].resize(x);
        REP(j, x) {
            R(l[i][j], r[i][j]);
            ps.PB(l[i][j]);
            r[i][j]++;
            ps.PB(r[i][j]);
        }
    }
    SORT_UNIQUE(ps);
    int n = SZ(ps) - 1;
    atcoder::dsu dsu(n);
    set<PII> seg;
    REP(i, n) {
        seg.emplace(i, i);
    }
    vector<bool> used(n);
    REP(i, C) {
        REP(j, SZ(l[i])) {
            int l1 = GET_POS(ps, l[i][j]), r1 = GET_POS(ps, r[i][j]);
            used[l1] = true;
            if (j) {
                debug(l1, GET_POS(ps, l[i][j-1]));
                dsu.merge(l1, GET_POS(ps, l[i][j-1]));
            }
            r1--;
            auto it = seg.lower_bound(MP(l1, 0));
            if (it == seg.end() || it->F > r1) {
                continue;
            }
            int l2 = it->F, r2 = it->S;
            while (it != seg.end() && it->F <= r1) {
                r2 = max(r2, it->S);
                if (it != seg.begin() && prev(it)->S >= l1) {
                    l2 = min(l2, prev(it)->F);
                    debug(prev(it)->S, it->F);
                    dsu.merge(prev(it)->S, it->F);
                    used[it->F] = true;
                    used[prev(it)->S] = true;
                    seg.erase(prev(it));
                }
                it++;
            }
        }
    }
    int s = dsu.groups().size();
    debug(dsu.groups());
    REP(i, n) {
        if (!used[i]) {
            s += ps[i+1] - ps[i] - 1;
        }
    }

    W(atcoder::modint998244353(M).pow(s).val());
}

#undef int
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
