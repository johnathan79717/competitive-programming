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

#include <vector>
using namespace std;

template<class T>
void Min(T& x, const T& y) {
    x = min(x, y);
}

#define chl(k) (k*2+1)
#define chr(k) (k*2+2)
int H, WW;

template<class Data, class Lazy>
struct SegmentTree {
    // static Data identity;
    int n;
    int size;
    vector<Data> dat;
    vector<Lazy> lazy;

    int real_size;
    SegmentTree(int n_) {
        real_size = n_;
        n = 1;
        size = n_;
        while(n < n_) n *= 2;
        dat = vector<Data>(2*n-1);
        lazy = vector<Lazy>(2*n-1, MOD);
        init(0, 0, n);
    }

    void init(int k, int l, int r) {
        if(r - l == 1) {
            if (l < real_size) { 
                dat[k] = H;
            }
        } else {
            // non-leaf
            int m = (l+r)/2;
            init(chl(k), l, m);
            init(chr(k), m, r);
            dat[k] = combine(dat[chl(k)], dat[chr(k)]);
        }
    }

    void update(int a, int z) {
        update(a, a+1, 0, 0, n, z);
    }
    void update(int a, int b, const Lazy &d) {
        update(a, b+1, 0, 0, n, d);
    }

    void propagate(int k, int l, int r) {
        dat[k] = min(dat[k], lazy[k]);
        if (chr(k) < lazy.size()) {
            Min(lazy[chl(k)], lazy[k]);
            Min(lazy[chr(k)], lazy[k]);
        }
        lazy[k] = MOD;
    }

    void update(int a, int b, int k, int l, int r, const Lazy &d) {
        // we have to make sure dat[k] is the right value after update
        propagate(k, l, r);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] = d;
            propagate(k, l, r);
        } else {
            int m = (l+r)/2;
            update(a, b, chl(k), l, m, d);
            update(a, b, chr(k), m, r, d);
            dat[k] = combine(dat[chl(k)], dat[chr(k)]);
        }
    }

    Data query(int a) {
        return query(a, a);
    }

    Data query(int a, int b) {
        return query(a, b+1, 0, 0, n);
    }

    Data query(int a, int b, int k, int l, int r) {
        // if [a, b) and [l, r) are disjoint
        if(r <= a || b <= l) return MOD;
        propagate(k, l, r);
        // if [l, r) contains [a, b)
        if(a <= l && r <= b) {
            return dat[k];
        } else {
            Data vl = query(a, b, chl(k), l, (l + r) / 2);
            Data vr = query(a, b, chr(k), (l + r) / 2, r);
            return combine(vl, vr);
        }
    }

    Data combine(Data vl, Data vr) {
        return min(vl, vr);
    }
};
void solve() {
    R(H, WW);

    VI A(H), B(H);
    REP(i, H) {
        R(A[i], B[i]);
        A[i]--;
        B[i]--;
    }

    SegmentTree<int, int> st(WW);
    VI next(H, MOD);
    for (int i = H-1; i >= 0; i--) {
        if (B[i] < WW-1) {
            next[i] = st.query(B[i]+1);
        }
        st.update(A[i], B[i], i);
    }

    debug(next);

    VI dp(H+1, MOD), ans(H+1, MOD);

    REP(w, WW) {
        if (w >= A[0] && w <= B[0]) {
            continue;
        }
        int h = st.query(w);
        if (h < MOD) {
            ans[h] = 0;
            if (B[h] < WW-1) {
                Min(dp[h], B[h] + 1 - w);
            }
        }
    }

    REPP(i, 1, H) {
        if (dp[i] < MOD) {
            int h = next[i];
            if (h < MOD) {
                Min(ans[h], dp[i]);
                if (B[h] < WW-1) {
                    Min(dp[h], dp[i] + B[h] - B[i]);
                }
            }
        }
    }

    for (int h = H; h; h--) {
        Min(ans[h-1], ans[h]);
    }

    FOR(h, 1, H) {
        W(ans[h] < MOD ? ans[h] + h : -1);
    }
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

