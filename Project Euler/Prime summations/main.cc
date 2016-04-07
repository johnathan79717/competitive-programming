#include <vector>
#include <iostream>

using namespace std;

#define MAX_N 100

vector<int> primes;
int dp[MAX_N+1][MAX_N+1];

int ways(int n, int i) {
  if(dp[n][i] >= 0) return dp[n][i];
  int ans = 0;
  if(n == 0) ans = 1;
  else {
    for(int j = 0; j <= i; j++) {
      if(primes[j] > n) break;
      ans += ways(n - primes[j], j);
    }
  }
  return dp[n][i] = ans;
}

int ways(int n) {
  int i;
  for(i = 0; i < primes.size(); i++) {
    if(primes[i] > n) break;
  }
  return ways(n, i-1);
}

bool notprime[MAX_N+1];

int main() {
  for(int p = 2; p <= MAX_N; p++) {
    if(notprime[p]) continue;
    primes.push_back(p);
    for(int k = p+p; k <= MAX_N; k += p)
      notprime[k] = true;
  }
  memset(dp, -1, sizeof dp);
  for(int p = 2; p <= MAX_N; p++)
    if(ways(p) > 5000)
      cout << p << endl;
}