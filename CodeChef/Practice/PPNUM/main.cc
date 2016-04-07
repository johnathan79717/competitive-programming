#include <iostream>

using namespace std;

#define M 1000000007

typedef long long ll;

ll ten[11];

ll sum(ll L, ll R) {
  return (L + R) * (R - L + 1) / 2 % M;
}

ll solve(ll L, ll R) {
  for(int i = 0; i < 11; i++) {
    if(ten[i] > L) {
      if(ten[i] <= R)
        return (i * sum(L, ten[i] - 1) + solve(ten[i], R)) % M;
      else
        return i * sum(L, R) % M;
    }
  }
}

int main() {
  int T;
  cin >> T;
  ten[0] = 1;
  for(int i = 1; i < 11; i++) {
    ten[i] = 10 * ten[i-1];
  }
  while(T--) {
    ll L, R;
    cin >> L >> R;
    cout << solve(L, R) << endl;
  }
}