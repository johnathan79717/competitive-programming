#include <iostream>

using namespace std;

#define MAX_R 52
#define MAX_C 52

int R, C;
char t[MAX_R][MAX_C];

int main() {
  int N;
  cin >> N;
  while(N--) {
    cin >> R >> C;
    int ans = 0;
    for(int i = 0; i < R; i++)
      cin >> t[i];
    for(int i = 0; i < R; i++) {
      int sum = 0;
      for(int j = 0; j < C; j++)
        sum += t[i][j] - '0';
      int partial = 0;
      for(int j = 0; j < C; j++) {
        partial += t[i][j] - '0';
        if(partial * 2 >= sum) {
          ans = max(ans, C - 1 - j);
          break;
        }
      }
      partial = 0;
      for(int j = C - 1; j >= 0; j--) {
        partial += t[i][j] - '0';
        if(partial * 2 >= sum) {
          ans = max(ans, j);
          break;
        }
      }
    }
    for(int j = 0; j < C; j++) {
      int sum = 0;
      for(int i = 0; i < R; i++)
        sum += t[i][j] - '0';
      int partial = 0;
      for(int i = 0; i < R; i++) {
        partial += t[i][j] - '0';
        if(partial * 2 >= sum) {
          ans = max(ans, R - 1 - i);
          break;
        }
      }
      partial = 0;
      for(int i = R - 1; i >= 0; i--) {
        partial += t[i][j] - '0';
        if(partial * 2 >= sum) {
          ans = max(ans, i);
          break;
        }
      }
    }
    cout << ans << endl;
  }
}