/*
ID: johnath2
PROG: dualpal
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
#define NAME "dualpal"

using namespace std;

#ifndef STDIO
  ifstream cin (NAME".in");
  ofstream cout (NAME".out");
#endif

bool ispal(int n, int base) {
  vector<int> digit;
  while(n) {
    digit.push_back(n % base);
    n /= base;
  }
  for(int i = 0; i < digit.size(); i++)
    if(digit[i] != digit[digit.size() - 1 - i])
      return false;
  return true;
}

int main() {
  int N, S;
  cin >> N >> S;
  while(N) {
    ++S;
    int cnt = 0;
    for(int base = 2; base <= 10; base++) {
      if(ispal(S, base)) {
        cnt++;
        if(cnt == 2) {
          N--;
          cout << S << endl;
        }
      }
    }
  }
  return 0;
}