#include <cstdio>
#include <cstring>
int dp[41][41][41];

void solve() {
  int N, P;
  scanf("%d%d", &N, &P);
  char SA[64001], SB[64001];
  scanf("%s%s", SA, SB);
  memset(dp, 0, sizeof(dp));
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      for(int k = 0; k < N; k++) {
        dp[i+1][j+1][k+1] = dp[i+1][j+1][k] + dp[i+1][j][k+1] + dp[i][j+1][k+1]
          - dp[i+1][j][k] - dp[i][j+1][k] - dp[i][j][k+1] + dp[i][j][k];
        if(SA[i*N*N + j*N + k] == SB[i*N*N + j*N + k])
          ++dp[i+1][j+1][k+1];
      }

  for(int S = N; S >= 1; S--) {
    int ans = 0;
    for(int i = S; i <= N; i++)
      for(int j = S; j <= N; j++)
        for(int k = S; k <= N; k++) {
          int eq = dp[i][j][k] - dp[i-S][j][k] - dp[i][j-S][k] - dp[i][j][k-S]
            + dp[i-S][j-S][k] + dp[i-S][j][k-S] + dp[i][j-S][k-S] - dp[i-S][j-S][k-S];
          if(eq * 100 >= P * S * S * S)
            ans++;
        }
    if(ans) {
      printf("%d %d\n", S, ans);
      return;
    }
  }
  puts("-1");
}
int main() {
  int T;
  scanf("%d", &T);
  while(T--)
    solve();
}