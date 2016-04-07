#include <iostream>
#include <vector>
using namespace std;

int sum(int n) {
  if(n == 1) return 1;
  for(int i = 2; i * i <= n; ++i) {
    if(n % i != 0) continue;

    int factor = i;
    int ans = 1;
    while(n % factor == 0) {
      ans += factor;
      factor *= i;
    }
    return ans * sum(n / (factor / i));
  }
  return 1 + n;
}

bool abundant(int n) {
  return sum(n) - n > n;
}

vector<int> abd;

bool a[28124];

int main() {
  // int cnt = 0;
  for(int i = 12; i <= 28123; ++i)
    if(abundant(i))
      abd.push_back(i);
  for(int i = 0; i < abd.size(); ++i)
    for(int j = 0; j < abd.size(); ++j) {
      if(abd[i] + abd[j] > 28123)
        break;
      a[abd[i] + abd[j]] = true;
    }
  // int ans = 0;
  // for(int i = 1; i < 28123; ++i)
  //   if(!a[i])
  //     ans += i;
  // cout << ans << endl;
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    puts((N > 28123 || a[N]) ? "YES" : "NO");
  }
}