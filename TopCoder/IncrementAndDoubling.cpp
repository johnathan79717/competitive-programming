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

class IncrementAndDoubling {
public:
  int numOnes(int n) {
    if(n == 0)
      return 0;
    return numOnes(n / 2) + ((n % 2) ? 1 : 0);
  }

  int numDigits(int n) {
    if(n == 0)
      return 0;
    return numDigits(n / 2) + 1;
  }

	int getMin(vector <int> desiredArray) {
    int ans = 0;
    int maxD = 0;
		for(int i = 0; i < desiredArray.size(); i++) {
      maxD = max(maxD, numDigits(desiredArray[i]));
      ans += numOnes(desiredArray[i]);
    }
    ans += (maxD - 1);
    return (ans < 0) ? 0 : ans;
	}
};
