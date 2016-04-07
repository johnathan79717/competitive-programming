#include <iostream>

using namespace std;

int table[600];

int sq(int n) {
  if(n == 0)
    return 0;
  else
    return sq(n / 10) + (n % 10) * (n % 10);
}

bool f(int n) {
  if(n < 600 && table[n])
    return table[n] == 89;
  bool ans = f(sq(n));
  if(n < 600)
    table[n] = ans ? 89 : 1;
  return ans;
}

int main() {
  table[1] = 1;
  table[89] = 89;
  int ans = 0;
  for(int i = 2; i < 10000000; i++) {
    if(f(i))
      ans++;
  }
  cout << ans << endl;
}