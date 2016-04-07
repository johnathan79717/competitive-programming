#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string names[5200];

int score(const string& name) {
  int ans = 0;
  for(int i = 0; i < name.size(); ++i)
    ans += (name[i] - 'A' + 1);
  return ans;
}

int main() {
  int T;
  cin >> T;
  for(int i = 0; i < T; i++) cin >> names[i];
  // int ans = 0;
  sort(names, names + T);
  // for(int i = 0; i < T; ++i)
  //   ans += (i+1) * score(names[i]);
  // cout << ans << endl;
  // cout << score(string("COLIN")) << endl;
  int Q;
  cin >> Q;
  while(Q--) {
    string name;
    cin >> name;
    cout << (lower_bound(names, names + T, name) - names + 1) * score(name) << endl;
  }
}