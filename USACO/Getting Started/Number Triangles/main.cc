/*
ID: johnath2
PROG: numtri
LANG: C++
*/
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#define NAME "numtri"

using namespace std;

#ifdef STDIO
#include <iostream>
#else
  ifstream cin (NAME".in");
  ofstream cout (NAME".out");
#endif

int main() {
  int R;
  cin >> R;
  int a[1000][1000];
  for(int i = 0; i < R; i++)
    for(int j = 0; j <= i; j++)
      cin >> a[i][j];
  for(int i = R - 2; i >= 0; i--)
    for(int j = 0; j <= i; j++)
      a[i][j] += max(a[i+1][j], a[i+1][j+1]);
  cout << a[0][0] << endl;
  return 0;
}