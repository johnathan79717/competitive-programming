#include <functional>
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

#define DRL(x) LL x; RL(x)
#ifndef LOCAL
    #define PL(x) printf("%I64d\n",x)
    #define RL(x) scanf("%I64d\n",&x)
#else
    #define PL(x) printf("%lld\n",x)
    #define RL(x) scanf("%lld\n",&x)
#endif

struct Query {
    int l, r, i;
};
const int B = 450;
bool compare(const Query &q1, const Query &q2) {
    if (q1.l / B != q2.l / B) {
        return q1.l / B < q2.l / B;
    } else if (q1.l / B % 2) {
        return q1.r > q2.r;
    } else {
        return q1.r < q2.r;
    }
}
int main() {
#ifdef CPP11
    static_assert(false, "CPP11");
#endif
    CASET {
        DRI(N);
        VI a(N+1);
        VI s(N+1);
        REP1(i, 1, N) RI(a[i]);
        REP1(i, 2, N-1) {
            if (a[i-1] <= a[i] && a[i] <= a[i+1]) {
                s[i] = true;
            }
        }
        DRI(Q);
        V(Query) q(Q);
        VI b(Q);
        REP(i, Q) {
            RI(q[i].l, q[i].r);
            q[i].i = i;
        }
        sort(ALL(q), compare);
        map<LL, int> mp;
        int l = 1, r = 0;
        int ans = 0;
        LL c = rand(), d = rand(), e = rand();
        REP(i, Q) {
            while (r < q[i].r) {
                r++;
                if (r - l + 1 >= 3 && s[r-1]) {
                    if (mp[a[r-2]*c + a[r-1]*d + a[r]*e]++ == 0) {
                        ans++;
                    }
                }
            }
            while (l > q[i].l) {
                l--;
                if (r - l + 1 >= 3 && s[l+1]) {
                    if (mp[a[l]*c + a[l+1]*d + a[l+2]*e]++ == 0) {
                        ans++;
                    }
                }
            }
            while (r > q[i].r) {
                if (r - l + 1 >= 3 && s[r-1]) {
                    if (mp[a[r-2]*c + a[r-1]*d + a[r]*e]++ == 1) {
                        mp.erase(a[r-2]*c+a[r-1]*d+a[r]*e);
                        ans--;
                    }
                }
                r--;
            }
            while (l < q[i].l) {
                if (r - l + 1 >= 3 && s[l+1]) {
                    if (mp[a[l]*c + a[l+1]*d + a[l+2]*e]++ == 1) {
                        ans--;
                        mp.erase(a[l]*c+a[l+1]*d+a[l+2]*e);
                    }
                }
                l++;
            }
            b[q[i].i] = ans;
        }
        REP(i, Q) {
            PI(b[i]);
        }
    }
    return 0;
}
