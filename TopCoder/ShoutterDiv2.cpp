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

class ShoutterDiv2 {
public:
	int count(vector <int> s, vector <int> t) {
    int ans = 0;
		for(int i = 0; i < s.size(); ++i) {
      for(int j = 0; j < i; ++j) {
        if(s[i] <= t[j] && s[j] <= t[i])
          ++ans;
        // cout << s[i] << ' ' << s[j] << ' ' << t[i] << ' ' << t[j] << endl;
      }
    }
    return ans;
	}
};
