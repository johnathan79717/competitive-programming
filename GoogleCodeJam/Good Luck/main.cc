#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  cout << "Case #1:" << endl;
  int R, N, M, K;
  cin >> R >> N >> M >> K;
  for(int r = 0; r < R; ++r) {
    int p[12];
    for(int k = 0; k < K; ++k)
      cin >> p[k];
    int f[6];
    memset(f, 0, sizeof(f));
    for(int k = 0; k < K; ++k) {
      if(p[k] == 125) {
        f[5] = 3;
        break;
      }
      if(p[k] == 27) {
        f[3] = 3;
        break;
      }
      if(p[k] == 64) {
        f[4] = 3;
        break;
      }
      if(p[k] == 24) {
        f[2] = f[3] = f[4] = 1;
        break;
      }
      if(p[k] == 40) {
        f[2] = f[4] = f[5] = 1;
        break;
      }
      if(p[k] == 60) {
        f[3] = f[4] = f[5] = 1;
        break;
      }
      if(p[k] == 36) {
        f[3] = 2;
        f[4] = 1;
        break;
      }
      if(p[k] == 100) {
        f[5] = 2;
        f[4] = 1;
        break;
      }
      if(p[k] == 48) {
        f[4] = 2;
        f[3] = 1;
        break;
      }
      if(p[k] == 80) {
        f[4] = 2;
        f[5] = 1;
      }
      if(p[k] % 25 == 0)
        f[5] = 2;
      if(p[k] % 32 == 0)
        f[4] = 2;
      if(p[k] % 9 == 0)
        f[3] = 2;
      if(f[2] == 0 && p[k] % 2 == 0 && p[k] % 4 != 0)
        f[2] = 1;
      if(f[5] == 0 && p[k] % 5 == 0)
        f[5] = 1;
      if(f[3] == 0 && p[k] % 3 == 0)
        f[3] = 1;
    }
    int count = 0;
    for(int i = 2; i <= 5; ++i) {
      count += f[i];
      for(int j = 0; j < f[i]; ++j)
        cout << i;
    }
    while(count < N) {
      cout << '4';
      ++count;
    }
    cout << endl;
  }
}