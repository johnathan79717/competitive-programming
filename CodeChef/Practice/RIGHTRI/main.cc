#include <iostream>

using namespace std;

bool solve() {
  int x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  int vx1 = x1 - x2, vy1 = y1 - y2, vx2 = x2 - x3, vy2 = y2 - y3, vx3 = x3 - x1, vy3 = y3 - y1;
  if(vx1 * vx2 + vy1 * vy2 == 0)
    return true;
  else if(vx2 * vx3 + vy2 * vy3 == 0)
    return true;
  else if(vx3 * vx1 + vy3 * vy1 == 0)
    return true;
  else
    return false;
}


int main() {
  int N;
  cin >> N;
  int ans = 0;
  while(N--) {
    if(solve())
      ans++;
  }
  cout << ans << endl;
}