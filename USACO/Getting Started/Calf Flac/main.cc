/*
ID: johnath2
PROG: calfflac
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
#define NAME "calfflac"

using namespace std;

#ifndef STDIO
  ifstream cin (NAME".in");
  ofstream cout (NAME".out");
#endif

bool equal(char a, char b) {
  return a == b || abs(a - b) == 'a' - 'A';
}

int main() {
  string s;
  char c;
  while(cin.get(c))
    s.push_back(c);
  int ans = 0, head = 0, len = 0;
  for(int i = 0; i < s.size(); i++) {
    if(isalpha(s[i])) {
      int left = i, right = i;
      for(int j = 0; j <= 1000 && left >= 0 && right < s.size(); j++) {
        if(!equal(s[left], s[right]))
          break;
        if(2 * j + 1 > ans) {
          ans = 2 * j + 1;
          len = right - left + 1;
          head = left;
        }
        do left--; while(left >= 0 && !isalpha(s[left]));
        do right++; while(right < s.size() && !isalpha(s[right]));
      }
      right = left = i; do right++; while(right < s.size() && !isalpha(s[right]));
      for(int j = 0; j <= 1000 && left >= 0 && right < s.size(); j++) {
        if(!equal(s[left], s[right]))
          break;
        if(2 * j + 2 > ans) {
          ans = 2 * j + 2;
          len = right - left + 1;
          head = left;
        }
        do left--; while(left >= 0 && !isalpha(s[left]));
        do right++; while(right < s.size() && !isalpha(s[right]));
      }
    }
  }
  cout << ans << endl;
  for(int i = head; i < head + len; i++) {
    cout << s[i];
  }
  cout << endl;
  return 0;
}