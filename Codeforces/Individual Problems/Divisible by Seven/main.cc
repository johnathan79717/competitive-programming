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
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
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
#define CASET int ___T,cas=1;scanf("%d ",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define FST first
#define SND second
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

char s[1000005];
int L;

void solve(int a, int b, int c, int d) {
  s[0] = a + '0';
  s[1] = b + '0';
  s[2] = c + '0';
  s[3] = d + '0';
}

int main() {
  RS(s);
  L = strlen(s);
  PER(i, L) if(s[i] == '1') {
    s[i] = s[0];
    s[0] = '0';
    break;
  }
  PER(i, L) if(s[i] == '6') {
    s[i] = s[1];
    s[1] = '0';
    break;
  }
  PER(i, L) if(s[i] == '8') {
    s[i] = s[2];
    s[2] = '0';
    break;
  }
  PER(i, L) if(s[i] == '9') {
    s[i] = s[3];
    s[3] = '0';
    break;
  }
  int sum = 0;
  REP(i, L) {
    sum = sum * 10 + (s[i] - '0');
    sum %= 7;
  }
  int ten = 1;
  REP(i, L-4) {
    ten = ten * 10 % 7;
  }
  int inv[] = {0, 1, 4, 5, 2, 3, 6};
  ten = inv[ten];
  int ans = ten * (7-sum) % 7;
  switch(ans) {
    case 0: solve(1, 8, 6, 9); break;
    case 1: solve(1, 9, 6, 8); break;
    case 2: solve(1, 6, 8, 9); break;
    case 3: solve(6, 1, 9, 8); break;
    case 4: solve(1, 6, 9, 8); break;
    case 5: solve(1, 9, 8, 6); break;
    case 6: solve(1, 8, 9, 6); break;
  }
  puts(s);
  return 0;
}