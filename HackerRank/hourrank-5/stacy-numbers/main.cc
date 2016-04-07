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
int MOD = 1000000007;
long long mul(long long a,long long b,long long mod=MOD){
  long long x = 0,y=a%mod;
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

long long pow(long long a, long long b, long long c=MOD){
  long long x=1,y=a; // ll is taken to avoid overflow of intermediate results
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
        return pow(MOD - 2);
    }
    ZZ pow(long long b) const {
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

    static ZZ choose0(int n, int k) {
        assert(n < 1e7);
        if(n < k) return 0;
        return fact(n) * (inv_fact(k) * inv_fact(n-k));
    }

    static ZZ choose1(int n, int k) {
        assert(k < 1e7);
        if (n < k) return 0;
        if (k == 0) return 1;
        return choose1(n-1, k-1) * n / k;
    }

    static pair<ZZ,int> factModExp(int n) {
            if (n == 0) return MP(1, 0);
            int e = n / MOD;
            pair<ZZ,int> pr = factModExp(e);
            if (e % 2) {
                    return MP(ZZ(0) - pr.first * fact(n % MOD), pr.second + e);
            } else {
                    return MP(pr.first * fact(n % MOD), pr.second + e);
            }
    }

    static ZZ choose2(int n, int k) {
        assert(MOD < 1e7);
        pair<ZZ,int> p1 = factModExp(n), p2 = factModExp(k), p3 = factModExp(n-k);
        if (p1.second > p2.second + p3.second) return 0;
        assert(p1.second == p2.second + p3.second);
        return p1.first / (p2.first * p3.first);
    }
};

typedef ZZ<int, long long> Z;
template<> int Z::MOD = 1000000007;
template<> vector<Z> Z::factorial(1, 1);
template<> vector<Z> Z::inv_factorial(1, 1);

#define MAX_N 150000
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
template<class T>
class BIT {
  vector<T> bit;
public:
  BIT() {}
  BIT(int n): bit(n+1) {}
  T sum(int i, int j) {
      return sum(j) - sum(i-1);
  }
  T sum(int i) {
    assert(i>=0);
    i = min(i, (int)bit.size()-1);
    T s = 0;
    while(i > 0) {
      s += bit.at(i);
      i &= i - 1;
    }
    return s;
  }
  void add(int i, T x) {
    while(i < bit.size()) {
      bit.at(i) += x;
      i += i & -i;
    }
  }
  void resize(int n) {
    bit.resize(n+1);
  }
};
#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define PL(x) printf("%lld\n", x)
#define RL(x) scanf("%lld", &x)
#define DRL(x) LL x; RL(x);
char S[100005];

int main() {
    DRI(N, Q);
    RS(S);
    int d = 1;
    BIT<int> bit(N);
    vector<Z> s(N+1);
    s[0] = 0;
    REP(i, N) {
        s[i+1] = s[i] * 10 + (S[i] - '0');
    }
    suffix_array(S, N);
    int *rank = temp[0];
    for (int i=0; i<N; ++i)
        rank[sa[i]] = i;
    int base = 0;
    while (Q--) {
        DRI(B);
        while (B - base > N - bit.sum(N)) {
            base += N - bit.sum(N);
            if (d == 1) {
                REP(i, N) {
                    if (S[i] == '0') {
                        bit.add(rank[i]+1, 1);
                    }
                }
            }
            if (S[N-d] != '0') {
                bit.add(rank[N-d]+1, 1);
            }
            d++;
        }
        B -= base;
        int lb = -1, ub = N;
        while (ub - lb > 1) {
            int m = (ub + lb) / 2;
            if (m+1 - bit.sum(m+1) < B) {
                lb = m;
            } else if (m+1 - bit.sum(m+1) >= B) {
                ub = m;
            }
        }
        int m = ub;
        assert(m+1 - bit.sum(m+1) == B);
        auto f = [&](int i, int l) {
            return s[i+l] - s[i] * Z(10).pow(d);
        };
        PZ(f(sa[m], d));
    }
    return 0;
}
