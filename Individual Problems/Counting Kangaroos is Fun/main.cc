#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int s[500001];
  map<int, int> cnt;
  for(int i = 0; i < n; i++) {
    scanf("%d", s + i);
    s[i] = -s[i];
    cnt[s[i]]++;
  }
  sort(s, s + n);
  int ans = n;
  for(int i = 0; i < n; i++) {
    if(cnt.count(s[i]) == 0) continue;
    map<int, int>::iterator it = cnt.lower_bound(s[i] / 2);
    if(it == cnt.end()) break;
    ans--;
    it->second--;
    if(it->second == 0)
      cnt.erase(it);
  }
  printf("%d\n", ans);
}