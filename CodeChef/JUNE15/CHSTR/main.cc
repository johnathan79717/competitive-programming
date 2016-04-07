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
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
#define ALL(x) (x).begin(),(x).end()
#define CASET2 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d:\n", case_n++) : 0), ___T-- > 0)
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
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
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define F first
#define S second
#define V(x) vector<x >
#define PV(v) REP(i, SZ(v)) if(i < SZ(v)-1) PIS(v[i]); else PI(v[i]);

int popcount(unsigned x) { return __builtin_popcount(x); } 
int popcount(unsigned long long x) { return __builtin_popcountll(x); } 

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

#include <unordered_set>
#include <unordered_map>
#define PL(x) printf("%lld\n",x)
#define EB emplace_back
#define RL(x) scanf("%lld",&x)
#define DRL(x) LL x;RL(x)

int MOD = 1000000007;
LL mul(LL a,LL b,LL mod=MOD){
  LL x = 0,y=a%mod;
  while(b > 0){
    if(b%2 == 1){
      x = x+y;
      if(x >= mod) x -= mod;
    }
    y = y*2;
    if(y >= mod) y -= mod;
    b /= 2;
  }
  return x%mod;
}

LL pow(LL a, LL b, LL c=MOD){
  LL x=1,y=a; // ll is taken to avoid overflow of intermediate results
  while(b > 0){
    if(b%2 == 1){
      x=mul(x, y, c);
    }
    y = mul(y, y, c); // squaring the base
    b /= 2;
  }
  return x%c;
}

#define PZ(x) PI((x).i);

const int MAX = 4005;
template<class Short, class Long>
struct ZZ {
    static Short MOD;
    Short i;
    ZZ():i(0) {}
    ZZ(Short i): i(i >= 0 ? i : i + MOD) {}
    ZZ(Long i): i(i % MOD) {}
    void operator +=(const ZZ& z) { i += z.i; if(i >= MOD) i -= MOD; }
    void operator -=(const ZZ& z) { i -= z.i; if(i < 0) i += MOD; }
    void operator *=(const ZZ& z) { i = (Long) i * z.i % MOD; }
    void operator /=(const ZZ& z) { (*this) *= z.inverse(); }
    ZZ operator +(const ZZ& z) const { ZZ ret(i); ret += z; return ret; }
    ZZ operator -(const ZZ& z) const { ZZ ret(i); ret -= z; return ret; }
    ZZ operator *(const ZZ& z) const { ZZ ret(i); ret *= z; return ret; }
    ZZ operator /(const ZZ& z) const { return (*this) * z.inverse(); }
    // ZZ operator -() const { return ZZ(-i); }
    ZZ inverse() const {
        Short a = i, d = MOD, x = 0, s = 1;
        while(a) {
            Short q = d / a, r = d % a, t = x - q * s;
            d = a, a = r, x = s, s = t;
        }
        if (d != 1) return Short(-1);
        return x < 0 ? x + MOD : x;
    }
    ZZ pow(long long b) {
        ZZ x=Short(1),y=*this;
        while(b > 0){
            if(b%2 == 1)
                x *= y;
            y *= y; // squaring the base
            b /= 2;
        }
        return x;
    }
    
    static vector<ZZ> factorial, inv_factorial;

    static ZZ fact(int n) {
        while(factorial.size() <= n)
            factorial.push_back(factorial.back() * SZ(factorial));
        return factorial.at(n);
    }

    static ZZ inv_fact(int n) {
        if (n < inv_factorial.size())
            return inv_factorial.at(n);
        int old_size = inv_factorial.size();
        inv_factorial.resize(n+1);
        inv_factorial.at(n) = fact(n).inverse();
        for (int i = n-1; i >= old_size; i--) {
            inv_factorial[i] = inv_factorial.at(i+1) * (i+1);
        }
        return inv_factorial.at(n);
    }

    static ZZ choose(int n, int k) {
        if(n < k) return 0;
        return fact(n) * (inv_fact(k) * inv_fact(n-k));
    }

    static pair<ZZ,int> factModExp(int n) {
            if (n == 0) return MP(1, 0);
            int e = n / MOD;
            pair<ZZ,int> pr = factModExp(e);
            if (e % 2) {
                    return MP(ZZ(0) - pr.F * fact(n % MOD), pr.S + e);
            } else {
                    return MP(pr.F * fact(n % MOD), pr.S + e);
            }
    }

    static ZZ choose2(int n, int k) {
        pair<ZZ,int> p1 = factModExp(n), p2 = factModExp(k), p3 = factModExp(n-k);
        if (p1.S > p2.S + p3.S) return 0;
        assert(p1.S == p2.S + p3.S);
        return p1.F / (p2.F * p3.F);
    }

    static ZZ choose3(int n, int k) {
        static bool first = true;
        if (first) {
            REP(i, MAX) {
                C[i][0] = 1;
                REP1(j, 1, i) {
                    C[i][j] = C[i-1][j] + C[i-1][j-1];
                }
            }
            first = false;
        }
        return C[n][k];
    } 

    static ZZ C[MAX][MAX];
};

typedef ZZ<int, LL> Z;
template<> int Z::MOD = 1000000007;
template<> vector<Z> Z::factorial(1, 1);
template<> vector<Z> Z::inv_factorial(1, 1);
template<> Z Z::C[MAX][MAX] = {};

// 該節點上方的樹枝，儲存s[a,b)的字元。
struct Node
{
    int a, b;
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
} pool[100000];
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

char s[5005];
int f[5001];
Z ans[5001];
int N, Q;

int dfs(Node *root) {
    if (root->b == 1e9) {
        f[1] += N - root->a;
        return 1;
    }
    int size = 0;
    REP(i, 27) {
        if (root->_l[i])
            size += dfs(root->_l[i]);
    }
    f[size] += root->b - root->a;
    return size;
}

int main() {
    DRI(T);
    while(T--) {
        RI(N, Q);
        RS(s);
        MS0(f);
        _p = 0;
        Node *root = Ukkonen(s);
        dfs(root);
        MS0(ans);
        REP1(k, 1, N) {
            REP1(i, k, N) {
                ans[k] += Z::choose(i, k) * f[i];
            }
        }
        while (Q--) {
            DRI(K);
            if (K > N) PI(0);
            else PZ(ans[K]);
        }
    }
    return 0;
}