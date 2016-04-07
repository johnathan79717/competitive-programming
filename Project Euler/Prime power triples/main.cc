#include <vector>
#include <iostream>

using namespace std;

bool isprime[7072];
bool f[50000001];

int main() {
  memset(isprime, true, sizeof isprime);
  vector<int> primes;
  for(int p = 2; p < 7072; p++) {
    if(isprime[p]) {
      for(int k = p+p; k < 7072; k += p)
        isprime[k] = false;
      primes.push_back(p);
    }
  }
  for(int i: primes) {
    int a = i*i*i*i;
    if(a > 5e7) break;
    for(int j: primes) {
      int b = j * j * j;
      if(a + b > 5e7) break;
      for(int k: primes) {
        int c = k * k;
        if(a + b + c > 5e7) break;
        f[a + b + c] = true;
      }
    }
  }
  int ans = 0;
  for(int i = 0; i <= 50000000; i++)
    if(f[i]) ans++;
  cout << ans << endl;
}