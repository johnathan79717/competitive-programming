#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> key(N);
  int total = 1;
  for(int i = 0; i < N; i++) {
    cin >> key[i];
    total *= key[i].size();
  }
  int M;
  cin >> M;
  while(M--) {
    string password;
    cin >> password;
    int L = password.size();
    vector<vector<bool> > dp(L+1, vector<bool>(total));
    for(int s = 0; s < total; s++)
      dp[L][s] = true;
    vector<int> state(N);
    for(int i = L-1; i >= 0; i--) {
      for(int s = 0; s < total; s++) {
        int temp = s;
        for(int j = 0; j < N; j++) {
          state[j] = temp % key[j].size();
          temp /= key[j].size();
        }
        for(int j = 0; j < N; j++) {
          if(key[j][state[j]] == password[i]) {
            int old = state[j];
            state[j]++;
            if(state[j] == key[j].size())
              state[j] = 0;
            int news = 0;
            for(int k = N-1; k >= 0; k--)
              news = news * key[k].size() + state[k];
            dp[i][s] = dp[i][s] || dp[i+1][news];
            state[j] = old;
          }
        }
      }
    }
    int ans = 100000000;
    for(int s = 0; s < total; s++) {
      if(dp[0][s]) {
        int temp = s, cnt = 0;
        for(int j = 0; j < N; j++) {
          cnt += temp % key[j].size();
          temp /= key[j].size();
        }
        ans = min(ans, cnt);
      }
    }
    if(ans >= 100000000)
      cout << -1 << endl;
    else
      cout << ans + L << endl;
  }
}