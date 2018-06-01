#include <functional>
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
#define REP(i,n) for(int i=0;i<int(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=int(b);i++)
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
void print(LL i);
template<class T> void PI(T i) { print(i); puts(""); }
template<class T> void PIS(T i) { print(i); printf(" "); }

template<class T>
void PV(T const &v, int N) {
    REP(i, N) {
        print(v[i]);
        printf("%c", i == N-1 ? '\n' : ' ');
    }
}

template<class T> void PV(T const &v) { PV(v, SZ(v)); }

template<class T, class S> bool has_bit(T mask, S i) { return (mask >> i) & 1; }
long long shift(int i) { return 1ll << i; }

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(int x) { return __builtin_popcount(x); } 
int popcount(long long x) { return __builtin_popcountll(x); } 

// 該節點上方的樹枝，儲存s[a,b)的字元。
struct Node
{
    int a, b;
    int value, top;
    Node* _l[27], *suffix;
    Node* &l(int i) {
        if (i == 0) return _l[26];
        return _l[i - 'a'];
    }
    Node() {}
    Node(int a, int b): a(a), b(b), suffix(0)
    {
        memset(_l, 0, sizeof(_l));
    }
} pool[1000000];
int _p = 0;

Node *get(int a, int b) {
    Node *ans = &pool[_p++];
    *ans = Node(a, b);
    return ans;
}
 
Node *Ukkonen(char *s)
{
    Node* root = get(0, 0), *p = root;
 
    // 逐次加入字元s[i]。包含'\0'。
    int N = strlen(s);
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
                p->l(s[a]) = q = get(r->a, k);
                q->l(s[k]) = r; r->a = k;
            }
 
            // 建立樹葉。終身為葉。
            q->l(s[i]) = get(i, 1e9);
 
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

#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)

char t[100005];
int N;

void dfs(Node *v) {
    VI values;
    for (int i = 0; i < 26; i++) {
        Node *u = v->_l[i];
        if (u) {
            dfs(u);
            values.PB(u->top);
        }
    }
    v->b = min(N, v->b);
    sort(ALL(values));
    values.resize(unique(ALL(values)) - values.begin());
    v->value = values.size();
    for (int i = 0; i < SZ(values); i++) {
        if (values[i] != i) {
            v->value = i;
            break;
        }
    }
    if (v->a + 1 == v->b) {
        v->top = v->value;
    } else if (v->a % 2 == v->b % 2) {
        v->top = !v->value;
    } else {
        v->top = !!v->value;
    }
}

char s[100005];

int main() {
    while(RS(t) != EOF) {
        _p = 0;
        N = LEN(t);
        Node *root = Ukkonen(t);
        dfs(root);
        DRI(n);
        int ans = 0;
        while (n--) {
            RS(s);
            Node *p = root;
            int i = 0;
            int M = LEN(s);
            while (i - p->a + p->b < M) {
                i += p->b - p->a;
                p = p->l(s[i]);
            }
            int v;
            if (i + p->b - p->a == M) {
                v = p->value;
            } else if (i % 2 == M % 2) {
                v = !p->top;
            } else {
                v = !!p->top;
            }
            ans ^= v;
        }
        //PI(ans);
        puts(ans ? "Alice" : "Bob");
    }
    return 0;
}
