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

#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define PL(x) printf("%lld\n", x)
#define RL(x) scanf("%lld", &x)
#define DRL(x) LL x; RL(x);
#define MAX_N 30003
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

int lcpa[MAX_N];
 
void lcp_array(char *s, int N)
{
    int *rank = temp[0];
    for (int i=0; i<N; ++i)
        rank[sa[i]] = i;
 
    for (int i=0, lcp=0; i<N; i++)
        if (rank[i] == 0)
            lcpa[0] = 0;
        else
        {
            int j = sa[rank[i]-1];
            if (lcp > 0) lcp--;
            while (s[i+lcp] == s[j+lcp]) {
                // assert(max(i, j) + lcp < N);
                lcp++;
            }
            lcpa[rank[i]] = lcp;
        }
}
template<const int& (*combine)(const int&, const int&)>
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
                sparse_table[k][i] = combine(sparse_table[k-1][i], sparse_table[k-1][i+(1<<(k-1))]);
            }
            k++;
        }
    }
    int query(int l, int r) {
        assert(l <= r);
        int k = sizeof(int) * 8 - 1 - __builtin_clz(r+1-l);
        return combine(sparse_table[k][l], sparse_table[k][r+1-(1<<k)]);
    }
};

char S[30004];
int dp[30003];
int main() {
    CASET {
        DRI(N, A, B);
        RS(S);
        reverse(S, S+N);
        suffix_array(S, N);
        lcp_array(S, N);
        SparseTable<min> lcp_st(N, lcpa);
        SparseTable<max> sa_st(N, sa);
        dp[N] = 0;
        int *rank = temp[0];
        PER(i, N) {
            dp[i] = dp[i+1] + A;
            int j = rank[i];
            if (j > 0) {
                int ub = j-1, lb = 0;
                auto f = [&](int m) { return sa_st.query(m, j-1) - i; };
                auto g = [&](int m) { return lcp_st.query(m+1, j); };
                while (ub - lb > 1) {
                    int m = (ub + lb) / 2, a = f(m), b = g(m);
                    if (a > b) {
                        lb = m;
                    } else {
                        ub = m;
                    }
                }
                int d = max(min(f(lb), g(lb)), min(f(ub), g(ub)));
                if (d > 0) {
                    dp[i] = min(dp[i], dp[i+d] + B);
                }
            }
            if (j < N-1) {
                int lb = j+1, ub = N-1;
                auto f = [&](int m) { return sa_st.query(j+1, m) - i; };
                auto g = [&](int m) { return lcp_st.query(j+1, m); };
                while (ub - lb > 1) {
                    int m = (ub + lb) / 2;
                    int a = f(m), b = g(m);
                    if (a > b) {
                        ub = m;
                    } else {
                        lb = m;
                    }
                }
                int d = max(min(f(lb), g(lb)), min(f(ub), g(ub)));
                if (d > 0) {
                    dp[i] = min(dp[i], dp[i+d] + B);
                }
            }
        }
        PI(dp[0]);
    }
    return 0;
}
