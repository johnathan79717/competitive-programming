// Create your own template by modifying this file!

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
#define LB lower_bound
#define UB upper_bound
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
const int INF = 1000000000;

int main() 
{
  DRIII(n, a, b);
  VI p(n);
  unordered_set<int> set, set2;
  REP(i, n) {
    RI(p[i]);
    set.insert(p[i]);
  }
  auto it = set.begin();
  function<void(int, int)> dfs;
  dfs = [a, b, &dfs, &set, &set2](int x, int p) {
    if(set.count(x)) {
      set2.insert(x);
      if(a - x != x && a - x != p)
        dfs(a - x, x);
      if(b - x != x && b - x != p)
        dfs(b - x, x);
    }
  };
  bool fail = false;
  unordered_map<int, int> ans;
  while(!set.empty()) {
    int x = *set.begin();
    set2.clear();
    dfs(x, -1);
    for(int x: set2) {
      // PI(x);
      set.erase(x);
    }
    fail = false;
    for(int x: set2) {
      if(!set2.count(a - x)) {
        fail = true;
        break;
      }
    }
    if(!fail) {
      for(int x: set2) {
        ans[x] = 0;
      }
      continue;
    }
    fail = false;
    for(int x: set2) {
      if(!set2.count(b - x)) {
        fail = true;
      }
    }
    if(fail) {
      break;
    } else {
      for(int x: set2) {
        ans[x] = 1;
      }
    }
  }
  if(fail) {
    puts("NO");
  } else {
    puts("YES");
    for(int pp: p) {
      PIS(ans[pp]);
    }
    puts("");
  }
  return 0;
}

