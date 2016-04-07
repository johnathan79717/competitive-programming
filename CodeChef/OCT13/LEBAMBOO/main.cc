#include <iostream>
using namespace std;

int solve() {
  int n;
  cin >> n;
  int d[50];
  for(int i = 0; i < n; i++)
    cin >> d[i];
  int sum = 0;
  for(int i = 0; i < n; i++) {
    int D;
    cin >> D;
    d[i] = D - d[i];
    sum += d[i];
  }
  if(n == 1) {
    if(d[0] > 0)
      return -1;
    else
      return -d[0];
  }
  if(n == 2) {
    if(d[0] + d[1] != 0)
      return -1;
    else
      return d[0] > 0 ? d[0] : d[1];
  }
  if(sum % (n-2))
    return -1;
  int k = sum / (n-2);
  for(int i = 0; i < n; i++) {
    if(k < d[i] || (k - d[i]) % 2)
      return -1;
  }
  return k;
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    cout << solve() << endl;
  }
}