#include <cstdio>

typedef long long ll;

ll N, K, C;

bool check(ll fail) {
  // ll M = K / (N - fail);
  // ll P = M * (N - fail) + fail * (M - 1);
  // return P >= C;
  return K / (N - fail) * N >= C;
}

int solve() {
  scanf("%lld%lld%lld", &N, &K, &C);
  ll fail = 0;
  while(!check(fail)) fail++;
  return C + fail;
}

int main() {
  int T, cas = 1;
  scanf("%d", &T);
  while(T--) {
    printf("Case #%d: %d\n", cas++, solve());
  }
}