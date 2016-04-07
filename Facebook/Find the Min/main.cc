#include <cstdio>
#include <unordered_set>
#include <queue>

using namespace std;
#define MAX_K 100005

typedef long long ll;
int n, k, a, b, c, r;
ll m[MAX_K*2];
int occ[MAX_K];

int solve() {
  memset(occ, false, sizeof(occ));
  m[0] = a;
  for(int i = 1; i < k; i++)
    m[i] = (ll(b) * m[i-1] + c) % r;
  for(int i = 0; i < k; i++)
    if(m[i] <= k)
      occ[m[i]]++;
  priority_queue<ll, vector<ll>, greater<ll> > available;
  for(ll i = 0; i <= k; i++)
    if(!occ[i])
      available.push(i);
  for(int i = k; i <= 2*k; i++) {
    m[i] = available.top();
    available.pop();
    occ[m[i]]++;
    if(m[i-k] <= k) {
      occ[m[i-k]]--;
      if(!occ[m[i-k]]) available.push(m[i-k]);
    }
  }
  // for(int i = 0; i <= n; i++)
    // printf("%d: %lld\n", i, m[i]);
    // printf("%d: %lld\t", i, m[i]);
  return m[(n - 1 - k) % (k+1) + k];
}

int main() {
  int T, cas = 1;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d%d%d%d%d", &n, &k, &a, &b, &c, &r);
    printf("Case #%d: %d\n", cas++, solve());
  }
}