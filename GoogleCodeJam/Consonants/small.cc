#include <iostream>

using namespace std;

bool consonant(char c) {
  return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

int main() {
  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t) {
    char str[1000001];
    cin >> str;
    int n;
    cin >> n;
    int L = strlen(str);
    int c = 0;
    int tail = 0;
    int ans = 0;
    // cout << "n: " << n << endl;
    for(int i = 0; i < L; ++i) {
      if(!consonant(str[i]))
        c = 0;
      else {
        ++c;
        if (c > n) {
          if(tail > 0)
            ++tail;
        }
        else if(c == n){
          tail = i - n + 2;
        }
      }
      ans += tail;
      // cout << "i: " << i <<' ';
      // cout << "ans: " << ans <<' ';
      // cout << "tail: " << tail << ' ';  
      // cout << "c: " << c << endl;
    }
    cout << "Case #" << t << ": " << ans << endl;
  }
}