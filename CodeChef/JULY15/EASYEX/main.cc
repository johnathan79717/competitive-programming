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
#define X first
#define Y second
#define V(x) vector<x >
#define PV(v) REP(i, SZ(v)) if(i < SZ(v)-1) PIS(v[i]); else PI(v[i]);

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(unsigned x) { return __builtin_popcount(x); } 
int popcount(unsigned long long x) { return __builtin_popcountll(x); } 

typedef long double LD;
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
    ZZ(Short i): i(i % MOD) {}
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
template<> int Z::MOD = 2003;
template<> vector<Z> Z::factorial(1, 1);
template<> vector<Z> Z::inv_factorial(1, 1);
template<> Z Z::C[MAX][MAX] = {};

Z p[1005][1005];
Z q[1005];//, c[1005];
Z dp[1000005];
Z c[1000005];
Z tmp1[20][1000005];

// int cnt = 0;

void karatsuba(Z* x, Z* y, int l, Z* z, int t) {
    if (l == 1) {
        z[0] = x[0] * y[0];
        // cnt++;
        return;
    }
    int n = (l + 1) / 2;
    memset(tmp1[t], 0, (2*n-1) * sizeof(Z));
    karatsuba(x, y, n, tmp1[t], t+1);
    REP(i, 2*n-1) {
        z[i] += tmp1[t][i];
        z[i+n] -= tmp1[t][i];
    }
    
    memset(tmp1[t], 0, (2*(l-n)-1) * sizeof(Z));
    karatsuba(x+n, y+n, l-n, tmp1[t], t+1);
    REP(i, 2*(l-n)-1) {
        z[i+n+n] += tmp1[t][i];
        z[i+n] -= tmp1[t][i];
    }
    
    REP1(i, n, l-1) {
        x[i-n] += x[i];
        y[i-n] += y[i];
    }
    memset(tmp1[t], 0, (2*n-1) * sizeof(Z));
    karatsuba(x, y, n, tmp1[t], t+1);
    REP(i, (2*n-1)) {
        z[i+n] += tmp1[t][i];
    }
    REP1(i, n, l-1) {
        x[i-n] -= x[i];
        y[i-n] -= y[i];
    }
}

Z x[1000005], y[1000005], z[1000005];
Z d[1000005];

int main() {
    DRI(T);
    while(T--) {
        DRI(N, K, L, F);
        dp[0] = 1;
        Z invK = Z(K).inverse();
        REP1(i, 1, 50004) {
            dp[i] = dp[i-1] * (N - i + 1) * invK;
        }
        MS0(p);
        p[0][0] = 1;
        REP(i, F) {
            REP(j, i+1) {
                p[i+1][j+1] += p[i][j];
                p[i+1][j] -= p[i][j] * i;
            }
        }
        MS0(q);
        q[F] = 1;
        PER1(i, F, 0) {
            c[F-i] = q[i];
            REP1(j, 0, i) {
                q[j] -= c[F-i] * p[i][j];
            }
        }

        MS0(x); MS0(y); MS0(z);

        // REP1(i, 0, F) {
        //     z[i] = c[i];
        // }

        x[0] = 1, x[1] = 2, x[2] = 3, x[3] = 4, x[4] = 5;
        y[0] = 2, y[1] = 3, y[2] = 4, y[3] = 5, y[4] = 6;
        karatsuba(x, y, 5, z, 0);
        REP(i, 9) {
            PZ(z[i]);
        }

        // MS0(d);
        // d[0] = 1;
        // int l = L, n = F;
        // while (l) {
        //     if (l % 2) {
        //         // d *= z;
        //         REP(i, n) {
        //             y[i] = d[i];
        //             d[i] = 0;
        //         }
        //         karatsuba(z, y, n, d, 0);
        //     }
        //     l /= 2;
        //     if (l) {
        //         REP(i, n) {
        //             x[i] = y[i] = z[i];
        //             z[i] = 0;
        //         }
        //         karatsuba(x, y, n, z, 0);
        //         n = n * 2 - 1;
        //     }
        // }

        // Z ans = 0;
        // REP1(i, 0, L*F) {
        //     ans += d[i] * dp[L*F - i];
        // }
        // PZ(ans);
    }
    return 0;
}