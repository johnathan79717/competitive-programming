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



int main() {
  DRI(T);
  REP1(t, 1, T) {
    char focal[100], ccd[100], image[100];
    RS(focal);
    RS(ccd);
    RS(image);
    double f = atof(focal), c = atof(ccd), i = atof(image);
    int mod = 0;
    int l = strlen(focal);
    switch(focal[l-2]) {
      case 'd': mod -= 1; break;
      case 'c': mod -= 2; break;
      case 'm': mod -= 3; break;
      case 'u': mod -= 6; break;
      case 'n': mod -= 9; break;
      default: break;
    }
    l = strlen(ccd);
    switch(ccd[l-2]) {
      case 'd': mod += 1; break;
      case 'c': mod += 2; break;
      case 'm': mod += 3; break;
      case 'u': mod += 6; break;
      case 'n': mod += 9; break;
      default: break;
    }
    // cout << f << ' ' << c << endl;
    // cout << mod << endl;
    printf("Case %d: %.2lfpx\n", t, i * f / c * pow(10, mod));
  }
  return 0;
}
