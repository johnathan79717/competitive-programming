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
#include <cassert>
using namespace std;
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
const int INF = 2000000000;

int main() {
  DRI(T);
  while(T--) {
    DRI(N);
    VI shelves(N);
    int bucket_size = sqrt(N);
    V(VI) buckets(N / bucket_size);
    if(N % bucket_size) buckets.EB();
    REP(i, N) {
      RI(shelves[i]);
      buckets[i / bucket_size].PB(shelves[i]);
    }
    FOR(bucket, buckets)
      sort(ALL(bucket));
    DRI(Q);
    while(Q--) {
      DRI(t);
      if(t) {
        DRII(x, k);
        x--;
        int i = x / bucket_size;
        auto it = find(ALL(buckets[i]), shelves[x]);
        assert(it != buckets[i].end());
        if(shelves[x] < k) {
          while(it + 1 != buckets[i].end() && *(it+1) < k) {
            *it = *(it+1);
            it++;
          }
          *it = k;
        } else {
          while(it != buckets[i].begin() && *(it-1) > k) {
            *it = *(it-1);
            it--;
          }
          *it = k;
        }
        shelves[x] = k;
      } else {
        DRIII(ox, oy, k);
        ox--; oy--; k--;
        int ub = 1001, lb = 1;
        while(ub - lb > 1) {
          int x = ox, y = oy;
          int m = (ub + lb) / 2, cnt = 0;
          while(x <= y && x % bucket_size)
            if(shelves[x++] < m)
              cnt++;
          while(x <= y && (y+1) % bucket_size)
            if(shelves[y--] < m)
              cnt++;
          if(x <= y)
            REP1(i, x / bucket_size, y / bucket_size)
              cnt += lower_bound(ALL(buckets[i]), m) - buckets[i].begin();
          if(cnt > k)
            ub = m;
          else
            lb = m;
        }
        PI(lb);
      }
    }
  }
  return 0;
}