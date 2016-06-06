#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a[200];
  int sum = 0;
  int m = -1001;
  int neg = 0;
  for(int i = 0; i < 2 * n - 1; ++i) {
    cin >> a[i];
    sum += abs(a[i]);
    if(a[i] <= 0) {
      ++neg;
      m = max(m, a[i]);
    }
  }
  if(n % 2 == 1 || neg % 2 == 0)
    cout << sum << endl;
  else
    cout << sum + 2 * m << endl;
}