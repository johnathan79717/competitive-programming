/*
ID: johnath2
PROG: milk3
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
#define NAME "milk3"

using namespace std;

#ifdef STDIO
#include <iostream>
#else
  ifstream cin (NAME".in");
  ofstream cout (NAME".out");
#endif

bool visited[21][21];

int A, B, C;
vector<int> ans;

void dfs(int a, int b, int c) {
  if(visited[a][c]) return;
  visited[a][c] = true;
  if(a == 0)
    ans.push_back(c);
  dfs(max(a + b - B, 0), min(a + b, B), c);
  dfs(min(a + b, A), max(a + b - A, 0), c);
  dfs(max(a + c - C, 0), b, min(a + c, C));
  dfs(min(a + c, A), b, max(a + c - A, 0));
  dfs(a, max(b + c - C, 0), min(b + c, C));
  dfs(a, min(b + c, B), max(b + c - B, 0));
}

int main() {
  cin >> A >> B >> C;
  dfs(0, 0, C);
  sort(ans.begin(), ans.end());
  for(int i = 0; i < ans.size(); i++)
    cout << ans[i] << (i != ans.size() - 1 ? ' ' : '\n');
  return 0;
}