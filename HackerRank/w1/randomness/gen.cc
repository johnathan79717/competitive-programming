#include <cstdio>
#include <random>

using namespace std;

int main(int argc, char **argv) {
  int N = atoi(argv[1]), Q = atoi(argv[2]);
  printf("%d %d\n", N, Q);
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator (seed);
  // default_random_engine generator;
  uniform_int_distribution<char> distribution1('a', 'z');
  uniform_int_distribution<int> distribution2(1, N);
  for(int i = 0; i < N; i++) {
    printf("%c", distribution1(generator));
  }
  puts("");
  for(int i = 0; i < Q; i++) {
    printf("%d %c\n", distribution2(generator), distribution1(generator));
  }
}