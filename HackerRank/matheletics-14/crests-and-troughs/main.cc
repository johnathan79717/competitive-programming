#include <iostream>

using std::cout;
using std::endl;

int inc[499999][10], dec[499999][10];

#define MOD 100003
inline int add(int a, int b, int mod=MOD) { return a + b < mod ? a + b : a + b - mod; }
inline void addBy(int &a, int b, int mod=MOD) { a = add(a, b, mod); }
inline int sub(int a, int b, int mod=MOD) { return a - b < 0 ? a - b + mod : a - b; }
inline void subBy(int &a, int b, int mod=MOD) { a = sub(a, b, mod); }

int main(int argc, char **argv) {
  int n = atoi(argv[1]);
  for(int i = 1; i <= 9; i++)
    inc[0][i] = dec[0][i] = 1;
  int ans = 9;
  for(int i = 1; i < n; i++) {
    inc[i][1] = dec[i-1][0];
    for(int j = 2; j <= 9; j++)
      inc[i][j] = add(inc[i][j-1], dec[i-1][j-1]);
    dec[i][8] = inc[i-1][9];
    for(int j = 7; j >= 0; j--)
      dec[i][j] = add(dec[i][j+1], inc[i-1][j+1]);
    for(int j = 0; j <= 9; j++)
      addBy(ans, add(dec[i][j], inc[i][j]));
  }
  cout << ans << endl;
}