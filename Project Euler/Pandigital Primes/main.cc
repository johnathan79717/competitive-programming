#include <iostream>
#include <algorithm>

using namespace std;

int get4(int *a) {
  return 10 * (10 * (10 * a[0] + a[1]) + a[2]) + a[3];
}

int get5(int *a) {
  return 10 * (10 * (10 * (10 * a[4] + a[5]) + a[6]) + a[7]) + a[8];
}

int main() {
  int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  do {
    if(get4(a) * 2 == get5(a))
      break;
  } while(prev_permutation(a, a + 9));
  cout << get4(a) << get5(a) << endl;
}