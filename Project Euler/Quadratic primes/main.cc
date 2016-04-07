#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

#define MAX_P 15000000
typedef long long LL;
vector<int> primes;
bool p[MAX_P];

void Eratosthenes() {
  memset(p, true, sizeof p);
  for(int i = 2; i < MAX_P; i++)
    if(p[i]) {
      primes.push_back(i);
      if((LL)i*i < MAX_P) 
        for(int j = i*i; j < MAX_P; j+=i)
          p[j] = false;
    }
}

bool isprime(LL n) {
  if(n < 2) return false;
  if(n < MAX_P) return p[n];
  int nn = sqrt(n);
  for(int p: primes) {
    if(p > nn)
      return true;
    if(n % p == 0)
      return false;
  }
  return true;
}



int main() {
    Eratosthenes();
    int N;
    cin >> N;
  int max = 0;
  long long best_a;
  long long best_b;
  for(int a = -N+1; a < N; ++a) {
    for(int b = -N+1; b < N; ++b) {
      int n = 0;
      long long y = b;
      while(isprime(y)) {
        y += (2*n+1+a);
        ++n;
      }
      if(n > max) {
        max = n;
        best_b = b;
        best_a = a;
      }
    }
  }
  cout << max << endl;
  // cout << best_a * best_b << endl;
  cout << best_a << ' ' << best_b << endl;
}