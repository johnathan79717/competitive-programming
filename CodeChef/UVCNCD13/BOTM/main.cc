#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int T;
  cin >> T;
  int P[100000];
  while(T--) {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
      cin >> P[i];
    sort(P, P + N);
    int ans = 0;
    for(int i = 0; i < N - 1 - i; i++)
      ans += (P[N-1-i] - P[i]);
    cout << ans << endl;
  }
}