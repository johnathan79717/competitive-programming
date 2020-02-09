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
class DisjointSet {

    void init() {
        for(int i = 0; i < N; i++) {
            par[i] = i;
            _size[i] = 1;
            left[i] = i;
            right[i] = i;
        }
    }

public:
    VI par, _size, left, right;
    int N;
    DisjointSet(int _N): par(_N), _size(_N), left(_N), right(_N), N(_N) {
        init();
    }

    int find(int x) {
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        int p;
        if(_size[x] < _size[y]) {
            p = y;
            par[x] = y;
            _size[y] += _size[x];
        } else {
            p = x;
            par[y] = x;
            _size[x] += _size[y];
        }
        left[p] = min(left[x], left[y]);
        right[p] = max(right[x], right[y]);
    }

    int size(int x) {
        return _size[find(x)];
    }
};

void dbg() {
    cerr << endl;
}

template<typename T, typename... Args>
void dbg(T t, Args... args) // recursive variadic function
{
    cerr << t << ' ';
    dbg(args...);
}

LL unfair(const VI& C, const VI& D, int K) {
    priority_queue<PII, vector<PII>, greater<PII>> qc, qd;
    int N = C.size();
    DisjointSet ds(N), ds2(N);
    REP(i, N) {
        qc.emplace(C[i], i);
        qd.emplace(D[i], i);
    }
    LL ans = 0;
    VI used(N), used2(N);
    auto loop = [&]() {
        int j = qc.top().Y;
        qc.pop();
        used2[j] = true;
        if (j && used2[j-1]) {
            ds2.unite(j-1, j);
        }
        if (j+1<N && used2[j+1]) {
            ds2.unite(j+1, j);
        }
        if (used[j]) {
            int g = ds.find(j), g2 = ds2.find(j);
            int l = max(ds.left[g], ds2.left[g2]);
            int r = min(ds.right[g], ds2.right[g2]);
            ans += 1ll * (j - l + 1) * (r - j + 1);
        }
    };
    while (qd.size()) {
        while (qc.size() && qc.top().X - qd.top().X <= K) {
            loop();
        }
        int i = qd.top().Y;
        qd.pop();
        used[i] = true;
        if (i && used[i-1]) {
            ds.unite(i-1, i);
        }
        if (i+1 < N && used[i+1]) {
            ds.unite(i, i+1);
        }
    }
    while (qc.size()) {
        loop();
    }
    return ans;
}

int main() {
    DRI(T);
    REP1(t, 1, T) {
        printf("Case #%d: ", t);
        DRI(N, K);
        VI C(N), D(N);
        REP(i, N) RI(C[i]);
        REP(i, N) RI(D[i]);
        LL u1 = unfair(C, D, K);
        LL u2 = unfair(D, C, K);
        PL((1ll + N) * N / 2 - u1 - u2);
    }
    return 0;
}
