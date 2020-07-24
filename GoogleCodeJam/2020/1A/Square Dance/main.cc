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
void print(LL i);
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

#include <array>
#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)

void dbg() {
    cerr << endl;
}

template<typename T, typename... Args>
void dbg(T t, Args... args) // recursive variadic function
{
    cerr << t << ' ';
    dbg(args...);
}

int main() {
    DRI(T);
    REP1(t, 1, T) {
        printf("Case #%d: ", t);
        DRI(R, C);
        int s[R][C], l[R][C], r[R][C], u[R][C], d[R][C];
        set<PII> candidates;
        LL level = 0, ans = 0;
        REP(i, R) {
            REP(j, C) {
                RI(s[i][j]);
                l[i][j] = j-1;
                r[i][j] = j+1;
                u[i][j] = i-1;
                d[i][j] = i+1;
                candidates.emplace(i, j);
                level += s[i][j];
            }
        }
        while (candidates.size()) {
            ans += level;
            set<PII> elimination;
            for (auto &pr: candidates) {
                int compass = 0, cnt = 0;
                int x = pr.X, y = pr.Y;
                if (u[x][y] >= 0) {
                    compass += s[u[x][y]][y];
                    cnt++;
                }
                if (d[x][y] < R) {
                    compass += s[d[x][y]][y];
                    cnt++;
                }
                if (l[x][y] >= 0) {
                    compass += s[x][l[x][y]];
                    cnt++;
                }
                if (r[x][y] < C) {
                    compass += s[x][r[x][y]];
                    cnt++;
                }
                if (cnt && cnt * s[x][y] < compass) {
                    elimination.emplace(x, y);
                    level -= s[x][y];
                }
            }

            candidates.clear();

            for (auto &pr: elimination) {
                int x = pr.X, y = pr.Y;
                int uu = u[x][y], dd = d[x][y], ll = l[x][y], rr = r[x][y];
                if (uu >= 0) {
                    d[uu][y] = dd;
                    if (!elimination.count(MP(uu, y))) {
                        candidates.emplace(uu, y);
                    }
                }
                if (dd < R) {
                    u[dd][y] = uu;
                    if (!elimination.count(MP(dd, y))) {
                        candidates.emplace(dd, y);
                    }
                }
                if (ll >= 0) {
                    r[x][ll] = rr;
                    if (!elimination.count(MP(x, ll))) {
                        candidates.emplace(x, ll);
                    }
                }
                if (rr < C) {
                    l[x][rr] = ll;
                    if (!elimination.count(MP(x, rr))) {
                        candidates.emplace(x, rr);
                    }
                }
            }
        }
        PL(ans);
    }
    return 0;
}
