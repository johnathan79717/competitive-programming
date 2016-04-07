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
#define BG begin()
#define ED end()
#define FOR(i,c) for(auto &i: c)
#define SZ size()
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

struct E {
    int to, y;
    E(int t, int y): to(t), y(y) {}
};

V(V(E)) adj;
VI X;

bool dfs(int v) {
    FOR(e, adj[v]) {
        if (X[e.to] < 0) {
            X[e.to] = X[v] ^ e.y;
            if (!dfs(e.to)) {
                return false;
            }
        } else if (X[e.to] != (X[v] ^ e.y)) {
            return false;
        }
    }
    return true;
}
int K;

void dfs2(int v, int p) {
    X[v] ^= K;
    FOR(e, adj[v]) {
        if (e.to != p) {
            dfs2(e.to, v);
        }
    }
}

int main() {
    DRII(N, M);
    RI(K);
    K--;
    adj.resize(N+1);
    X = VI(N+1, -1);
    REP(i, M) {
        DRIII(u, v, y);
        adj[u].EB(v, y);
        adj[v].EB(u, y);
    }
    VI last;
    int m = -1;
    for (int i = 1; i <= N; i++) {
        if (X[i] < 0) {
            // X[i] = 0;
            // last = i;
            // if (!dfs(i)) {
            //     PI(-1);
            //     return 0;
            // }
            queue<int> q;
            q.push(i);
            X[i] = 0;
            VI tmp;
            while (!q.empty()) {
                int j = q.front();
                q.pop();
                tmp.PB(j);
                FOR(e, adj[j]) {
                    if (X[e.to] < 0) {
                        q.push(e.to);
                        X[e.to] = X[j] ^ e.y;
                    } else if (X[e.to] != (X[j] ^ e.y)) {
                        PI(-1);
                        return 0;
                    }
                }
            }
            int t = *min_element(ALL(tmp));
            if (t > m) {
                m = t;
                last = move(tmp);
            }
        }
    }
    // dfs2(last, 0);
    FOR(i, last) {
        X[i] ^= K;
    }
    REP1(i, 1, N) {
        if (i < N)
            PIS(X[i]);
        else
            PI(X[i]);
    }
    return 0;
}
