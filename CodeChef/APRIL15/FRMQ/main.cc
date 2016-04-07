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
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <sstream>
#include <bitset>
using namespace std;
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define BG begin()
#define ED end()
#define FOR(i,c) for(auto &i: c)
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define GET_4TH(_1, _2, _3, NAME, ...) NAME
#define RI(argv...) GET_4TH(argv, RI3, RI2, RI1)(argv)
#define RI1(x) scanf("%d",&x)
#define RI2(x,y) RI1(x), RI1(y)
#define RI3(x,y,z) RI1(x), RI2(y, z)
#define DRI(argv...) int argv;RI(argv)
#define RL(x) scanf("%lld",&x)
#define DRL(x) LL x;RL(x)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PL(x) printf("%lld\n",x)
#define PZ(x) PI((x).i);
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define PQ priority_queue
#define E emplace
#define EB emplace_back
#define LB lower_bound
#define UB upper_bound
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#define V(x) vector<x >
#define DRA(A, N) VI A(N); REP(i, N) RI(A[i])

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000;

int sparse_table[17][100001];

template<class T>
void make_sparse_table(int N, const T &A) {
    REP(i, N) {
        sparse_table[0][i] = A[i];
    }
    int k = 1;
    while ((1 << k) <= N) {
        REP1(i, 0, N - (1 << k)) {
            sparse_table[k][i] = max(sparse_table[k-1][i], sparse_table[k-1][i+(1<<(k-1))]);
        }
        k++;
    }
}

int query_sparse_table(int l, int r) {
    if (l > r) swap(l, r);
    int k = sizeof(int) * 8 - 1 - __builtin_clz(r+1-l);
    return max(sparse_table[k][l], sparse_table[k][r+1-(1<<k)]);
}

int main() {
    DRI(N);
    DRA(A, N);
    DRI(M, x, y);
    make_sparse_table(N, A);
    LL ans = 0;
    while (M--) {
        ans += query_sparse_table(x, y);
        x += 7;
        while (x >= N-1) x -= N-1;
        y += 11;
        while (y >= N) y -= N;
    }
    PL(ans);
    return 0;
}
