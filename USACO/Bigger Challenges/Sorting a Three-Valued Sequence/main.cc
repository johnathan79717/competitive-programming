/*
ID: johnath2
PROG: sort3
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
#define NAME "sort3"

using namespace std;
  
int N;
int a[1000], cnt[4], perm[4][4];

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", a + i);
    cnt[a[i]]++;
  }

  cnt[2] += cnt[1];

  for(int i = 0; i < cnt[1]; i++)
    perm[1][a[i]]++;
  for(int i = cnt[1]; i < cnt[2]; i++)
    perm[2][a[i]]++;
  for(int i = cnt[2]; i < N; i++)
    perm[3][a[i]]++;

  fprintf(stderr, "%d %d %d %d %d %d\n", perm[1][2], perm[2][1], perm[1][3], perm[3][1], perm[2][3], perm[3][2]);

  int ans = 0;
  ans += min(perm[1][2], perm[2][1]);
  ans += 2 * (max(perm[1][2], perm[2][1]) - ans);
  ans += min(perm[2][3], perm[3][2]);
  ans += min(perm[3][1], perm[1][3]);
  printf("%d\n", ans);

  return 0;
}