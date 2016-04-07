/*
ID: johnath2
PROG: sprime
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
#define NAME "sprime"

using namespace std;

#include <cstring>
#include <vector>
using namespace std;
vector<int> primes;

void genPrimes() {
  bool isprime[10000];
  memset(isprime, true, sizeof isprime);
  for(int i = 2; i < 10000; i++)
    if(isprime[i]) {
      primes.push_back(i);
      for(int j = i+i; j < 10000; j+=i)
        isprime[j] = false;
    }
}

bool isprime(int n) {
  for(int i = 0; i < primes[i] && primes[i] < n; i++)
    if(n % primes[i] == 0)
      return false;
  return true;
}

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  int N;
  scanf("%d", &N);
  genPrimes();
  vector<int> dp[2];
  dp[0].push_back(2);
  dp[0].push_back(3);
  dp[0].push_back(5);
  dp[0].push_back(7);
  for(int i = 1; i < N; i++) {
    vector<int> &ans = dp[i%2], &prev = dp[1-i%2];
    ans.clear();
    for(int j = 0; j < prev.size(); j++)
      for(int d = 1; d <= 9; d+=2)
        if(isprime(prev[j]*10+d))
          ans.push_back(prev[j]*10+d);
  }
  for(int i = 0; i < dp[1-N%2].size(); i++)
    printf("%d\n", dp[1-N%2][i]);
  return 0;
}