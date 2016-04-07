#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
  int N, cas = 1;
  cin >> N;
  while(N--) {
    ll X;
    cin >> X;
    ll ans = 0;
    for(ll i = 0; 2*i*i <= X; i++) {
      ll j = round(sqrt(X - i * i));
      if(i * i + j * j == X)
        ans++;
    }
    // cout << "Case #" << cas++ << ": " << ans << endl;
    cout << ans << endl;
  }
}