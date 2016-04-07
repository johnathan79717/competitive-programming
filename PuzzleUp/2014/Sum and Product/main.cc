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
#include <sstream>
#include <bitset>
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
  unordered_map<int, set<pair<int, pair<int, int> > > > sum, prod;
  REP1(x, 1, 15) {
    REP1(y, x+1, 15) {
      REP1(z, y+1, 15) {
        sum[x+y+z].insert(MP(x, MP(y, z)));
        prod[x*y*z].insert(MP(x, MP(y, z)));
      }
    }
  }
  // for(auto &pr2: prod) {
  //   PIS(pr2.first);
  //   for(int p: pr2.second) PIS(p);
  //   puts("");
  // }
  auto it = sum.begin();
  vector<int> wrongSums;
  while(it != sum.end()) {
    auto temp = it++;
    bool know = false;
    for(auto &p: temp->second) {
      if(prod[p.first * p.second.first * p.second.second].size() == 1)
        know = true;
    }
    if(know || temp->second.size() == 1) {
      wrongSums.PB(temp->first);
      // sum.erase(temp);
    } else {
      // PI(temp->first);
      // for(auto p: temp->second)
      //   PIS(p);
      // puts("");
    }
  }
  for(int i: wrongSums) {
    sum.erase(i);
  }
  for(auto &pr2: sum) {
    PI(pr2.first);
    for(auto &p: pr2.second) {
      PIS(p.first); PIS(p.second.first); PIS(p.second.second);
      PI(p.first * p.second.first * p.second.second);
    }
  }
  // for(auto &pr2: prod) {
  //   for(int i: wrongSums)
  //     pr2.second.erase(i);
  //   // PIS(pr2.first);
  //   // for(auto p: pr2.second)
  //   //   PIS(p);
  //   // puts("");
  //   if(pr2.second.size() == 1) {
  //     for(auto &pr1: sum) {
  //       pr1.second.erase(pr2.first);
  //     }
  //   }
  // }
  // for(auto pr1: sum) {
  //   // PI(pr1.first);
  //   // for(auto p: pr1.second)
  //   //   PIS(p);
  //   // puts("");
  //   if(pr1.second.size() == 1) {
  //     PI(pr1.first);
  //     PI(*pr1.second.begin());
  //   }
  // }
  return 0;
}
