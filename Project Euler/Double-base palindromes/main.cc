#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
  int N, a, b;
  cin >> N >> a >> b;
  auto is_palindrome = [](int *a, int l) {
    for(int i = 0; i < l; i++) {
      if(a[i] != a[l-1-i])
        return false;
    }
    return true;
  };
  long long ans = 0;
  auto itoa = [](int n, int *a, int b) {
    int i = 0;
    while(n) {
      a[i++] = n % b;
      n /= b;
    }
    return i;
  };
  for(int i = 0; i < N; i++) {
    int ans1[100], ans2[100];
    int l1 = itoa(i, ans1, a);
    int l2 = itoa(i, ans2, b);
    // int l1 = strlen(ans1), l2 = strlen(ans2);
    if(is_palindrome(ans1, l1) && is_palindrome(ans2, l2)) {
      ans += i;
      // cout << i << endl;
    }
  }
  cout << ans << endl;
}