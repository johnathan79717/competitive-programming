#include <cstdio>

#define p 1000000007

typedef long long ll;

ll pow2(int n) {
  if(n == 0)
    return 1;
  ll x = pow2(n / 2);
  if(n % 2)
    return x * x * 2 % p;
  else
    return x * x % p;
}

ll solve() {
  int N;
  scanf("%d", &N);
  return (pow2(N) + p - 1) % p;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    printf("%lld\n", solve());
  }
}