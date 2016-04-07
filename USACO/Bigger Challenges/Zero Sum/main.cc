/*
ID: johnath2
PROG: zerosum
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
#include <cstdio>
#include <iostream>
#define NAME "zerosum"
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
typedef long long ll;

using namespace std;

const int MOD = 9901;
int add(int a, int b) {
  int ans = a + b;
  return ans < MOD ? ans : ans - MOD;
}
int sub(int a, int b) {
  int ans = a - b;
  return ans < 0 ? ans + MOD : ans;
}
int mul(int a, int b) {
  return (ll)a * b % MOD;
}

int N;
char sign[10];
string seq = "1 2 3 4 5 6 7 8 9";
vector<string> ans;

void dfs(int sum, int n) {
  if(n > N) {
    if(sum == 0)
      ans.push_back(seq);
    return;
  }
  int first = 0;
  for(int i = n; i <= N; i++) {
    first = 10 * first + i;
    if(i > 1)
      seq[2*i-3] = ' ';
    if(n == 1)
      dfs(first, i + 1);
    else {
      seq[2*n-3] = '+';
      dfs(sum + first, i + 1);
      seq[2*n-3] = '-';
      dfs(sum - first, i + 1);
    }
  }
}

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  cin >> N;
  seq = seq.substr(0, 2 * N - 1);
  dfs(0, 1);
  sort(ALL(ans));
  FOR(it, ans)
    cout << *it << endl;
  return 0;
}