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


int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
    int W, H;
    int fld[100][100];
    scanf("%d%d", &H, &W);
    rep (y, H) rep (x, W) {
      char c;
      scanf(" %c", &c);
      fld[y][x] = c - '0';
    }

    int ans = 0;
    rep (dir, 4) {
      rep (y, H) {
        int ss = 0;
        rep (x, W) {
          int s = ss, tx;
          for (tx = x; tx < W; ++tx) {
            s -= fld[y][tx];
            if (s < 0) break;
          }
          ans = max(ans, tx - x);

          ss += fld[y][x];
        }
      }

      int tmp[100][100];
      rep (y, H) rep (x, W) {
        tmp[x][H - y - 1] = fld[y][x];
      }
      memcpy(fld, tmp, sizeof(fld));
      swap(W, H);
    }

    printf("%d\n", ans);
  }


  return 0;
}

