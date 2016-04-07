#include <cstdio>

using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int N;
    int A[100];
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
      scanf("%d", A + i);
    int K;
    scanf("%d", &K);
    K--;
    int ans = 0;
    for(int i = 0; i < N; i++)
      if(A[i] <= A[K])
        ans++;
    printf("%d\n", ans);
  }
}