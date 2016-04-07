#include <cstdio>
#include <cstdlib>

int main() {
  puts("200");
  for(int j = 0; j < 200; ++j) {
    for(int i = 0; i < 10000; ++i)
      printf("%d", rand() % 10);
    puts("");
  }
}
