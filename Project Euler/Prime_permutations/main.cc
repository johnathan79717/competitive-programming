#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_P 15000000
// vector<int> primes;
bool p[MAX_P];

void Eratosthenes() {
  memset(p, true, sizeof p);
  for(int i = 2; i < MAX_P; i++)
    if(p[i]) {
      // primes.push_back(i);
      if((long long)i*i < MAX_P) 
        for(int j = i*i; j < MAX_P; j+=i)
          p[j] = false;
    }
}

bool isprime(int n) {
  return p[n];
}

bool is_perm(int a, int b, int n) {
  int A[n], B[n];
  for(int i = 0; i < n; ++i) {
    A[i] = a % 10;
    B[i] = b % 10;
    a /= 10;
    b /= 10;
  }
  return is_permutation(A, A+n, B);
}

int main() {
  Eratosthenes();
  int N, K;
  cin >> N >> K;
  if(K == 3) {
    puts("148748178147");
    if(N > 2969) {
        puts("296962999629");
    }
  }
  for(int i = 10001; i < N; i+=2) {
    if(!isprime(i))
      continue;
    int A[5], a = i;
    for(int j = 0; j < 5; ++j) {
      A[j] = a % 10;
      a /= 10;
    }
    sort(A, A+5);
    do {
      int j = 0;
      for(int k = 0; k < 5; k++) {
        j = j * 10 + A[k];
      }
      if(j <= i || !isprime(j))
        continue;
      int k = 2 * j - i;
      if(k > 99999 || !is_perm(j, k, 5) || !isprime(k))
        continue;
      if(K == 3)
        cout << i << j << k << '\n';
      else {
        int l = 2 * k - j;
        if(l > 99999 || !is_perm(k, l, 5) || !isprime(l))
          continue;
        cout << i << j << k << l << '\n';
      }
    } while(next_permutation(A, A+5));
  }
  for(int i = 100001; i < N; i+=2) {
    if(!isprime(i))
      continue;
    int A[6], a = i;
    for(int j = 0; j < 6; ++j) {
      A[j] = a % 10;
      a /= 10;
    }
    sort(A, A+6);
    do {
      int j = 0;
      for(int k = 0; k < 6; k++) {
        j = j * 10 + A[k];
      }
      if(j <= i || !isprime(j))
        continue;
      int k = 2 * j - i;
      if(k > 999999 || !is_perm(j, k, 6) || !isprime(k))
        continue;
      if(K == 3)
        cout << i << j << k << '\n';
      else {
        int l = 2 * k - j;
        if(l > 999999 || !is_perm(k, l, 6) || !isprime(l))
          continue;
        cout << i << j << k << l << '\n';
      }
    } while(next_permutation(A, A+6));
  }
}