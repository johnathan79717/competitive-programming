#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <climits>
using namespace std;

char T[100][100];
int n;
set<string> good;
map<string, int> ans;

void set_good(string &s, int r, int c) {
  if(r >= n || c >= n)
    return;
  string s2 = s + T[r][c];
  if(good.find(s2) == good.end())
    good.insert(s2);
  set_good(s2, r, c + 1);
  set_good(s2, r + 1, c);
}

int solve(string &s, int score) {
  if(ans.find(s) != ans.end())
    return ans[s];
  int ret;
  if(s.size() == 2 * n - 1) {
    return score;
  }
  if(s.size() % 2) {
    ret = INT_MAX;
    for(char c = 'a'; c <= 'z'; c++) {
      string s2 = s + c;
      int score2 = score;
      if(c == 'a')
        score2++;
      else if(c == 'b')
        score2--;
      if(good.find(s2) != good.end())
        ret = min(ret, solve(s2, score2));
    }
  } else {
    ret = -INT_MAX;
    for(char c = 'a'; c <= 'z'; c++) {
      string s2 = s + c;
      int score2 = score;
      if(c == 'a')
        score2++;
      else if(c == 'b')
        score2--;      if(good.find(s2) != good.end())
        ret = max(ret, solve(s2, score2));
    }
  }
  ans[s] = ret;
  return ret;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> T[i];
  string s;
  set_good(s, 0, 0);
  // cout << solve(s) << endl;
  if(solve(s, 0) > 0)
    cout << "FIRST" << endl;
  else if(solve(s, 0) < 0)
    cout << "SECOND" << endl;
  else
    cout << "DRAW" << endl;
  // s = string("abd");
  // cout << solve(s) << endl;
  // s = string("acd");
  // cout << solve(s) << endl;
  // s = string("ab");
  // cout << solve(s) << endl;
  // s = string("ac");
  // cout << solve(s) << endl;
  // s = string("a");
  // cout << solve(s) << endl;
}