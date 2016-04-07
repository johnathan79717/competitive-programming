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

template<class T>
struct SegmentTree {
    int n;
    vector<T> dat;

    void update(int k, T const& a) {
        // starting from leaf node
        k += n - 1;
        dat[k] = a;
        while(k > 0) {
            k = (k - 1) / 2;
            dat[k] = T::combine(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    T query(int a, int b) {
        if (a > b) return T::identity();
        return query(a, b+1, 0, 0, n);
    }

    T query(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) {
            // if [a, b) and [l, r) are disjoint
            return T::identity();
        } else if(a <= l && r <= b) {
            // if [l, r) contains [a, b)
            return dat[k];
        } else {
            T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return T::combine(vl, vr);
        }
    }

    int real_size;
    SegmentTree(int n_) {
        real_size = n_;
        n = 1;
        while(n < n_) n *= 2;
        dat.resize(2*n-1);
        init(0, 0, n);
    }

    void init(int k, int l, int r) {
        if(r - l == 1) {
            // leaf
            if (l >= real_size)
                return;
            dat[k] = T::get(l);
        } else {
            // non-leaf
            init(k*2+1, l, (l + r) / 2);
            init(k*2+2, (l + r) / 2, r);
            dat[k] = T::combine(dat[k*2+1], dat[k*2+2]);
        }
    }
};

#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define PL(x) printf("%lld\n", x)
#define RL(x) scanf("%lld\n", &x)
#define DRL(x) LL x; RL(x);

int sp[1000001];

struct Data {
    int a[4];
    Data() { MS0(a); }
    static Data identity() { return Data(); }
    static Data combine(const Data& d1, const Data& d2) {
        Data ans;
        REP(i, 4) ans.a[i] = d1.a[i] + d2.a[i];
        return ans;
    }
    static Data get(int i) {
        Data ans;
        ans.a[sp[i]] = 1;
        return ans;
    }
    void combine(const Data& other) {
        REP(i, 4) a[i] += other.a[i];
    }
};

int A[1000001];

int main() {
    REP1(i, 10, 1000000) {
        bool x[4];
        MS0(x);
        for (int p = 10; p <= i; p *= 10) {
            int a = i / p, b = i % p;
            int a1 = a / 10, a2 = a % 10;
            int b1 = b / (p/10), b2 = b % (p/10);
            int j = a1 * p + (a2+b1)%10*(p/10) + b2;
            x[sp[j]] = true;
        }
        REP(j, 4) {
            if (!x[j]) {
                sp[i] = j;
                break;
            }
        }
    }
    SegmentTree<Data> st(1000001);
    CASET {
        DRI(N, M);
        int sum = 0;
        REP(i, M) {
            RI(A[i]);
            sum ^= sp[A[i]];
        }
        sort(A, A+M);
        Data ans = st.query(1, A[0]-1);
        ans.combine(st.query(A[M-1]+1, N));
        REP(i, M-1) {
            ans.combine(st.query(A[i]+1, A[i+1]-1));
        }
        Z o[4], e[4];
        REP(i, 4) {
            if (ans.a[i] == 0) {
                e[i] = 1;
                o[i] = 0;
            } else {
                e[i] = o[i] = Z(2).pow(ans.a[i] - 1);
            }
        }
        Z a = o[0] + e[0];
        if (sum == 0) {
            a *= (e[3] * e[2] * e[1] + o[3] * o[2] * o[1]);
            a -= 1;
        } else if (sum == 1) {
            a *= (e[3] * e[2] * o[1] + o[3] * o[2] * e[1]);
        } else if (sum == 2) {
            a *= (e[3] * o[2] * e[1] + o[3] * e[2] * o[1]);
        } else {
            a *= (e[3] * o[2] * o[1] + o[3] * e[2] * e[1]);
        }
        PZ(a);
    }
    return 0;
}
