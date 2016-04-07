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

class EelAndRabbit {
public:
  int getmax(vector <int> l, vector <int> t) {
    vector<int> point;
    for(int i = 0; i < l.size(); ++i) {
      point.push_back(t[i]);
      point.push_back(t[i] + l[i]);
    }
    vector<vector<int> > c(point.size());
    for(int i = 0; i < c.size(); ++i)
      for(int j = 0; j < l.size(); ++j)
        if(point[i] >= t[j] && point[i] <= t[j] + l[j])
          c[i].push_back(j);
    // for(int i = 0; i < c.size(); ++i) {
    //   for(int j = 0; j < c[i].size(); ++j)
    //     cout << c[i][j] << ' ';
    //   cout << endl;
    // }
    vector<int> best(50);
    int ans = 0;
    for(int i = 0; i < point.size(); ++i) {
      for(int j = 0; j < point.size(); ++j) {
        vector<int>::iterator it = set_union(c[i].begin(), c[i].end(), c[j].begin(), c[j].end(), best.begin());
        ans = max(ans, int(it - best.begin()));
        // cout << ptr - best << endl;
      }
    }
    return ans;
  }
};
