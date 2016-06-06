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

VI A;
int k;
int N;
class DisjointSet {
    VI par, _size;
    V(LL) _sum;
    int N;

    void init() {
        for(int i = 0; i < N; i++) {
            par[i] = i;
            _size[i] = 1;
            assert(i * k <= ::N);
            _sum[i] = A[i * k];
        }
    }

public:
    DisjointSet(int _N): par(_N), _size(_N), _sum(_N), N(_N) {
        init();
    }

    void resize(int _N) {
        N = _N;
        init();
    }

    int find(int x) {
        assert(x < N);
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(_size[x] < _size[y]) {
            par[x] = y;
            _size[y] += _size[x];
            _sum[y] += _sum[x];
        } else {
            par[y] = x;
            _size[x] += _size[y];
            _sum[x] += _sum[y];
        }
    }

    int size(int x) {
        return _size[find(x)];
    }

    LL sum(int x) {
        return _sum[find(x)];
    }
};

bool comp(int i, int j) {
    assert(i <= N && j <= N);
    return A[i] > A[j];
}

bool used[300003];
int B[300003];

int main() {
#ifdef CPP11
    static_assert(false, "CPP11");
#endif
    CASET {
        RI(N);
        A = VI(N+1);
        REP1(i, 1, N) {
            RI(A[i]);
        }
        LL ans = 0;
        DisjointSet ds(300003);
        for (k = 1; k <= N; k++) {
            int n = 0;
            int j = k;
            while (j <= N) {
                B[n++] = j;
                j += k;
            }
            //DisjointSet ds(n+1);
            ds.resize(n+1);
            sort(B, B+n, comp);
            int s = sqrt(k);
            while ((s+1)*(s+1) <= k) s++;
            while (s * s > k) s--;
            REP(i, n) {
                assert(B[i] % k == 0);
                int b = B[i] / k;
                used[b] = true;
                if (b > 1 && used[b-1]) {
                    ds.unite(b, b-1);
                }
                if (b < n && used[b+1]) {
                    ds.unite(b, b+1);
                }
                ans = max(ans, ds.sum(b) * 1ll * A[B[i]] * s);
            }
            REP(i, n) {
                used[B[i] / k] = false;
            }
        }
        PL(ans);
    }
    return 0;
}
