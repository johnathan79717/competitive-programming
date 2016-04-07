#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int T;
  cin >> T;
  while(T--) {
    long long N;
    cin >> N;
    N--;
    char ans[14] = {};
    string candidate = "abcdefghijklm";
    long long fact = 1;
    for(int i = 1; i <= 13; i++)
      fact *= i;
    for(int i = 0; i < 13; i++) {
      fact /= 13-i;
      int p = N / fact;
      ans[i] = candidate[p];
      candidate.erase(p, 1);
      N %= fact;
    }
    puts(ans);
  }
}