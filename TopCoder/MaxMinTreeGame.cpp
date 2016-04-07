#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <deque>
#include <climits>
#include <set>
#include <vector>
#include <functional>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <list>
using namespace std;
#define MS0(x) memset(x,0,sizeof(x))
typedef long long LL;

class MaxMinTreeGame {
public:
  int findend(vector <int> edges, vector <int> costs) {
    int deg[51], N = costs.size();
    int ans = INT_MIN;
    MS0(deg);
    for(int i = 0; i < edges.size(); i++) {
      deg[i+1]++;
      deg[edges[i]]++;
    }
    for(int i = 0; i < N; i++) {
      if(deg[i] == 1)
        ans = max(ans, costs[i]);
    }
    return ans;
  }
};

// BEGIN CUT HERE
int main() {	
  MaxMinTreeGame test;

  cout << test.findend() << endl;
}
// END CUT HERE
