// Sample input 3, in CPP.

#include <cassert>

long long GetToddLength() {
  return 5LL;
}

long long GetStevenLength() {
  return 5LL;
}

long long GetToddValue(long long i) {
  switch ((int)i) {
    case 0: return 129462715LL;
    case 1: return 1123984713LL;
    case 2: return 2123984713LL;
    case 3: return 3123984713LL;
    case 4: return 4123984713LL;
    default: assert(0);
  }
}

long long GetStevenValue(long long i) {
  switch ((int)i) {
    case 0: return 129384710LL;
    case 1: return 1123841020LL;
    case 2: return 2194327210LL;
    case 3: return 3123411240LL;
    case 4: return 4129347120LL;
    default: assert(0);
  }
}
