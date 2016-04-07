/*
ID: johnath2
PROG: maze1
LANG: C++
*/
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
using namespace std;
#define NAME "maze1"
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define SZ(x) ((int)(x).size())
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
#define CASET int ___T,cas=1;scanf("%d ",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int MOD = 1000000007;
const int INF = 2000000000;
inline int add(int a, int b) { return a + b < MOD ? a + b : a + b - MOD; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + MOD : a - b; }
inline int mul(int a, int b) { return (LL)a * b % MOD; }

#define MAX_W 38
#define MAX_H 100
#define MAX_QUEUE MAX_H*MAX_W

template<class T>
struct Queue {
  T arr[MAX_QUEUE];
  int f, b;
  Queue() : f(0), b(0) {}
  void push(const T& val) { arr[b++] = val; }
  bool empty() { return f == b; }
  T& pop() { return arr[f++]; }
};

struct P {
  int i, j, l;
  P() {}
  P(int i, int j, int l) : i(i), j(j), l(l) {}
};

char grid[2*MAX_H + 1][2 * MAX_W + 2];
int W, H;
Queue<P> q;
bool used[MAX_H][MAX_W];

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  RII(W, H);
  gets(grid[0]);
  REP(i, 2*H+1)
    gets(grid[i]);
  REP(j, W) {
    if(grid[0][2*j+1] == ' ')
      q.push(P(0, j, 1)), used[0][j] = true;;
    if(grid[2*H][2*j+1] == ' ')
      q.push(P(H-1, j, 1)), used[H-1][j] = true;
  }
  REP(i, H) {
    if(grid[2*i+1][0] == ' ')
      q.push(P(i, 0, 1)), used[i][0] = true;
    if(grid[2*i+1][2*W] == ' ')
      q.push(P(i, W-1, 1)), used[i][W-1] = true;
  }
  int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1}, ans = 1;
  while(!q.empty()) {
    P p = q.pop();
    REP(k, 4) {
      int ii = p.i + di[k], jj = p.j + dj[k];
      if(ii < 0 || jj < 0 || ii >= H || jj >= W)
        continue;
      if(grid[2*p.i + 1 + di[k]][2*p.j + 1 + dj[k]] == ' ' && !used[ii][jj])
        q.push(P(ii, jj, ans = p.l + 1)), used[ii][jj] = true;
    }
  }
  PI(ans);
  return 0;
}