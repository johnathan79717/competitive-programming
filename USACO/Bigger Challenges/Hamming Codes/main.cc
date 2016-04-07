/*
ID: johnath2
PROG: hamming
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
#define NAME "hamming"

using namespace std;

int N, B, D;
bool used[1<<9];

int bitCount(int n) {
  int ans = 0;
  for(int k = 0; k < B; k++)
    if((n >> k) & 1)
      ans++;
  return ans;
}

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  scanf("%d%d%d", &N, &B, &D);
  vector<int> diff;
  for(int i = 0; i < (1 << B); i++)
    if(bitCount(i) < D)
      diff.push_back(i);
  int u = 0;
  for(int i = 0; i < N; i++) {
    while(used[u]) u++;
    printf("%d", u);
    printf("%c", i == N-1 || i % 10 == 9 ? '\n' : ' ');
    for(int j = 0; j < diff.size(); j++)
      used[u ^ diff[j]] = true;
  }
  return 0;
}