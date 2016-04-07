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
#define RI(x) scanf("%d",&x)
#define RL(x) scanf("%lld",&x)
#define DRI(x) int x;RI(x)
#define DRL(x) LL x;RL(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PL(x) printf("%lld\n",x)
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

// typedef pairs<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000;

char str[1000002];
int P[1000002];
int single[1000002][4];
LL pairs[1000002][4][4]; //, suffix_pair[1000002][4][4];

int transform(char c) {
    switch (c) {
        case 'c': return 0;
        case 'h': return 1;
        case 'e': return 2;
        case 'f': return 3;
        default: assert(false);
    }    
}

int main() {
    RS(str);
    int N = LEN(str);
    REP(i, N) {
        P[i+1] = transform(str[i]);
    }
    REP1(i, 1, N) {
        REP(j, 4) {
            REP(k, 4) {
                pairs[i][j][k] = pairs[i-1][j][k];
            }
            pairs[i][j][P[i]] += single[i-1][j];
        }
        REP(j, 4) {
            single[i][j] = single[i-1][j];
        }
        single[i][P[i]]++;
    }
    // PER1(i, N, 1) {
    //     REP(j, 4) {
    //         REP(k, 4) {
    //             suffix_pair[i][j][k] = suffix_pair[i+1][j][k];
    //         }
    //         suffix_pair[i][j][P[i]] += suffix_single[i+1][j];
    //     }
    //     REP(j, 4) {
    //         suffix_single[i][j] = suffix_single[i+1][j];
    //     }
    //     suffix_single[i][P[i]]++;
    // }
    CASET {
        char s1[2], s2[2];
        RS(s1); RS(s2);
        char a = transform(s1[0]), b = transform(s2[0]);
        DRII(L, R);
        PL(pairs[R][a][b] - pairs[L-1][a][b] - (LL)single[L-1][a] * (single[R][b] - single[L-1][b]));
    }
    return 0;
}
