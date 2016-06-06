#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int l, r, Ql, Qr;

int solve(int *w, int n, int sum) {
  if(n == 0)
    return 0;
  if(n == 1)
    return min(l, r) * w[0];
  int ans = min(r * sum + (n-1) * Qr, l * sum + (n-1) * Ql);
  return min(ans, l * w[0] + r * w[n-1] + solve(w+1, n-2, sum - w[0] - w[n-1]));
}

int main() {
  int n;
  cin >> n >> l >> r >> Ql >> Qr;
  int w[100000];
  int sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> w[i];
    sum += w[i];
  }
  cout << solve(w, n, sum) << endl;
}