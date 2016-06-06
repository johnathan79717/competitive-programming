#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int gcd(int a, int b) {
  if(a == 0)
    return b;
  return gcd(b % a, a);
}

typedef long long ll;

int main() {
  long long n, m;
  cin >> n >> m;
  string x, y;
  cin >> x >> y;

  if(x.size() == y.size()) {
    ll ans = 0;
    for(int i = 0; i < x.size(); i++)
      ans += (x[i] == y[i]) ? 0 : 1;
    cout << n * ans << endl;
    return 0;
  }

  int d = gcd(x.size(), y.size());

  ll dist = 0;
  for(int i = 0; i < d; i++) {
    long long fx[26], fy[26];
    memset(fx, 0, sizeof(fx));
    memset(fy, 0, sizeof(fy));
    for(int j = i; j < x.size(); j += d)
      fx[x[j] - 'a']++;
    for(int j = i; j < y.size(); j += d)
      fy[y[j] - 'a']++;

    for(int kx = 0; kx < 26; kx++)
      for(int ky = 0; ky < 26; ky++)
        if(kx != ky)
          dist += fx[kx] * fy[ky];
  }

  cout << dist * (n / ll(y.size() / d)) << endl;
}