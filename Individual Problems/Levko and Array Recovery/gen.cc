#include <cstdio>
#include <cstdlib>
int main() {
  int n = 10000, m = 10000;
  printf("%d %d\n", n, m);
  for(int i = 0; i < m; i++) {
    if(random() % 2)
      printf("1 1 %d 10000\n", n);
    else
      printf("2 1 %d 50000000\n", n);
  }
}