/*
ID: johnath2
PROG: clocks
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
#define NAME "clocks"

using namespace std;

#ifdef STDIO
#include <iostream>
#else
  ifstream cin (NAME".in");
  ofstream cout (NAME".out");
#endif


bool check(int clock[9]) {
  for(int i = 0; i < 9; i++)
    if(clock[i] % 12)
      return false;
  return true;
}

int main() {
  int clock[9];
  for(int i = 0; i < 9; i++)
    cin >> clock[i];
  int temp[9];
  int move[9][5] = {
    {0, 1, 3, 4}, {0, 1, 2}, {1, 2, 4, 5},
    {0, 3, 6}, {1, 3, 4, 5, 7}, {2, 5, 8},
    {3, 4, 6, 7}, {6, 7, 8}, {4, 5, 7, 8}
  };
  int size[9] = {4, 3, 4, 3, 5, 3, 4, 3, 4};
  vector<int> ans(30);
  for(int comb = 0; comb < (1<<18); comb++) {
    memcpy(temp, clock, sizeof(clock));
    vector<int> v;
    for(int i = 0; i < 9; i++) {
      int times = (comb >> i >> i) & 3;
      for(int j = 0; j < size[i]; j++)
        temp[move[i][j]] += 3 * times;
      while(times--)
        v.push_back(i);
    }
    if(check(temp))
      if(v.size() < ans.size() || 
        (v.size() == ans.size() && lexicographical_compare(v.begin(), v.end(), ans.begin(), ans.end())))
          ans = v;
  }
  for(int i = 0; i < ans.size(); i++)
    cout << ans[i] + 1 << (i == ans.size() - 1 ? '\n' : ' ');
  return 0;
}