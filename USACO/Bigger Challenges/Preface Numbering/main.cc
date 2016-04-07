/*
ID: johnath2
PROG: preface
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
#define NAME "preface"

using namespace std;

int N, dp[3500][7];
char c[] = "IVXLCDM";

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    if(i >= 1000) {
      memcpy(dp[i], dp[i % 1000], sizeof dp[i]);
      dp[i][6] += i / 1000;
    } else if(i >= 900) {
      memcpy(dp[i], dp[i - 900], sizeof dp[i]);
      dp[i][6]++;
      dp[i][4]++;
    } else if(i >= 500) {
      memcpy(dp[i], dp[i - 500], sizeof dp[i]);
      dp[i][5]++;
    } else if(i >= 100) {
      memcpy(dp[i], dp[i % 100], sizeof dp[i]);
      if(i / 100 >= 4) {
        dp[i][4]++;
        dp[i][5]++;
      } else
        dp[i][4] += i / 100;
    } else if(i >= 90) {
      memcpy(dp[i], dp[i - 90], sizeof dp[i]);
      dp[i][2]++;
      dp[i][4]++;
    } else if(i >= 50) {
      memcpy(dp[i], dp[i - 50], sizeof dp[i]);
      dp[i][3]++;
    } else if(i >= 10) {
      memcpy(dp[i], dp[i % 10], sizeof dp[i]);
      if(i / 10 >= 4) {
        dp[i][2]++;
        dp[i][3]++;
      } else {
        dp[i][2] += i / 10;
      }
    } else if(i == 9) {
      dp[i][2]++;
      dp[i][0]++;
    } else if(i >= 5) {
      dp[i][1]++;
      dp[i][0] = i - 5;
    } else if(i == 4) {
      dp[i][1]++;
      dp[i][0]++;
    } else {
      dp[i][0] = i;
    }
  }
  for(int i = 0; i < 7; i++) {
    int sum = 0;
    for(int j = 1; j <= N; j++)
      sum += dp[j][i];
    if(sum > 0)
      printf("%c %d\n", c[i], sum);
  }
  
  return 0;
}