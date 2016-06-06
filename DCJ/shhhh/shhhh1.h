// Sample input 1, in CPP.

#include <cassert>

long long GetN() {
  return 2LL;
}

long long GetLeftNeighbour(long long i) {
  switch ((int)i) {
    case 0: return 1LL;
    case 1: return 0LL;
    default: assert(0);
  }
}

long long GetRightNeighbour(long long i) {
  switch ((int)i) {
    case 0: return 1LL;
    case 1: return 0LL;
    default: assert(0);
  }
}
