#include <iostream>
using namespace std;

string s;

bool solve() {
  int ub = 0, lb = 0;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == '(') {
      ub++;
      if(i == 0 || s[i-1] != ':')
        lb++;
    } else if(s[i] == ')') {
      if(lb > 0)
        lb--;
      if(i == 0 || s[i-1] != ':') {
        if(ub > 0)
          ub--;
        else
          return false;
      }
    }
  }
  return lb == 0;
}

int main() {
  int T, cas = 1;
  cin >> T;
  cin.ignore();
  while(T--) {
    getline(cin, s);
    printf("Case #%d: %s\n", cas++, solve() ? "YES" : "NO");
  }
}