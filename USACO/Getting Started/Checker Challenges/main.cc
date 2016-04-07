/*
ID: johnath2
PROG: checker
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
#define NAME "checker"

using namespace std;

int N;
bool used[13], diag1[26], diag2[26];
int ans;
int perm[13];

void dfs(int n) {
  if(n == N) {
    if(ans < 3)
      for(int i = 0; i < n; i++)
        printf("%d%c", 1+perm[i], i == n-1 ? '\n' : ' ');
    ans++;
  }
  else {
    for(int i = 0; i < N; i++)
      if(!used[i] && !diag1[i+n] && !diag2[i-n+N]) {
        perm[n] = i;
        diag1[i+n] = true;
        used[i] = true;
        diag2[i-n+N] = true;
        dfs(n+1);
        used[i] = false;
        diag2[i-n+N] = false;
        diag1[i+n] = false;
      }
  }
}

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  scanf("%d", &N);
  dfs(0);
  printf("%d\n", ans);
  return 0;
}