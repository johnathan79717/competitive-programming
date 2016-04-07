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
#include <cassert>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
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

const int ONE = 0;
const int I = 1;
const int J = 2;
const int K = 3;

int mul[8][8] = {
    {ONE, I, J, K},
    {I, 7-ONE, K, 7-J},
    {J, 7-K, 7-ONE, I},
    {K, J, 7-I, 7-ONE}
};

int mypow(int x, LL n) {
    if (n == 0) return ONE;
    int ans = mypow(mul[x][x], n/2);
    if (n % 2) return mul[ans][x];
    else return ans;
}

char s[10005];

int main() {
    REP(i, 4) REP(j, 4) {
        mul[7-i][j] = 7-mul[i][j];
        mul[i][7-j] = 7-mul[i][j];
        mul[7-i][7-j] = mul[i][j];
    }
  DRI(T);
  REP1(t, 1, T) {
    printf("Case #%d: ", t);
    DRL(L); DRL(X);
    RS(s);
    if (L * X < 3) {
        puts("NO");
        continue;
    }
    int product = ONE;
    REP(i, L) {
        s[i] = s[i] - 'i' + 1;
        product = mul[product][s[i]];
    }
    product = mypow(product, X);
    if (product != 7-ONE) {
        puts("NO");
        continue;
    }
    int x = ONE;
    LL l = -1, r = -1;
    // REP(i, L * X) {
    REP(i, L * min(4ll, X)) {
        x = mul[x][s[i%L]];
        if (x == I) {
            l = i;
            // PI(l);
            break;
        }
    }
    x = ONE;
    // REP(i, L * X) {
    REP(i, L * min(4ll, X)) {
        LL j = L*X-1-i;
        x = mul[s[j%L]][x];
        if (x == K) {
            r = j;
            // PI(r);
            break;
        }
    }
    if (l < 0 || r < 0 || l >= r) {
        puts("NO");
        continue;
    }
    puts("YES");
  }
  return 0;
}
