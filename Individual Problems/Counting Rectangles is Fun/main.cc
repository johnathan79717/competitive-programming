#include <cstdio>
#include <cstring>
bool good[45][45][45][45];
bool grid[45][45];
int dp[45][45][45][45];

int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for(int i = 1; i <= n; i++) {
    char str[45];
    scanf("%s", str);
    for(int j = 1; j <= m; j++)
      if(str[j-1] == '0')
        grid[i][j] = true;
  }
  memset(good, true, sizeof(good));
  for(int a = 1; a <= n; a++)
    for(int b = 1; b <= m; b++)
      for(int c = a; c <= n; c++)
        for(int d = b; d <= m; d++)
          if((!grid[c][d]) || (!good[a][b][c-1][d]) || (!good[a][b][c][d-1]))
            good[a][b][c][d] = false;

  for(int w = 0; w < n; w++)
    for(int h = 0; h < m; h++) 
      for(int a = 1; a + w <= n; a++)
        for(int b = 1; b + h <= m; b++) {
          int c = a + w, d = b + h;
          dp[a][b][c][d] = dp[a+1][b][c][d] + dp[a][b+1][c][d] + dp[a][b][c-1][d] + dp[a][b][c][d-1]
                          - dp[a+1][b+1][c][d] - dp[a+1][b][c-1][d] - dp[a+1][b][c][d-1]
                          - dp[a][b+1][c-1][d] - dp[a][b+1][c][d-1] - dp[a][b][c-1][d-1]
          + dp[a+1][b+1][c-1][d] + dp[a+1][b+1][c][d-1] + dp[a+1][b][c-1][d-1] + dp[a][b+1][c-1][d-1]
          - dp[a+1][b+1][c-1][d-1];
          if(good[a][b][c][d])
            dp[a][b][c][d]++;
        }

  while(q--) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d\n", dp[a][b][c][d]);
  }
}