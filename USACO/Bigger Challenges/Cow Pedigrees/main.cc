/*
ID: johnath2
PROG: nocows
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
#define NAME "nocows"
#define all(v) (v).begin(), (v).end()
typedef long long ll;

using namespace std;
#define MAX_N 200
#define MAX_K 100

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

int N, K, exact[MAX_N + 1], leq[MAX_N + 1];

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  scanf("%d%d", &N, &K);
  exact[1] = 1;
  leq[1] = 1;
  for(int k = 2; k <= K; k++) {
    for(int i = N; i >= 0; i--) {
      exact[i] = 0;
      for(int j = 0; j < i; j++) {
        exact[i] = add(exact[i], mul(exact[j], leq[i-1-j]));
        exact[i] = add(exact[i], mul(leq[j], exact[i-1-j]));
        exact[i] = sub(exact[i], mul(exact[j], exact[i-1-j]));
      }
      leq[i] = add(leq[i], exact[i]);
    }
  }
  printf("%d\n", exact[N]);
  return 0;
}