#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = a % b;
        a = b; b = t;
    }
    return a;
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    int ans;
    cin >> ans;
    for(int i = 1; i < N; ++i) {
      int A;
      cin >> A;
      ans = gcd(ans, A);
    }
    cout << ans << endl;
  }
}