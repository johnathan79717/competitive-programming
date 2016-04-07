#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int cycle(int S) {
  int m = 0, d = 1, a = sqrt(S), a0 = a;
  if(a * a == S) return 0;
  int ans = 0;
  // cout << "S: " << S << endl;
  // int k = 0;
  while(a != 2*a0) {
    m = d * a - m;
    d = (S - m * m) / d;
    a = (a0 + m) / d;
    ans++;
    // if(k++ == 5) break;
  }
  return ans;
}

int main() {
  int n;
  int ans = 0;
  for(int n = 1; n <= 10000; n++) {
    ans += (cycle(n) % 2);
    // cout << n << ' ' << cycle(n) << endl;
  }
  cout << ans << endl;
}