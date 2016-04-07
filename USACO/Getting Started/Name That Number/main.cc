/*
ID: johnath2
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define NAME "namenum"

using namespace std;

bool check(const string &number, const string &name) {
  for(int i = 0; i < name.size(); i++) {
    switch(name[i]) {
      case 'A': case 'B': case 'C': if(number[i] != '2') return false; break;
      case 'D': case 'E': case 'F': if(number[i] != '3') return false; break;
      case 'G': case 'H': case 'I': if(number[i] != '4') return false; break;
      case 'J': case 'K': case 'L': if(number[i] != '5') return false; break;
      case 'M': case 'N': case 'O': if(number[i] != '6') return false; break;
      case 'P': case 'R': case 'S': if(number[i] != '7') return false; break;
      case 'T': case 'U': case 'V': if(number[i] != '8') return false; break;
      default: if(number[i] != '9') return false; break;
    }
  }
  return true;
}

int main() {
#ifndef STDIO
  ifstream cin (NAME".in");
  ofstream cout (NAME".out");
#endif
  ifstream dict("dict.txt");
  string number, name;
  cin >> number;
  bool none = true;
  while(dict >> name) {
    if(name.size() != number.size())
      continue;
    if(check(number, name)) {
      none = false;
      cout << name << '\n';
    }
  }
  if(none)
    cout << "NONE" << endl;
  return 0;
}