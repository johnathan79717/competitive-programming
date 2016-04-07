#include <algorithm>
#include <cstdio>
#include <climits>

using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int N, M;
    scanf("%d%d", &N, &M);
    pair<int, int> p[20001];
    for(int i = 0; i < M; ++i) {
      int w, x, y, z;
      scanf("%d%d%d%d", &w, &x, &y, &z);
      if(w == 1) { // add
        p[i] = make_pair(x, z);
        p[i+M] = make_pair(y+1, -z);
      } else { // subtract
        p[i] = make_pair(x, -z);
        p[i+M] = make_pair(y+1, z);
      }
    }
    sort(p, p+M+M);
    int minimum = INT_MAX, maximum = -INT_MAX;
    int inc = 0, right = 1, left;
    for(int i = 0; i < M+M; ++i) {
      left = right;
      right = p[i].first;
      if(left < right) {
        minimum = min(minimum, left + inc);
        maximum = max(maximum, right - 1 + inc);
      }
      inc += p[i].second;
    }
    if(right <= N) {
      minimum = min(minimum, right + inc);
      maximum = max(maximum, N + inc);
    }
    // printf("%d\n", maximum);
    // printf("%d\n", minimum);
    printf("%d\n", maximum - minimum);
  }
}