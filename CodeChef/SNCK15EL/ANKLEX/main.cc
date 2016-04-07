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

#define MAX_N 1500000
int sa[MAX_N];
int c[MAX_N];
int temp[2][MAX_N];

void suffix_array(char *t, int N)
{
    int A = 128;
    int* rank = temp[0];
    int* sa2 = temp[1];
 
    for (int i=0; i<A; ++i) c[i] = 0;
    for (int i=0; i<N; ++i) c[rank[i] = t[i]]++;
    for (int i=1; i<A; ++i) c[i] += c[i-1];
    for (int i=N-1; i>=0; --i)
        sa[--c[t[i]]] = i;
 
    for (int n=1; n<N; n*=2)
    {
        int r = 0;
        for (int i=N-n; i<N; ++i)
            sa2[r++] = i;
 
        for (int i=0; i<N; ++i)
            if (sa[i] >= n)
                sa2[r++] = sa[i] - n;
 
        for (int i=0; i<A; ++i) c[i] = 0;
        for (int i=0; i<N; ++i) c[rank[i]]++;
        for (int i=1; i<A; ++i) c[i] += c[i-1];
        for (int i=N-1; i>=0; --i)
            sa[--c[rank[sa2[i]]]] = sa2[i];
 
        int*& new_rank = sa2;
        new_rank[sa[0]] = r = 0;
        for (int i=1; i<N; ++i)
        {
            if (!(rank[sa[i-1]] == rank[sa[i]] &&
                sa[i-1]+n < N &&
                rank[sa[i-1]+n] == rank[sa[i]+n]))
                r++;
            new_rank[sa[i]] = r;
        }
        swap(rank, sa2);
 
        if (r == N-1) break;
        A = r + 1;
    }
}

int lcpa[MAX_N], rk[MAX_N];
 
void lcp_array(char *s, int N)
{
    for (int i=0; i<N; ++i)
        rk[sa[i]] = i;
 
    for (int i=0, lcp=0; i<N; i++)
        if (rk[i] == 0)
            lcpa[0] = 0;
        else
        {
            int j = sa[rk[i]-1];
            if (lcp > 0) lcp--;
            while (s[i+lcp] == s[j+lcp]) {
                lcp++;
            }
            lcpa[rk[i]] = lcp;
        }
}

char s[1000000];

template<const int& (*f)(const int&, const int&)>
class SparseTable {
    V(VI) sparse_table;
public:
    template<typename T>
    SparseTable(int N, const T &A) : sparse_table(20, VI(N)) {
        REP(i, N) {
            sparse_table[0][i] = A[i];
        }
        int k = 1;
        while ((1 << k) <= N) {
            REP1(i, 0, N - (1 << k)) {
                sparse_table[k][i] = f(sparse_table[k-1][i], sparse_table[k-1][i+(1<<(k-1))]);
            }
            k++;
        }
    }
    int query(int l, int r) {
        assert(l <= r);
        int k = sizeof(int) * 8 - 1 - __builtin_clz(r+1-l);
        return f(sparse_table[k][l], sparse_table[k][r+1-(1<<k)]);
    }
};

int main() {
    RS(s);
    int N = LEN(s);
    suffix_array(s, N);
    lcp_array(s, N);
    SparseTable<min> lcp(N, lcpa), suffix(N, sa);
    CASET {
        DRI(idx, len);
        idx--;
        int r = rk[idx];
        int lb = r, ub = N;
        while (ub - lb > 1) {
            int m = (ub + lb) / 2;
            if (lcp.query(r+1, m) < len) {
                ub = m;
            } else {
                lb = m;
            }
        }
        if (ub == N) {
            PI(-1);
            continue;
        }
        int i = ub;
        if (N - sa[i] < len) {
            lb = i, ub = N;
            while (ub - lb > 1) {
                int m = (ub + lb) / 2;
                if (N - suffix.query(i, m) >= len) {
                    ub = m;
                } else {
                    lb = m;
                }
            }
            if (ub == N) {
                PI(-1);
                continue;
            }
            i = ub;
        }
        lb = i, ub = N;
        while (ub - lb > 1) {
            int m = (ub + lb) / 2;
            if (lcp.query(i+1, m) < len) {
                ub = m;
            } else {
                lb = m;
            }
        }
        PI(suffix.query(i, lb)+1);
    }
    return 0;
}