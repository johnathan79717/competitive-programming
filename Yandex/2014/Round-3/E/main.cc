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

struct Point
{
  int x, y, z;
};

int sign(Point p1, Point p2, Point p3)
{
  return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

int main() {
  Point p[4];
  Point v;
  v.x = v.y = v.z = 0;
  REP(i, 4) {
    RIII(p[i].x, p[i].y, p[i].z);
    v.x += p[i].x;
    v.y += p[i].y;
    v.z += p[i].z;
    p[i].x *= 4;
    p[i].y *= 4;
    p[i].z *= 4;
  }

  int s1 = sign(v, p[0], p[1]);
  int s2 = sign(v, p[1], p[2]);
  int s3 = sign(v, p[2], p[0]);
  // cerr << s1 << ' ' << s2 << ' ' << s3 << endl;
  if(s1 == 0 && (p[0].x <= v.x && v.x <= p[1].x || p[1].x <= v.x && v.x <= p[0].x) ||
    s2 == 0 && (p[1].x <= v.x && v.x <= p[2].x || p[2].x <= v.x && v.x <= p[1].x) ||
    s3 == 0 && (p[2].x <= v.x && v.x <= p[0].x || p[0].x <= v.x && v.x <= p[2].x)) {
    puts("Unstable");
    return 0;
  }
  bool b1 = s1 < 0, b2 = s2 < 0, b3 = s3 < 0;
  if ((b1 == b2) && (b2 == b3)) {
    puts("Standing");
  } else {
    puts("Falling");
  }
  return 0;
}
