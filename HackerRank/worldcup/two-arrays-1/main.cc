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

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(int x) { return __builtin_popcount(x); } 
int popcount(long long x) { return __builtin_popcountll(x); } 

#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
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

struct Data {
    Z w, a, b, prod;
};

struct Lazy {
    Z a, b;
};

VI points;
struct SegmentTree {
  // static Data identity;
  int n;
  int size;
  vector<Data> dat;
  vector<Lazy> lazy;

  SegmentTree(int n_) {
    n = 1;
    size = n_;
    while(n < n_) n *= 2;
    dat = vector<Data>(2*n-1);
    lazy = vector<Lazy>(2*n-1);
    init(0, 0, n);
  }

  int chl(int k) const {
    return k * 2 + 1;
  }

  int chr(int k) const {
    return k * 2 + 2;
  }

  void init(int k, int l, int r) {
    if(r - l == 1) {
        // set dat[k] of leaf
        if (l+1 < SZ(points))
            dat[k].w = points[l+1] - points[l];
    } else {
        // non-leaf
        init(chl(k), l, (l + r) / 2);
        init(chr(k), (l + r) / 2, r);
        Data &vl = dat[chl(k)], &vr = dat[chr(k)];
        dat[k].w = vl.w + vr.w;
        dat[k].a = vl.a + vr.a;
        dat[k].b = vl.b + vr.b;
        dat[k].prod = vl.prod + vr.prod;
    }
  }
  void update(int a, int b, const Lazy &d) {
    update(a, b, 0, 0, n, d);
  }

  void propagate(int k) {
      const Lazy& d = lazy[k];
      if (!d.a.i && !d.b.i) return;
    dat[k].prod += d.a * dat[k].b + d.b * dat[k].a + d.a * d.b * dat[k].w;
    dat[k].a += d.a * dat[k].w;
    dat[k].b += d.b * dat[k].w;
    if (chr(k) < SZ(lazy)) {
        lazy[chl(k)].a += d.a;
        lazy[chl(k)].b += d.b;
        lazy[chr(k)].a += d.a;
        lazy[chr(k)].b += d.b;
    }
    lazy[k] = Lazy();
  }

  void update(int a, int b, int k, int l, int r, const Lazy &d) {
    propagate(k);
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
        lazy[k] = d;
        propagate(k);
    } else {
        update(a, b, chl(k), l, (l+r)/2, d);
        update(a, b, chr(k), (l+r)/2, r, d);
        Data &vl = dat[chl(k)], &vr = dat[chr(k)];
        dat[k].a = vl.a + vr.a;
        dat[k].b = vl.b + vr.b;
        dat[k].prod = vl.prod + vr.prod;
    }
  }

  Z query(int a, int b) {
    return query(a, b, 0, 0, n);
  }

  Z query(int a, int b, int k, int l, int r) {
    // if [a, b) and [l, r) are disjoint
    if(r <= a || b <= l) return Z();
    propagate(k);
    // if [l, r) contains [a, b)
    if(a <= l && r <= b) {
        return dat[k].prod;
    } else {
        Z vl = query(a, b, chl(k), l, (l + r) / 2);
        Z vr = query(a, b, chr(k), (l + r) / 2, r);
        return vl + vr;
    }
  }

  Data combine(Data vl, Data vr) {
      Data ret;
      ret.a = vl.a + vr.a;
      ret.b = vl.b + vr.b;
      ret.prod = vl.prod + vr.prod;
      ret.w = vl.w + vr.w;
      return ret;
  }
};

struct Query {
    int t, l, r, c;
};
int main() {
    DRI(N, Q);
    V(Query) query(Q);
    points.PB(1);
    points.PB(N+1);
    REP(i, Q) {
        RI(query[i].t, query[i].l, query[i].r);
        query[i].r++;
        points.PB(query[i].l);
        points.PB(query[i].r);
        if (query[i].t < 3) {
            RI(query[i].c);
        }
    }
    sort(ALL(points));
    points.resize(unique(ALL(points)) - points.begin());
    SegmentTree st(points.size());
    REP(i, Q) {
        if (query[i].t == 1) {
            Lazy d;
            d.a = query[i].c;
            int l = lower_bound(ALL(points), query[i].l) - points.begin();
            int r = lower_bound(ALL(points), query[i].r) - points.begin();
            st.update(l, r, d);
        } else if (query[i].t == 2) {
            Lazy d;
            d.b = query[i].c;
            int l = lower_bound(ALL(points), query[i].l) - points.begin();
            int r = lower_bound(ALL(points), query[i].r) - points.begin();
            st.update(l, r, d);
        } else {
            assert(query[i].t == 3);
            int l = lower_bound(ALL(points), query[i].l) - points.begin();
            int r = lower_bound(ALL(points), query[i].r) - points.begin();
            PZ(st.query(l, r));
        }
    }
    return 0;
}
