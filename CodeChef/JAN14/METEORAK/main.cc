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
#define MAX(x,a) (x)=max(x,a)
#define MIN(x,a) (x)=min(x,a)

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 2000000000;

struct Bar {
  int pos, height;
  Bar() {}
  Bar(int p, int h) : pos(p), height(h) {}
};

int height[1001];
bool dangerous[1001][1001];
int ans[1001][1001];

int main() {
  DRIII(N, M, K);
  while(K--) {
    DRII(x, y);
    dangerous[x-1][y-1] = true;
  }
  REP(i, N) {
    stack<Bar> stack;
    REP(j, M) {
      if(dangerous[i][j])
        height[j] = 0;
      else
        height[j]++;
      int pos = j;
      while(!stack.empty() && stack.top().height > height[j]) {
        MAX(ans[i][stack.top().height], j - stack.top().pos);
        pos = stack.top().pos;
        stack.pop();
      }
      if(stack.empty() || stack.top().height < height[j])
        stack.push(Bar(pos, height[j]));
    }
    while(!stack.empty()) {
      MAX(ans[i][stack.top().height], M - stack.top().pos);
      stack.pop();
    }
    PER1(h, i, 0)
      MAX(ans[i][h], ans[i][h+1]);
    REP1(h, 0, i+1)
      ans[i][h] *= h;
    REP1(h, 0, i)
      MAX(ans[i][h+1], ans[i][h]);
    if(i == 0) continue;
    REP1(h, 0, i)
      MAX(ans[i][h+1], ans[i-1][h]);
  }
  DRI(Q);
  while(Q--) {
    DRII(L, H);
    PI(ans[H-1][H-L+1]);
  }
  return 0;
}