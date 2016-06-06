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
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <stack>
#include <functional>
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

char s[100001];

int main() {
    RS(s);
    int cnt = 0;
    // VI ans;
    int num = 0;
    int last = -1;
    REPL(i, s) {
        char c = s[i];
        if (c == '(') cnt++;
        else if (c == ')') cnt--;
        else {
            last = i;
            num++;
            cnt--;
        }
        if (cnt < 0) {
            PI(-1);
            return 0;
        }
    }
    int cnt2 = 0;
    REPL(i, s) {
        char c = s[i];
        if (c == '(') cnt2++;
        else if (i != last) cnt2--;
        else {
            cnt2 -= cnt + 1;
        }
        if (cnt2 < 0) {
            PI(-1);
            return 0;
        }
    }
    REP(i, num-1) PI(1);
    PI(cnt + 1);
  return 0;
}
