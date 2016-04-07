#include <iostream>
#include <string>

using namespace std;

string p[201][201];

void jump(int i, int j, int x, int y, char c) {
  if(i + x < 0 || i + x > 200 || j + y < 0 || j + y > 200) return;
  p[i+x][j+y] = p[i][j] + c;
  // cout << i + x - 100 << ' ' << j + y - 100 << ' ' << p[i+x][j+y] << endl;
}

int main() {
  int T;
  cin >> T;
  p[100][101] = string("N");
  p[100][99] = string("S");
  p[99][100] = string("W");
  p[101][100] = string("E");
  for(int n = 2; n <= 500; ++n) {
    for(int i = 0; i < 201; ++i) {
      for(int j = 0; j < 201; ++j) {
        if(p[i][j].size() == n-1) {
          jump(i, j, n, 0, 'E');
          jump(i, j, -n, 0, 'W');
          jump(i, j, 0, n, 'N');
          jump(i, j, 0, -n, 'S');
        }
      }
    }
  }
  for(int t = 1; t <= T; ++t) {
    int x, y;
    cin >> x >> y;
    cout << "Case #" << t << ": " << p[100+x][100+y] << endl;
  }
}