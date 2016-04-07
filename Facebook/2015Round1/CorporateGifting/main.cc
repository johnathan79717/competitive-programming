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
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <sstream>
#include <bitset>
using namespace std;
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define BG begin()
#define ED end()
#define FOR(i,c) for(auto &i: c)
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define RL(x) scanf("%lld",&x)
#define DRI(x) int x;RI(x)
#define DRL(x) LL x;RL(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PL(x) printf("%lld\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define PQ priority_queue
#define E emplace
#define EB emplace_back
#define LB lower_bound
#define UB upper_bound
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000;

V(VI) adj;

int maxi = 0;

pair<pair<LL, int>, pair<LL, int> > dfs(int u, int p) {
    LL perfect = 0;
    unordered_map<int, LL> extra;
    FOR(v, adj[u]) {
        if (v != p) {
            auto sub = dfs(v, u);
            perfect += sub.F.F;
            extra[sub.F.S] += sub.S.F - sub.F.F;
        }
    }
    int i = 1;
    pair<LL, int> first, second;
    first.F = second.F = LLONG_MAX;
    int cnt = 0;
    while (cnt < 2) {
        pair<LL, int> cand = MP(i+perfect, i);
        if (extra.count(i) == 0) {
            cnt++;
        } else {
            cand.F += extra[i];
        }
        if (cand < first) {
            second = first;
            first = cand;
        } else if (cand < second) {
            second = cand;
        }
        i++;
    }
    maxi = max(maxi, max(first.S, second.S));
    return MP(first, second);
}

int main() {
    int T, cas = 1;
    scanf("%d", &T);
    while(T--) {
        printf("Case #%d: ", cas++);
        DRI(N);
        adj = V(VI)(N+1);
        REP1(i, 1, N) {
            DRI(j);
            adj[i].PB(j);
            adj[j].PB(i);
        }
        PL(dfs(1, 0).F.F);
    }
    cerr << maxi << endl;
}