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
#include <deque>
#include <stack>
#include <functional>
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
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
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

VI lc[1001], rc[1001];
struct Node
{
    Node *lc, *rc;
    int val;
} pool[1001];

Node *get() {
    static int i = 0;
    return &pool[i++];
}

int maximum(int v) {
    int ans = v;
    FOR(u, lc[v]) {
        ans = max(ans, maximum(u));
    }
    FOR(u, rc[v]) {
        ans = max(ans, maximum(u));
    }
    return ans;
}
int minimum(int v) {
    int ans = v;
    FOR(u, lc[v]) {
        ans = min(ans, minimum(u));
    }
    FOR(u, rc[v]) {
        ans = min(ans, minimum(u));
    }
    return ans;
}

Node *solve(int l, int r) {
    if (l > r) return 0;
    Node *root = get();
    root->val = l;
    int M = 0, m = INF;
    FOR(v, lc[l]) {
        M = max(M, maximum(v));
    }
    FOR(v, rc[l]) {
        m = min(m, minimum(v));
    }
    if (M > 0 && m < INF && m <= M) {
        puts("IMPOSSIBLE");
        exit(0);
    }
    if (M == 0) {
        root->rc = solve(l+1, r);
    } else if (m == INF) {
        root->lc = solve(l+1, r);
    } else {
        root->lc = solve(l+1, m-1);
        root->rc = solve(m, r);
    }
    return root;
}

void print(Node *root) {
    if (root->lc) {
        print(root->lc);
    }
    PIS(root->val);
    if (root->rc) {
        print(root->rc);
    }
}

int main() 
{
    DRII(n, c);
    while (c--) {
        DRII(a, b);
        char str[10];
        RS(str);
        if (str[0] == 'L') {
            lc[a].PB(b);
        } else {
            rc[a].PB(b);
        }
        if (a >= b) {
            puts("IMPOSSIBLE");
            return 0;
        }
    }
    Node *root = solve(1, n);
    print(root);
    puts("");
}

