#include <iostream>

using namespace std;

typedef long long ll;

bool check(ll n) {
  for(int i = 9; i >= 1; i--) {
    if(n % 10 != i)
      return false;
    n /= 100;
  }
  return true;
}

int main() {
  for(ll i = 7; i < 450000000; i+=10) {
    if(check(i * i))
      cout << i << ' ' << i * i << endl;
  }
  // cout << check(11223344556677889LL) << endl;
}