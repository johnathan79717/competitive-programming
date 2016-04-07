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
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
#define ALL(x) (x).begin(),(x).end()
#define CASET2 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d:\n", case_n++) : 0), ___T-- > 0)
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
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
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define F first
#define S second
#define V(x) vector<x >
#define PV(v) REP(i, SZ(v)) if(i < SZ(v)-1) PIS(v[i]); else PI(v[i]);

int popcount(unsigned x) { return __builtin_popcount(x); } 
int popcount(unsigned long long x) { return __builtin_popcountll(x); } 

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

#include <unordered_set>
#include <unordered_map>
#define PL(x) printf("%lld\n",x)
#define EB emplace_back
#define RL(x) scanf("%lld",&x)
#define DRL(x) LL x;RL(x)

struct T {
    int min;
    bool all;
    int left;
    int right;
    PII max;
};

int A[100005];

struct SegmentTree {
    int n;
    vector<T> dat;
    int real_size;

    SegmentTree(int _n): real_size(_n), n(1) {
        while(n < real_size) n *= 2;
        dat.resize(2*n-1);
        init(0, 0, n);
    }

    void init(int k, int l, int r) {
        if(r - l == 1) {
            // leaf
            if (l >= real_size)
                return;
            // TODO set leaf
            dat[k].min = l;
            dat[k].all = dat[k].left = dat[k].right = dat[k].max.F = (A[l] == 1);
            dat[k].max.S = -l;
        } else {
            // non-leaf
            int m = (l + r) / 2;
            init(k*2+1, l, m);
            init(k*2+2, m, r);
            dat[k] = combine(dat[k*2+1], dat[k*2+2], m);
        }
    }

    void update(int l) {
        int k = l + n - 1;
        dat[k].min = l;
        dat[k].all = dat[k].left = dat[k].right = dat[k].max.F = (A[l] == 1);
        dat[k].max.S = -l;
        int r = l + 1;
        while (k > 0) {
            if (k % 2) {
                r = r + r - l;
            } else {
                l = l - (r - l);
            }
            k = (k - 1) / 2;
            dat[k] = combine(dat[k*2+1], dat[k*2+2], (l+r)/2);
        }
    }

    // void update(int k, T const& a) {
    //     // starting from leaf node
    //     k += n - 1;
    //     dat[k] = a;
    //     while(k > 0) {
    //         k = (k - 1) / 2;
    //         dat[k] = combine(dat[k * 2 + 1], dat[k * 2 + 2]);
    //     }
    // }

    T query(int a, int b) {
        return query(a, b+1, 0, 0, n);
    }

    T query(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) {
            // if [a, b) and [l, r) are disjoint
            T ret;
            ret.min = -1;
            return ret;
        } else if(a <= l && r <= b) {
            // if [l, r) contains [a, b)
            return dat[k];
        } else {
            int m = (l+r)/2;
            T vl = query(a, b, k * 2 + 1, l, m);
            T vr = query(a, b, k * 2 + 2, m, r);
            return combine(vl, vr, m);
        }
    }

    T combine(T const & vl, T const & vr, int m);
};

T SegmentTree::combine(T const & vl, T const & vr, int m) {
    if (vl.min < 0) return vr;
    if (vr.min < 0) return vl;
    T ans;
    ans.min = (A[vl.min] <= A[vr.min]) ? vl.min : vr.min;
    ans.all = vl.all && vr.all;
    ans.left = vl.left;
    if (vl.all) ans.left += vr.left;
    ans.right = vr.right;
    if (vr.all) ans.right += vl.right;
    ans.max = max(max(vl.max, vr.max), MP(vl.right + vr.left, -(m - vl.right)));
    return ans;
}

int main() {
    DRI(N, Q);
    REP(i, N) RI(A[i]);
    SegmentTree st(N);
    while (Q--) {
        DRI(t, i, j);
        if (t == 1) {
            T ans = st.query(i-1, j-1);
            if (A[ans.min] == 0) {
                PIS(0); PIS(i); PI(j);
            } else if (A[ans.min] > 1) {
                PIS(A[ans.min]); PIS(ans.min+1); PI(ans.min+1);
            } else {
                PIS(1); PIS(-ans.max.S+1); PI(-ans.max.S+ans.max.F);
            }
        } else {
            assert(t == 2);
            A[i-1] = j;
            st.update(i-1);
        }
    }
    return 0;
}