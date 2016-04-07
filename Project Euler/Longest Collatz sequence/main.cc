#include <iostream>
#include <cassert>
#include <map>
using namespace std;

int c[5000001];

int collatz(long long n) {
  assert(n > 0);
  int ans;
  if(n <= 5000000 && c[n])
    return c[n];
  else if(n & 1)
    ans = 1 + collatz(3 * n + 1); 
  else
    ans = 1 + collatz(n >> 1);
  if(n <= 5000000)
    c[n] = ans;
  return ans;
}

pair<int, int> ans[5000001];

int main() {
  c[1] = 1;
  ans[1] = make_pair(1, 1);
  for(int n = 2; n <= 5000000; ++n) {
    int c = collatz(n);
    ans[n] = max(ans[n-1], make_pair(c, n));
  }
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    cout << ans[N].second << endl;
  }
}