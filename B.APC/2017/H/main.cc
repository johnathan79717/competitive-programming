#include <cstdio>
#include <algorithm>

bool l1[1000005], l2[1000005];
int dp[1000005][3];

using namespace std;

int main() {
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int d;
        scanf("%d", &d);
        l1[d] = true;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int d;
        scanf("%d", &d);
        l2[d] = true;
    }
    for (int i = 0; i < 1000005; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = -1000000000;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < 1000000; i++) {
        dp[i+1][0] = dp[i][0];
        dp[i+1][1] = dp[i][1];
        dp[i+1][2] = dp[i][2];
        if (l1[i] && l2[i]) {
            dp[i+1][0] = max(dp[i][0], max(dp[i][1], dp[i][2])) + 1;
        }
        if (l1[i] && !l2[i]) {
            dp[i+1][1] = max(dp[i+1][1], max(dp[i][0], dp[i][2]) + 1);
        }
        if (!l1[i] && l2[i]) {
            dp[i+1][2] = max(dp[i+1][2], max(dp[i][0], dp[i][1]) + 1);
        }
    }
    printf("%d\n", max(dp[1000000][0], max(dp[1000000][1], dp[1000000][2])));
}
