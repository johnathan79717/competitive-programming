/*
ID: johnath2
PROG: frac1
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
#define NAME "frac1"

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
  return a.first * b.second < b.first * a.second;
}

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  int N;
  scanf("%d", &N);
  vector<pair<int, int> > ans;
  for(int i = 1; i <= N; i++)
    for(int j = 0; j <= i; j++)
      if(gcd(i, j) == 1)
        ans.push_back(make_pair(j, i));
  sort(ans.begin(), ans.end(), compare);
  for(int i = 0; i < ans.size(); i++)
    printf("%d/%d\n", ans[i].first, ans[i].second);
  return 0;
}