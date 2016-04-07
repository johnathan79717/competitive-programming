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

#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)

V(PII) edge[100001];
bool used[100001];
VI factors;

int mul[501][501];
int N, M;

//int subtree[100001];
int paths[100001][24];
int num[501];

LL ans;
void dfs(int root, int p) {
    //subtree[root] = 1;
    for (auto &e: edge[root]) {
        if (e.X == p) continue;
        dfs(e.X, root);
        //subtree[root] += subtree[e.X];
        REP(i, SZ(factors)) {
            REP(j, SZ(factors)) {
                int k = mul[j][num[e.Y]];
                if (mul[i][k] == num[M]) {
                    ans += paths[root][i] * 1ll * paths[e.X][j];
                }
            }
            if (mul[i][num[e.Y]] == num[M]) {
                ans += paths[root][i];
            }
        }

        REP(i, SZ(factors)) {
            int k = mul[i][num[e.Y]];
            paths[root][k] += paths[e.X][i];
            if (k == num[M]) {
                ans += paths[e.X][i];
            }
        }
        if (e.Y == M) ans++;
        paths[root][num[e.Y]]++;
    }
}

//int center(int root) {
    //dfs(root);
    //int p = root;
    //while (true) {
        //bool stop = true;
        //for (auto &e: edge[p]) {
            //if (subtree[e.X] >= N/2) {
                //p = e.X;
                //stop = false;
                //break;
            //}
        //}
        //if (stop) break;
    //}
    //return p;
//}

//VI solve(int root) {
    //int c = center(root);
    //used[c] = true;
    //VI a(SZ(factors));
    //for (auto &e: edge[c]) {
        //VI s = solve(e.X);
        //REP(i, SZ(s)) {
            //a[mul[factors[i]][e.Y]] += s[i];
        //}            
    //}
    //REP(i, SZ(factors)) {
        //REP(j, i) {
            //if (mul[factors[i]][factors[j]] == M) {
                //ans += a[i] * 1ll * a[j];
            //}
        //}
    //}
//}

int main() {
    RI(N, M);
    for (int p = 1; p * p <= M; p++) {
        if (M % p == 0) {
            factors.PB(p);
            if (p * p < M) {
                factors.PB(M / p);
            }
        }
    }
    sort(ALL(factors));
    REP(i, SZ(factors)) num[factors[i]] = i;
    REP(i, SZ(factors)) {
        REP(j, SZ(factors)) {
            mul[i][j] = num[__gcd(M, factors[i] * factors[j])];
        }
    }
    REP(i, N-1) {
        DRI(a, b, c);
        c = __gcd(c, M);
        edge[a].EB(b, c);
        edge[b].EB(a, c);
    }
    dfs(1, -1);
    PL(ans);
    return 0;
}
