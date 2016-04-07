#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
  int m, cas = 1;
  cin >> m;
  cin.ignore();
  while(m--) {
    string s;
    getline(cin, s);
    array<int, 26> freq;
    freq.fill(0);
    for(char c : s) {
      // cout << c << endl;
      if('a' <= c && c <= 'z')
        freq[c-'a']++;
      else if('A' <= c && c <= 'Z')
        freq[c-'A']++;
    }
    sort(freq.begin(), freq.end());
    int ans = 0, beauty = 1;
    for(int f : freq) {
      // cout << f << endl;
      ans += f * (beauty++);
    }
    cout << "Case #" << cas++ << ": " << ans << endl;
  }
}