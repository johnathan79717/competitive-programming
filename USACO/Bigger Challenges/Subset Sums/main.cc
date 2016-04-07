/*
ID: johnath2
PROG: subset
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
#define NAME "subset"

using namespace std;
int N;
long long dp[800];
int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  scanf("%d", &N);
  if(N * (N+1) / 2 % 2)
    printf("0\n");
  else {
    for(int i = 1; i <= N; i++) {
      for(int j = 799; j >= 0; j--)
        if(dp[j])
          dp[i+j] += dp[j];
      dp[i]++;
    }
    printf("%lld\n", dp[N * (N+1) / 4] / 2);
  }

  return 0;
}