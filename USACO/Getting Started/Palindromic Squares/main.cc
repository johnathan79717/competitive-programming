/*
ID: johnath2
PROG: palsquare
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
#define NAME "palsquare"

using namespace std;

bool isPalindrome(vector<int> &digit) {
  for(int i = 0; i < digit.size(); i++) {
    if(digit[i] != digit[digit.size() - 1 - i])
      return false;
  }
  return true;
}

#ifndef STDIO
  ifstream cin (NAME".in");
  ofstream cout (NAME".out");
#endif

void print(vector<int> &digit) {
  for(int i = digit.size() - 1; i >= 0; i--)
    if(digit[i] < 10)
      cout << digit[i];
    else
      cout << char(digit[i] - 10 + 'A');
}

int main() {
  int B;
  cin >> B;
  for(int N = 1; N <= 300; N++) {
    int n = N * N;
    vector<int> digit;
    while(n) {
      digit.push_back(n % B);
      n /= B;
    }
    if(isPalindrome(digit)) {
      int temp = N;
      vector<int> digitN;
      while(temp) {
        digitN.push_back(temp % B);
        temp /= B;
      }
      print(digitN);
      cout << ' ';
      print(digit);
      cout << '\n';
    }
  }
  return 0;
}