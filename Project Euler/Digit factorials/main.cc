#include <iostream>

using namespace std;

int factorial(int n) {
  switch(n) {
    case 9: return 362880;
    case 8: return 40320;
    case 7: return 5040;
    case 6: return 720;
    case 5: return 120;
    case 4: return 24;
    case 3: return 6;
    case 2: return 2;
    default: return 1;
  }
}

int digitFactSum(int n) {
  int ans = 0;
  while(n) {
    ans += factorial(n % 10);
    n /= 10;
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  int ans = 0;
  for(int i = 10; i < N; i++) {
    // cout << digitFactSum(i) << endl;
    if(digitFactSum(i) % i == 0) {
      ans += i;
    }
  }
  cout << ans << endl;
}