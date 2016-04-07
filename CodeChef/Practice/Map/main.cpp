#include <cstdio>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cassert>

using namespace std;

#define REP(i,a,b) for(i=a;i<b;++i)
#define rep(i,n) REP(i,0,n)

int distance(int x1, int y1, int x2, int y2) {
  return (x1-x2)*(x1-x2) + (y1-y2) * (y1-y2);
}

int X[1000], Y[1000], i, j;
double solve5(int N) {
  int m = 0;
  rep(i, N) REP(j, 0, i)
    m = max(distance(X[i], Y[i], X[j], Y[j]), m);
  return sqrt(m);
}

int det(int a, int b, int c, int d) {
  return a*d-b*c;
}

bool between(double x, int x1, int x2) {
  if( x >= x1 && x <= x2 ) return true;
  if( x <= x1 && x >= x2 ) return true;
  return false;
}

double solve4() {
  int m = 0;
  int i1, j1;
  rep(i1, 4) REP(j1, 0, i1) {
    int d = distance(X[i1], Y[i1], X[j1], Y[j1]);
    if(d > m) {
      int B1 = X[i1] - X[j1], A1 = Y[j1] - Y[i1];
      int C1 = A1*X[i1] + B1*Y[i1];
      // printf("%d %d %d %d\n", X[i1], Y[i1], X[j1], Y[j1]);
      // printf("%d %d %d\n", A1, B1, C1);
      assert(A1*X[j1]+B1*Y[j1] == C1);
      int i2 = 0;     while(i2 == i1 || i2 == j1) ++i2;
      int j2 = i2+1;  while(j2 == i1 || j2 == j1) ++j2;
      int B2 = X[i2] - X[j2], A2 = Y[j2] - Y[i2];
      int C2 = A2*X[i2] + B2*Y[i2];
      // printf("%d %d %d %d\n", X[i2], Y[i2], X[j2], Y[j2]);
      // printf("%d %d %d\n", A2, B2, C2);
      assert(A2*X[j2]+B2*Y[j2] == C2);
      int dd = det(A1, B1, A2, B2);
      if(dd == 0) m = d;
      else {
        double x = det(C1, B1, C2, B2) / (double)dd;
        double y = det(A1, C1, A2, C2) / (double)dd;
        // printf("%f %f\n", x, y);
        if(between(x, X[i1], X[j1]) && between(y, Y[i1], Y[j1]) && between(x, X[i2], X[j2]) && between(y, Y[i2], Y[j2]))
          continue;
        m = d;
      }
    }
  }
  return sqrt(m);
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int N;
    scanf("%d", &N);
    rep(i, N) scanf("%d%d", X+i, Y+i);

    if(N >= 5) {
      printf("%.10f\n", solve5(N));
    } else { 
      // N = 4
      printf("%.10f\n", solve4());
    }
  }
}