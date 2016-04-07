#include <random>
#include <iostream>
using namespace std;

int main() {
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(1,999999);
  puts("200000");
  for(int i = 0; i < 100000; i++) {
    printf("U %d 10 %d\n", distribution(generator), distribution(generator));
    printf("R %d %d\n", distribution(generator), distribution(generator));
  }
}