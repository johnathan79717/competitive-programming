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
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case %d: ", case_n++) : 0), ___T-- > 0)
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
#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define PL(x) printf("%lld\n", x)
#define RL(x) scanf("%lld", &x)
#define DRL(x) LL x; RL(x);

LL K;

const int N2 = 60, N3 = 38, N5 = 26, N7 = 22;
Z dp[100][N2][N3][N5][N7];
int d[][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {2, 0, 0, 0},
    {0, 0, 1, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 1},
    {3, 0, 0, 0},
    {0, 2, 0, 0}
};
Z solve(char *A, int c2, int c3, int c5, int c7, bool include) {
    int L = LEN(A);
    Z ans = 0;
    REP1(i, 1, L-1) {
        ans += dp[i-1][c2][c3][c5][c7];
    }
    REPL(i, A) {
        int a = A[i] - '0';
        if (a == 0) return ans;
        REP1(j, 1, a-1) {
            if (c2>=d[j][0] && c3>=d[j][1] && c5>=d[j][2] && c7>=d[j][3]) {
                if (i == L-1) {
                    ans += (c2 == d[j][0] && c3 == d[j][1] && c5 == d[j][2] && c7 == d[j][3]);
                } else {
                    ans += dp[L-1-i-1][c2-d[j][0]][c3-d[j][1]][c5-d[j][2]][c7-d[j][3]];
                }
            }
        }
        c2 -= d[a][0], c3 -= d[a][1], c5 -= d[a][2], c7 -= d[a][3];
        if (c2 < 0 || c3 < 0 || c5 < 0 || c7 < 0) {
            break;
        }
    }
    if (include && c2 == 0 && c3 == 0 && c5 == 0 && c7 == 0) {
        ans += 1;
    }
    return ans;
}

const LL KK = 1000000000000000000ll;

int main() {
    //dp[0][0][0][0][0] = 1;
    REP1(j, 1, 9) dp[0][d[j][0]][d[j][1]][d[j][2]][d[j][3]] = 1;
    REP1(i, 1, 99) {
        LL k = 1;
        REP(i2, N2) {
            REP(i3, N3) {
                REP(i5, N5) {
                    REP(i7, N7) {
                        REP1(j, 1, 9) {
                            if (i2 + d[j][0] < N2 && i3 + d[j][1] < N3 &&
                                    i5 + d[j][2] < N5 && i7 + d[j][3] < N7) {
                                dp[i][i2+d[j][0]][i3+d[j][1]][i5+d[j][2]][i7+d[j][3]] +=
                                    dp[i-1][i2][i3][i5][i7];
                            }
                        }
                        k *= 7;
                        if (k > KK) break;
                    }
                    while (k % 7 == 0) k /= 7;
                    k *= 5;
                    if (k > KK) break;
                }
                while (k % 5 == 0) k /= 5;
                k *= 3;
                if (k > KK) break;
            }
            while (k % 3 == 0) k /= 3;
            k *= 2;
            if (k > KK) break;
        }
    }
    char A[104], B[104];

    CASET1 {
        RS(A);
        RS(B);
        RL(K);
        assert(K);
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
        while (K % 2 == 0) c2++, K /= 2;
        while (K % 3 == 0) c3++, K /= 3;
        while (K % 5 == 0) c5++, K /= 5;
        while (K % 7 == 0) c7++, K /= 7;
        if (K > 1) {
            PI(0);
            continue;
        }
        Z ans = solve(B, c2, c3, c5, c7, true) - solve(A, c2, c3, c5, c7, false);
        PZ(ans);
    }
    return 0;
}
