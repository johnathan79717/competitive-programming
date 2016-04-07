#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  while(T--) {
    int h1, m1, s1, h2, m2, s2;
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    int t1 = (h1 * 60 + m1) * 60 + s1;
    int t2 = (h2 * 60 + m2) * 60 + s2;
    int d = t2 - t1;
    if(d < 0) d += 86400;

    d %= 400;
    if(d < 100)
      cout << 'S' << endl;
    else if(d < 200)
      cout << 'C' << endl;
    else if(d < 300)
      cout << 'S' << endl;
    else
      cout << 'C' << endl;
  }
}