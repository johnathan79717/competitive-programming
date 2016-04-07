/*
ID: johnath2
PROG: rect1
LANG: C++
*/
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
using namespace std;
#define NAME "rect1"
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define SZ(x) ((int)(x).size())
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
#define PLL(x) printf("%lld\n",x)
#define PIS(x) printf("%d ",x)
#define CASET int ___T,cas=1;scanf("%d ",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int MOD = 1000000007;
const int INF = 1000000000;
inline int add(int a, int b) { return a + b < MOD ? a + b : a + b - MOD; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + MOD : a - b; }
inline int mul(int a, int b) { return (LL)a * b % MOD; }

struct Rect {
  int x1, x2, y1, y2, c;
  Rect() : c(0) {}
  Rect(int x1, int x2, int y1, int y2, int c)
  : x1(x1), x2(x2), y1(y1), y2(y2), c(c) {}

  bool contains(int x, int y) const {
    return x1 <= x && x <= x2 && y1 <= y && y <= y2;
  }
  bool operator<(const Rect &b) const {
    if(x1 != b.x1) return x1 < b.x1;
    if(y1 != b.y1) return y1 < b.y1;
    if(x2 != b.x2) return x2 < b.x2;
    if(y2 != b.y2) return y2 < b.y2;
    return c < b.c;
  }
};

bool intersect(const Rect &a, const Rect &b) {
  return a.contains(b.x1, b.y1) || a.contains(b.x1, b.y2)
      || a.contains(b.x2, b.y1) || a.contains(b.x2, b.y2)
      || b.contains(a.x1, a.y1) || b.contains(a.x1, a.y2)
      || b.contains(a.x2, a.y1) || b.contains(a.x2, a.y2);
}

void print(const Rect s) {
  printf("%d %d %d %d %d\n", s.x1, s.y1, s.x2, s.y2, s.c);
}

void print(const vector<Rect> s) {
  FOR(it, s) print(*it);
}

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  DRIII(A, B, N);
  vector<Rect> v[2];
  vector<Rect> *rects = v, *next = v+1;
  rects->PB(Rect(0, A, 0, B, 1));
  while(N--) {
    // PI(N);
    DRII(x1, y1);
    DRIII(x2, y2, c);
    next->clear();
    FOR(it, *rects) {
      // printf("Get "); print(*it);
      if(it->x1 < x1)
        next->PB(Rect(it->x1, min(it->x2, x1), it->y1, it->y2, it->c));
      if(x2 < it-> x2)
        next->PB(Rect(max(it->x1, x2), it->x2, it->y1, it->y2, it->c));
      if(it->y1 < y1 && x1 < it-> x2 && it->x1 < x2)
        next->PB(Rect(max(it->x1, x1), min(it->x2, x2), it->y1, min(it-> y2, y1), it->c));
      if(y2 < it->y2 && x1 < it-> x2 && it->x1 < x2)
        next->PB(Rect(max(it->x1, x1), min(it->x2, x2), max(it->y1, y2), it->y2, it->c));
    }
    next->PB(Rect(x1, x2, y1, y2, c));
    swap(rects, next);
  }
  int ans[2501]; MS0(ans);
  FOR(it, *rects) {
    ans[it->c] += (it->x2 - it->x1) * (it->y2 - it->y1);
  }
  REP1(i, 1, 2500)
    if(ans[i] > 0)
      PIS(i), PI(ans[i]);
  return 0;
}