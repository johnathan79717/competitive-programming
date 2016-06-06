#include <iostream>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  if(n * (n-1) / 2 > k) {
    for(int i = 0; i < n; ++i) {
      cout << 0 << ' ' << i << endl;
    }
  }
  else {
    cout << "no solution" << endl;
  }
}