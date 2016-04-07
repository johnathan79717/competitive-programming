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
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
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
};

typedef ZZ<int, LL> Z;

template<>
int Z::MOD = 1000000007;

template<>
vector<Z> Z::factorial(1, 1);

template<>
vector<Z> Z::inv_factorial(1, 1);

int main() {
    DRI(T);
    while(T--) {
        DRI(N, K);
        if (K == 1) {
            PI(0);
            continue;
        }
        Z single = (Z(K) - Z(K).pow(N+1)) / (1 - K);
        Z include1 = (single - Z(K).pow(N+1) * N) / (1 - K);
        Z include2 = (include1 - Z(K).pow(N+1) * N * (N+1) / 2) / (1 - K);
        Z ans = single * single * single; // 1
        ans -= include1 * single * 6; // A -> B: 6

        // A -> B, B -> A : 3
        ans += single * single * 3;

        // A > B, B > C : 6
        ans += include2 * 6;

        // A > B, A > C : 3
        ans += (include2 * 2 - include1) * 3;

        // A < B, A < C : 3
        Z in2 = (Z(K).pow(N+1) * single - Z(K).pow(N+1) * N * 2 + single) / (K - 1) / (K - 1) * 3;
        ans += in2;

        // A > B > C > A : 2
        ans -= single * 2;

        // A = B, A <(>) C : 12
        ans -= include1 * 12;
        // A > B > C, A > C: 6
        ans -= include2 * 6;

        // A = B, B = C: 3
        ans += single * 3;

        // A = B, B > C, C > A: 6
        ans += single * 6;

        // A = B, B <(>) C, A <(>) C: 6
        ans += include1 * 6;

        // A = B, B = C, A <(>) C: 6
        ans -= single * 6;

        ans += single;

        PZ(ans);
    }
    return 0;
}