/*
ID: johnath2
PROG: cowtour
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
#define NAME "cowtour"
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
const double INF = 1e12;
inline int add(int a, int b) { return a + b < MOD ? a + b : a + b - MOD; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + MOD : a - b; }
inline int mul(int a, int b) { return (LL)a * b % MOD; }
#define MAX_QUEUE 10000000
template<class T>
struct Queue {
  T arr[MAX_QUEUE];
  int f, b;
  Queue() : f(0), b(0) {}
  void push(const T& val) { arr[b++] = val; }
  bool empty() { return f == b; }
  T& pop() { return arr[f++]; }
};

#define MAX_N 151
int N;
double X[MAX_N], Y[MAX_N];
bool adj[MAX_N][MAX_N];
int groupNum[MAX_N];
double dist[MAX_N][MAX_N];
double farthest[MAX_N];
vector<VI> group;

void dfs(int i, int g) {
  if(groupNum[i] < 0) {
    groupNum[i] = g;
    group[g].PB(i);
    REP(k, N) {
      if(adj[i][k])
        dfs(k, g);
    }
  }
}

double distance(double xi, double yi, double xj, double yj) {
  return sqrt((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj));
}

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  RI(N);
  REP(i, N)
    scanf("%lf%lf", &X[i], &Y[i]);
  REP(i, N) {
    char str[MAX_N+1];
    RS(str);
    REP(j, N)
      if(str[j] != '0')
        adj[i][j] = true;
  }
  int G = 0;
  MS1(groupNum);
  REP(i, N) {
    if(groupNum[i] < 0) {
      group.PB(VI());
      dfs(i, G++);
    }
  }
  REP(i, N) REP(j, N) {
    if(adj[i][j] || i == j)
      dist[i][j] = distance(X[i], Y[i], X[j], Y[j]);
    else
      dist[i][j] = INF;
  }

  REP(k, N) REP(i, N) REP(j, N) {
    if(groupNum[k] != groupNum[i] || groupNum[k] != groupNum[j])
      continue;
    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  }

  double diameter = 0;
  REP(i, N) {
    REP(j, N) {
      if(groupNum[i] == groupNum[j])
        farthest[i] = max(farthest[i], dist[i][j]);
    }
    diameter = max(diameter, farthest[i]);
  }

  double best = INF;
  REP(g1, G) REP(g2, g1) {
    FOR(i, group[g1]) FOR(j, group[g2]) {
      double d = distance(X[*i], Y[*i], X[*j], Y[*j]);
      best = min(best, farthest[*i] + farthest[*j] + d);
    }
  }

  printf("%lf\n", max(best, diameter));
  return 0;
}