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

struct Info
{
  int i, f0, f1;
  Info(int i, int f0, int f1): i(i), f0(f0), f1(f1) {}
};

int main() {
  DRI(n);
  V(VI) adj(n+1);
  REP(i, n-1) {
    DRII(u, v);
    adj[u].PB(v);
    adj[v].PB(u);
  }
  VI init(1+n), goal(1+n);
  REP1(i, 1, n) RI(init[i]);
  REP1(i, 1, n) RI(goal[i]);
  queue<Info> q;
  VI ans;
  V(bool) visited(n+1);
  q.emplace(1, 0, 0);
  while(!q.empty()) {
    int i = q.front().i, f0 = q.front().f0, f1 = q.front().f1;
    q.pop();
    if(visited[i]) continue;
    visited[i] = true;
    int b = init[i]^goal[i]^f0;
    if(b) ans.EB(i);
    FOR(v, adj[i]) {
      q.emplace(v, f1, f0^b);
    }
  }
  PI(ans.size());
  FOR(a, ans) PI(a);
  return 0;
}
