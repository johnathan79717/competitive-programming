#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

bool perfect(ll n) {
  if(n == 0)
    return true;
  switch(n % 10) {
    case 0:
    case 1:
    case 4:
    case 9: return perfect(n / 10);
    default: return false;
  }
}

int main() {
  int T;
  scanf("%d", &T);
  vector<ll> v;
  for(ll i = 0; i <= 100000; i++)
    if(perfect(i * i))
      v.push_back(i * i);

  while(T--) {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    printf("%d\n", upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a));
  }
}