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
int n;
VI c;

VI poss;

void dfs(int k, int sum, int used, int cnt) {
  if(sum == 0 && cnt > 1)
    poss.PB(used);
  REP1(i, k, n-1) {
    if(c[i] > sum) break;
    if(used & (1 << i)) continue;
    dfs(i+1, sum - c[i], used | (1<<i), cnt + 1);
  }
}

map<pair<int, int>, int> mp;

bool solve(int i, int used) {
  if(i == n) return used == (1<<n)-1;
  if(mp.count(MP(i, used))) return mp[MP(i, used)];
  if(c[i] == 1) return mp[MP(i, used)] = solve(i+1, used);
  // if(c[i] == 2) return mp[MP(i, used)] = false;
  poss.clear();
  dfs(0, c[i]-1, used, 0);
  FOR(p, poss) {
    if(solve(i+1, p)) return mp[MP(i, used)] = true;
  }
  return mp[MP(i, used)] = false;
}

int main() {
  RI(n);
  c.resize(n);
  REP(i, n) RI(c[i]);
  sort(ALL(c));
  if(solve(0, 1<<(n-1))) puts("YES"); else puts("NO");
  return 0;
}
