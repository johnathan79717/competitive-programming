/*
ID: johnath2
PROG: crosswords
LANG: C++11
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
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <stack>
#include <functional>
using namespace std;
#define NAME "crosswords"
#define FOR(i,c) for(auto &i: c)
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
#define PLL(x) printf("%lld\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
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



int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  DRII(N, M);
  char s[N][M+1];
  REP(i, N) {
    RS(s[i]);
  }
  V(PII) ans;
  REP(i, N) {
    REP(j, M) {
        if (s[i][j] == '.' && 
            (((i == 0 || s[i-1][j] == '#') && i+2 < N && s[i+1][j] == '.' && s[i+2][j] == '.') ||
            ((j == 0 || s[i][j-1] == '#') && j+2 < M && s[i][j+1] == '.' && s[i][j+2] == '.'))) {
            ans.EB(i+1, j+1);
        }
    }
  }
  PI(ans.size());
  FOR(a, ans) {
    PIS(a.F); PI(a.S);
  }
  return 0;
}