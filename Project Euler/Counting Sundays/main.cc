#include <iostream>
using namespace std;

bool is_leap(long long y) {
  if(y % 400 == 0) return true;
  if(y % 100 == 0) return false;
  return y % 4 == 0;
}

int days(long long Y1, int M1) {
  switch(M1) {
    case 2: return is_leap(Y1) ? 29 : 28;
    case 4:
    case 6:
    case 9:
    case 11: return 30;
    default: return 31;
  }
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    long long Y1, Y2;
    int M1, M2, D1, D2;
    cin >> Y1 >> M1 >> D1 >> Y2 >> M2 >> D2;
    if(D1 > 1) {
      M1++;
      if(M1 > 12) {
        M1 = 1;
        Y1++;
      }
    }
    int ans = 0;
    int day = [=]() {
      int q = 1, m = M1;
      long long y = Y1;
      if(m < 3) {
        m += 12;
        y--;
      }
      int h = (q + (m+1)*26/10 + y + y/4 + 6*(y/100) + y/400) % 7;
      return (h + 6) % 7;
    }();
    cerr << day << endl;
    while(Y1 < Y2 || (Y1 == Y2 && M1 <= M2)) {
      if(day == 0)
        ++ans;
      day = (day + days(Y1, M1)) % 7;
      ++M1;
      if(M1 > 12) {
        M1 = 1;
        ++Y1;
      }
    }
    cout << ans << endl;
  }
}