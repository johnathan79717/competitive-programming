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


int main() {
    DRI(N);
    VI b(N);
    LL sum = 0;
    REP(i, N) {
        RI(b[i]);
        sum += b[i];
    }
    if (sum % 3) {
        PI(-1);
        return 0;
    }
    sum /= 3;
    V(LL) prefix(N), suffix(N);
    prefix[2] = b[1];
    REP1(i, 3, N-1) {
        prefix[i] = prefix[i-3] + b[i-1];
    }
    suffix[N-3] = b[N-2];
    PER1(i, N-4, 0) {
        suffix[i] = suffix[i+3] + b[i+1];
    }
    VI ans(N);
    switch (N % 3) {
        case 0: {
            break;
        }
        case 2: {
            REP(i, N) {
                LL t = prefix[i] + suffix[i];
                if (i % 3 == 0) {
                    t += b[N-1];
                } else if (i % 3 == 1) {
                    t += b[0];
                }
                if (t - sum <= 0) {
                    PI(-1);
                    return 0;
                }
                ans[i] = t - sum;
            }
            break;
        }
        case 1: {
            REP(i, N) {
                LL t = 0;
                if (i > 0) t += prefix[i-1];
                if (i + 1 < N) t += suffix[i+1];
                if (i % 3 == 1) {
                    t += b[N-1];
                } else if (i % 3 == 2) {
                    t += b[0];
                }
                if (sum - t <= 0) {
                    PI(-1);
                    return 0;
                }
                ans[i] = sum - t;
            }
            break;
        }
    }
    REP(i, N) {
       if (i == N-1) PI(ans[i]);
       else PIS(ans[i]); 
    }
    return 0;
}
