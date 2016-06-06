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
#define FOR(i,c) for(auto i=(c).begin();i!=(c).tail();i++)
#define SZ size()
#define ALL(x) (x).begin(),(x).tail()
#define REP(i,n) for(i=0;i<(n);i++)
#define REP1(i,a,b) for(i=(a);i<=(b);i++)
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
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

char first[51], last[51];
LL AC[51];
char s[3][101], l[3];

int main() {
  DRII(k, x); DRII(n, m);
  int i, j;
  l[1] = n; l[2] = m;
  REP1(first[1], 'A', 'C') REP1(last[1], 'A', 'C') {
    if(n == 1 && first[1] != last[1])
      continue;
    REP1(AC[1], 0, n/2) {
      if(n == 2 && AC[1] == 0 && first[1] == 'A' && last[1] == 'C')
        continue;
      if(AC[1] * 2 == n && (first[1] != 'A' || last[1] != 'C'))
        continue;
      if(n > 1 && AC[1] * 2 == n-1 && first[1] != 'A' && last[1] != 'C')
        continue;
      REP1(first[2], 'A', 'C') REP1(last[2], 'A', 'C') {
        if(m == 1 && first[2] != last[2])
          continue;
        REP1(AC[2], 0, m/2) {
          if(m == 2 && AC[2] == 0 && first[2] == 'A' && last[2] == 'C')
            continue;
          if(AC[2] * 2 == m && (first[2] != 'A' || last[2] != 'C'))
            continue;
          if(m > 1 && AC[2] * 2 == m-1 && first[2] != 'A' && last[2] != 'C')
            continue;
          REP1(i, 3, k) {
            first[i] = first[i-2];
            last[i] = last[i-1];
            AC[i] = AC[i-2] + AC[i-1];
            if(last[i-2] == 'A' && first[i-1] == 'C')
              AC[i]++;
          }
          if(AC[k] != x)
            continue;
          REP1(j, 1, 2) {
            fill(s[j], s[j] + l[j], 'B');
            s[j][0] = first[j];
            s[j][l[j]-1] = last[j];
            if(s[j][0] == 'A')
              REP(i, 2*AC[j])
                s[j][i] = (i%2) ? 'C' : 'A';
            else
              REP1(i, 1, 2*AC[j])
                s[j][i] = (i%2) ? 'A' : 'C';
            puts(s[j]);
          }
          return 0;
        }
      }
    }
  }
  puts("Happy new year!");
  return 0;
}