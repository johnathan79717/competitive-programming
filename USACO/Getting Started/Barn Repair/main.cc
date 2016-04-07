/*
ID: johnath2
PROG: barn1
LANG: C++
*/
#ifdef STDIO
#include <iostream>
#endif

#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#define NAME "barn1"

using namespace std;

#ifndef STDIO
  ifstream cin (NAME".in");
  ofstream cout (NAME".out");
#endif

int main() {
  int M, S, C;
  cin >> M >> S >> C;
  if(M >= C) {
    cout << C << endl;
    return 0;
  }
  int cow[200];
  for(int i = 0; i < C; i++)
    cin >> cow[i];
  sort(cow, cow + C);
  int ans = cow[C-1] - cow[0] + 1;
  // cout << ans << endl;
  int gap[200];
  for(int i = 1; i < C; i++)
    gap[i-1] = cow[i] - cow[i-1] - 1;
  sort(gap, gap + C - 1, greater<int>());
  for(int i = 0; i < M - 1; i++)
    ans -= gap[i];
  cout << ans << endl;
  return 0;
}