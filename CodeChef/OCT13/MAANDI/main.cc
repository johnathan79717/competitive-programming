#include <iostream>

using namespace std;

bool overlucky(int n) {
  if(n == 0)
    return false;
  if(n % 10 == 4 || n % 10 == 7)
    return true;
  else
    return overlucky(n / 10);
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    int n, ans = 0;
    cin >> n;
    for(int k = 1; k * k <= n; k++) {
      if(n % k == 0) {
        if(overlucky(k))
          ans++;
        if(n / k != k && overlucky(n / k))
          ans++;
      }
    }
    cout << ans << endl;
  }
}