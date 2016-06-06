#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define MAX_N 200005

int a[MAX_N];
map<int, int> b;

typedef long long ll;
int main() {
  ll n, m, p;
  scanf("%lld%lld%lld", &n, &m, &p);
  for(ll i = 0; i < n; i++)
    scanf("%d", a + i);
  for(ll i = 0; i < m; i++) {
    int bi;
    scanf("%d", &bi);
    b[bi]++;
  }

  vector<int> ans;
  for(int i = 0; i < p; i++) {
    if(i + (m-1) * p >= n)
      break;
    map<int, int> cnt;
    int fault = 0;
    for(int j = 0; j < m - 1; j++) {
      int ai = a[i+j*p];
      cnt[ai]++;
      if(cnt[ai] > b[ai])
        fault++;
    }
    for(int q = i; q + (m-1) * p < n; q += p) {
      int ai = a[q + (m-1) * p];
      cnt[ai]++;
      if(cnt[ai] > b[ai])
        fault++;
      if(!fault)
        ans.push_back(q);
      if(cnt[a[q]] > b[a[q]])
        fault--;
      cnt[a[q]]--;
    }
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for(int i = 0; i < ans.size(); i++)
    printf("%d%c", ans[i] + 1, (i == ans.size() - 1 ? '\n' : ' '));
}