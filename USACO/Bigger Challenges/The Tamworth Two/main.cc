/*
ID: johnath2
PROG: ttwo
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
#define NAME "ttwo"
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
const int N = 10;
char grid[10][11];
struct P {
  int i, j, di, dj;
  P() {}
  P(int i, int j) : i(i), j(j), di(-1), dj(0) {}
  void move() {
    if(i + di < 0 || j + dj < 0 || i + di > 9 || j + dj > 9 || grid[i+di][j+dj] == '*')
      turn();
    else {
      i += di;
      j += dj;
    }
  }
  void turn() {
    int temp = dj;
    dj = -di;
    di = temp;
  }
  bool operator==(const P &p) {
    return i == p.i && j == p.j;
  }
};
P farmer, cows;

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  REP(i, 10) {
    RS(grid[i]);
    REP(j, 10) {
      if(grid[i][j] == 'F')
        farmer = P(i, j), grid[i][j] = '.';
      if(grid[i][j] == 'C')
        cows = P(i, j), grid[i][j] = '.';
    }
  }

  REP1(k, 1, 200000) {
    farmer.move();
    cows.move();
    if(farmer == cows) {
      PI(k);
      return 0;
    }
  }
  PI(0);

  return 0;
}