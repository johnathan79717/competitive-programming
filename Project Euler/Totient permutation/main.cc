#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 10000000

vector<int> prime_divisors[MAX_N];
bool isprime[MAX_N];

int phi(int n) {
  for(int p : prime_divisors[n])
    n = n / p * (p-1);
  return n;
}

void getDigits(int n, vector<int> &digits) {
  while(n) {
    digits.push_back(n % 10);
    n /= 10;
  }
}

bool check(int n, int p) {
  vector<int> digits, digits_phi;
  getDigits(n, digits);
  getDigits(p, digits_phi);
  sort(digits.begin(), digits.end());
  sort(digits_phi.begin(), digits_phi.end());
  if(digits_phi.size() != digits.size())
    return false;
  for(int i = 0; i < digits.size(); i++)
    if(digits[i] != digits_phi[i])
      return false;
  return true;
}

int main() {
  memset(isprime, true, sizeof(isprime));
  isprime[0] = isprime[1] = false;
  for(int i = 2; i < MAX_N; i++) {
    if(isprime[i]) {
      prime_divisors[i].push_back(i);
      for(int j = i+i; j < MAX_N; j+=i) {
        isprime[j] = false;
        prime_divisors[j].push_back(i);
      }
    }
  }

  double min_ratio = 1e9;
  int ans = 0;
  for(int n = 2; n < MAX_N; n++) {
    int p = phi(n);
    if(double(n) / p < min_ratio && check(n, p)) {
      min_ratio = double(n) / p;
      ans = n;
    }
  }

  cout << ans << endl;
  cout << phi(ans) << endl;
}