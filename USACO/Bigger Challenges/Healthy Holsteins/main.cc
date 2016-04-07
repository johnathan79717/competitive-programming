/*
ID: johnath2
PROG: holstein
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
#define NAME "holstein"

using namespace std;
int feeds[15][25], G;
int V;
int req[25];

bool check(int i) {
  for(int j = 0; j < V; j++) {
    int sum = 0;
    for(int k = 0; k < G; k++)
      if((i >> k) & 1)
        sum += feeds[k][j];
    if(sum < req[j])
      return false;
  }
  return true;
}

int num_bits(int i) {
  int ans = 0;
  for(int k = 0; k < G; k++)
    if((i >> k) & 1)
      ans++;
  return ans;
}

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  scanf("%d", &V);
  for(int i = 0; i < V; i++)
    scanf("%d", req + i);
  scanf("%d", &G);
  for(int i = 0; i < G; i++)
    for(int j = 0; j < V; j++)
      scanf("%d", feeds[i] + j);
  int bestb = INT_MAX, best;
  for(int i = 0; i < (1 << G); i++) {
    int nb = num_bits(i);
    if(nb < bestb && check(i)) {
      bestb = nb;
      best = i;
    }
  }
  printf("%d", bestb);
  for(int k = 0; k < G; k++)
    if((best >> k) & 1)
      printf(" %d", k+1);
  puts("");
  return 0;
}