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

char S1[100001], S2[100001], ans[100001];

V(VI) adj;

bool visited[100001];
VI index;

void dfs(int u) {
    index.PB(u);
    FOR(v, adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    CASET {
        DRII(N, M);
        RS(S1); RS(S2);
        adj = V(VI)(N);
        MS0(visited);
        while (M--) {
            DRII(a, b);
            a--; b--;
            adj[a].PB(b);
            adj[b].PB(a);
        }
        REP(i, N) {
            if (!visited[i]) {
                int freq[26];
                index.clear();
                dfs(i);
                sort(ALL(index));
                MS0(freq);
                FOR(j, index) {
                    freq[S1[j]-'a']++;
                }
                int k = 0;
                int tmp[26];
                memcpy(tmp, freq, sizeof freq);
                FOR(j, index) {
                    while (!tmp[k]) k++;
                    if (k >= S2[j] - 'a' && freq[S2[j] - 'a']) {
                        freq[S2[j] - 'a']--;
                        ans[j] = S2[j];
                    }
                    tmp[k]--;
                }
            }
        }

    }
    return 0;
}
