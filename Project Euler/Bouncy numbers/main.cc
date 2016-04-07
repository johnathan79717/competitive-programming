#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool bouncy(int n) {
  vector<int> d;
  while(n) {
    d.push_back(n % 10);
    n /= 10;
  }
  if(is_sorted(d.begin(), d.end()) || is_sorted(d.rbegin(), d.rend()))
    return false;
  else
    return true;
}

int main() {
  int cnt = 0;
  for(int n = 1; n < 10000000;n++) {
    if(bouncy(n))
      cnt++;
    if(cnt * 100 == n * 99) {
      cout << n << endl;
      break;
    }
  }
}