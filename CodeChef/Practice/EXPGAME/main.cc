#include <iostream>
#include <cstring>
using namespace std;

#define MAX_A 100000

int nim[MAX_A+1];

int solve() {
  int N, ans = 0;
  cin >> N;
  while(N--) {
    int A;
    cin >> A;
    ans ^= nim[A];
  }
  // cout << "ans: " << ans << endl;
  return ans;
}

int main() {
  int e[] = {1, 2*2, 3*3*3, 4*4*4*4, 5*5*5*5*5, 6*6*6*6*6*6, 7*7*7*7*7*7*7};
  nim[0] = 0;
  for(int i = 1; i <= MAX_A; i++) {
    bool outcome[7];
    memset(outcome, false, sizeof(outcome));
    for(int j = 0; e[j] <= i; j++)
      outcome[nim[i-e[j]]] = true;
    for(int n = 0; n < 7; n++)
      if(!outcome[n]) {
        nim[i] = n;
        break;
      }
    // if(i < 30)
    //   cout << i << ' ' << nim[i] << endl;
  }
  int T;
  cin >> T;
  while(T--) {
    cout << (solve() == 0 ? "Head Chef" : "Little Chef") << endl;
  }
}