// Create your own template by modifying this file!

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
#define FOR(i,c) for(auto i=(c).begin();i!=(c).end();i++)
#define SZ size()
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

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;


int main() {
    DRI(T);
    while (T--) {
        DRII(N, M);
        vector<VI> v(M+1);
        DRII(a, b);
        v[0].PB(a);
        REP1(j, 1, M)
            v[j].PB(min(a, b));
        REP(i, N-1) {
            RII(a, b);
            PER1(j, M, 0) {
                int i1;
                if (a > v[j].back()) {
                    // v[j].PB(a);
                    i1 = v[j].size();
                } else {
                    // *lower_bound(v[j].begin(), v[j].end(), a) = a;
                    i1 = lower_bound(v[j].begin(), v[j].end(), a) - v[j].begin();
                }

                if (j > 0) {
                    if (b > v[j-1].back()) {
                        if (v[j].size() == v[j-1].size())
                            v[j].PB(b);
                        else
                            v[j][v[j-1].size()] = min(v[j][v[j-1].size()], b);
                    } else {
                        int i2 = lower_bound(ALL(v[j-1]), b) - v[j-1].begin();
                        v[j][i2] = min(v[j][i2], b);
                    }
                }
                if (i1 < v[j].size()) v[j][i1] = min(v[j][i1], a);
                else v[j].PB(a);
            }
        }
        PI(v[M].size());
    }
    return 0;
}
