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
#include <cassert>
using namespace std;
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
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

map<int, VI> adj;
vector<bool> visited(20000001);

int main() {
  int id;
  char str[10];
  int num = 0;
  vector<pair<int, char> > vote;
  while(scanf("%d%s", &id, str) != EOF) {
    num++;
    if(str[0] >= '0' && str[0] <= '9') {
      int id2 = atoi(str);
      adj[id2].PB(id);
    } else if(str[0] == 'S') {
      vote.PB(MP(id, 0));
    } else if(str[0] == 'J') {
      vote.PB(MP(id, 1));
    } else {
      vote.PB(MP(id, 2));
    }
  }
  int q[num], qf = 0, qb = 0;
  int ans[3] = {0, 0, 0};
  REP(i, vote.size()) {
    int cnt = 1;
    qf = qb = 0;
    q[qb++] = vote[i].F;
    while(qf < qb) {
      int v = q[qf++];
      REP(j, adj[v].size()) {
        if(!visited[adj[v][j]]) {
          q[qb++] = adj[v][j];
          visited[adj[v][j]] = true;
          cnt++;
        }
      }
    }
    ans[vote[i].S] += cnt;
  }
  printf("Steve %d\nJenny %d\nEva %d\nInvalid %d\n", ans[0], ans[1], ans[2], num - ans[0] - ans[1] - ans[2]);
  return 0;
}
