#include <cstdio>

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    double p;
    scanf("%lf", &p);
    if(p < 0.5) p = 1-p;
    printf("%lf\n", 10000 + 20000 * (1-p) * (p-0.5));
  }
}