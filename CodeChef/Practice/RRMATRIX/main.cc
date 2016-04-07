#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if(a == 0)
    return b;
  else
    return gcd(b % a, a);
}

int solve() {
  int N, M;
  cin >> N >> M;
  return gcd(N - 1, M - 1) + 1;
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    cout << solve() << endl;
  }
}