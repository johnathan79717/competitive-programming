#include <iostream>

using namespace std;

bool special(int n) {
  while(n) {
    if(n % 10 == 3 || n % 10 == 5 || n % 10 == 6)
      return true;
    else
      n /= 10;
  }
  return false;
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    int N, i, ans = 0;
    cin >> N;
    for(i = 1; i * i <= N; i++) {
      if(N % i == 0) {
        if(special(i))
          ans++;
        if(i * i < N && special(N / i))
          ans++;
      }
    }
    cout << ans << endl;
  }
}