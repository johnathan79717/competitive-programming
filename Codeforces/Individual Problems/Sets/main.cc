#include <iostream>

using namespace std;

#define MAX_N 100005
#define MAX_M 20
int set[MAX_N];
bool bad[1 << MAX_M];
int cnt[MAX_M];

int main() {
  int n, m, d;
  cin >> n >> m >> d;
  for(int i = 0; i < m; i++) {
    int si;
    cin >> si;
    for(int j = 0; j < si; j++) {
      int v;
      cin >> v;
      set[v] = i;
    }
  }
  int must = 0;
  for(int i = 1; i <= d - 1; i++) {
    cnt[set[i]]++;
    must |= (1 << set[i]);
  }
  for(int i = d; i <= n; i++) {
    cnt[set[i]]++;
    must |= (1 << set[i]);
    bad[((1 << m) - 1) & ~must] = true;
    if(!--cnt[set[i-d+1]])
      must &= ~(1 << set[i-d+1]);
  }
  for(int i = 0; i < (1<<m); i++) {
    if(!bad[i]) continue;
    int j = i;
    do {
      bad[j] = true;
      j = (j - 1) & i;
    } while(j != i);
  }
  int ans = n;
  for(int i = 0; i < (1<<m); i++) {
    if(bad[i]) continue;
    int ones = 0;
    for(int j = 0; j < m; j++)
      if(i & (1 << j))
        ones++;
    ans = min(ans, ones);
  }
  cout << ans << endl;
}