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

class BinPacking {
public:
	int minBins(vector <int> item) {
		sort(item.begin(), item.end());
    int n100 = 0;
    while(!item.empty() && item[0] == 100) {
      n100++;
      item.erase(item.begin());
    }
    int l = 0, r = item.size() - 1, ans = 0;
    while(l < r) {
      if(item[l] + item[r] > 300) {
        ans++;
        if(100 + item[r] <= 300)
          n100--;
        r--;
      } else {
        ans++;
        l++;
        r--;
      }
    }
    if(l == r) {
      ans++;
      if(100 + item[l] <= 300)
        n100--;
    }
    if(n100 > 0)
      ans += (n100-1) / 3 + 1;
    return ans;
	}
};
