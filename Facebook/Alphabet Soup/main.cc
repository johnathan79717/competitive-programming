#include <iostream>

using namespace std;

string s;

int solve() {
  int freq[26];
  memset(freq, 0, sizeof(freq));
  for(int i = 0; i < s.size(); i++)
    freq[s[i] - 'A']++;
  int ans = 1000;
  ans = min(ans, freq['H'-'A']);
  ans = min(ans, freq['A'-'A']);
  ans = min(ans, freq['C'-'A'] / 2);
  ans = min(ans, freq['K'-'A']);
  ans = min(ans, freq['E'-'A']);
  ans = min(ans, freq['R'-'A']);
  ans = min(ans, freq['U'-'A']);
  ans = min(ans, freq['P'-'A']);
  return ans;
}

int main() {
  int T, cas = 1;
  cin >> T;
  cin.ignore();
  while(T--) {
    getline(cin, s);
    cout << "Case #" << cas++ << ": " << solve() << endl;
  }
}