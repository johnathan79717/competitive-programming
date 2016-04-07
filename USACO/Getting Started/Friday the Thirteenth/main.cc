/*
ID: johnath2
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

bool is_leap(int y) {
  if(y % 400 == 0) return true;
  if(y % 100 == 0) return false;
  return y % 4 == 0;
}

int days(int year, int month) {
  switch(month) {
    case 4:
    case 6:
    case 9:
    case 11: return 30;
    case 2: return is_leap(year) ? 29 : 28;
    default: return 31;
  }
}

int ans[7];

int main() {
  int year = 1900;
  int month = 1;
  int day = 6;

  int N;
  ifstream fin ("friday.in");
  ofstream fout ("friday.out");
  fin >> N;
  while(year < 1900 + N) {
    ++ans[day];
    // cout << days(year, month) << ' ';
    day = (day + days(year, month)) % 7;
    ++month;
    if(month > 12) {
      month = 1;
      ++year;
      // cout << endl;
    }
  }
  fout << ans[6];
  for(int i = 0; i < 6; ++i)
    fout << ' ' << ans[i];
  fout << endl;
}