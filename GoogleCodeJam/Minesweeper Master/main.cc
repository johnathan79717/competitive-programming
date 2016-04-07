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
    DRIII(R, C, M);
    int f = R*C - M;
    printf("Case #%d:\n", t);
    char g[50][51];
    MS0(g);
    REP(i, R) REP(j, C) g[i][j] = '*';
    bool impossible = false;
    if(R == 1) {
      REP(j, f) g[0][j] = '.';
    } else if(C == 1) {
      REP(i, f) g[i][0] = '.';
    } else if(f == 1) {
      g[0][0] = '.';
    } else if(f == 4) {
      g[0][1] = g[1][0] = g[1][1] = '.';
    } else if(f <= 3 || f == 5 || f == 7) {
      impossible = true;
    } else if(R == 2) {
      if(f % 2)
        impossible = true;
      else
        REP(i, f/2) g[0][i] = g[1][i] = '.';
    } else if(C == 2) {
      if(f % 2)
        impossible = true;
      else
        REP(i, f/2) g[i][0] = g[i][1] = '.';
    } else if(f > 2 * C) {
      REP(i, f / C) REP(j, C) g[i][j] = '.';
      REP(j, f % C) g[f/C][j] = '.';
      if(f % C == 1) {
        if(f / C == 2) {
          g[0][C-1] = g[1][C-1] = '*';
          g[2][f%C] = g[2][f%C+1] = '.';
        } else {
          g[f/C-1][C-1] = '*';
          g[f/C][f%C] = '.';
        }
      }
    } else if(f % 2 == 0) {
      REP(i, f/2) g[0][i] = g[1][i] = '.';
    } else {
      assert(f >= 9);
      REP(i, 3) REP(j, 3) g[i][j] = '.';
      int cnt = 9;
      int i = 3;
      while(cnt < f) {
        g[0][i] = g[1][i] = '.';
        cnt += 2;
        i++;
      }
    }
    g[0][0] = 'c';
    if(impossible)
      puts("Impossible");
    else
      REP(i, R) puts(g[i]);
  }
  return 0;
}
