#include <iostream>
#include <string>

using namespace std;

long long cnt[36001];

int main() {
  int a;
  cin >> a;
  string s;
  cin >> s;
  for(int i = 0; i < s.size(); i++) {
    int sum = 0;
    for(int j = i; j < s.size(); j++) {
      sum += (s[j] - '0');
      cnt[sum]++;
    }
  }
  if(a == 0) {
    long long all = s.size() * (s.size() + 1) / 2;
    cout << cnt[0] * all * 2 - cnt[0] * cnt[0] << endl;
    return 0;
  }

  long long ans = 0;
  for(int i = 1; i * i <= a; i++) {
    if(a % i) continue;
    // cout << i << ' ' << cnt[i] << ' ' << cnt[a/i] << endl;
    if(a / i <= 36000) {
      ans += (cnt[i] * cnt[a/i]);
      if(i < a / i)
        ans += (cnt[i] * cnt[a/i]);
    }
  }

  cout << ans << endl;
}