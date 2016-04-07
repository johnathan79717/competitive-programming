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
using namespace std;
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(x) (x).begin(),(x).end()
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define RI(argv...) GET_MACRO(argv, RI3, RI2, RI1)(argv)
#define RI1(x) scanf("%d",&x)
#define DRI(argv...) int argv...;RI(argv)
#define RI2(x,y) scanf("%d%d",&x,&y)
#define RIL(args...) while (RI(args) != EOF)
#define DRIL(args...) int args; RIL(args)
#define RI3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define F first
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

V(VI) adj;

int main() {
    DRIL(N, M, K) {
        adj = V(VI)(N+1);
        VI in(N+1);
        while(M--) {
            DRI(u, v);
            adj[u].PB(v);
            in[v]++;
        }
        set<vertex> 
    }
    return 0;
}
