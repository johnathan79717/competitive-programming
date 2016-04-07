#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
  int T;
  cin >> T;
  while(T--) {
    int N, A[100000];
    long long ans = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
      cin >> A[i];
      if(A[i] == 2)
        A[i] = 4;
      if(A[i] == 1)
        A[i] = INT_MAX;
    }
    sort(A, A + N);
    for(int i = 0; i < N; i++) {
      int B;
      cin >> B;
      if(B == 2)
        B = 4;
      if(B == 1)
        B = INT_MAX;
      ans += (lower_bound(A, A + N, B) - A);
      // cout << ans << endl;
    }
    // cout << ans << endl;
    printf("%.06lf\n", double(ans) / N);
  }
}