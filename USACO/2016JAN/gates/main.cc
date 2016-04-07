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

/*
ID: johnath2
PROG: gates
LANG: C++11
*/
#include <unordered_set>
#include <unordered_map>
#define NAME "gates"

const int L = 1005;
char step[L];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
set<PII> adj[4];
enum { E, N, W, S };
bool visited[2*L][2*L];
void dfs(int i, int j) {
    visited[i][j] = true;
    REP(k, 4) {
        if (adj[k].count(MP(i, j))) continue;
        int ii = i + dx[k], jj = j + dy[k];
        if (ii < 0 || ii >= 2*L || jj < 0 || jj >= 2*L) {
            continue;
        }
        if (!visited[ii][jj]) {
            dfs(ii, jj);
        }
    }
}
int main() {
#ifndef STDIO
    freopen(NAME".in", "r", stdin);
    freopen(NAME".out", "w", stdout);
#endif
    DRI(n);
    int x = L, y = L;
    RS(step);
    REP(i, n) {
        if (step[i] == 'N') {
            adj[W].emplace(x, y);
            adj[E].emplace(x-1, y);
            y++;
        } else if (step[i] == 'S') {
            y--;
            adj[W].emplace(x, y);
            adj[E].emplace(x-1, y);
        } else if (step[i] == 'E') {
            adj[S].emplace(x, y);
            adj[N].emplace(x, y-1);
            x++;
        } else {
            x--;
            adj[S].emplace(x, y);
            adj[N].emplace(x, y-1);
        }
    }
    int ans = 0;
    REP(i, 2*L) {
        REP(j, 2*L) {
            if (!visited[i][j]) {
                ans++;
                dfs(i, j);
            }
        }
    }
    PI(ans - 1);
    return 0;
}
