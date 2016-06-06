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

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(unsigned x) { return __builtin_popcount(x); } 
int popcount(unsigned long long x) { return __builtin_popcountll(x); } 

#include <unordered_set>
#include <unordered_map>
#define PL(x) printf("%lld\n",x)
void print(LL i) { PL(i); }
#define EB emplace_back
#define RL(x) scanf("%lld",&x)
#define DRL(x) LL x;RL(x)

int color[50001], socket[100001];

int neg(int var) {
    return var ^ 1;
}

struct SAT {
    int N;
    SAT() : N(0) {}
    V(VI) adj;
    VI idx, lowlink, onStack, ans;
    stack<int> stack;
    int i;
    int addVariable() {
        N += 2;
        return N - 2;
    }
    void imply(int a, int b) {
        adj.resize(N);
        adj[a].PB(b);
        adj[neg(b)].PB(neg(a));
    }
    bool fail;
    void dfs(int v) {
        idx[v] = i;
        lowlink[v] = i;
        i++;
        stack.push(v);
        onStack[v] = true;
        FOR(it, adj[v]) {
            int w = *it;
            if (idx[w] < 0) {
                dfs(w);
                if (fail) return;
            }
            if (onStack[w]) {
                lowlink[v] = min(lowlink[v], lowlink[w]);
            }
        }

        if (lowlink[v] == idx[v]) {
            // found a new strongly component
            int w;
            set<int> comp;
            do {
                // w is in this strongly component
                w = stack.top(); stack.pop();
                onStack[w] = false;
                if (comp.count(neg(w))) {
                    fail = true;
                    return;
                }
                comp.insert(w);
                if (!ans[neg(w)]) ans[w] = true;
            } while(w != v);
        }
    }

    bool solve() {
        i = 0;
        onStack = VI(N);
        idx = VI(N, -1);
        lowlink = VI(N);
        ans = VI(N);
        fail = false;
        REP(v, N) {
            if (idx[v] < 0) {
                dfs(v);
                if (fail) return false;
            }
        }
        return true;
    }
};

int var[100001], pre[50001];

int main() {
#ifdef ONLINE_JUDGE
    freopen("chip.in", "r", stdin);
    freopen("chip.out", "w", stdout);
#endif
    DRI(N);
    REP1(i, 1, N) {
        RI(color[i]);
    }
    N *= 2;
    SAT sat;
    MS1(pre);
    REP(i, N) {
        RI(socket[i]);
        var[i] = sat.addVariable();
        if (i > 0 && color[socket[i]] == color[socket[i-1]]) {
            sat.imply(var[i], neg(var[i-1]));
        }
        if (pre[socket[i]] >= 0) {
            sat.imply(var[i], neg(pre[socket[i]]));
            sat.imply(neg(var[i]), pre[socket[i]]);
        }
        pre[socket[i]] = var[i];
    }
    sat.imply(var[N-1], neg(var[0]));
    if (sat.solve()) {
        puts("YES");
        VI a(N/2+1);
        REP(i, N) {
            if (sat.ans[var[i]]) {
                assert(a[socket[i]] == 0);
                a[socket[i]] = i+1;
            }
        }
        REP1(i, 1, SZ(a)) {
            if (i == SZ(a)-1) {
                PI(a[i]);
                break;
            } else {
                PIS(a[i]);
            }
        }
    } else {
        puts("NO");
    }
    return 0;
}
