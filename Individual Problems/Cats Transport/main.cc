#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, m, p;
  cin >> n >> m >> p;
  int d[100001];
  d[1] = 0;
  for(int i = 2; i <= n; ++i) {
    int temp;
    cin >> temp;
    d[i] = d[i-1] + temp;
  }
  int c[100001];
  for(int i = 0; i < m; ++i) {
    int h, t;
    cin >> h >> t;
    c[i] = t - d[h];
  }
  sort(c, c + m);
}