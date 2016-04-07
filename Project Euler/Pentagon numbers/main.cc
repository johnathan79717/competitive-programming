#include <iostream>
#include <algorithm>

using namespace std;
const int M = 2000000;
  long long a[M];
int main() {
  int N, K;
  cin >> N >> K;
  a[0] = 0;
  for(int i = 1; i < M; ++i) {
    a[i] = a[i-1] + 3 * i - 2;
  }
  auto ok = [=](long long n) {
    return (*lower_bound(a, a + M, n) == n);
  };
  for(int n = K+1; n < N; n++) {

    if(ok(a[n] - a[n-K]) || ok(a[n] + a[n-K])) {
      printf("%lld\n", a[n]);
    }
  }
  //   for(int j = i-1; a[i] - a[j] < a[j]; --j) {
  //     int p = lower_bound(a, a+j, a[i] - a[j]) - a;
  //     if(a[p] != a[i] - a[j])
  //       continue;
  //     int q = lower_bound(a, a+j, a[j] - a[p]) - a;
  //     if(a[q] == a[j] - a[p]) {
  //       cout << a[q] << ' ' << a[p] << ' ' << a[j] << ' ' << a[i] << endl;
  //     }
  //   }
  // }
}