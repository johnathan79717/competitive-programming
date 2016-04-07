/*
ID: johnath2
PROG: packrec
LANG: C++
*/
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#define NAME "packrec"
using namespace std;
#ifdef STDIO
#include <iostream>
#else
  ifstream cin (NAME".in");
  ofstream cout (NAME".out");
#endif

pair<int, int> minmax(int a, int b) {
  return make_pair(min(a, b), max(a, b));
}

int max4(int x, int y, int z, int w) {
  return max(max(x, y), max(z, w));
}

int max3(int x, int y, int z) {
  return max(x, max(y, z));
}

int area = INT_MAX;
vector<pair<int, int> > ans;

int s[4][2];

void check(int a, int b) {
  if(a == 6 && b == 6) {
    cout << s[0][0] << ' ' << s[0][1] << endl;
    cout << s[1][0] << ' ' << s[1][1] << endl;
    cout << s[2][0] << ' ' << s[2][1] << endl;
    cout << s[3][0] << ' ' << s[3][1] << endl;
  }
  if(a * b < area) {
    ans.clear();
    area = a * b;
  }
  if(a * b == area)
    ans.push_back(minmax(a, b));
}


int main() {
  int l[4][2];
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 2; j++)
      cin >> l[i][j];

  
  int p[] = {0, 1, 2, 3};
  do {
    for(int b = 0; b < (1<<4); b++) {
      for(int i = 0; i < 4; i++)
        for(int j = 0; j < 2; j++)
          s[i][j] = l[p[i]][j ^ ((b>>i) & 1)];

      check(max4(s[0][0], s[1][0], s[2][0], s[3][0]), s[0][1] + s[1][1] + s[2][1] + s[3][1]);
      check(s[0][0] + max3(s[1][0], s[2][0], s[3][0]), max(s[0][1], s[1][1] + s[2][1] + s[3][1]));
      check(max(s[0][0] + max(s[1][0], s[2][0]), s[3][0]), max(s[0][1], s[1][1] + s[2][1]) + s[3][1]);
      check(max3(s[0][0], s[1][0]+s[2][0], s[3][0]), s[0][1] + max(s[1][1], s[2][1]) + s[3][1]);
      check(max3(s[0][0]+s[1][0], s[2][0], s[3][0]), max(s[0][1], s[1][1]) + s[2][1] + s[3][1]);
      if(s[0][1] >= s[1][1] && s[0][0] <= s[2][0])
        check(max(s[0][0]+s[1][0], s[2][0]+s[3][0]), max(s[0][1]+s[2][1],s[1][1] + s[3][1]));
    }
  } while(next_permutation(p, p+4));
  
  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());


  cout << area << endl;
  for(int i = 0; i < ans.size(); i++)
    cout << ans[i].first << ' ' << ans[i].second << endl;
  return 0;
}