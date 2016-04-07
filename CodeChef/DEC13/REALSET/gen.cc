#include <cstdio>
#include <cstdlib>
int main() {
  printf("1\n30000\n");
  for(int i = 0; i < 30000; i++)
    printf("%d\n", rand() % 2001 - 1000);
}