#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

#define rep(i,n) for(i=0;i<n;++i)

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int N, M, A[100], B[100], C[100];
    scanf("%d%d", &N, &M);
    int i, j, k;
    int ans[10][10], d[10][10];
    rep(i, N) rep(j, N) ans[i][j] = 0, d[i][j] = 1000;
    rep(i, N) d[i][i] = 0, ans[i][i] = 1;
    for(i = 0; i < M; ++i) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      --a; --b;
      d[a][b] = c;
      d[b][a] = c;
      ans[a][b] = 1;
      ans[b][a] = 1;
    }

    rep(k, N) rep(i, N) rep(j, N) {
      if(i == k || j == k) continue;
      if(d[i][k] + d[k][j] < d[i][j]) {
        d[i][j] = d[i][k] + d[k][j];
        ans[i][j] = ans[i][k] * ans[k][j];
      } else if (d[i][j] == d[i][k] + d[k][j]) {
        ans[i][j] += ans[i][k] * ans[k][j];
      }
    }
    // printf("%d\n", d[0][N-1]);
    printf("%d\n", ans[0][N-1]);
  }
}