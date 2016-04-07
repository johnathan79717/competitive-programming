#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <sstream>
#include <queue>
#include <climits>
typedef long long ll;
using namespace std;

class AstronomicalRecords {
public:

  int lcs(vector<ll> &a, vector<ll> &b) {
    int dp[51][51];
    memset(dp, 0, sizeof(dp));

    // cout << a.size() << ' ' << b.size() << endl;

    for(int i = 1; i < a.size(); i++)
      for(int j = 1; j < b.size(); j++)
        if(a[i] == b[j])
          dp[i][j] = dp[i-1][j-1] + 1;
        else
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    return dp[a.size() - 1][b.size() - 1];
  }

	int minimalPlanets(vector <int> A, vector <int> B) {
    int ans = -INT_MAX;
    for(int i = 0; i < A.size(); i++) {
      for(int j = 0; j < B.size(); j++) {
        vector<ll> a, b;
        a.push_back(0);
        b.push_back(0);
        for(int k = 0; k < A.size(); k++)
          a.push_back(ll(A[k]) * ll(B[j]));
        for(int k = 0; k < B.size(); k++)
          b.push_back(ll(B[k]) * ll(A[i]));
        ans = max(ans, lcs(a, b));
      }
    }
    return A.size() + B.size() - ans;
	}
};
