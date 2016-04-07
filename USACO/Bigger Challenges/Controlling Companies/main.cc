/*
ID: johnath2
PROG: concom
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
#define NAME "concom"
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
typedef long long LL;
typedef unsigned long long ULL;

int own[100][100];
bool ctrl[100][100];

void control(int i, int j) {
  if(ctrl[i][j]) return;
  ctrl[i][j] = true;
  REP(k, 100) {
    if(k == i || k == j) continue;
    own[i][k] += own[j][k];
    if(own[i][k] > 50)
      control(i, k);
  }
}

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  DRI(n);
  while(n--) {
    DRIII(i,j,p);
    own[i-1][j-1] = p;
  }
  REP(i, 100) {
    REP(j, 100) {
      if(own[i][j] > 50)
        control(i, j);
    }
  }
  REP(i, 100) {
    REP(j, 100) {
      if(ctrl[i][j] && i != j) PIS(i+1), PI(j+1);
    }
  }

  return 0;
}