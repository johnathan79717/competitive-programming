#include <cstdio>
#include <cstring>

int dp[31][1002];

void solve(int N, int M) {
    // printf("%d %d\n", N, M);
    for (int i = M; i >= 2; --i) {
        if (dp[N][i]) {
            printf("%d\n", M-i);
            return;
        }
    }
    puts("-1");
}

int main() {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int n = 1; n <= 30; ++n) {
        for (int i = 0; i <= n-1-i; ++i) {
            int j = n-1-i;
            for (int a = 0; a <= 1000; ++a) {
                for (int b = 0; n+1+a+b <= 1000; ++b) {
                    if (dp[i][a] && dp[j][b])
                        dp[n][n+1+a+b] = 1;
                }
            }
        }
    }
    // printf("%d%d%d%d\n", dp[3][7], dp[3][8], dp[3][9], dp[3][10]);
    int T;
    scanf("%d", &T);
    while(T--) {
        int N, M;
        scanf("%d%d", &N, &M);
        solve(N, M);
    }
}