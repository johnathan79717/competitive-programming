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
using namespace std;
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define LEN(X) strlen(X)
#define NAME "stampede"
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

struct Cow {
    int y, endtime; //, i;
    bool operator <(Cow const &other) const {
        return y > other.y;
    }
};

int y[50001];

int main() {
#ifndef STDIO
    freopen(NAME".in", "r", stdin);
    freopen(NAME".out", "w", stdout);
#endif
    DRI(N);
    // V(Cow) cow(N);
    map<int, V(Cow)> begin, end;
    REP(i, N) {
        DRIII(x, yy, r);
        // Cow cow;
        // cow.y = y;
        // cow.endtime = -x*r;
        // cow.i = i;
        // cows[-(x+1)*r].PB(cow);
        y[i] = yy;
        end[-x*r].PB(i);
        begin[-(x+1)*r].PB(i);
    }
    // sort(ALL(cow), [](const Cow& c1, const Cow &c2) {
    //     return c1.t1 < c2.t1;
    // });
    priority_queue<Cow> pq;
    int t = 0;
    int ans = 0;
    FOR(pr, cows) {
        while (!pq.empty() && pq.top().endtime <= pr.F) {
            if (pq.top().endtime > t) {
                ans++;
                t = pq.top().endtime;
            }
            pq.pop();
        }
        FOR(cow, pr.S) {
            pq.push(cow);
        }
    }
    while (!pq.empty()) {
        if (pq.top().endtime > t) {
            ans++;
            t = pq.top().endtime;
        }
        pq.pop();
    }
    PI(ans);
    return 0;
}