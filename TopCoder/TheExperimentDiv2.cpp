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

class TheExperimentDiv2 {
public:
	vector <int> determineHumidity(vector <int> intensity, int L, vector <int> leftEnd) {
    vector<int> ans(leftEnd.size());
		for(int i = 0; i < leftEnd.size(); ++i) {
      for(int j = 0; j < L; ++j) {
        ans[i] += intensity[leftEnd[i] + j];
        intensity[leftEnd[i] + j] = 0;
      }
    }
    return ans;
	}
};
