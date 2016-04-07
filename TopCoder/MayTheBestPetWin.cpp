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

using namespace std;

class MayTheBestPetWin {
public:
	int calc(vector <int> A, vector <int> B) {
    bool dp[1000001];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    int sum = 0;
    int diff = 0;
    for(int i = 0; i < A.size(); ++i) {
      int s = A[i] + B[i];
      sum += s;
      diff += (B[i] - A[i]);
      for(int j = 1000000 - s; j >= 0; --j) {
        if(dp[j])
          dp[j + s] = true;
      }
    }
    int half = sum / 2;
    while(!dp[half]) --half;
    return (diff + sum - half - half) / 2;
	}
};
