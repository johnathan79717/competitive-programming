#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;

ll fact[19];

int main() {
  fact[0] = 1;
  for(int i = 1; i <= 18; i++)
    fact[i] = fact[i-1] * i;
  int T;
  cin >> T;
  while(T--) {
    int freq[10];
    memset(freq, 0, sizeof(freq));
    ll N;
    cin >> N;
    vector<int> digit;
    while(N > 0) {
      digit.push_back(N % 10);
      freq[N % 10]++;
      N /= 10;
    }
    ll ans = 0;
    for(int i = digit.size() - 1; i >= 0; i--) {
      for(int j = 0; j < digit[i]; j++) {
        if(freq[j]) {
          freq[j]--;
          ll ways = fact[i];
          for(int k = 0; k < 10; k++)
            ways /= fact[freq[k]];
          ans += ways;
          freq[j]++;
        }
      }
      freq[digit[i]]--;
    }
    cout << ans + 1 << endl;
  }
}