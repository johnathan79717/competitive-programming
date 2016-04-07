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

char c[101][101];

bool visited[101][101];

int N, M, ans;

bool dfs(int i, int j) {
  visited[i][j] = true;
  if(c[i][j] == '*')
    return true;
  int ways = 0;
  bool found = false;
  if(i-1 >= 0 && !visited[i-1][j] && c[i-1][j] != 'X') {
    found = found || dfs(i-1, j);
    ways++;
  }
  if(j+1 < M && !visited[i][j+1] && c[i][j+1] != 'X') {
    found = found || dfs(i, j+1);
    ways++;
  }
  if(j-1 >= 0 && !visited[i][j-1] && c[i][j-1] != 'X') {
    found = found || dfs(i, j-1);
    ways++;
  }
  if(i+1 < N && !visited[i+1][j] && c[i+1][j] != 'X') {
    found = found || dfs(i+1, j);
    ways++;
  }
  if(found && ways > 1)
    ans++;
  return found;
}

int main() {
  DRI(T);
  while(T--) {
    RII(N, M);
    REP(i, N)
      RS(c[i]);
    DRI(K);
    ans = 0;
    MS0(visited);
    REP(i, N) REP(j, M) if(c[i][j] == 'M') {
      dfs(i, j);
    }
    // cerr << ans << endl;
    if(ans == K)
      puts("Impressed");
    else
      puts("Oops!");
  }
  return 0;
}