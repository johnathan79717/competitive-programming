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
using namespace std;
#define BG begin()
#define ED end()
#define FOR(i,c) for(auto &i: c)
#define SZ size()
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

char s1[1000001], s2[1000001];

void read(char *s, VI &n, V(char) &c) {
  n.PB(0);
  REPL(i, s) {
    if(!isdigit(s[i])) {
      c.PB(s[i]);
      n.PB(0);
    } else {
      (n.back() *= 10) += (s[i] - '0');
    }
  }
  n.pop_back();
  // assert(n.size() == c.size());
}

int main() {
  DRI(T);
  REP1(t, 1, T) {
    DRI(L);
    printf("Case %d: ", t);
    RS(s1);
    VI n1; V(char) c1;
    read(s1, n1, c1);
    RS(s2);
    VI n2; V(char) c2;
    read(s2, n2, c2);
    LL sum1 = 0;
    LL sum2 = 0;
    REP(i, n1.size()) sum1 += n1[i];
    // REP(i, n2.size()) sum2 += n2[i];
    // assert(sum1 == sum2);
    V(string) f1(sum1 / L), f2(sum1 / L);
    int k = 0;
    REP(i, n1.size()) {
      REP(j, n1[i]) {
        f1[k].PB(c1[i]);
        k++;
        if(k == f1.size()) k = 0;
      }
    }
    k = 0;
    REP(i, n2.size()) {
      REP(j, n2[i]) {
        f2[k].PB(c2[i]);
        k++;
        if(k == f2.size()) k = 0;
      }
    }
    sort(ALL(f1));
    sort(ALL(f2));
    if(f1 == f2) puts("Yes");
    else puts("No");
  }
  return 0;
}
