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
using namespace std;
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(x) (x).begin(),(x).end()
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
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
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

struct City
{
    int f, s, i;
};

bool operator<(const City &c1, const City &c2) {
    if (c1.f - c1.s != c2.f - c2.s)
        return (c1.f - c1.s > c2.f - c2.s);
    if (c1.s != c2.s)
        return c1.s < c2.s;
    return c1.i < c2.i;
}

#define PII(i, n, x) REP(i, n) if (i < n-1) PIS(x); else PI(x);

int main() {
    int N;
    while(RI(N) != EOF) {
        V(City) city(N);
        REP(i, N) {
            RII(city[i].f, city[i].s);
            city[i].i = i;
        }
        sort(ALL(city));
        PII(i, N, city[i].i);
        // REP(i, N) {
        //     if (i < N-1)
        //         PIS(city[i].i);
        //     else PI(city[i].i);
        // }
    }
    return 0;
}
