/*
ID: johnath2
PROG: ariprog
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
#define NAME "ariprog"

using namespace std;

#ifdef STDIO
#include <iostream>
#else
  ifstream cin (NAME".in");
  ofstream cout (NAME".out");
#endif

bool mark[125001];
int N, M, MAX;

bool check(int a, int b) {
  a += (b << 1);
  for(int i = 2; i < N; i++) {
    if(a > MAX || !mark[a])
      return false;
    a += b;
  }
  return true;
}

int main() {
  cin >> N >> M;
  MAX = 2*M*M;
  for(int p = 0; p <= M; p++)
    for(int q = 0; q <= p; q++)
      mark[p*p+q*q] = true;

  vector<pair<int, int> > ans;

  for(int a = 0; a <= MAX; a++) {
    if(!mark[a]) continue;
    int d = (N > 3) ? 4 : 1;
    for(int b = a+d; b <= MAX; b+=d) {
      if(!mark[b]) continue;
      int final = a + (N-1) * (b-a);
      if(final > MAX || !mark[final])
        continue;
      if(check(a, b - a))
        ans.push_back(make_pair(b-a, a));
    }
  }
  if(ans.empty())
    cout << "NONE" << endl;
  else {
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
      cout << ans[i].second << ' ' << ans[i].first << endl;
  }
  return 0;
}