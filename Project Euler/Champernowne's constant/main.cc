#include <iostream>
#include <cmath>
using namespace std;

int f(long long n) {
  int i = 1;
  n--;
  while(n >= i * (pow(10ll, i) - pow(10ll, i-1))) {
    n -= i * (pow(10ll, i) - pow(10ll, i-1));
    i++;
  }
  long long num = n / i + pow(10ll, i-1);
  char str[20];
  sprintf(str, "%lld", num);
  return str[n % i] - '0';
}

int main() {
  int N;
  cin >> N;
  cout << f(N) << endl;
}