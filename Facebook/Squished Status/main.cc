#include <iostream>
using namespace std;

#define MAX_L 1005
typedef long long ll;
int M;
string s;
const ll mod = 4207849484ll;
ll dp[MAX_L];

ll solve() {
  memset(dp, 0, sizeof(dp));
  dp[s.size()] = 1;
  for(int i = s.size() - 1; i >= 0; i--) {
    int num = 0;
    for(int j = i; j < s.size(); j++) {
      num = num * 10 + int(s[j] - '0');
      if(1 <= num && num <= M)
        dp[i] += dp[j+1];
      else
        break;
    }
    dp[i] %= mod;
  }
  return dp[0];
}

int main() {
  int N, cs = 1;
  cin >> N;
  while(N--) {
    cin >> M >> s;
    cout << "Case #" << cs++ << ": " << solve() << endl;
  }
}