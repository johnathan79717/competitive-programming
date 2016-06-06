// Create your own template by modifying this file!
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
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <stack>
#include <functional>
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define FOR(i,c) for(auto &i: c)
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#ifdef ONLINE_JUDGE
    #define PL(x) printf("%I64d\n",x);
#else
    #define PL(x) printf("%lld\n",x)
#endif
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define V(x) vector<x>
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const LL INF = 1e18;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;

LL d[200005];
int h[200005];

struct T {
    LL diff, sum, ans;
};

// template<typename T>
struct SegmentTree {
    // static T identity;
    int n;
    vector<T> dat;

    // void update(int k, T const& a) {
    //     // starting from leaf node
    //     k += n - 1;
    //     dat[k] = a;
    //     while(k > 0) {
    //         k = (k - 1) / 2;
    //         // dat[k] = combine(k, k * 2 + 1, k * 2 + 2);
    //         int chl = k*2+1, chr = k*2+2;
    //         dat[k].diff = max(dat[chl].diff, dat[chr].diff);
    //         dat[k].sum = max(dat[chl].sum, dat[chr].sum);
    //         dat[k].ans = max(dat[chl].diff + dat[chr].diff, max(dat[chl].ans, dat[chr].ans));
    //     }
    // }

    T query(int a, int b) {
        return query(a, b, 0, 0, n);
    }

    static T identity;

    T query(int a, int b, int k, int l, int r) {
        // if [a, b) and [l, r) are disjoint
        if(r <= a || b <= l) return identity;
        // if [l, r) contains [a, b)
        if(a <= l && r <= b) return dat[k];
        else {
            T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            // return combine(vl, vr);
            T ret;
            ret.diff = max(vl.diff, vr.diff);
            ret.sum = max(vl.sum, vr.sum);
            ret.ans = max(vl.diff + vr.sum, max(vl.ans, vr.ans));
            return ret;
        }
    }

    SegmentTree(int n_) {
        real_size = n_;
        n = 1;
        while(n < n_) n *= 2;
        dat.resize(2*n-1);
        init(0, 0, n);
    }

    int real_size;

    void init(int k, int l, int r) {
        if(r - l == 1) {
            // leaf
            // setLeaf(k, l);
            if (l >= real_size) return;
            dat[k].diff = h[l] - d[l];
            dat[k].sum = h[l] + d[l];
            // dat[k].ans = dat[k].diff + dat[k].sum;
            dat[k].ans = -INF;
        } else {
            // non-leaf
            int chl = k * 2 + 1, chr = k * 2 + 2;
            init(chl, l, (l + r) / 2);
            init(chr, (l + r) / 2, r);
            // dat[k] = combine(dat[chl], dat[chr]);
            dat[k].diff = max(dat[chl].diff, dat[chr].diff);
            dat[k].sum = max(dat[chl].sum, dat[chr].sum);
            dat[k].ans = max(dat[chl].diff + dat[chr].sum, max(dat[chl].ans, dat[chr].ans));
        }
    }
    void setLeaf(int k, int l);
    T combine(const T& vl, const T& vr);
};

T SegmentTree::identity = (T){-INF, -INF, -INF};

// template<>
// void SegmentTree<Data>::setLeaf(int k, int l) {

// }

// template<>
// Data SegmentTree<Data>::combine(const Data &vl, const Data &vr) {

// }

// template<>
// Data SegmentTree<Data>::identity;

int main() 
{
    DRII(N, M);
    REP(i, N) {
        DRI(dd);
        d[i+1] = d[i+N+1] = dd;
    }
    REP(i, 2*N) {
        d[i+1] += d[i];
    }
    REP(i, N) {
        RI(h[i]);
        h[i] *= 2;
        h[i+N] = h[i];
    }
    SegmentTree st(2*N);
    while (M--) {
        DRII(a, b);
        // printf("%I64d\n", a <= b ? st.query(b+1-1, a-1+N).ans : st.query(b+1-1, a-1).ans);
        PL(a <= b ? st.query(b+1-1, a-1+N).ans : st.query(b+1-1, a-1).ans);
    }
}

