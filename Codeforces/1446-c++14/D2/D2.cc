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
//#ifdef DEBUG
 //#define debug(...) {printf("[DEBUG] ");W(__VA_ARGS__);        fflush(stdout);}
//#else
 #define debug(...)
//#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
template<class T> void MIN(T& a, const T& b) { a = min(a, b); }
template<class T> void MAX(T& a, const T& b) { a = max(a, b); }

void solve() {
    int N;
    R(N);
    VI A(N);
    int D = 0;
    map<int, VI> occ;
    VI f(N);
    REP(i, N) {
        R(A[i]);
        occ[A[i]].PB(i);
        if (!D || SZ(occ[A[i]]) > SZ(occ[D])) {
            D = A[i];
        }
        f[i] = SZ(occ[A[i]]);
    }
    int ans = 0;
    set<int> allD(ALL(occ[D]));
    for (auto &pr : occ) {
        int V = pr.F;
        debug("V", V);
        if (D == V) continue;
        const VI& occV = pr.S;

        VI occD;
        for (int v : occV) {
            debug("v", v);
            auto it = allD.lower_bound(v);
            REP(i, 2) {
                if (it != allD.end()) {
                    occD.PB(*it);
                    it = allD.erase(it);
                }
            }
            REP(i, 2) {
                if (it != allD.begin()) {
                    --it;
                    if (it != allD.end()) {
                        occD.PB(*it);
                        it = allD.erase(it);
                    }
                }
            }
        }
        debug("D", D, "V", V, "occD", occD, "occV", occV);

        SORT_UNIQUE(occD);
        for (int o : occD) {
            allD.insert(o);
        }


        VI all;
        merge(ALL(occV), ALL(occD), back_inserter(all));

        debug("all", all);

        auto it = allD.lower_bound(all[0]);
        int cv = 0, cd = it != allD.begin() ? f[*prev(it)] : 0, pf = cd - cv;
        unordered_map<int, int> pos;
        pos[0] = -1;
        for (int i : all) {
            if (pos.count(pf)) {
                ans = max(ans, i - 1 - pos[pf]);
            }
            if (A[i] == D) {
                cd = f[i];
            } else if (A[i] == V) {
                cv = f[i];
            }
            pf = cd - cv;
            if (!pos.count(pf)) {
                pos[pf] = i;
            }
        }
        cd = f[*allD.rbegin()];
        pf = cd - cv;
        if (pos.count(pf)) {
            ans = max(ans, N - 1 - pos[pf]);
        }
        debug("ans", ans);
    }
    W(ans);

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
