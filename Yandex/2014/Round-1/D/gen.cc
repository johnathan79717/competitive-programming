#include <random>
#include <iostream>
using namespace std;

int main() {
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(1,10000);
  puts("10000");
  for(int i = 0; i < 10000; i++) {
    printf("%d%c", distribution(generator), i == 9999 ? '\n' : ' ');
  }
}