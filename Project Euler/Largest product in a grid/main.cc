#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a[20][20];
  for(int i = 0; i < 20; ++i) {
    for(int j = 0; j < 20; ++j) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  for(int i = 0; i < 20; ++i) {
    for(int j = 0; j < 20; ++j) {
      if(j + 3 < 20)
        ans = max(ans, a[i][j] * a[i][j+1] * a[i][j+2] * a[i][j+3]);
      if(i + 3 < 20)
        ans = max(ans, a[i][j] * a[i+1][j] * a[i+2][j] * a[i+3][j]);
      if(i + 3 < 20 && j + 3 < 20) {
        ans = max(ans, a[i][j] * a[i+1][j+1] * a[i+2][j+2] * a[i+3][j+3]);
        ans = max(ans, a[i+3][j] * a[i+2][j+1] * a[i+1][j+2] * a[i][j+3]);
      }
    }
  }
  cout << ans << endl;
}