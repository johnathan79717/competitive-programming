#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 505
int N, M;
bool g[MAX_N][MAX_N];
int u[MAX_N][MAX_N][2], l[MAX_N][MAX_N][2], r[MAX_N][MAX_N], dp[MAX_N][MAX_N][2];

int solve() {
  memset(u, 0, sizeof(u));
  memset(l, 0, sizeof(l));
  memset(r, 0, sizeof(r));
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;
  for(int j = 1; j < M; j++)
    if(g[0][j] && dp[0][j-1][0])
      dp[0][j][0] = dp[0][j-1][0] + 1;

  for(int i = 1; i < N; i++) {
    for(int j = 0; j < M; j++)
      for(int k = 0; k < 2; k++)
        if(g[i][j] && dp[i-1][j][k])
          u[i][j][k] = dp[i-1][j][k] + 1;
    for(int j = 1; j < M; j++)
      for(int k = 0; k < 2; k++)
        if(g[i][j] && (l[i][j-1][k] || u[i][j-1][k]))
          l[i][j][k] = 1 + max(l[i][j-1][k], u[i][j-1][k]);
    for(int j = M-2; j >= 0; j--)
      if(g[i][j] && (r[i][j+1] || u[i][j+1][0]))
        r[i][j] = 1 + max(r[i][j+1], u[i][j+1][0]);
    for(int j = 0; j < M; j++) {
      dp[i][j][0] = max(u[i][j][0], l[i][j][0]);
      dp[i][j][1] = max(r[i][j], max(u[i][j][1], l[i][j][1]));
    }
  }

  int ans = 0;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      for(int k = 0; k < 2; k++)
        ans = max(ans, dp[i][j][k]);
  return ans;

  // for(int i = 0; i < N; i++) {
  //   for(int j = 0; j < M; j++)
  //     printf("%3d", u[i][j]);
  //   puts("");
  // }
  //   puts("");

  // for(int i = 0; i < N; i++) {
  //   for(int j = 0; j < M; j++)
  //     printf("%3d", l[i][j]);
  //   puts("");
  // }
  //   puts("");

  // for(int i = 0; i < N; i++) {
  //   for(int j = 0; j < M; j++)
  //     printf("%3d", r[i][j]);
  //   puts("");
  // }
    // puts("");


  // for(int i = 0; i < N; i++) {
  //   for(int j = 0; j < M; j++)
  //     printf("%3d", dp[i][j][0]);
  //   puts("");
  // }
  //   puts("");

  // for(int i = 0; i < N; i++) {
  //   for(int j = 0; j < M; j++)
  //     printf("%3d", dp[i][j][1]);
  //   puts("");
  // }
}

int main() {
  int T, cas = 1;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++) {
      char s[505];
      scanf("%s", s);
      for(int j = 0; j < M; j++)
        g[i][j] = s[j] == '.';
    }
    int ans = solve();
    for(int i = 0; i < MAX_N; i++)
      for(int j = 0; j < i; j++)
        swap(g[i][j], g[j][i]);
    swap(N, M);
    printf("Case #%d: %d\n", cas++, max(ans, solve()));
  }
}