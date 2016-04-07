#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    int c = 0;
 
    while (!(a & 1) && !(b & 1))
        a >>= 1, b >>= 1, c++;
 
    while (a)
        if (!(a & 1))
            a >>= 1;
        else if (!(b & 1))
            b >>= 1;
        else
        {
            int t = abs(a-b) >> 1;
            if (a < b) b = t; else a = t;
        }
 
    return b << c;
}
const int MAX = 5000000;
int ans[MAX+1], m[MAX+1];
int main() {
  for(int x = 1; 2 * x * (x+1) <= MAX; ++x) {
    for(int y = 1; y < x; ++y) {
      if(x%2 == y%2 || gcd(x, y) > 1)
        continue;
      int temp = 2 * x * (x + y);
      int i = 1;
      while(temp * i <= MAX) {
        ans[temp * i]++;
        i++;

      }
    }
  }
  m[12] = 12;
  for(int n = 13; n <= MAX; n++) {
    m[n] = m[n-1];
    if(ans[n] > ans[m[n]])
      m[n] = n;
  }
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    cout << m[N] << '\n';
  }
}