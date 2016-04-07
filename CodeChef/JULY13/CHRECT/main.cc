#include <cstdio>

int solve() {
  int N, M, K;
  scanf("%d%d%d", &N, &M, &K);
  if(N * M <= 2)
    return 0;
  if(N == 1 || M == 1)
    return K;
  else
    return K / 2 + K % 2;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    printf("%d\n", solve());
  }
}