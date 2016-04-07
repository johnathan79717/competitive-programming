#include <cstdio>
#include <random>
int main() {
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(-1e9, 1e9);
  puts("3");
  for(int t = 0; t < 3; t++) {
    puts("100000 30");
    for(int n = 0; n < 100000; n++)
      // printf("%d\n", distribution(generator));
      puts("987654321");
    for(int q = 0; q < 30; q++)
      puts("100");
  }
}