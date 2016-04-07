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

class RaiseThisBarn {
public:
	int calc(string str) {
    int cnt = 0;
		for(int i = 0; i < str.size(); ++i) {
      if(str[i] == 'c')
        cnt++;
    }
    if(cnt % 2)
      return 0;
    cnt /= 2;
    int ans = 0;
    for(int i = 0; i < str.size()-1; ++i) {
      if(str[i] == 'c')
        cnt--;
      if(cnt == 0)
        ans++;
    }
    return ans;
	}
};
