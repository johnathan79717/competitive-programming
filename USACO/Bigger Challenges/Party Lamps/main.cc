/*
ID: johnath2
PROG: lamps
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
#define NAME "lamps"
#define all(v) (v).begin(), (v).end()
typedef long long ll;

using namespace std;

int N, C, bits[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
vector<int> cand;
bool impossible[16];

void check(int b) {
  while(true) {
    int lamp;
    scanf("%d", &lamp);
    if(lamp < 0) break;
    for(int i = 0; i < cand.size(); i++) {
      if(impossible[i]) continue;
      int state = 1;
      if(cand[i] & 1)
        state ^= 1;
      if((cand[i] & 2) && lamp % 2 == 1)
        state ^= 1;
      if((cand[i] & 4) && lamp % 2 == 0)
        state ^= 1;
      if((cand[i] & 8) && lamp % 3 == 1)
        state ^= 1;
      if(state != b)
        impossible[i] = true;
    }
  }  
}

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  scanf("%d%d", &N, &C);

  for(int i = 0; i < 16; i++)
    if(bits[i] % 2 == C % 2 && bits[i] <= C)
      cand.push_back(i);

  check(1);
  check(0);

  vector<int> ans;
  for(int i = 0; i < cand.size(); i++)
    if(!impossible[i]) {
      int state = 0b111111;
      if(cand[i] & 1)
        state ^= 0b111111;
      if(cand[i] & 2)
        state ^= 0b101010;
      if(cand[i] & 4)
        state ^= 0b010101;
      if(cand[i] & 8)
        state ^= 0b100100;
      ans.push_back(state);
    }

  if(ans.empty())
    puts("IMPOSSIBLE");
  else {
    sort(all(ans));
    for(int i = 0; i < ans.size(); i++) {
      for(int j = 0; j < N; j++)
        printf("%d", (ans[i] >> (5 - j % 6)) & 1);
      puts("");
    }
  }

  return 0;
}