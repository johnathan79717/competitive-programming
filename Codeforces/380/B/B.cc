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

#define MAX 7000

struct Segment {
  int l, r;
  int x;
  Segment() {}
  Segment(int l, int r, int x) : l(l), r(r), x(x) {}
};

int lft[1 << 24], rht[1 << 24];
vector<Segment> record[MAX+1];

int num_bits(int n) {
  return n == 0 ? 0 : 1 + num_bits(n >> 1);
}

int left(int l) {
  return l + num_bits(l - 1);
}

int right(int r) {
  return r + num_bits(r);
}

int main() {
  DRII(n, m);
  REP(i, m) {
    DRII(type, level);
    if(type == 1) {
      DRIII(l, r, x);
      record[level].EB(l, r, x);
    } else {
      DRI(position);
      int l = position, r = position;
      unordered_set<int> ans;
      while(level <= n) {
        for(const Segment & seg : record[level])
          if(seg.l <= r && l <= seg.r)
            ans.insert(seg.x);
        if(level < n) {
          l = left(l);
          r = right(r);
        }
        level++;
      }
      PI((int)ans.size());
    }
  }
  return 0;
}