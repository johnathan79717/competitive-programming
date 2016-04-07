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
int popcount(int x) { return __builtin_popcount(x); } 
int popcount(long long x) { return __builtin_popcountll(x); } 

#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
V(VI) adj;

int i, N, cnt;
stack<int> s;
int idx[100001], lowlink[100001];
bool onStack[100001];
bool important[2][100001];
V(VI) components;
int group[100001];
VI toVisit;
void strongconnect(int v) {
    idx[v] = i;
    lowlink[v] = i;
    i++;
    s.push(v);
    onStack[v] = true;
    FOR(it, adj[v]) {
        int w = *it;
        if (idx[w] < 0) {
            strongconnect(w);
        }
        if (onStack[w]) {
            lowlink[v] = min(lowlink[v], lowlink[w]);
        }
    }

    if (lowlink[v] == idx[v]) {
        // found a new strongly component
        components.EB();
        int w;
        do {
            // w is in this strongly component
            w = s.top(); s.pop();
            onStack[w] = false;
            components.back().PB(w);
            group[w] = cnt;
            if (important[0][w]) important[1][cnt] = true;
        } while(w != v);
        if (important[1][cnt]) {
            toVisit.PB(cnt);
        }
        cnt++;
        sort(ALL(components.back()));
    }
}

void tarjan() {
    components.clear();
    toVisit.clear();
    MS0(group);
    i = 0;
    s = stack<int>();
    MS0(onStack);
    MS1(idx);
    cnt = 0;
    REP1(v, 1, N) {
        if (idx[v] < 0) {
            strongconnect(v);
        }
    }
}

int main() {
    CASET {
        int M, K;
        RI(N, M, K);
        adj = V(VI)(N+1);
        MS0(important);
        REP(i, K) {
            DRI(a);
            important[0][a] = true;
        }
        REP(i, M) {
            DRI(x, y);
            adj[x].PB(y);
        }
        tarjan();
        V(VI) cadj(cnt);
        REP1(i, 1, N) {
           for (int v: adj[i]) {
               cadj[group[i]].PB(group[v]);
           }
        } 
        REP(i, cnt) {
            sort(ALL(cadj[i]));
            cadj[i].resize(unique(ALL(cadj[i])) - cadj[i].begin());
        }
        bool fail = false;
        REP(i, SZ(toVisit)-1) {
            queue<int> q;
            unordered_set<int> visit;
            visit.insert(toVisit[i+1]);
            q.push(toVisit[i+1]);
            bool found = false;
            while (SZ(q)) {
                for (int v: cadj[q.front()]) {
                    if (v == toVisit[i]) {
                        found = true;
                        break;
                    } else if (v > toVisit[i] && !visit.count(v)) {
                        q.push(v);
                        visit.insert(v);
                    }
                }
                if (found) break;
                q.pop();
            }
            if (!found) {
                fail = true;
                break;
            }
        }
        if (fail) {
            PI(-1);
            continue;
        }
        PER(i, SZ(toVisit)) {
            for (int c: components[toVisit[i]]) {
                if (important[0][c]) {
                    PIS(c);
                }
            }
        }
        puts("");
    }
    return 0;
}
