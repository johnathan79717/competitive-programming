/*
ID: johnath2
PROG: money
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
#define NAME "money"
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

#define MAX_V 25
#define MAX_N 10000
int V, N;
ll dp[MAX_N + 1];

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  scanf("%d%d", &V, &N);
  dp[0] = 1;
  while(V--) {
    int c;
    scanf("%d", &c);
    for(int i = c; i <= N; i++)
      dp[i] += dp[i-c];
  }
  printf("%lld\n", dp[N]);
  return 0;
}