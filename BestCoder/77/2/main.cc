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

char a[505][505], b[505][505];
bool used[505][505];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int main() {
#ifdef CPP11
    static_assert(false, "CPP11");
#endif
    CASET {
        DRI(N, M);
        REP(i, N) {
            RS(a[i]);
        }
        DRI(Q);
        V(PII) p(Q);
        REP(i, Q) {
            RI(p[i].X, p[i].Y);
        }
        int lb = -1, ub = Q+1;
        while (ub - lb > 1) {
            int mid = (ub + lb) / 2;
            MS0(used);
            memcpy(b, a, sizeof a);
            REP(i, mid) {
                b[p[i].X][p[i].Y] = '1';
            }
            queue<PII> q;
            REP(j, M) {
                if (b[0][j] == '0') {
                    q.push(MP(0, j));
                }
            }
            bool success = false;
            while (q.size()) {
                int x = q.front().X, y = q.front().Y;
                q.pop();
                REP(k, 4) {
                    int xx = x + dx[k], yy = y + dy[k];
                    if (xx >= 0 && xx < N && yy >= 0 && yy < M && b[xx][yy] == '0' && !used[xx][yy]) {
                        if (xx == N-1) {
                            success = true;
                            break;
                        }
                        used[xx][yy] = true;
                        q.push(MP(xx, yy));
                    }
                }
                if (success) break;
            }
            if (success) {
                lb = mid;
            } else {
                ub = mid;
            }
        }
        if (ub > Q) {
            PI(-1);
        } else {
            PI(ub);
        }
    }
    return 0;
}
