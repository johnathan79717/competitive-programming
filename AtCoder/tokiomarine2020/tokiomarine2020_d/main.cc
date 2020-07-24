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
void print(LL i);
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

#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)

//int dp[105];

const int M = 100000;
const int X = 511;
int D[520][M+1];

int main() {
    DRI(N);
    VI v(N), w(N);
    REP(i, N) {
        RI(v[i], w[i]);
    }
    MS1(D);
    REP1(k, 0, M) D[0][k] = 0;
    REP1(u, 1, min(X, N)) {
        REP1(k, 0, M) {
            D[u][k] = D[u / 2][k];
        }
        PER1(k, M, w[u-1]) {
            if (D[u / 2][k - w[u-1]] >= 0) {
                D[u][k] = max(D[u][k], D[u / 2][k - w[u-1]] + v[u - 1]);
            }
        }
    }
    DRI(Q);
    while (Q--) {
        DRI(V, L);
        //cout << V << ' ' << L << endl;
        //unordered_map<int, int> m1, m2;
        //m1[0] = m2[0] = 0;
        VI p;
        do {
            p.PB(V-1);
            V /= 2;
        } while (V >= 512);

        list<PII> combinations;

        combinations.EB(0, 0);

        for (int u : p) {
            list<PII> new_values;
            for (auto &pr : combinations) {
                if (pr.X + w[u] <= L) {
                    new_values.EB(pr.X + w[u], pr.Y + v[u]);
                }
            }
            for (auto &pr : new_values) {
                combinations.push_back(pr);
            }
        }

        int ans = 0;
        for (auto &pr : combinations) {
            ans = max(ans, pr.Y + D[V][L - pr.X]);
        }

        //MS1(dp);
        //dp[0] = 0;
        //for (int u : p) {
            ////cout << v[u] << ' ' << w[u] << endl;
            //PER1(j, L - w[u], 0) {
                //if (dp[j] >= 0) {
                    //dp[j + w[u]] = max(dp[j + w[u]], dp[j] + v[u]);
                //}
            //}
        //}
        //int brute = 0;
        //REP1(i, 0, L) {
            //brute = max(brute, dp[i]);
        //}

        
        //REP(i, SZ(p) / 2) {
            //unordered_map<int, int> tmp = m1;
            //for (auto &pr : m1) {
                //if (pr.X + w[u] <= L)
                    //tmp[pr.X + w[u]] = max(tmp[pr.X + w[u]], pr.Y + v[u]);
            //}
            //swap(tmp, m1);
        //}
        //REP1(i, SZ(p) / 2, SZ(p)-1) {
            //unordered_map<int, int> tmp = m2;
            //int u = p[i];
            //for (auto &pr : m2) {
                //if (pr.X + w[u] <= L)
                    //tmp[pr.X + w[u]] = max(tmp[pr.X + w[u]], pr.Y + v[u]);
            //}
            //swap(tmp, m2);
        //}
        //map<int, int> o2(m2.begin(), m2.end());
        //map<int, int> o1(m1.begin(), m1.end());
        //auto it2 = o2.rbegin();
        //int best1 = 0;
        //int ans = 0;
        //for (auto &pr : o1) {
            //while (it2 != o2.rend() && it2->X + pr.X > L) {
                //ans = max(ans, best1 + it2->Y);
                //it2++;
            //}
            //best1 = max(best1, pr.Y);
            //if (it2 == o2.rend()) {
                //ans = max(ans, best1);
            //} else {
                //ans = max(ans, best1 + it2->Y);
            //}
        //}
        //while (it2 != o2.rend()) {
            //ans = max(ans, best1 + it2->Y);
            //it2++;
        //}
        //assert(brute == ans);
        PI(ans);
    }
    return 0;
}
