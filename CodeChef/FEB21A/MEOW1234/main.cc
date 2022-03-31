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


void solve() {
    int N, T;
    R(N, T);
    map<int, PII> minMaxX;
    REP(i, N) {
        int x, y;
        R(x, y);

        auto it = minMaxX.find(y);
        if (it == minMaxX.end()) {
            minMaxX[y] = MP(x, x);
        } else {
            minMaxX[y] = MP(min(x, it->S.F), max(x, it->S.S));
        }
    }

    
    set<pair<PII, PII>> s;
    Z cnt1 = 1;
    auto emplace = [&](const auto& p1, const auto& p2) {
        cnt1 *= Z::choose0(abs(p1.F - p2.F) + abs(p1.S - p2.S), abs(p1.S - p2.S));
        return s.emplace(p1, p2).F;
    };
    auto erase = [&](const auto &it) {
        cnt1 /= Z::choose0(abs(it->F.F - it->S.F) + abs(it->F.S - it->S.S), abs(it->F.S - it->S.S));
        return s.erase(it);
    };
    LL ans = 0;
    for (auto I = minMaxX.rbegin(); I != minMaxX.rend(); I++) {
        auto &pr = *I;
        LL y = pr.F;
        PII l(pr.S.F, y), r(pr.S.S, y);
        ans += r.F - l.F + 1;

        bool overlap = false;
        auto processOverlap = [&](set<pair<PII, PII>>::iterator it) {
            overlap = true;
            LL y1 = min(it->F.S, it->S.S);
            bool flat = it->F.S == it->S.S;
            int xl = max(l.F, it->F.F + (flat ? 0 : 1));
            int xr = min(r.F, it->S.F - (flat ? 0 : 1));
            ans += (abs(y1 - y) - 1ll) * (xr - xl + 1);
            if (it->F.S > it->S.S && it->F.F >= l.F && it->F.F <= r.F) {
                ans -= abs(it->S.S - it->F.S);
            }
            if (it->F.S < it->S.S && it->S.F >= l.F && it->S.F <= r.F) {
                ans -= abs(it->F.S - it->S.S);
            }
            if (it->F.F < l.F) {
                if (flat) {
                    emplace(it->F, MP(l.F - 1, y1));
                } else if (it->F.S != y1) {
                    emplace(it->F, MP(l.F, y1));
                } else if (prev(it)->S.S == y1) {
                    auto tmp = *prev(it);
                    erase(prev(it));
                    emplace(tmp.F, MP(l.F - 1, y1));
                } else if (it->F.F + 1 <= l.F - 1){
                    emplace(MP(it->F.F+1, y1), MP(l.F - 1, y1));
                }
            }
            if (it->S.F > r.F) {
                if (flat) {
                    emplace(MP(r.F + 1, y1), it->S);
                } else if (it->S.S != y1){
                    emplace(MP(r.F, y1), it->S);
                } else if (next(it)->F.S == y1) {
                    auto tmp = *next(it);
                    erase(next(it));
                    emplace(MP(r.F + 1, y1), tmp.S);
                } else if (r.F + 1 <= it->S.F - 1) {
                    emplace(MP(r.F + 1, y1), MP(it->S.F - 1, y1));
                }
            }
        };

        auto it = s.lower_bound(MP(l, r));
        while (it != s.end() && (it->F.F < r.F || (it->F == MP(r.F, it->S.S)))) {
            processOverlap(it);
            it = erase(it);
        }

        while (it != s.begin() && (prev(it)->S.F > l.F || (prev(it)->S == MP(l.F,prev(it)->S.S)))) {
            it--;
            processOverlap(it);
            it = erase(it);
        }
        auto itNew = emplace(l, r);

        if (next(itNew) != s.end()) {
            it = next(itNew);
            while (it != s.end()) {
                if (it->F.S < it->S.S) break;
                if (prev(it) != itNew && prev(it)->S.S < it->S.S) {
                    break;
                }
                it++;
            }
            auto border = it;
            int y1 = prev(it)->S.S;

            it = next(itNew);
            auto p1 = MP(it->F.F + (it->F.S != it->S.S ? 1 : 0), y1), p2 = p1;
            if (it != border) {
                do {
                    int y2 = min(it->F.S, it->S.S);
                    if (it->F.S == it->S.S) {
                        ans += 1ll * abs(y2 - y1) * (it->S.F - it->F.F + 1);
                    } else {
                        ans += 1ll * abs(y2 - y1) * (it->S.F - it->F.F - 1);
                        ans -= abs(it->F.S - it->S.S);
                    }
                    p2.F = it->S.F;
                    it = erase(it);
                } while (it != border);
                emplace(p1, p2);
            }
            if (!overlap) {
                emplace(r, p1);
                ans += p1.F - r.F + abs(r.S - p1.S) - 1;
            }
        }
        if (itNew != s.begin()) {
            it = itNew;
            while (true) {
                if (it == s.begin()) break;
                if (prev(it)->F.S > prev(it)->S.S) break;
                if (it != itNew && it->F.S < prev(it)->F.S) break;
                it--;
            }
            int y1 = it->F.S;
            auto border = it;
            it = prev(itNew);
            auto p1 = MP(it->S.F - (it->F.S != it->S.S ? 1 : 0), y1), p2 = p1;
            if (border != itNew) {
                while (true) {
                    int y2 = min(it->F.S, it->S.S);
                    if (it->F.S == it->S.S) {
                        ans += 1ll * abs(y1 - y2) * (it->S.F - it->F.F + 1);
                    } else {
                        ans += 1ll * abs(y1 - y2) * (it->S.F - it->F.F - 1);
                        ans -= abs(it->F.S - it->S.S);
                    }
                    p2.F = it->F.F;
                    if (it == border) {
                        erase(it);
                        break;
                    }
                    it = prev(erase(it));
                }
                emplace(p2, p1);
            }
            if (!overlap) {
                emplace(p1, l);
                ans += l.F - p1.F + abs(l.S - p1.S) - 1;
            }
        }
        debug(ans);
    }
    
    if (T == 0) {
        W(ans);
    } else {
        W(ans, cnt1.i);
    }
}

#undef int
int main() {
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}
