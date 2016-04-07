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


V(unsigned) x(43);

int rnd() {
  static int i = 0;
  static int c = 0;
  int r = 43, s = 22;
  if(i < 43) return x[i++];
  if((ULL)x[i-s] < (ULL)x[i-r] + c)
    c = 1;
  x.PB(x[i-s] - x[i-r] - c);
  return x.back();
}

int main() {
  DRI(T);
  REP(t, T) {
    DRI(n);
    V(ULL) a(n);
    REP(i, n) scanf("%llu", &a[i]);
    REP(i, 43) RI(x[i]);
    int c = 0;
    DRI(m);
    char s[5001];
    RS(s);
    REPL(i, s) {
      int j, dir;
      if(s[i] == 'l') {
        dir = 1;
        j = 0;
      } else {
        dir = -1;
        j = n-1;
      }
      VI nw;
      ULL prev = 0;
      for(; j < a.size() && j >= 0; j += dir) {
        if(a[j] == prev) {
          nw.PB(2 * prev);
          prev = 0;
        } else {
          if(prev) nw.PB(prev);
          prev = a[j];
        }
      }
      if(prev) nw.PB(prev);
      fill(ALL(a), 0);
      if(dir == 1) j = 0; else j = n-1;
      for(; j < a.size() && j >= 0; j += dir) {
        if(dir == 1)
          a[j] = nw[j];
        else
          a[j] = nw[n-1-j];
      }
      VI empty;
      REP(j, a.size()) {
        if(!a[j]) empty.PB(j);
      }
      if(empty.size() == 0) break;
      int pos = rnd() % empty.size();
      if(rnd() % 10 == 0)
        a[empty[pos]] = 4;
      else
        a[empty[pos]] = 2;
    }
    REP(i, a.size()) {
      printf("%llu", a[i]);
      if(i == a.size()-1)
        puts("");
      else
        printf("%c", ' ');
    }
  }
  return 0;
}
