#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if(a == 0)
    return b;
  else
    return gcd(b%a, a);
}

int main() {
  int ans = 0;
  for(int i = 1; i < 4000; i++)
    for(int j = 1; 3*i + 2*j<=12000; j++)
      if(gcd(i, j) == 1)
        ans++;

  cout << ans << endl;
}