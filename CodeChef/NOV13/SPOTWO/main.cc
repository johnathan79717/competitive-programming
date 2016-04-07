#include <cstdio>
#include <iostream>

#define p 1000000007

typedef unsigned long long ull;
using namespace std;

ull ten[20];

ull pow2(ull n) {
  if(n == 0)
    return 1;
  ull x = pow2(n / 2);
  if(n % 2)
    return x * x * 2 % p;
  else
    return x * x % p;
}

int main() {
  ten[0] = 1;
  for(int i = 1; i < 20; i++)
    ten[i] = ten[i-1] * 10;
  int T;
  scanf("%d", &T);
  while(T--) {
    int N;
    ull N_bin = 0;
    scanf("%d", &N);
    for(int i = 0; i < 20; i++)
      if(N & (1ull << i))
        N_bin += ten[i];

    // cout << N_bin + 1 << endl;
    ull x = pow2(N_bin);
    printf("%llu\n", x * x % p);
  }
}