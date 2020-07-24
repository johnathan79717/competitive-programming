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

#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

void kmp_table(char *W, int *T) {
    T[0] = -1;
    int lw = strlen(W);
    int pos = 1, cnd = 0;
    while(pos < lw) {
        if(W[pos] == W[cnd]) {
            // when we need to backtrack,
            // the next character must be different from W[pos]
            // which implies it will not match W[cnd] either
            // so we can skip cnd and go to T[cnd] directly
            T[pos] = T[cnd];
        } else {
            T[pos] = cnd;
            do {
                cnd = T[cnd];
            } while (cnd >= 0 && W[pos] != W[cnd]);
        }
        pos++;
        cnd++;
    }
    T[lw] = cnd;
}

// search W in S, time complexity O(|S|)
vector<int> kmp_search(char *S, char *W, int *T) {
    int j = 0, k = 0;
    int ls = strlen(S), lw = strlen(W);
    vector<int> P;
    while(j < ls) {
        if (W[k] == S[j]) {
            k++;
            j++;
            if(k == lw) {
                P.push_back(j - lw);
                k = T[k];
            }
        } else {
            k = T[k];
            if (k < 0) {
                j++;
                k = 0;
            }
        }
    }
    return P;
}

int advance(char *str, int l, int *kmp, char ch, int j) {
    while (j == l || ch != str[j]) {
        if (kmp[j] < 0) {
            return 0;
        }
        j = kmp[j];
    }
    // j < l && ch == str[j]
    return j + 1;
}
#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)

char A[1001], B[1001];

void solve() {
    RS(A); RS(B);
    DRI(N);

    REP(i, N) {
        char S[27] = {};
        RS(S); DRI(b[i]);
        int matchedA = 0, lenS = strlen(S), kmp1[lenS+1], kmp2[lenS+1];
        kmp_table(S, kmp1);

        char invS[lenS+1];
        strcpy(invS, S);
        reverse(invS, invS + lenS);
        kmp_table(invS, kmp2);

        int lenA = strlen(A), lenB = strlen(B), fullA = 0;
        puts(S);
        REP(j, lenA) {
            matchedA = advance(S, lenS, kmp1, A[j], matchedA);
            if (matchedA == lenS) {
                fullA++;
            }
            int matchedB = 0, fullB = 0;
            PER(k, lenB) {
                matchedB = advance(invS, lenS, kmp2, B[k], matchedB);
                if (matchedB == lenS) {
                    fullB++;
                }
                PI(matchedB);
            }
        }
    }
}

int main() {
    CASET {
        solve();
    }
    return 0;
}
