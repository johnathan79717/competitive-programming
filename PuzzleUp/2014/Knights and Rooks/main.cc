#include <iostream>
using namespace std;
int main() {
  const int N = 3;
  auto rook = [](int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) * abs(y1 - y2) == 2;
  };
  int cnt = 0;
  for (int b = 0; b < (1ll<<(8*N)); b++) {
    int c = b;
    auto get = [&c]() {
      int ret = c & ((1<<N) - 1);
      c >>= N;
      return ret;
    };
    int r1x = get(), r1y = get(), r2x = get(), r2y = get();
    int n1x = get(), n1y = get(), n2x = get(), n2y = get();
    if (r1x > r2x) continue;
    if (n1x > n2x || (n1x == n2x && n1y >= n2y)) continue;
    if (r1x == r2x || r1x == n1x || r1x == n2x || r2x == n1x || r2x == n2x) continue;
    if (r1y == r2y || r1y == n1y || r1y == n2y || r2y == n1y || r2y == n2y) continue;
    if (rook(n1x, n1y, n2x, n2y) ||
        rook(n1x, n1y, r1x, r1y) ||
        rook(n1x, n1y, r2x, r2y) ||
        rook(n2x, n2y, r1x, r1y) ||
        rook(n2x, n2y, r2x, r2y)) continue;
    cnt++;
  }
  cout << cnt << endl;
}