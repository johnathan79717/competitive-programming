#include <iostream>
#include <cstring>
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
    long long a[10001];
    memset(a, 0, sizeof(a));
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i) {
      int A;
      cin >> A;
      for(int j = 1; j <= 10000; ++j) {
        if(a[j] == 0) continue;
        a[gcd(A, j)] += a[j];
      }
      ++a[A];
      // for(int j = 1; j <= 10; ++j)
      //   cout << a[j] << ' ';
      // cout << endl;
    }
    cout << a[1] << endl;
  }
}