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

class UndoHistory {
public:
	int minPresses(vector <string> lines) {
		int ans = lines[0].size() + 1;
    for(int i = 1; i < lines.size(); ++i) {
      // cout << ans << endl;
      if(lines[i-1].size() <= lines[i].size()) {
        int k;
        for(k = 0; k < lines[i-1].size(); ++k)
          if(lines[i-1][k] != lines[i][k]) break;
        if(k == lines[i-1].size()) {
          ans += (lines[i].size() - lines[i-1].size() + 1);
          continue;
        }
      }
      int best = 0;
      for(int j = 0; j < i; ++j) {
        int k;
        for(k = 0; k < min(lines[i].size(), lines[j].size()); ++k)
          if(lines[i][k] != lines[j][k]) break;
        best = max(best, k);
      }
      ans += (3 + lines[i].size() - best);
    }
    return ans;
	}
};
