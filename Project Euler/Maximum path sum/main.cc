#include <iostream>

using namespace std;

#define ROWS 100

int a[ROWS][ROWS];

int main() {
  for(int i = 0; i < ROWS; ++i)
    for(int j = 0; j <= i; ++j)
      cin >> a[i][j];
  for(int i = ROWS - 2; i >= 0; --i) {
    for(int j = 0; j <= i; ++j) {
      a[i][j] += max(a[i+1][j], a[i+1][j+1]);
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
  cout << a[0][0] << endl;
}