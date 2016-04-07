#include <iostream>
#include <cstring>
using namespace std;

bool ans[1000001];

bool solve(int S) {
  if(ans[S])
    return true;
  for(int i = 1; i * i <= S; i++)
    if(S % i == 0 && (ans[i] || ans[S / i]))
      return true;
  return false;
}

int main() {
  int T;
  cin >> T;
  memset(ans, false, sizeof(ans));
  for(int i = 1; i < 1000; i++)
    for(int j = 1; i*i+j*j <= 1000000; j++) {
      if(i == j)
        break;
      ans[i*i+j*j] = true;
    }

  // for(int i = 1; i <= 100; i++)
  //   if(solve(i)) cout << i << endl;
  while(T--) {
    int S;
    cin >> S;
    cout << (solve(S) ? "PERFECT" : "IMPERFECT") << endl;
  }
}