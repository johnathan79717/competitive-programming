#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

const int MAX_N = 10000010;

vector<pair<int, int> > factor[MAX_N + 1];

void factorize_all(int n) {
  static int rest[MAX_N + 1];
  for (int i = 2; i <= n; i++) {
    rest[i] = i;
    factor[i].clear();
  }
  for (int i = 2; i * i <= n; i++) {
    if (factor[i].size() != 0) continue;
    for (int j = i; i * j <= n; j++) {
      int t = i * j, c = 0;
      while (rest[t] % i == 0) {
        c++;
        rest[t] /= i;
      }
      factor[t].push_back(make_pair(i, c));
    }
  }
  for (int i = 2; i <= n; i++) {
    if (rest[i] != 1) factor[i].push_back(make_pair(rest[i], 1));
  }
}

int main() {
  factorize_all(MAX_N);

  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);

    int ans = 0;
    for (int x = a; x <= b; ++x) {
      if (factor[x].size() == n) ++ans;
    }
    printf("%d\n", ans);
  }
  return 0;
}

