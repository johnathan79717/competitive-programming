#include <iostream>

using namespace std;

int phi[1000001];

int main() {
  for(int i = 2; i <= 1000000; i++)
    phi[i] = i;

  long long ans = 0;
  for(int i = 2; i <= 1000000; i++) {
    if(phi[i] == i)
      for(int j = i; j <= 1000000; j += i)
        phi[j] = phi[j] / i * (i-1);
    ans += phi[i];
  }

  cout << ans << endl;
}