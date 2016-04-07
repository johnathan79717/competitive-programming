#include <iostream>

using namespace std;

int divisors(int n) {
  if(n == 1)
    return 1;
  for(int p = 2; p * p <= n; ++p)
    if(n % p == 0) {
      int pow = 0;
      do {
        n /= p;
        ++pow;
      } while(n % p == 0);
      return divisors(n) * (pow + 1);
    }

  return 2;
}

int main() {
  int n = 1;
  while(true) {
    if(divisors(n) * divisors(2*n-1) >= 500) {
      cout << n*(2*n-1) << endl;
      break;
    }
    if(divisors(n) * divisors(2*n+1) >= 500) {
      cout << n*(2*n+1) << endl;
      break;
    }
    ++n;
  }
}