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
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <valarray>
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
#define VV(x) vector<vector<x > >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000;

typedef long double LD;
const long double EPS = 1e-11;

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

template<class T, class F>
T search_root(T lb, T ub, F f) {
  T fl = f(lb), fu = f(ub);
  for(int i = 0; i < 100; i++) {
    T m = (lb + ub) / 2;
    if(fl * f(m) <= 0)
      ub = m;
    else
      lb = m;
  }
  return (lb + ub) / 2;
}

int main() {
  DRI(N);
  REP(nnn, N) {
    DRI(t);
    LD T = t;
    VV(LD) M(4, V(LD)(4));
    V(LD) y(4);
    REP(i, 4) {
      DRII(ct, cv);
      M[i][0] = 1;
      REP1(j, 1, 3)
        M[i][j] = M[i][j-1] * ct;
      y[i] = cv;
    }
    vector<LD> x = gauss_jordan(M, y);
    LD A = x[3], B = x[2], C = x[1], D = x[0];
    LD a = 3*A, b = 2*B, c = C, d = b*b-4*a*c;
    V(LD) roots = {0};
    auto f = [A, B, C, D](LD x) {
      return ((A*x+B)*x+C)*x+D;
    };
    if(d <= 0) {
      if(f(0) * f(T) <= 0)
        roots.PB(search_root(0.0l, T, f));
    } else {
      LD x1 = (-b+sqrt(d))/(2*a);
      LD x2 = (-b-sqrt(d))/(2*a);
      if(x1 > x2) swap(x1, x2);
      if(x1 < 0) x1 = 0;
      if(x2 < 0) x2 = 0;
      if(x1 > T) x1 = T;
      if(x2 > T) x2 = T;
      if(f(0) * f(x1) <= 0)
        roots.PB(search_root(0.0l, x1, f));
      if(f(x1) * f(x2) <= 0)
        roots.PB(search_root(x1, x2, f));
      if(f(x2) * f(T) <= 0)
        roots.PB(search_root(x2, T, f));
    }
    roots.PB(T);
    // FOR(r, roots) cout << r << endl;
    auto s = [A, B, C, D](LD x) {
      return (((A*x/4+B/3)*x+C/2)*x+D)*x;
    };
    LD ans = 0;
    REP(i, roots.size()-1)
      ans += abs(s(roots[i+1]) - s(roots[i]));
    printf("%Lf\n", ans);
  }
  return 0;
}
