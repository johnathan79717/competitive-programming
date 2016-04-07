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

class LittleElephantAndBalls {
public:
	int getNumber(string S) {
		int r = 0, g = 0, b = 0, ans = 0;
    for(int i = 0; i < S.size(); i++) {
      ans += (r + g + b);
      if(r < 2 && S[i] == 'R')
        r++;
      else if(g < 2 && S[i] == 'G')
        g++;
      else if(b < 2 && S[i] == 'B')
        b++;
    }
    return ans;
	}
};
