/*
ID: johnath2
PROG: crypt1
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
#define NAME "crypt1"

using namespace std;

#ifdef STDIO
#include <iostream>
#else
  ifstream cin (NAME".in");
  ofstream cout (NAME".out");
#endif


int N;
int digit[9];
bool inSet[10];

bool check(int n) {
  if(n == 0)
    return true;
  if(!inSet[n % 10])
    return false;
  return check(n / 10);
}

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> digit[i];
    inSet[digit[i]] = true;
  }
  int ans = 0;
  for(int i1 = 0; i1 < N; i1++)
  for(int i2 = 0; i2 < N; i2++)
  for(int i3 = 0; i3 < N; i3++)
  for(int j1 = 0; j1 < N; j1++)
  for(int j2 = 0; j2 < N; j2++) {
    int i = (digit[i1] * 10 + digit[i2]) * 10 + digit[i3];
    if(i * digit[j1] >= 1000 || !check(i * digit[j1]))
      continue;
    if(i * digit[j2] >= 1000 || !check(i * digit[j2]))
      continue;
    if(i * (10 * digit[j1] + digit[j2]) < 10000 && check(i * (10 * digit[j1] + digit[j2])))
      ++ans;
  }
  cout << ans << endl;

  return 0;  
}