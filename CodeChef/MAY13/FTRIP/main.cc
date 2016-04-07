#include <cmath>
#include <iostream>
using namespace std;

double log_factorial[1001];

double log_choose(int n, int k) {
  return log_factorial[n] - log_factorial[k] - log_factorial[n-k];
}

double solve() {
  int S, N, M, K;
  cin >> S >> N >> M >> K;
  double ans = 0;
  for(int k = K; k < min(M, N); ++k) {
    if(S - M < N - 1 - k) continue;
    ans += exp(log_choose(M-1, k) + log_choose(S-M, N-1-k) - log_choose(S-1, N-1));
  }
  return ans;
}

int main() {
  log_factorial[0] = 0;
  for(int i = 1; i <= 1000; ++i)
    log_factorial[i] = log_factorial[i-1] + log(i);
  int T;
  cin >> T;
  while(T--) {
    cout << solve() << endl;
  }
}