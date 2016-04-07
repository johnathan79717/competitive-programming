#include <cstdio>

int solve(int p) {
  int ans = 0;
  for(int i = 0; i < 11; ++i) {
    ans += p % 2;
    p /= 2;
  }
  return ans + p;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int p;
    scanf("%d", &p);
    printf("%d\n", solve(p));
  }
}