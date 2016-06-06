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
#include <new>

const int POOL_SIZE = 1000004;
struct Node {
    Node *child[26];
    int isLeaf;
    Node() : isLeaf(-1) {
        memset(child, 0, sizeof child);
    }
    void insert(char *word, int i) {
        if (*word) {
            getChild(*word)->insert(word+1, i);
        } else {
            isLeaf = i;
        }
    }
    static Node pool[POOL_SIZE];
    static Node *ptr;
    Node* getChild(char c) {
        if ('A' <= c && c <= 'Z') {
            c = c - 'A' + 'a';
        }
        return child[c-'a'] ? child[c-'a'] : (child[c-'a'] = new(ptr++) Node);
    }
} Node::pool[], *Node::ptr = pool;

char t[10005];
char w[1001];
V<string> d;

int dp[10004];
int main() 
{
    DRI(N);
    RS(t);
    auto root = new(Node::ptr++)Node;
    DRI(M);
    REP(i, M) {
        RS(w);
        d.EB(w);
        reverse(w, w+LEN(w));
        root->insert(w, i);
    }
    MS1(dp);
    dp[N] = N;
    PER(i, N) {
        int j = i;
        Node *p = root;
        while (p->child[t[j]-'a']) {
            p = p->child[t[j]-'a'];
            j++;
            if (p->isLeaf >= 0 && dp[j] >= 0) {
                dp[i] = p->isLeaf;
                break;
            }
        }
    }
    assert(dp[0] >= 0);
    int i = 0;
    while (i < N) {
        printf("%s ", d[dp[i]].c_str());
        i = i + SZ(d[dp[i]]);
    }
    puts("");
}


