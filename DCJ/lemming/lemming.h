// Sample input 3, in CPP.

#include <cassert>

long long GetRows() {
  return 3LL;
}

long long GetColumns() {
  return 3LL;
}

char c[][5] = {
  ">>>v",
  "^v<v",
  "^>^v",
  "^<<<",
};

char GetDirection(long long i, long long j) {
  return c[i][j];
  assert(0);
}
