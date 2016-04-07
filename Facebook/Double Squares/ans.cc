#include <iostream>
#include <set>
#include <cmath>
using namespace std;

typedef long long unsigned int llu;
set<llu> squares;

int main() {
  for (int i = 0; i < 50000; i++) {
    llu i2 = i*i;
    if (i2 > 2147483647L * 2L) {
      break;
    } else {
      squares.insert(i2);
    }
  }

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    int ans = 0;
    for(set<llu>::iterator it = squares.begin(); it != squares.end(); ++it) {
      llu first = *it;
      if (2 * first > num) break;
      if (squares.count(num - first)) {
        ans++;
      }
    }
    cout << ans << endl;
  }
}