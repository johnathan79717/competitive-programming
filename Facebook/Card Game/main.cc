#include <cstdio>
#include <algorithm>
typedef long long ll;
#define MAX_N 10005
const ll m = 1000000007;
ll fact[MAX_N];

ll extgcd(ll a, ll b, ll &x, ll &y) {
  ll d = a;
  if(b) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}

ll mod_inverse(ll a) {
  ll x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}

ll comb(int n, int k) {
  if(n < k)
    return 0;
  return fact[n] * mod_inverse(fact[k] * fact[n-k]) % m;
}

int N, K;
ll a[MAX_N];
ll solve() {
  ll ans = 0;
  std::sort(a, a + N);
  for(int i = K-1; i < N; i++) {
    // printf("%lld %lld\n", fact[i], fact[i-K+1]);
    ans = (ans + a[i] * comb(i, K-1)) % m;
  }
  return ans;
}

int main() {
  fact[0] = 1;
  for(int i = 1; i < MAX_N; i++)
    fact[i] = fact[i-1] * i % m;

  int T, cas = 1;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &N, &K);
    for(int i = 0; i < N; i++)
      scanf("%lld", a + i);
    printf("Case #%d: %lld\n", cas++, solve());
  }
}