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

double a, b, c, d, L, R;

double f(double x) {
    return abs(((a * x + b) * x + c) * x + d);
}

int main() {
    while(scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &L, &R) != EOF) {
        double ans = max(f(L), f(R));

        if (a == 0) {
            if (b != 0) {
                double x = -c / (b * 2);
                if (L <= x && x <= R)
                    ans = max(ans, f(x));
            }
        } else {
            double A = a * 3, B = b * 2, C = c, D = B * B - 4 * A * C;
            if (D >= 0) {
                double x1 = (-B + sqrt(D)) / (2 * A), x2 = (-B - sqrt(D)) / (2 * A);
                if (L <= x1 && x1 <= R)
                    ans = max(ans, f(x1));
                if (L <= x2 && x2 <= R)
                    ans = max(ans, f(x2));
            }
        }
        printf("%.2f\n", ans);
    }
    return 0;
}
