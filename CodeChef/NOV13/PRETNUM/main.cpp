#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

bool isprime[1000000];

void sieve() {
  memset(isprime, true, sizeof(isprime));
  isprime[0] = isprime[1] = false;
  for(int p = 2; p < 1000000; p++)
    if(isprime[p])
      for(int i = 2*p; i < 1000000; i+=p)
        isprime[i] = false;
}

int main() {
  sieve();

  vector<int> primes;
  vector<ll> v;

  for(int p = 0; p < 1000000; p++)
    if(isprime[p])
      primes.push_back(p);

  for(int i = 0; i < primes.size(); i++) {
    int &p = primes[i];
    ll x = ll(p) * p;
    for(int j = 2; x <= 1000000000000ll; j++) {
      if(isprime[j+1])
        v.push_back(x);
      x *= p;
    }
  }
  sort(v.begin(), v.end());
  // for(int i = 0; i < 10; i++)
  //   printf("%lld\n", v[i]);


  int T;
  scanf("%d", &T);
  while(T--) {
    ll L, R;
    scanf("%lld%lld", &L, &R);
    bool a[1000001];
    memset(a, true, sizeof(a));
    for(int j = 0; j < primes.size(); j++) {
      int &p = primes[j];
      ll i = max((L-1) - (L-1) % p + p, ll(2) * p);
      while(i <= R) {
        // printf("%lld\n", i);
        a[i-L] = false;
        i += p;
      }
    }
    int ans = upper_bound(v.begin(), v.end(), R) - lower_bound(v.begin(), v.end(), L);
    // printf("%d\n", ans);
    for(ll i = max(L, ll(2)); i <= R; i++)
      if(a[i-L])
        ans++;

    printf("%d\n", ans);
  }
}