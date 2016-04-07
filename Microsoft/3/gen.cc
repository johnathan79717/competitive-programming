#include <random>
#include <iostream>
using namespace std;

int main() {
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(10000,10000);
  puts("1");
  puts("100 100");
  for(int i = 0; i < 100; i++) for(int j = 0; j < 100; j++) {
    printf("%d%c", distribution(generator), j == 99 ? '\n' : ' ');
  }
}