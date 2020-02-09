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
#define X first
#define Y second
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
#define CASET int ___T; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define FOR(i,c) for(auto &i: c)
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI1(x) scanf("%d",&x)
#define RI2(x,y) RI1(x), RI1(y)
#define RI3(x,y...) RI1(x), RI2(y)
#define RI4(x,y...) RI1(x), RI3(y)
#define RI5(x,y...) RI1(x), RI4(y)
#define RI6(x,y...) RI1(x), RI5(y)
#define GET_MACRO(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define RI(argv...) GET_MACRO(argv, RI6, RI5, RI4, RI3, RI2, RI1)(argv)
#define DRI(argv...) int argv;RI(argv)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define DRL(x) LL x; RL(x)
#ifdef ONLINE_JUDGE
    #define PL(x) printf("%I64d\n",x)
    #define RL(x) scanf("%I64d\n",&x)
#else
    #define PL(x) printf("%lld\n",x)
    #define RL(x) scanf("%lld\n",&x)
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
#define DRA(A, N) VI A(N); REP(i, N) RI(A[i])
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;
template<typename T>
using V = std::vector<T>;
class DisjointSet {
    VI par, _size;
    int N;

    void init(V<LL> &s) {
        for(int i = 0; i < N; i++) {
            par[i] = i;
            _size[i] = 1;
        }
    }

public:
    V<LL> left, right;
    int num_sets;
    LL sum_width;
    DisjointSet(int _N, V<LL> &s): par(_N), _size(_N), N(_N), left(s), right(s)
                         , num_sets(_N), sum_width(_N) {
        init(s);
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
        sum_width += max(left[x], left[y]) - min(right[x], right[y]) - 1;
        left[p] = min(left[x], left[y]);
        right[p] = max(right[x], right[y]);
        num_sets--;
    }

    int size(int x) {
        return _size[find(x)];
    }
};

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

int main() 
{
    DRI(n);
    V<LL> s(n);
    REP(i, n) {
        RL(s[i]);
    }
    sort(ALL(s));
    s.resize(unique(ALL(s)) - s.begin());
    priority_queue<pair<LL,int>, V<pair<LL,int>>, greater<pair<LL,int>>> pq;
    n = SZ(s);
    REP1(i, 1, n-1) {
        pq.emplace(s[i] - s[i-1], i);
    }
    DRI(q);
    V<pair<LL, int>> l(q);
    V<LL> ans(q);
    REP(i, q) {
        DRL(a); DRL(b);
        l[i].X = b - a;
        l[i].Y = i;
    }
    sort(ALL(l));
    DisjointSet ds(n, s);

    for (auto &pr : l) {
        LL r = pr.X;
        while (pq.size() && pq.top().X <= r) {
            int i = pq.top().Y;
            ds.unite(i-1, i);
            pq.pop();
        }
        ans[pr.Y] = ds.sum_width + ds.num_sets * r;
    }

    for (LL a : ans) {
        printf("%lld ", a);
    }
    puts("");
}

