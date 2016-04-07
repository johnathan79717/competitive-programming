#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;
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
const int INF = 2000000000;

int main() {
    DRI(T);
    while(T--) {
        DRII(N, M);
        V(VI) adj(N+1);
        // V(list<int>::iterator) it(N+1);
        VI d(N+1, INF);
        while (M--) {
            DRII(a, b);
            adj[a].PB(b);
            adj[b].PB(a);
        }
        DRI(s);
        queue<int> q({s});
        d[s] = 0;
        set<int> unpushed;
        // list<int> unpushed;
        REP1(i, 1, N) {
            if (i != s) {
                unpushed.insert(i);
                // unpushed.push_front(i);
                // it[i] = unpushed.begin();
            }
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            set<int> topush;
            // list<int> topush;
            swap(topush, unpushed);
            FOR(u, adj[v]) {
                if (d[u] == INF) {
                    topush.erase(u);
                    unpushed.insert(u);
                    // topush.erase(it[u]);
                    // unpushed.push_front(u);
                    // it[u] = unpushed.begin();
                }
            }
            FOR(u, topush) {
                if (d[u] == INF) {
                    q.push(u);
                    d[u] = d[v] + 1;
                }
            }
        }
        REP1(i, 1, N) {
            if (i != s) {
                PIS(d[i]);
            }
        }
        puts("");
    }
  return 0;
}