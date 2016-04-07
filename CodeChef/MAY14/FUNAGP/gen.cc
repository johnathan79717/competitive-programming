#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

int main() {
  default_random_engine generator;
  int N = 100000, Q = 100000, R = 1000000000, p1 = 99999989, p2 = 99999989;
  uniform_int_distribution<int> distribution(1,N);
  // int dice_roll = distribution(generator);  // generates number in the range 1..6
  auto dice = bind(distribution, generator);
  puts("1");
  printf("%d %d %d %d %d\n", N, Q, R, p1, p2);
  while(N--) {
    printf("%d ", dice());
  }
  puts("");
  while(Q--) {
    int t = dice() % 3;
    int X = dice(), Y = dice();
    if(X > Y) swap(X, Y);
    if(t == 0) {
      printf("0 %d %d %d %d\n", dice(), dice(), X, Y);
    } else if(t == 1) {
      printf("1 %d %d\n", dice(), dice());
    } else {
      printf("2 %d %d\n", X, Y);
    }
  }
}