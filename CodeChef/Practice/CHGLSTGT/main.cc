#include <iostream>
#include <cstring>
using namespace std;

bool p[5000][5000];
int dp[5000];

int main() {
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    char s[5001];
    cin >> s;
    memset(p, false, sizeof(p));
    for(int diff = 0; diff < N; diff++) {
      for(int i = 0; i + diff < N; i++) {
        if(diff == 0)
          p[0][i] = true;
        else if(diff == 1)
          p[1][i] = (s[i] == s[i+1]);
        else
          p[diff][i] = (p[diff-2][i+1] && s[i] == s[i+diff]);
      }
    }

    dp[0] = 1;
    for(int i = 1; i < N; i++) {
      if(p[i][0]) {
        dp[i] = 1;
        continue;
      }
      dp[i] = dp[i-1] + 1;
      for(int j = 1; j < i; j++) {
        if(p[i-j][j]) // if s[j..i] is palindrome
          dp[i] = min(dp[i], dp[j-1] + 1);
      }
    }

    cout << dp[N-1] << endl;
  }
}