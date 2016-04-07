#include <iostream>
#include <random>
using namespace std;

int main(int argc, char *argv[]) {
  std::default_random_engine generator(atoi(argv[1]));
  std::uniform_int_distribution<int> distribution(1,6);
  auto dice = std::bind ( distribution, generator );
  int N = dice(), C = dice();
  cout << N << ' ' << C << '\n';
  for(int i = 0; i < N; i++)
    cout << dice() << ' ';
  puts("");
  for(int i = 0; i < N; i++)
    cout << dice() << ' ';
  puts("");
}