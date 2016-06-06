#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, k, a[2000], dp[2000];

bool check(long long c) {
  // dp[i] = move element before i
  for(int i = 0; i < n; i++)
    dp[i] = i;
  for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++)
      if(abs(a[j] - a[i]) <= c * (j - i))
        dp[j] = min(dp[j], dp[i] + j - i - 1);
  for(int i = 0; i < n; i++)
    if(dp[i] + n - 1 - i <= k)
      return true;
  return false;
}

int main() {
  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  long long lb = -1, ub = 2e9;
  while(ub - lb > 1) {
    long long mid = (lb + ub) / 2;
    // cout << mid << endl;
    if(check(mid))
      ub = mid;
    else
      lb = mid;
  }
  cout << ub << endl;
}