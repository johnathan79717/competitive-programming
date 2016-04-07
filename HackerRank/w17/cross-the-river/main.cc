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
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
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
const int INF = 2000000000;

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

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(int x) { return __builtin_popcount(x); } 
int popcount(long long x) { return __builtin_popcountll(x); } 

#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
typedef int T;
struct SegmentTree {
    int n;
    vector<T> dat;

    void update(int k, T const& a) {
        // starting from leaf node
        k += n - 1;
        dat[k] = a;
        while(k > 0) {
            k = (k - 1) / 2;
            dat[k] = combine(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    T query(int a, int b) {
        return query(a, b+1, 0, 0, n);
    }

    T query(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) {
            // if [a, b) and [l, r) are disjoint
            return -INF;
        } else if(a <= l && r <= b) {
            // if [l, r) contains [a, b)
            return dat[k];
        } else {
            T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return combine(vl, vr);
        }
    }

    int real_size;
    SegmentTree(int n_) {
        real_size = n_;
        n = 1;
        while(n < n_) n *= 2;
        //dat.resize(2*n-1);
        dat = VI(2*n-1, -INF);
        init(0, 0, n);
    }

    void init(int k, int l, int r) {
        if(r - l == 1) {
            // leaf
            if (l >= real_size)
                return;
        } else {
            // non-leaf
            init(k*2+1, l, (l + r) / 2);
            init(k*2+2, (l + r) / 2, r);
            dat[k] = combine(dat[k*2+1], dat[k*2+2]);
        }
    }
    T combine(T const & vl, T const & vr);
};

T SegmentTree::combine(T const & vl, T const & vr) {
    return max(vl, vr);
}

struct Rock {
    int Y, X, Z;
    bool operator<(const Rock& other) const {
        return Y < other.Y;
    }
};

int dp[100005];
deque<int> largestIndices[100005];

int main() {
    DRI(N, H, dH, dW);
    V(Rock) rock(N);
    REP(i, N) {
        DRI(Y, X, Z);
        rock[i] = {Y, X, Z};
    }
    sort(ALL(rock));
    SegmentTree st(100005);
    int l = 0, r = 0, toRemove = 0;
    int ans = -INF;
    while (l < N) {
        int y = rock[l].Y;
        while (r < N && rock[r].Y == y) {
            r++;
        }
        assert(toRemove <= l);
        while (rock[toRemove].Y < y - dH) {
            assert(toRemove < l);
            auto &largestIndex = largestIndices[rock[toRemove].X];
            if (largestIndex.front() == toRemove) {
                largestIndex.pop_front();
            }
            st.update(rock[toRemove].X, largestIndex.size() ? dp[largestIndex.front()] : -INF);
            toRemove++;
            assert(toRemove <= l);
        }
        REP1(i, l, r-1) {
            dp[i] = rock[i].Z + st.query(rock[i].X - dW, rock[i].X + dW);
            if (y <= dH) dp[i] = max(dp[i], rock[i].Z);
            if (dp[i] < -INF/2) dp[i] = -INF;
            if (y + dH >= H) ans = max(ans, dp[i]);
        }
        REP1(i, l, r-1) {
            auto &largestIndex = largestIndices[rock[i].X];
            while (largestIndex.size() && dp[largestIndex.back()] <= dp[i]) {
                largestIndex.pop_back();
            }
            largestIndex.push_back(i);
            st.update(rock[i].X, dp[largestIndex.front()]);
        }
        l = r;
    }
    assert(ans > -INF);
    PI(ans);
    return 0;
}
