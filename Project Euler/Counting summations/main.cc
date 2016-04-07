#include <iostream>

using namespace std;

long long dp[101][101];

// dp[i][j] = dp[i][j-1] + dp[i-j][j], j <= i

int main() {
  dp[0][0] = 1;
  for(int i = 1; i <= 100; i++) {
    for(int j = 1; j <= i; j++) {
      dp[i][j] = dp[i][j-1] + dp[i-j][min(j, i - j)];
    }
  }
  cout << dp[100][99] << endl;
}