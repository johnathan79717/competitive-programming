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

int a[8], b[7];
int states[400000][8], numStates = 0;
//void genStates(int M) {
    //REP(i, M-1) {
        //b[i] = 1;
    //}
    //int m = 1;
    //while (true) {
        //REP(i, M) {
            //states[numStates][i] = a[i];
            //printf("%d", a[i]);
        //}
        //puts("");
        //numStates++;
        //if (a[M-1] != m) {
            //a[M-1]++;
        //} else {
            //int j = M-2;
            //while (a[j] == b[j]) {
                //j--;
            //}
            //if (j == 0) {
                //break;
            //}
            //a[j]++;
            //m = b[j] + (a[j] == b[j]);
            //j++;
            //while (j < M-1) {
                //a[j] = 0;
                //b[j] = m;
                //j++;
            //}
            //a[M-1] = 0;
        //}
    //}
//}

//int stateNum[2][3][4][5][6][7][8][9];
int fact[] = {1, 2, 6, 24, 120, 720, 5040, 40320};
int N, M;
int agetStateNum() {
    int ans = 0;
    int m = 0;
    for (int i = 0; i < M; i++) {
        ans += a[i] * fact[i];
        assert(a[i] <= m+1);
        m = max(m, a[i]);
    }
    return ans;
}

int getStateNum() {
    int ans = 0;
    int m = 0;
    for (int i = 0; i < M; i++) {
        ans += a[i] * fact[i];
        //assert(a[i] <= m+1);
        m = max(m, a[i]);
    }
    return ans;
}

VI stateNums;
void dfs(int i, int m) {
    if (i == M) {
        int j = getStateNum();
        stateNums.PB(j);
        REP(i, M) {
            states[j][i] = a[i];
        }
        return;
    }
    for (a[i] = 0; a[i] <= m+1; a[i]++) {
        dfs(i+1, max(m, a[i]));
    }
}

Z dp[2][400000];
char s[101][10];
bool hasRoad[101][10];

int main(int, char **) { 
    RI(N, M);
    //M = atoi(argv[1]);
    //genStates(M);
    //PI(numStates);
    dfs(0, 0);
    sort(ALL(stateNums));
    assert(unique(ALL(stateNums)) == stateNums.end());
    //PI(SZ(stateNums));
    int n = 0;
    dp[1][0] = 1;
    REP(i, N) RS(s[i]);
    bool h = false;
    PER(i, N) PER(j, M) {
        if (s[i][j] == '.') {
            h = true;
        }
        hasRoad[i][j] = h;
    }
    Z ans = 0;
    REP(i, N) {
        REP(j, M) {
            n ^= 1;
            MS0(dp[n^1]);
            for(int k: stateNums) {
                if (dp[n][k].i == 0) continue;
                //PIS(i); PIS(j); PIS(k); PIS(dp[n][k].i); PZ(ans);
                auto state = states[k];
                auto setA = [&]() {
                    REP(i, M) {
                        a[i] = state[i];
                    }
                };
                auto block = [&]() {
                    setA();
                    int first = -1;
                    int cnt = 0;
                    PER(i, M) {
                        if (a[i] == a[j]) {
                            first = i;
                            cnt++;
                        }
                    }
                    if (cnt == 1) { // alone
                        bool fail = false;
                        REP(i, M) {
                            if (a[i] > 1) {
                                fail = true;
                            }
                        }
                        if (j+1 < M) {
                            h = hasRoad[i][j+1];
                        } else if (i+1 < M) {
                            h = hasRoad[i+1][0];
                        } else {
                            h = false;
                        }
                        if (!h && !fail) {
                            ans += dp[n][k];
                        }
                    } else if (first == j) {
                        int l = a[j], m = a[j];
                        int i;
                        for(i = j+1; i < M; i++) {
                            if (a[i] == l) {
                                break;
                            }
                            m = max(m, a[i]);
                        }
                        REP(i, M) {
                            if (a[i] == l) {
                                a[i] = m;
                            } else if (a[i] > l && a[i] <= m) {
                                a[i]--;
                            }
                        }
                        a[j] = 0;
                        dp[1^n][agetStateNum()] += dp[n][k];
                    } else {
                        a[j] = 0;
                        dp[1^n][agetStateNum()] += dp[n][k];
                    }
                };
                if (j == 0 || state[j-1] == 0) {
                    if (state[j] == 0) { // not road
                        if (s[i][j] != '.') { // don't build road
                            dp[n^1][k] += dp[n][k];
                        }
                        if (s[i][j] != '#') { // build road
                            // add a set for j
                            setA();
                            int m = 0;
                            REP(i, j) {
                                m = max(m, a[i]);
                            }
                            a[j] = m+1;
                            REP1(i, j+1, M-1) {
                                if (a[i] > m) {
                                    a[i]++;
                                }
                            }
                            dp[1^n][agetStateNum()] += dp[n][k];
                        }
                    } else { // is road
                        if (s[i][j] != '.') { // don't build road
                            // block j
                            block();
                        }
                        if (s[i][j] != '#') { // build road
                            dp[n^1][k] += dp[n][k];
                        }
                    }
                } else { // j-1 is road
                    if (state[j] == 0) { // j is not road
                        if (s[i][j] != '.') { // don't build road
                            dp[n^1][k] += dp[n][k];
                        }
                        if (s[i][j] != '#') { // build road
                            setA();
                            a[j] = a[j-1];
                            dp[n^1][agetStateNum()] += dp[n][k];
                        }
                    } else { // j is road
                        if (s[i][j] != '.') { // don't build road
                            // block j
                            block();
                        }

                        if (s[i][j] != '#') { // build road
                            // connect j-1 and j
                            if (state[j-1] != state[j]) {
                                setA();
                                int mx = max(a[j-1],a[j]);
                                int mn = min(a[j-1], a[j]);
                                REP(i, M) {
                                    if (a[i] == mx) {
                                        a[i] = mn;
                                    } else if (a[i] > mx) {
                                        a[i]--;
                                    }
                                }
                                dp[1^n][getStateNum()] += dp[n][k];
                            }
                        }
                    }
                }
            }
        }
    }
    for (int k: stateNums) {
        bool fail = false;
        REP(j, M) {
            if (states[k][j] > 1) {
                fail = true;
            }
        }
        if (!fail) ans += dp[1^n][k];
    }
    PZ(ans);
    return 0;
}
