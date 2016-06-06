#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

#define MAX_N 100005

int main() {
  string s;
  int m;
  cin >> s >> m;
  int x[MAX_N], y[MAX_N], z[MAX_N];
  x[0] = y[0] = z[0] = 0;
  for(int i = 0; i < s.size(); i++) {
    x[i+1] = x[i];
    y[i+1] = y[i];
    z[i+1] = z[i];
    switch(s[i]) {
      case 'x': x[i+1]++; break;
      case 'y': y[i+1]++; break;
      default: z[i+1]++; break;
    }
  }
  
  for(int k = 0; k < m; k++) {
    int l, r;
    cin >> l >> r;
    if(r - l < 2) {
      cout << "YES" << endl;
      continue;
    }

    int xx = x[r] - x[l-1];
    int yy = y[r] - y[l-1];
    int zz = z[r] - z[l-1];
    if(abs(xx - yy) <= 1 && abs(yy-zz) <= 1 && abs(zz-xx) <= 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
