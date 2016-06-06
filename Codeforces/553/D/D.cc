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

int deg[100005], str[100005];
bool f[100005];

struct Ratio {
    int q, p;
    Ratio() {}
    Ratio(int q, int p): q(q), p(p) {}
    bool operator<(const Ratio &r) const {
        return (LL)q * r.p < (LL)r.q * p;
    }
};

int main() 
{
    DRI(N, M, K);
    REP(i, K) {
        DRI(x);
        f[x] = true;
    }
    V(VI) adj(N+1);
    REP(i, M) {
        DRI(a, b);
        deg[a]++;
        deg[b]++;
        if (!f[a] && !f[b]) {
            str[a]++;
            str[b]++;
        }
        adj[a].PB(b);
        adj[b].PB(a);
    }
    priority_queue<pair<Ratio,int>, vector<pair<Ratio,int>>, greater<pair<Ratio,int>>> pq;
    Ratio bestr;
    int besti = -1;
    REP1(i, 1, N) {
        if (!f[i]) {
            pq.emplace(Ratio(str[i], deg[i]), i);
        }
    }
    VI v;
    while (!pq.empty()) {
        Ratio s = pq.top().first;
        int i = pq.top().second;
        pq.pop();
        if (f[i]) {
            continue;
        }
        if (besti < 0 || bestr < s) {
            bestr = s;
            besti = v.size();
        }
        v.PB(i);
        f[i] = true;
        for(int v: adj[i]) {
            if (!f[v]) {
                str[v]--;
                pq.emplace(Ratio(str[v], deg[v]), v);
            }
        }
    }
    PI(SZ(v) - besti);
    REP1(i, besti, SZ(v)-1) {
        if (i == SZ(v)-1)
            PI(v[i]);
        else
            PIS(v[i]);
    }
    // puts("");
}

