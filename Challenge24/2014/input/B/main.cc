#include <cstdio>

int m[1000][1000];

int main() {
  int N, E;
  scanf("%d%d", &N, &E);
  for(int i = 0; i < E; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    m[u][u]++; m[v][v]++;
    m[u][v] = m[v][u] = -1;
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      printf("%d%c", m[i][j], j == N-1 ? '\n' : ',');
    }
  }
}