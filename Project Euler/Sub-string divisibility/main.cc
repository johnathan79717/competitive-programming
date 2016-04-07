#include <iostream>
#include <algorithm>

using namespace std;

int get3(int *a) {
  return 10 * (10 * a[0] + a[1]) + a[2];
}

long long get(int *a, int N) {
  long long ans = 0;
  for(int i = 0; i < N+1; ++i)
    ans = ans * 10 + a[i];
  return ans;
}

int main() {
  int N;
  cin >> N;
  // if(N == 9) {
  //   cout << 16695334890ll << endl;
  //   return 0;
  // }
  int a[] = {0,1,2,3,4,5,6,7,8,9};
  int p[] = {0, 2, 3, 5, 7, 11, 13, 17};
  long long ans = 0;
  do {
    bool fail = false;
    for(int j = 1; j <= N-2; j++) {
      if(get3(a+j) % p[j]) {
        fail = true;
        break;
      }
    }
    if(!fail) {
    // if(get3(a+1) % 2 == 0 && get3(a+2) % 3 == 0 && get3(a+3) % 5 == 0 && get3(a+4) % 7 == 0 && get3(a+5) % 11 == 0 && get3(a+6) % 13 == 0 && get3(a+7) % 17 == 0) {
      long long i = get(a, N);
      ans += i;
      cout << get(a, N) << endl;
      // c.push_back(i);
    }
  } while(next_permutation(a, a + N+1));
  cout << ans << endl;
}