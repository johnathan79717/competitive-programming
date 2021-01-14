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
#include <bitset>
#include <numeric>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB emplace_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
template<class T> void _R(T &x) { cin >> x;  }
void _R(int &x) { scanf("%d", &x);  }
void _R(int64_t &x) { scanf("%lld", &x);  }
void _R(double &x) { scanf("%lf", &x);  }
void _R(char &x) { scanf(" %c", &x);  }
void _R(char *x) { scanf("%s", x);  }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...);  }
template<class T> void _W(const T &x) { cout << x;  }
void _W(const int &x) { printf("%d", x);  }
void _W(const int64_t &x) { printf("%lld", x);  }
void _W(const double &x) { printf("%.16f", x);  }
void _W(const char &x) { putchar(x);  }
void _W(const char *x) { printf("%s", x);  }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' ');  }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...);  }
#ifdef DEBUG
 #define debug(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define debug(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
template<class T> void MIN(T& a, const T& b) { a = min(a, b); }
template<class T> void MAX(T& a, const T& b) { a = max(a, b); }

#define PZ(x) PI((x).i);

template<class Short, class Long>
struct ZZ {
    static Short MOD;
    Short i;
    ZZ():i(0) {}
    ZZ(Short _i): i(_i >= 0 ? _i : _i + MOD) {}
    ZZ(Long _i): i(_i % MOD >= 0 ? _i % MOD : _i % MOD + MOD) {}
    Short val() { return i; }
    static ZZ raw(Short _i) { return ZZ(_i); }
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

long long mul(long long a,long long b,long long mod=Z::MOD){
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

long long pow(long long a, long long b, long long c=Z::MOD){
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

void _W(Z x) { printf("%d", x.i);  }

#include <vector>
using namespace std;

#define chl(k) (k*2+1)
#define chr(k) (k*2+2)

struct Data {
    Z pairs, sum;
};

typedef Z Lazy;

VL points;

struct SegmentTree {
  // static Data identity;
  int n;
  int size;
  vector<Data> dat;
  vector<Lazy> lazy;

  int real_size;
  SegmentTree(int n_) {
    real_size = n_;
    n = 1;
    size = n_;
    while(n < n_) n *= 2;
    dat = vector<Data>(2*n-1);
    lazy = vector<Lazy>(2*n-1);
    init(0, 0, n);
  }

  void init(int k, int l, int r) {
    if(r - l == 1) {
      if (l < real_size) { 
          dat[k] = Data({0, 0});
      }
    } else {
      // non-leaf
      int m = (l+r)/2;
      init(chl(k), l, m);
      init(chr(k), m, r);
      dat[k] = combine(dat[chl(k)], dat[chr(k)]);
    }
  }

  void update(int a, int z) {
    update(a, a+1, 0, 0, n, z);
  }
  void update(int a, int b, const Lazy &d) {
    update(a, b+1, 0, 0, n, d);
  }

  void propagate(int k, int l, int r) {
      Z p = (points[min(SZ(points)-1, r)] - points[min(SZ(points)-1, l)]);
      dat[k].pairs += dat[k].sum * lazy[k] + p * (lazy[k].i * (lazy[k].i - 1ll) / 2);
      dat[k].sum += lazy[k] * p;
      if (chr(k) < lazy.size()) {
          lazy[chl(k)] += lazy[k];
          lazy[chr(k)] += lazy[k];
      }
      lazy[k] = Lazy();
  }

  void update(int a, int b, int k, int l, int r, const Lazy &d) {
      // we have to make sure dat[k] is the right value after update
      // also all ancestor's lazy values should have already been propagated here
      if (a <= l && r <= b) {
          lazy[k] += d;
          propagate(k, l, r);
      } else {
          propagate(k, l, r);
          if (r <= a || b <= l) {
              return;
          }
          int m = (l+r)/2;
          update(a, b, chl(k), l, m, d);
          update(a, b, chr(k), m, r, d);
          dat[k] = combine(dat[chl(k)], dat[chr(k)]);
      }
  }

  Data query(int a, int b) {
    return query(a, b+1, 0, 0, n);
  }

  Data query(int a, int b, int k, int l, int r) {
    // if [a, b) and [l, r) are disjoint
    if(r <= a || b <= l) return Data({0, 0});
    propagate(k, l, r);
    // if [l, r) contains [a, b)
    if(a <= l && r <= b) {
      return dat[k];
    } else {
      Data vl = query(a, b, chl(k), l, (l + r) / 2);
      Data vr = query(a, b, chr(k), (l + r) / 2, r);
      return combine(vl, vr);
    }
  }

  Data combine(Data vl, Data vr) {
      return Data({vl.pairs + vr.pairs, vl.sum + vr.sum});
  }
};

#define int LL

struct Segment {
    int l, r, w;
};


# define MULTITEST 1
void solve() {
    int Q, K;
    R(Q, K);
    vector<vector<Segment>> queries(Q);
    points.clear();
    points.PB(0);
    points.PB(1<<(K/2));
    for (auto &q : queries) {
        LL l, r;
        R(l, r);
        auto process = [&q, K](LL x, int w) {
            //root.add(w * (x >> (K/2)), 1 << (K/2));
            q.PB(Segment({0, 1<<(K/2), w * int(x >> (K/2))}));
            int u = 0;
            REPP(i, K - K / 2, K) {
                u = (u << 1) | ((x >> i) & 1);
            }
            int l = 0;
            for (int i = K/2-1; i >= 0; i--) {
                if (u & (1<<i)) {
                    l ^= (1<<i);
                }
                if (x & (1<<i)) {
                    int r = l + (1<<i);
                    q.PB(Segment({l, r, w}));
                    points.PB(l);
                    points.PB(r);
                    l ^= (1<<i);
                }
            }
            points.PB(l);
            points.PB(l+1);
            q.PB(Segment({l, l+1, w}));
        };
        process(r, 1);
        if (l) {
            process(l-1, -1);
        }
    }
    SORT_UNIQUE(points);
    SegmentTree st(SZ(points));
    for (auto &q : queries) {
        for (auto &s : q) {
            int lp = GET_POS(points, s.l);
            int rp = GET_POS(points, s.r);
            if (rp == SZ(points) - 1) {
                rp = st.n;
            }
            st.update(lp, rp - 1, s.w);
        }
        W(st.query(0, st.n-1).pairs);
    }
}

#undef int
int main() {
    Z::MOD = 998'244'353;
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}
