/*
ID: johnath2
PROG: runround
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
#define NAME "runround"
typedef long long ll;
using namespace std;
#define all(v) (v).begin(), (v).end()

int perm[9];
bool used[10];
vector<ll> ans;

bool runaround(int n) {
  if(n == 0) return false;
  bool visited[10];
  memset(visited, false, sizeof visited);
  int d = 0;
  for(int i = 0; i < n; i++) {
    if(visited[d])
      return false;
    visited[d] = true;
    d = (d + perm[d]) % n;
  }
  return d == 0;
}

void dfs(ll num, int n) {
  if(runaround(n))
    ans.push_back(num);
  if(n < 9)
    for(int i = 1; i <= 9; i++)
      if(!used[i]) {
        used[i] = true;
        perm[n] = i;
        dfs(num * 10 + i, n + 1);
        used[i] = false;
      }
}

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  dfs(0, 0);
  sort(all(ans));
  int M;
  scanf("%d", &M);
  printf("%lld\n", *upper_bound(all(ans), M));
  // perm[0] = 8; perm[1] = 1; perm[2] = 3; perm[3] = 6; perm[4] = 2;
  // printf("%d\n", runaround(5));
  return 0;
}