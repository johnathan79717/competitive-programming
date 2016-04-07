#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

bool is_subseq(char *a, char *b) {
  int j = 0;
  for(int i = 0; b[i] != 0; ++i) {
    if(b[i] == a[j])
      ++j;
    if(a[j] == 0)
      return true;
  }
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    char M[25001], W[25001];
    scanf("%s%s", M, W);
    char *longer, *shorter;
    if(strlen(M) <= strlen(W)) {
      longer = W;
      shorter = M;
    }
    else {
      longer = M;
      shorter = W;
    }
    if(is_subseq(shorter, longer))
      puts("YES");
    else
      puts("NO");
  }
}