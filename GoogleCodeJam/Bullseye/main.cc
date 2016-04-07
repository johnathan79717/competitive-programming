#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int T;
  cin >> T;
  for(int tt = 1; tt <= T; ++tt) {
    double r, t;
    cin >> r >> t;
    double bound = (sqrt((2*r-1) * (2*r-1) + 4 * t) - (2*r-1)) / 2;
    cout << (long long)bound << endl;
  }
}