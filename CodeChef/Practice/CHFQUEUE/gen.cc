#include <ctime>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main() {
  srand(time(NULL));
  int N = 1000000, K = 100000;
  printf("%d %d\n", N, K);
  while(N--)
    printf("%d ", (int)random() % K);
}