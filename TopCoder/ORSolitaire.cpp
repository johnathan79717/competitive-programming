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

class ORSolitaire {
public:
	int getMinimum(vector <int> numbers, int goal) {
    int ans = numbers.size();
		for(int i = 1; i; i <<= 1) {
      if(goal & i) {
        int cnt = 0;
        for(auto n : numbers) {
          if((n | goal) != goal)
            continue;
          if(n & i)
            cnt++;
        }
        ans = min(ans, cnt);
      }
    }
    return ans;
	}
};
