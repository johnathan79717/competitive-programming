/*
ID: johnath2
PROG: crypt1
LANG: C++11
*/
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
#include <deque>
#include <stack>
#include <functional>
#include <cassert>
using namespace std;
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define LEN(X) strlen(X)
#define NAME "meeting"
#define FOR(i,c) for(auto &i: c)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PLL(x) printf("%lld\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#define V(x) vector<x >
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 2000000000;

bool dp1[101][10001], dp2[101][10001];

vector<pair<int, pair<int,int>>> adj[101];

int main() {
#ifndef STDIO
    freopen(NAME".in", "r", stdin);
    freopen(NAME".out", "w", stdout);
#endif
    DRII(N, M);
    REP(i, M) {
        DRII(A, B);
        DRII(C, D);
        adj[A].PB(MP(B, MP(C, D)));
    }
    dp1[1][0] = true;
    dp2[1][0] = true;
    REP1(i, 1, N) {
        REP(j, 10001) {
            if (dp1[i][j]) {
                FOR(pr, adj[i]) {
                    assert(j + pr.S.S <= 10000);
                    dp1[pr.F][j + pr.S.F] = true;
                }
            }
            if (dp2[i][j]) {
                FOR(pr, adj[i]) {
                    assert(j + pr.S.S <= 10000);
                    dp2[pr.F][j + pr.S.S] = true;
                }
            }
        }
    }
    REP(j, 10001) {
        if (dp1[N][j] && dp2[N][j]) {
            PI(j);
            return 0;
        }
    }
    puts("IMPOSSIBLE");
    return 0;
}