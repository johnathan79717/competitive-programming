#include <random>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
  std::default_random_engine generator;
  std::uniform_int_distribution<int> dist1(1,1e9);
  std::uniform_int_distribution<long long> dist2(1,1e15);
  puts("100000");
  for(int i = 0; i < 100000; i++) {
    printf("%d%c", dist1(generator), i == 99999 ? '\n' : ' ');
  }
  puts("100000");
  for(int i = 0; i < 100000; i++) {
    printf("%lld\n", dist2(generator));
  }  
}