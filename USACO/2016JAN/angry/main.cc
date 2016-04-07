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

template<class C> void mineq(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxeq(C&a4, C b4){a4=max(a4, b4); }
int popcount(int x) { return __builtin_popcount(x); } 
int popcount(long long x) { return __builtin_popcountll(x); } 

/*
ID: johnath2
PROG: angry
LANG: C++11
*/
#include <unordered_set>
#include <unordered_map>
#define NAME "angry"

int L[50005], R[50005];
int main() {
#ifndef STDIO
    freopen(NAME".in", "r", stdin);
    freopen(NAME".out", "w", stdout);
#endif
    DRI(N);
    VI A(N);
    REP(i, N) RI(A[i]);
    sort(ALL(A));
    REP(i, N) L[i] = R[i] = INF;
    L[0] = -1;
    L[1] = A[1] - A[0];
    REP1(i, 1, N-2) {
        int r = L[i];
        if (r == INF) continue;
        int j = upper_bound(ALL(A), A[i] + r + 1) - A.begin() - 1;
        if (j == i) {
            mineq(L[i+1], A[i+1] - A[i]);
        } else {
            mineq(L[j], r+1);
        }
    }
    PER(i, N-1) {
        mineq(L[i], L[i+1]);
    }
    R[N-1] = -1;
    R[N-2] = A[N-1] - A[N-2];
    PER1(i, N-2, 1) {
        int r = R[i];
        if (r == INF) continue;
        int j = lower_bound(ALL(A), A[i] - r - 1) - A.begin();
        if (i == j) {
            mineq(R[i-1], A[i] - A[i-1]);
        } else {
            mineq(R[j], r+1);
        }
    }
    REP(i, N-1) {
        mineq(R[i+1], R[i]);
    }
    int lb = 0, ub = 1e9;
    while (ub - lb > 1) {
        int m = lb + (ub - lb) / 2;
        int p = m / 2 - 1;
        int l = upper_bound(L, L+N, p) - L - 1;
        int r = lower_bound(R, R+N, p, greater<int>()) - R;
        if (A[r] - A[l] <= m) {
            ub = m;
        } else {
            lb = m;
        }
    }
    printf("%.1f\n", ub / 2.0);
    //int l = 0, r = N-1;
    //double ans = INF;
    //while (l <= r) {
        //mineq(ans, max((A[r] - A[l]) / 2.0, 1.0 + max(L[l], R[r])));
        //if (L[l] == R[r]) {
            //if (l == r) break;
            //if (L[l+1] < R[r-1]) {
                //l++;
            //} else {
                //r--;
            //}
        //} else if (L[l] < R[r]) {
            //l++;
        //} else {
            //r--;
        //}
    //}
    //printf("%.1f\n", ans);
    return 0;
}
