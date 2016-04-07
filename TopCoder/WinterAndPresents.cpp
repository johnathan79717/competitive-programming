#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <deque>
#include <climits>
#include <set>
#include <vector>
using namespace std;

typedef long long LL;


class WinterAndPresents {
public:
  long long getNumber(vector <int> apple, vector <int> orange) {
    LL m = INT_MAX;
    for(int i = 0; i < apple.size(); i++) {
      m = min(m, LL(apple[i] + orange[i]));
    }
    long long ans = 0;
    for(int i = 0; i < apple.size(); i++) {
      if(m <= apple[i])
        ans += (1+m) * m / 2;
      else
        ans += LL(1+apple[i]) * (apple[i]) / 2 + (m - apple[i]) * apple[i];
      if(m <= orange[i])
        ans += (1+m) * m / 2;
      else
        ans += LL(1+orange[i]) * (orange[i]) / 2 + (m - orange[i]) * orange[i];
    }
    // for(int x = 1; x <= m; x++) {
    //   int max_a = 0, max_o = 0;
    //   for(int i = 0; i < apple.size(); i++) {
    //     max_a += min(x, apple[i]);
    //     max_o += min(x, orange[i]);
    //     cout << max_a << ' ' << max_o << endl;
    //   }
    //   long long total = LL(x) * apple.size();
    //   ans += (max_a + max_o - total + 1);
    //   cout << ans << endl;
    // }
    return ans - (1+m) * m / 2 * apple.size() + m;
  }
};
