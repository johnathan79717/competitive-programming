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
#include <unordered_set>
#include <unordered_map>
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

int wkx, wky, wrx, wry;

bool attacked(int bkx, int bky) {
  if(abs(bkx-wkx) <= 1 && abs(bky - wky) <= 1)
    return true;
  if(bkx == wrx && bky == wry)
    return false;
  if(wrx == bkx) {
    return wkx != wrx || (wky - wry) * (wky - bky) > 0;
  } else if(wry == bky) {
    return wky != wry || (wkx - wrx) * (wkx - bkx) > 0;
  } else {
    return false;
  }
}

bool in(int x, int y) {
  return x >= 0 && x < 8 && y >= 0 && y < 8;
}

bool move(int bkx, int bky) {
  REP1(x, bkx-1, bkx+1) REP1(y, bky-1, bky+1) {
    if(!in(x, y) || (x == bkx && y == bky))
      continue;
    if(!attacked(x, y))
      return true;
  }
  return false;
}

int main() {
  wkx = getchar() - 'a';
  wky = getchar() - '1';
  getchar();
  wrx = getchar() - 'a';
  wry = getchar() - '1';
  getchar();
  int bkx = getchar() - 'a';
  int bky = getchar() - '1';
  // printf("%d%d%d%d%d%d", wkx, wky, wrx, wry, bkx, bky);
  if(abs(wkx - bkx) <= 1 && abs(wky - bky) <= 1) {
    puts("Strange");
  } else if(!attacked(bkx, bky)) {
    if(move(bkx, bky))
      puts("Normal");
    else
      puts("Stalemate");
  } else {
    if(move(bkx, bky))
      puts("Check");
    else
      puts("Checkmate");
  }
}