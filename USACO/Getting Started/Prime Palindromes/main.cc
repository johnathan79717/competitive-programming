/*
ID: johnath2
PROG: pprime
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
#include <iostream>
#include <cstdio>
#define NAME "pprime"

using namespace std;

vector<int> ans;
vector<int> primes;
int a, b;

void add(int p) {
  if(a <= p && p <= b) {
    for(int i = 0; i < primes.size() && primes[i] < p; i++)
      if(p % primes[i] == 0)
        return;
    ans.push_back(p);
  }
}

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  scanf("%d%d", &a, &b);
  bool isprime[10000];
  memset(isprime, true, sizeof isprime);
  for(int i = 2; i < 10000; i++)
    if(isprime[i]) {
      primes.push_back(i);
      for(int j = i+i; j < 10000; j+=i)
        isprime[j] = false;
    }
  for(int d1 = 1; d1 <= 9; d1+=2) {
    add(d1);
    add(d1 * 11);
    for(int d2 = 0; d2 <= 9; d2++) {
      add(d1 * 101 + d2 * 10);
      add(d1 * 1001 + d2 * 110);
      for(int d3 = 0; d3 <= 9; d3++) {
        add(d1 * 10001 + d2 * 1010 + d3 * 100);
        add(d1 * 100001 + d2 * 10010 + d3 * 1100);
        for(int d4 = 0; d4 <= 9; d4++) {
          add(d1 * 1000001 + d2 * 100010 + d3 * 10100 + d4 * 1000);
          add(d1 * 10000001 + d2 * 1000010 + d3 * 100100 + d4 * 11000);
        }
      }
    }
  }
  sort(ans.begin(), ans.end());
  for(int i = 0; i < ans.size(); i++)
    printf("%d\n", ans[i]);
  return 0;
}