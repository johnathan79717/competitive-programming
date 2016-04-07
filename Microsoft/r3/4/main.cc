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

typedef long double LD;
const long double EPS = 1e-13;

template<class T>
vector<T> gauss_jordan(vector<vector<T> > const &M, vector<T> const &b) {
  int n = M.size();
  vector<vector<T> > B(n, vector<T>(n+1));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      B[i][j] = M[i][j];
    B[i][n] = b[i];
  }
  for(int i = 0; i < n; i++) {
    int pivot = i;
    for(int j = i; j < n; j++)
      if(abs(B[j][i]) > abs(B[pivot][i]))
        pivot = j;
    swap(B[i], B[pivot]);
    if(abs(B[i][i]) < EPS) return vector<T>();
    for(int j = i+1; j <= n; j++)
      B[i][j] /= B[i][i];
    for(int j = 0; j < n; j++)
      if(i != j)
        for(int k = i+1; k <= n; k++)
          B[j][k] -= B[j][i] * B[i][k];
  }
  vector<T> x(n);
  for(int i = 0; i < n; i++)
    x[i] = B[i][n];
  return x;
}

int main() {
  DRI(T);
  REP1(t, 1, T) {
    DRI(n);
    V(LL) x(n), y(n), z(n);
    REP(i, n) {
      RL(x[i]); RL(y[i]); RL(z[i]);
    }
    double A, B, C;
    double x1 = x[0], y1 = y[0], z1 = z[0], x2 = x[1], y2 = y[1], z2 = z[1];
    if(x1 * y2 != x2 * y1) {
      C = -1;
      A = double(z1*y2 - z2 * y1) / (x1 * y2 - x2 * y1);
      B = double(x1*z2 - x2 * z1) / (x1 * y2 - x2 * y1);
    } else if(x1 * z2 != x2 * z1) {
      B = -1;
      A = double(y1*z2 - y2 * z1) / (x1 * z2 - x2 * z1);
      C = double(x1*y2 - x2 * y1) / (x1 * z2 - x2 * z1);
    } else if(y1 * z2 != y2 * z1) {
      A = -1;
      B = double(x1*z2 - x2 * z1) / (y1 * z2 - y2 * z1);
      C = double(y1*x2 - y2 * x1) / (y1 * z2 - y2 * z1);
    } else if(x1 != 0) {
      B = C = -1;
      A = double(y1 + z1) / x1;
    } else if(x2 != 0) {
      B = C = -1;
      A = double(y2 + z2) / x2;
    } else if(y1 != 0) {
      A = C = -1;
      B = double(x1 + z1) / y1;
    } else if(y2 != 0) {
      A = C = -1;
      B = double(x2 + z2) / y2;
    } else if(z1 != 0) {
      A = B = -1;
      C = double(y1 + x1) / z1;
    } else if(z2 != 0) {
      A = B = -1;
      C = double(y2 + x2) / z2;
    } else {
      A = B = C = 1;
    }
    printf("Case %d: ", t);
    printf("%lf %lf %lf\n", A, B, C);
  }
  return 0;
}
