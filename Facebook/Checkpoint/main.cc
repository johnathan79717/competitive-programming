#include <iostream>

using namespace std;

#define MAX_S 10000000
typedef long long ll;

int R, S;
int dp[MAX_S + 1];

int main() {
  for(int n = 1; n <= MAX_S; n++)
    dp[n] = n;
  for(int n = 1; n <= MAX_S; n++) {
    ll nCk = 1;
    for(int k = 0; k <= n / 2; k++) {
      if(nCk > MAX_S)
        break;
      else
        dp[nCk] = min(dp[nCk], n);
      nCk = nCk * (n-k) / (k+1);
    }
  }
  int cas = 1;
  cin >> R;
  while(R--) {
    cin >> S;
    int ans = INT_MAX;
    for(int d = 1; d * d <= S; d++) {
      if(S % d) continue;
      ans = min(ans, dp[d] + dp[S/d]);
    }
    cout << "Case #" << cas++ << ": " << ans << endl;
  }
}