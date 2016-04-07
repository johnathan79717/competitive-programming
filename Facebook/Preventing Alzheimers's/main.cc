#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
int A[22], B[22];
int used[100], u;
int bestu[100];
int ans, best, pre;

bool ok(int cand) {
  for(int p = 2; p * p <= cand; p++)
    if(cand % p == 0) {
      for(int i = 0; i < u; i++)
        if(used[i] == p)
          return false;
      do cand /= p; while (cand % p == 0);
    }
  for(int i = 0; i < u; i++)
    if(used[i] == cand)
      return false;
  return true;
}

int t[] = {5, 5, 4, 4, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1};

void dfs(int i) {
  if(i == N) {
    if(u > 1 && used[0] == 0 && used[1] > 0) ans++;
    if(best > ans) {
      best = ans;
      // puts("Answer: ");
      // for(int i = 0; i < u; i++) {
      //   printf("%d\n", used[i]);
      // }
    }
    if(u > 1 && used[0] == 0 && used[1] > 0) ans--;
    return;
  }
  int cand = A[i];
  if(cand > 1) cand = max(cand, pre + 1);
  for(int k = 0; k < t[i]; k++) {
    while(!ok(cand))
      cand++;

    int temp = cand;
    for(int p = 2; p * p <= temp; p++)
      if(temp % p == 0) {
        used[u++] = p;
        do {temp /= p;} while(temp % p == 0);
      }
    if(temp != 1) {
      used[u++] = temp;
    }
    ans += (K * cand - B[i]);
    // if(ans >= best) {
    //   ans -= K * cand - B[i];
    //   return;
    // }
    pre = cand;
    dfs(i + 1);
    ans -= (K * cand - B[i]);
    temp = cand;
    for(int p = 2; p * p <= temp; p++)
      if(temp % p == 0) {
        --u;
        do temp /= p; while(temp % p == 0);
      }
    if(temp != 1) {
      --u;
    }
    if(cand == 1) break;
    cand++;
  }
}

int solve() {
  u = 0;
  best = INT_MAX;
  ans = 0;
  pre = -1;
  dfs(0);
  return best;
}

int main() {
  int T, cas = 1;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &N, &K);
    for(int i = 0; i < N; i++) {
      scanf("%d", B + i);
      if(B[i]) A[i] = (B[i] + K - 1) / K;
      else A[i] = 0;
    }
    sort(A, A + N);
    sort(B, B + N);
    printf("Case #%d: %d\n", cas++, solve());
  }
}