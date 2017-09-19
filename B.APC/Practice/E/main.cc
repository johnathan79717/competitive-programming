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
//const int INF = 1000000000;

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

#include <unordered_set>
#include <unordered_map>
#define EB emplace_back

list<pair<int,int>> adj[10001];
int N, M, X;
long long d[10001];

const long long INF = 1e18;

typedef pair<long long, int> P;
long long shortest_path(int ub) {
    for (int i = 1; i <= N; i++) {
        d[i] = INF;
    }
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(d[1] = 0, 1);
    while (pq.size()) {
        auto p = pq.top();
        pq.pop();
        int i = p.second;
        if (p.first > d[i]) {
            continue;
        }
        if (i == N) {
            return d[i];
        }
        for (auto& edge : adj[i]) {
            if (edge.second > ub) {
                continue;
            }
            int j = edge.first;
            if (d[i] + edge.second < d[j]) {
                d[j] = d[i] + edge.second;
                pq.emplace(d[j], j);
            }
        }
    }
    return INF;
}

int main() {
    scanf("%d%d%d", &N,&M,&X);
    while (M--) {
        int C1, C2, T;
        scanf("%d%d%d", &C1, &C2, &T);
        adj[C1].emplace_back(C2, T);
        adj[C2].emplace_back(C1, T);
    }
    long long L = shortest_path(1e9);
    int lb = 0, ub = 1e9+1;
    while (ub - lb > 1) {
        int m = lb + (ub - lb) / 2;
        long long l = shortest_path(m);
        if (l * 100 <= L * (100 + X)) {
            ub = m;
        } else {
            lb = m;
        }
    }
    printf("%d\n", ub);
    return 0;
}
