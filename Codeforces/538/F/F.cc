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
#include <cassert>
#include <deque>
#include <stack>
#include <functional>
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
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
#define GET_4TH(_1, _2, _3, NAME, ...) NAME
#define RI(argv...) GET_4TH(argv, RI3, RI2, RI1)(argv)
#define RI1(x) scanf("%d",&x)
#define RI2(x,y) RI1(x), RI1(y)
#define RI3(x,y,z) RI1(x), RI2(y, z)
#define DRI(argv...) int argv;RI(argv)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#ifdef ONLINE_JUDGE
    #define PL(x) printf("%I64d\n",x);
#else
    #define PL(x) printf("%lld\n",x)
#endif
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
#define DRA(A, N) VI A(N); REP(i, N) RI(A[i])
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

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

int a[1000000];

void merge(VI &a, VI &b, VI &c) {
    a.reserve(SZ(b) + SZ(c));
    int i = 0, j = 0;
    while (i < SZ(b) && j < SZ(c)) {
        if (b[i] < c[j]) {
            a.PB(b[i++]);
        } else {
            a.PB(c[j++]);
        }
    }
    while (i < SZ(b)) a.PB(b[i++]);
    while (j < SZ(c)) a.PB(c[j++]);
}

typedef VI T;
struct SegmentTree {
    int n;
    int real_size;
    vector<T> dat;

    int query(int a, int b, int x) {
        return query(a, b, 0, 0, n, x);
    }

    int query(int a, int b, int k, int l, int r, int x) {
        if(r <= a || b <= l) {
            // if [a, b) and [l, r) are disjoint
            // return identity;
            return 0;
        } else if(a <= l && r <= b) {
            // if [l, r) contains [a, b)
            return lower_bound(ALL(dat[k]), x) - dat[k].BG;
        } else {
            int vl = query(a, b, k * 2 + 1, l, (l + r) / 2, x);
            int vr = query(a, b, k * 2 + 2, (l + r) / 2, r, x);
            // return combine(vl, vr);
            return vl + vr;
        }
    }

    SegmentTree(int n_) {
        real_size = n_;
        n = 1;
        while(n < n_) n *= 2;
        dat.resize(2*n-1);
        init(0, 0, n);
    }

    void init(int k, int l, int r) {
        if(r - l == 1) {
            // leaf
            if (l >= real_size)
                return;
            // TODO set leaf
            dat[k].PB(a[l]);
        } else {
            // non-leaf
            init(k*2+1, l, (l + r) / 2);
            init(k*2+2, (l + r) / 2, r);
            // dat[k] = combine(dat[k*2+1], dat[k*2+2]);
            merge(dat[k], dat[k*2+1], dat[k*2+2]);
        }
    }
    T combine(const T& vl, const T& vr);
};

int main() 
{
    DRI(N);
    REP(i, N) {
        RI(a[i]);
    }
    SegmentTree st(N);
    REP1(k, 1, N-1) {
        int ans = 0;
        REP(v, N) {
            if ((LL)k * v + 1 >= N) {
                break;
            }
            ans += st.query(k*v+1, k*v+k+1, a[v]);
        }
        if (k == N-1)
            PI(ans);
        else
            PIS(ans);
    }
}

