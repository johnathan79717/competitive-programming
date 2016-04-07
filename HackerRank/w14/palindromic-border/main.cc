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
const int INF = 1000000000;

// char t[100001];       // 要處理的字串
char s[100001 * 2];   // 中間插入特殊字元的t。
int Z[100001 * 2], L, R;  // Gusfield's Algorithm
int N;
// 由a往左、由b往右，對稱地作字元比對。
int match(int a, int b)
{
    int i = 0;
    while (a-i>=0 && b+i<N && s[a-i] == s[b+i]) i++;
    return i;
}
 
void manacher(char *t)
{
    N = strlen(t);
 
    // 在t中插入特殊字元，存放到s。
    memset(s, '.', N*2+1);
    for (int i=0; i<N; ++i) s[i*2+1] = t[i];
    N = N*2+1;
 
    // modified Gusfield's lgorithm
    Z[0] = 1;
    L = R = 0;
    for (int i=1; i<N; ++i)
    {
        int ii = L - (i - L);   // i的映射位置
        int n = R + 1 - i;
 
        if (i > R)
        {
            Z[i] = match(i, i);
            L = i;
            R = i + Z[i] - 1;
        }
        else if (Z[ii] == n)
        {
            Z[i] = n + match(i-n, i+n);
            L = i;
            R = i + Z[i] - 1;
        }
        else
        {
            Z[i] = min(Z[ii], n);
        }
    }
 
    // // 尋找最長迴文子字串的長度。
    // int n = 0, p = 0;
    // for (int i=0; i<N; ++i)
    //     if (Z[i] > n)
    //         n = Z[p = i];
 
    // // 記得去掉特殊字元。
    // cout << "最長迴文子字串的長度是" << (n-1) / 2;
 
    // // 印出最長迴文子字串，記得別印特殊字元。
    // for (int i=p-Z[p]+1; i<=p+Z[p]-1; ++i)
    //     if (i & 1)
    //         cout << s[i];
}

char str[100005];

// 該節點上方的樹枝，儲存s[a,b)的字元。
struct Node
{
    int a, b;
    Node* _l[9], *suffix;
    Node* &l(int i) { return _l[i - 'a']; }
    int cnt;
    Node(int a, int b): a(a), b(b), suffix(0), cnt(0)
    {
        memset(_l, 0, sizeof(_l));
    }
    int count() {
        if (b == INF) {
            return cnt = 1;
        }
        REP(i, 8) {
            if (_l[i])
                cnt += _l[i]->count();
        }
        if (_l[8]) cnt++;
        return cnt;
    }
    LL dfs(int depth) {
        depth += b - a;
        LL ans = (LL)cnt * (cnt-1) / 2 * (min(b, N) - a);
        REP(i, 8) {
            if (_l[i])
                ans += _l[i]->dfs(depth);
        }
        return ans;
    }
};
 
Node *Ukkonen(char *s, int N)
{
    Node* root = new Node(0, 0), *p = root;
 
    // 逐次加入字元s[i]。包含'\0'。
    // int N = strlen(s);
    for (int a=0, i=0; i<N+1; ++i)
    {
        Node* ant = root;
        while (a <= i)
        {
            // 往下走，直到字元s[i-1]出現。
            while (true)
            {
                if (a == i) break;
                Node* q = p->l(s[a]);
                if (a + q->b - q->a > i) break;
                a += q->b - q->a;
                p = q;
            }
 
            Node* q = p;
            if (a == i)     // s[i-1]位在樹枝末梢。
            {
                // 節點已經建立。
                if (p->l(s[i])) break;
            }
            else if (a < i) // s[i-1]位在樹枝中間。
            {
                // 節點已經建立。
                Node* r = p->l(s[a]);
                int k = r->a + i - a;
                if (s[i] == s[k]) break;
 
                // 節點尚未建立。
                // 分裂此樹枝，以利將來插入樹葉。
                p->l(s[a]) = q = new Node(r->a, k);
                q->l(s[k]) = r; r->a = k;
            }
 
            // 建立樹葉。終身為葉。
            q->l(s[i]) = new Node(i, 1e9);
 
            // 建立上次樹葉的suffix link，連到這次樹葉。
            // 至於這次樹葉的suffix link要等到下次才知道。
            if (ant != root) ant->suffix = q;
            ant = q;
 
            // 走訪suffix link
            if (p->suffix) p = p->suffix;
            else a++;   // 次長後綴在同一個節點
        }
        if (ant != root) ant->suffix = p;
    }
    return root;
}

void clean(Node *root) {
    for(int i = 0; i < 9; i++)
        if(root->_l[i])
           clean(root->_l[i]);
    delete root;
}

// int main() {
//     Node *root = Ukkonen();
//     clean(root);
// }

int main() {
    RS(str);
    manacher(str);
    N = LEN(str);
    str[N] = 'a'+8;
    Node *root = Ukkonen(str, N);
    root->count();
    PL(root->dfs());
  return 0;
}