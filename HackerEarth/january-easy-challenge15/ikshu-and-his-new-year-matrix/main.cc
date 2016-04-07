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

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000;

bool isprime[100001];
int a[1001][1001];

int v(int i, int j) {
    return a[i][j] + a[i-1][j-1] + a[i+1][j+1] + a[i-1][j+1] + a[i+1][j-1];
}

int main() {
    DRII(N, K);
    MS1(isprime);
    for (int p = 2; p <= 100000; p++) {
        if (isprime[p]) {
            for (int i = p+p; i <= 100000; i += p)
                isprime[i] = false;
        }
    }
    REP1(i, 1, N) REP1(j, 1, N) {
        DRI(m);
        if (isprime[m]) a[i][j] = 0;
        else if (K > 1 && m % K == 0 || K == 4 && m % 2 == 0)
            a[i][j] = 1000000;
        else {
            while (m < 100000 && !isprime[m]) {
                m++;
                a[i][j]++;
            }
            if (!isprime[m]) a[i][j] = 1000000;
        }
    }
    int r = 2, c = 2;
    REP1(i, 2, N-1) REP1(j, 2, N-1) {
        if (v(i, j) < v(r, c)) {
            r = i, c = j;
        }
    }
    if (v(r, c) >= 1000000) {
        puts("no");
    } else {
        puts("yes");
        PI(v(r, c));
        PIS(r); PI(c);
    }
    return 0;
}
