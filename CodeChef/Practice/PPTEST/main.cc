#include <iostream>
#include <cstring>
using namespace std;

int main() {
  int T;
  cin >> T;
  while(T--) {
    int N, W;
    cin >> N >> W;
    int C[101], P[101], T[101];
    for(int i = 1; i <= N; i++)
      cin >> C[i] >> P[i] >> T[i];
    int dp[101][101];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= N; i++) {
      for(int t = 0; t < T[i]; t++)
        dp[i][t] = dp[i-1][t];
      for(int t = T[i]; t <= W; t++)
        dp[i][t] = max(dp[i-1][t], dp[i-1][t-T[i]] + C[i] * P[i]);
    }
    cout << dp[N][W] << endl;
  }
}