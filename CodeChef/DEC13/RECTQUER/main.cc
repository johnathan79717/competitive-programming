#include <cstdio>
#define MAX_N 300
int dp[MAX_N + 1][MAX_N + 1][10];

int main() {
  int N;
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      for(int k = 0; k < 10; k++)
        dp[i][j][k] = dp[i-1][j][k] + dp[i][j-1][k] - dp[i-1][j-1][k];
      int A;
      scanf("%d", &A);
      dp[i][j][A-1]++;
    }
  }
  // for(int k = 0; k < 10; k++)
  //   for(int i = 0; i <= N; i++) {
  //     for(int j = 0; j <= N; j++)
  //       printf("%d", dp[i][j][k]);
  //     puts("");
  //   }
  int Q;
  scanf("%d", &Q);
  while(Q--) {
    int X1, Y1, X2, Y2;
    scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
    int ans = 0;
    for(int k = 0; k < 10; k++)
      if(dp[X2][Y2][k] + dp[X1-1][Y1-1][k] - dp[X1-1][Y2][k] - dp[X2][Y1-1][k])
        ans++;
    printf("%d\n", ans);
  }
}