/*
ID: johnath2
PROG: prefix
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
#define NAME "prefix"
#define all(v) (v).begin(), (v).end()
typedef long long ll;

using namespace std;

char *isPrefix(char *p, char*s) {
  while(*p)
    if(*p++ != *s++)
      return 0;
  return s;
}

char prim[201][11];
int P = -1;
char S[200001];
int dp[200001], l;

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  do {
    scanf("%s", prim[++P]);
  } while(prim[P][0] != '.');
  char *s = S;
  int result;
  do {
    result = scanf("%s", s);
    s = s + strlen(s);
  } while(result != EOF);
  int l = strlen(S);
  dp[l] = l;
  for(int i = l-1; i >= 0; i--) {
    dp[i] = i;
    for(int j = 0; j < P; j++) {
      char *p = isPrefix(prim[j], S+i);
      if(p)
        dp[i] = max(dp[i], dp[p - S]);
    }
  }
  printf("%d\n", dp[0]);
  return 0;
}