#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
  int N, T[250][250];

  scanf("%d", &N);

  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      scanf("%d", T[i]+j);

  for(int k = 0; k < N; ++k)
    for(int i = 0; i < N; ++i)
      for(int j = 0; j < N; ++j)
        T[i][j] = min(T[i][j], T[i][k] + T[k][j]);

  int M;
  scanf("%d", &M);
  for(int i = 0; i < M; ++i) {
    int S, G, D;
    scanf("%d%d%d", &S, &G, &D);
    printf("%d %d\n", T[S][G] + T[G][D], T[S][G] + T[G][D] - T[S][D]);
  }
}