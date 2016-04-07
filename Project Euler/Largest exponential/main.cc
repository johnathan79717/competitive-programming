#include <cstdio>
#include <cmath>

int main() {
  double max = 0;
  for(int line = 1; line <= 1000; line++) {
    int b, e;
    scanf("%d,%d", &b, &e);
    if(log(b) * e > max) {
      max = log(b) * e;
      printf("%d\n", line);
    }
  }
}