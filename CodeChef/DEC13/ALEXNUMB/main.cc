#include <cstdio>

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", (long long)(n-1) * n / 2);
    while(n--) {
      int a;
      scanf("%d", &a);
    }
  }
}