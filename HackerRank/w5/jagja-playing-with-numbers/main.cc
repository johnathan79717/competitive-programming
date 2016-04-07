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
#include <unordered_map>
#include <unordered_set>
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

// index starts with 1
template<class T>
class BIT {
public:
  vector<T> bit;
  BIT() {}
  BIT(int n): bit(n+1) {}
  T sum(int i) {
    i = min(i, (int)bit.size()-1);
    T s = 0;
    while(i > 0) {
      s += bit[i];
      i &= i - 1;
    }
    return s;
  }
  void add(int i, T x) {
    while(i < bit.size()) {
      bit[i] += x;
      i += i & -i;
    }
  }
  void resize(int n) {
    bit.resize(n+1);
  }
};

int main() {
  DRI(Q);
  char type[2];
  int N = 1000000;
  BIT<LL> bit(N);
  int ps[] = {48576, 48640, 49152, 65536, 131072, 262144, 524288};
  while(Q--) {
    RS(type);
    if(type[0] == 'R') {
      DRII(pos1, pos2);
      PL(bit.sum(pos2) - bit.sum(pos1 - 1));
    } else {
      DRIII(pos, M, plus);
      int todo = 0;
      for (int i=1;i<=50;i++) {
        int back = pos;
        int j;
        for(j = 999; j >= 0; j--) {
          int a = 0;
          // bit.add(pos, M);
          bit.bit[pos] += (a+=M);
          // int s,in=__builtin_popcount(pos);
          for(int k = 0;;k++) {
            // s = pos + (1<<k);
            // if( __builtin_popcount(s) <= in ) {
            //   in = __builtin_popcount(s);
            //   pos = s;
              pos += pos & -pos;
              if(pos>N) {
                break;
              }
              // bit.add(pos, M);
              bit.bit[pos] += (a+=M);
            // }
          }
          pos -= N;
          if(pos == 48576) break;
        }
        todo += j;
        pos = back+plus;
        if(pos>N) pos-=N;
      }
      todo *= M;
      for(int i = 0; i < 7; i++) {
        bit.bit[ps[i]] += todo * (i+1);
        // bit.add(ps[i], todo);
      }
    }
  }
  return 0;
} 