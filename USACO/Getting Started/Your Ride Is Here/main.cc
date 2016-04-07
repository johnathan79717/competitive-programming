/*
ID: johnath2
PROG: ride
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

int convert(char *str) {
  int L = strlen(str);
  int ans = 1;
  for(int i = 0; i < L; ++i)
    ans *= (str[i] - 'A' + 1);
  return ans % 47;
}

int main() {
  char group[7], comet[7];
  ifstream fin("ride.in");
  ofstream fout("ride.out");
  fin >> group >> comet;
  if(convert(group) == convert(comet))
    fout << "GO" << endl;
  else
    fout << "STAY" << endl;
}