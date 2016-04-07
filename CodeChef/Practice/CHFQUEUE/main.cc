#include <cstdio>

#define MAX_N 1000000
#define P 1000000007

int main() {
  int N, K;
  scanf("%d%d", &N, &K);

  int fear[MAX_N], A[MAX_N];
  for(int i = 0; i < N; i++)
    scanf("%d", A + i);
  fear[N-1] = -1;
  for(int i = N-2; i >= 0; i--) {
    int next = i + 1;
    while(next >= 0 && A[i] <= A[next])
      next = fear[next];

    fear[i] = next;
  }

  long long ans = 1;
  for(int i = 0; i < N; i++) {
    if(fear[i] >= 0)
      ans = ans * (fear[i] - i + 1) % P;
  }
  printf("%lld\n", ans);
}