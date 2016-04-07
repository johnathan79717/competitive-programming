#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
#define MAX_N 100000
typedef long long ll;
int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int N, K;
    scanf("%d%d", &N, &K);
    ll A[MAX_N];
    for(int i = 0; i < N; i++)
      scanf("%lld", A + i);
    ll best = LLONG_MIN, tail = 0;
    ll front[MAX_N], back[MAX_N];
    for(int i = 0; i < N; i++) {
      best = max(best, tail + A[i]);
      front[i] = best;
      tail = max(0ll, tail + A[i]);
      // printf("%3lld", front[i]);
    }
    best = LLONG_MIN; tail = 0;
    for(int i = N-1; i >= 0; i--) {
      best = max(best, tail + A[i]);
      back[i] = best;
      tail = max(0ll, tail + A[i]);
      // printf("%3lld", back[i]);
    }
    ll ans = LLONG_MIN;
    for(int i = 0; i + K + 1 < N; i++)
      ans = max(ans, front[i] + back[i + K + 1]);
    printf("%lld\n", ans);
  }
}