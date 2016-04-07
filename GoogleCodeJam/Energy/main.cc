#include <iostream>

using namespace std;

int E, R, N;
int v[10000];

int solve(int e, int n) {
  if(n == N-1)
    return e * v[n];
  int ans = 0;
  for(int i = 0; i <= e; ++i)
    ans = max(ans, i * v[n] + solve(min(e - i + R, E), n + 1));
  return ans;
}

int main() {
  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t) {
    cin >> E >> R >> N;
    for(int i = 0; i < N; ++i)
      cin >> v[i];
    cout << "Case #" << t << ": " << solve(E, 0) << endl;
  }
}