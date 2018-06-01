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

VI A;

//typedef multiset<int> T;
typedef VI T;

T combine(T &d1, T &d2) {
    T ans;
    auto i = d1.begin(), j = d2.begin();
    while (i != d1.end() && j != d2.end()) {
        if (*i > *j) {
            ans.PB(*(i++));
        } else {
            ans.PB(*(j++));
        }
    }
    while (i != d1.end()) {
        ans.PB(*(i++));
    }
    while (j != d2.end()) {
        ans.PB(*(j++));
    }
    if (SZ(ans) > 45) {
        ans.resize(45);
    }
    return ans;
}

struct SegmentTree {
    int n;
    vector<T> dat;

    //void update(int k, int a, int old) {
        //dat[k].insert(a);
        //auto it = dat[k].find(old);
        //dat[k].erase(it);
    //}

    void update(int k, int a) {
        // starting from leaf node
        k += n - 1;
        dat[k] = { a };
        while(k > 0) {
            k = (k - 1) / 2;
            dat[k] = combine(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    typedef pair<int, pair<T*, T::reverse_iterator>> P;
    struct Compare {
        bool operator()(const P& x, const P&y) {
            return x.first < y.first;
        }
    };
    priority_queue<P, vector<P>, Compare> pq;

    T query(int a, int b) {
        //if (a > b) return T::identity();
        return query(a, b+1, 0, 0, n);
    }

    T query(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) {
            // if [a, b) and [l, r) are disjoint
            return T();
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
        dat.resize(2*n-1);
        init(0, 0, n);
    }

    void init(int k, int l, int r) {
        if(r - l == 1) {
            // leaf
            if (l >= real_size)
                return;
            dat[k] = { A[l] };
        } else {
            // non-leaf
            init(k*2+1, l, (l + r) / 2);
            init(k*2+2, (l + r) / 2, r);
            dat[k] = combine(dat[k*2+1], dat[k*2+2]);
        }
    }
};
#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)


int main() {
    DRI(N, Q);
    A.resize(N);
    REP(i, N) {
        RI(A[i]);
    }
    SegmentTree st(N);
    while(Q--) {
        DRI(t);
        if (t == 1) {
            DRI(pos, val);
            st.update(pos-1, val);
        } else {
            DRI(l, r);
            if (r - l + 1 < 3) {
                PI(0);
            } else {
                LL ans = 0;
                VI b = st.query(l-1, r-1);
                REP(i, SZ(b) - 2) {
                    if (b[i] < b[i+1] + b[i+2]) {
                        ans = 0ll + b[i] + b[i+1] + b[i+2];
                        break;
                    }
                }
                PL(ans);
            }
        }
    }
    return 0;
}
