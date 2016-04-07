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

pair<LL,LL> get(int N) {
    VI A(N);
    REP(i, N) RI(A[i]);
    reverse(ALL(A));
    LL p = 0, q = 1;
    for(int a: A) {
        swap(p, q);
        q += p * a;        
    }
    return MP(q, p);
}

LL gcd(LL a, LL b) {
    if (!b) return a;
    return gcd(b, a % b);
}

void output(LL q, LL p) {
    LL d = gcd(p, abs(q));
    p /= d; q /= d;
    bool first = true;
    while (p) {
        if (first) {
            first = false;
        } else {
            printf(" ");
        }
        LL d = q / p, r = q % p;
        if (r < 0) {
            r += p;
            d--;
        }
        printf("%lld", d);
        q = r;
        swap(p, q);
    }
    puts("");
}

int main() {
    int N1, N2, cas = 1;
    while (true) {
        scanf("%d%d", &N1, &N2);
        if (!N1) break;
        printf("Case %d:\n", cas++);
        auto pr1 = get(N1);
        auto pr2 = get(N2);
        // PL(pr1.F); PL(pr1.S); PL(pr2.F); PL(pr2.S);
        output(pr1.S * pr2.F + pr1.F * pr2.S, pr1.S * pr2.S);
        output(pr1.F * pr2.S - pr1.S * pr2.F, pr1.S * pr2.S);
        output(pr1.F * pr2.F, pr1.S * pr2.S);
        output(pr1.F * pr2.S, pr1.S * pr2.F);
    }
    return 0;
}
