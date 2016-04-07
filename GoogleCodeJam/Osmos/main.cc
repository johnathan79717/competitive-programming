#include <iostream>
#include <algorithm>

using namespace std;

int solve() {
  int A, N;
  int mote[100];
  cin >> A >> N;
  for(int i = 0; i < N; ++i)
    cin >> mote[i];
  if(A == 1)
    return N;
  sort(mote, mote + N);
  int min_op = INT_MAX;
  for(int remove = 0; remove <= N; ++remove) {
    int op = remove;
    int a = A;
    for(int i = 0; i < N - remove; ++i) {
      while(a <= mote[i]) {
        a = a + a - 1;
        ++op;
      }
      a += mote[i];
      // cout << "a: " << a << endl;
    }
    // cout << op << endl;
    min_op = min(min_op, op);
  }
  return min_op;
}

int main() {
  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": " << solve() << endl;
  }
}