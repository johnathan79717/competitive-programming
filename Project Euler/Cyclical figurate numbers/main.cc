#include <iostream>
#include <vector>
using namespace std;

vector<int> edge[6][100];
int perm[] = {0, 1, 2, 3, 4, 5};

bool dfs(int level, int n, int start) {
  if(level == 6) {
    if(n == start)
      return true;
    else
      return false;
  }
  for(auto to : edge[perm[level]][n]) {
    if(dfs(level + 1, to, start)) {
      cout << n << endl;
      return true;
    }
  }
  return false;
}

int main() {
  for(int type = 0; type < 6; type++) {
    for(int n = 1;; n++) {
      int p;
      switch(type) {
        case 0: p = n * (n+1) / 2; break;
        case 1: p = n * n; break;
        case 2: p = n * (3*n-1) / 2; break;
        case 3: p = n * (2*n-1); break;
        case 4: p = n * (5*n-3) / 2; break;
        default: p = n * (3*n-2); break;
      }
      if(p < 1000) continue;
      if(p > 9999) break;
      int curr = p / 100, next = p % 100;
      if(next < 10) continue;
      edge[type][curr].push_back(next);
    }
  }

  do {
    for(int i = 10; i < 100; i++)
      dfs(0, i, i);
  } while(next_permutation(perm + 1, perm + 6));
}