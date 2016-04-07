#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <cassert>
using namespace std;

int main() {
  int N;
  cin >> N;
  int p[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  unordered_set<int> ans;
  do {
    auto check = [&ans](int a, int b, int c) {
      if(a * b == c) {
        ans.insert(c);
      }
    };
    auto f = [p](int a, int b = 9, int c = 9, int d = 9) {
      return p[a] + 10*p[b] + 100*p[c] + 1000*p[d];
    };
    switch(N) {
    case 9:
      check(f(0, 1), f(2, 3, 4), f(5, 6, 7, 8));
      check(f(0), f(1, 2, 3, 4), f(5, 6, 7, 8));
      break;
    case 8:
      check(f(0, 1), f(2, 3), f(4, 5, 6, 7));
      check(f(0), f(1, 2, 3), f(4, 5, 6, 7));
      break;
    case 7:
      check(f(0, 1), f(2, 3), f(4, 5, 6));
      check(f(0), f(1, 2, 3), f(4, 5, 6));
      break;
    case 6:
      check(f(0), f(1, 2), f(3, 4, 5));
      break;
    case 5:
      check(f(0), f(1, 2), f(3, 4));
      break;
    case 4:
      check(f(0), f(1), f(2, 3));
      break;
    default:
      assert(false);
    }
  } while(next_permutation(p, p+N));
  int sum = 0;
  for(int i: ans)
    sum += i;
  cout << sum << endl;
}