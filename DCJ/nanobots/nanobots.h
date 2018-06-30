// Sample input 3, in CPP.
#include <cassert>

long long GetRange() {
  return 1000000000000ll;
}

long long GetNumNanobots() {
  return 1;
}

static long long sizes[] = {1000000000000ll};
static long long speeds[] = {1000000000000ll};

char Experiment(long long size, long long speed) {
  if (size < 1 || size > GetRange() || speed < 1 || speed > GetRange())
    assert(0);
  for (int i = 0; i < 1; ++i)
    if (sizes[i] > size && speeds[i] > speed) return 'T';
  return 'E';
}

