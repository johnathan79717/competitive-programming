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

int A[100005];

int MOD = 1000000007;
struct Z {
  int i;
  Z():i(0) {}
  Z(int i): i(i >= 0 ? i : i + MOD) {}
  Z(long long i): i(i % MOD) {}
  void operator +=(const Z& z) { i += z.i; if(i >= MOD) i -= MOD; }
  void operator -=(const Z& z) { i -= z.i; if(i < 0) i += MOD; }
  void operator *=(const Z& z) { i = (long long) i * z.i % MOD; }
  void operator /=(const Z& z) { (*this) *= z.inverse(); }
  Z operator +(const Z& z) const { Z ret(i); ret += z; return ret; }
  Z operator -(const Z& z) const { Z ret(i); ret -= z; return ret; }
  Z operator *(const Z& z) const { Z ret(i); ret *= z; return ret; }
  Z operator /(const Z& z) const { return (*this) * z.inverse(); }
  // Z operator -() const { return Z(-i); }
  Z inverse() const {
    int a = i, d = MOD, x = 0, s = 1;
    while(a) {
      int q = d / a, r = d % a, t = x - q * s;
      d = a, a = r, x = s, s = t;
    }
    if (d != 1) return -1;
    return x < 0 ? x + MOD : x;
  }
  Z pow(long long b) {
    Z x=1,y=*this;
    while(b > 0){
      if(b%2 == 1)
        x *= y;
      y *= y; // squaring the base
      b /= 2;
    }
    return x;
  }
};

struct Matrix {
  static int M;

  Z a[2][2];
  Matrix() {
    MS0(a);
  }

  Z* operator[](int i) {
    return a[i];
  }

  Matrix operator* (const Matrix &other) const {
    Matrix ret;
    REP(i, M) REP(j, M) REP(k, M) {
      ret.a[i][j] += a[i][k] * other.a[k][j];
    }
    return ret;
  }

  Matrix pow(LL n) {
    if(n % 2) {
      return *this * pow(n-1);
    } else {
      if(n)
        return (*this * *this).pow(n / 2);
      else {
        Matrix ret;
        REP(i, M) {
          ret.a[i][i] = 1;
        }
        return ret;
      }
    }
  }
};
int Matrix::M = 2;

Matrix m;

Matrix get(int l) {
    Matrix a = m.pow(A[l]);
    a[0][0] += 1;
    a[1][1] += 1;
    return a;
}

inline Matrix combine(const Matrix &m1, const Matrix &m2) {
    return m1 * m2;
}

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
            dat[k] = combine(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    T query(int a, int b) {
        //if (a > b) return T::identity();
        return query(a, b+1, 0, 0, n);
    }

    T query(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) {
            // if [a, b) and [l, r) are disjoint
            Matrix x;
            x[0][0] = x[1][1] = 1;
            return x;
        } else if(a <= l && r <= b) {
            // if [l, r) contains [a, b)
            return dat[k];
        } else {
            T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return combine(vl, vr);
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
            dat[k] = get(l);
        } else {
            // non-leaf
            init(k*2+1, l, (l + r) / 2);
            init(k*2+2, (l + r) / 2, r);
            dat[k] = combine(dat[k*2+1], dat[k*2+2]);
        }
    }
};
#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)

int main() {
    DRI(N, Q);
    REP(i, N) RI(A[i]);
    m[0][1] = m[1][0] = m[1][1] = 1;
    SegmentTree<Matrix> st(N+1);
    while (Q--) {
        char cmd[3];
        RS(cmd);
        if (cmd[0] == 'C') {
            DRI(X, Y);
            X--;
            A[X] = Y;
            st.update(X, get(X));
        } else {
            DRI(L, R);
            Matrix a = st.query(L-1, R-1);
            PI((a[0][1]).i);
        }
    }
    return 0;
}
