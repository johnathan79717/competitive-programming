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
#include <functional>
#include <stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

class TypoCoderDiv1 {
public:
  int dp[51][2201];
  int getmax(vector <int> D, int X) {
    memset(dp, -1, sizeof dp);
    dp[0][X] = 0;
    int ans = 0;
    REP(i, D.size()) {
      REP(j, 2200) {
        if(dp[i][j] < 0) continue;
        dp[i+1][max(0, j - D[i])] = max(dp[i+1][max(0, j - D[i])], dp[i][j]);
        if(j + D[i] < 2200)
          dp[i+1][j + D[i]] = max(dp[i+1][j+D[i]], dp[i][j]);
        if(i+1 < D.size() && j + D[i] >= 2200 && j + D[i] - D[i+1] < 2200)
          dp[i+2][max(0, j + D[i] - D[i+1])] = max(dp[i+2][max(0, j+D[i]-D[i+1])], dp[i][j] + 2);
        if(i == D.size() - 1 && j + D[i] >= 2200)
          ans = max(ans, dp[i][j] + 1);
      }
    }
    REP(j, 2200) if(dp[D.size()][j] > 0) ans = max(ans, dp[D.size()][j]);
    return ans;
  }
};

// BEGIN CUT HERE
int main() {
  TypoCoderDiv1 test;
  vector<int> D = {1000000000, 1000000000, 10000, 100000, 2202, 1};
  int X = 1000;
  cout << test.getmax(D, X) << endl;
}
// END CUT HERE
