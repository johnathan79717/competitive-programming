/*
ID: johnath2
PROG: castle
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
#define NAME "castle"

using namespace std;

int adj[50][50];
bool visited[50][50];
int comp[50][50];
int M, N;
int size[2501];

void dfs(int i, int j, int c) {
  if(visited[i][j])
    return;
  visited[i][j] = true;
  comp[i][j] = c;
  if(!(adj[i][j] & 1))
    dfs(i, j - 1, c);
  if(!(adj[i][j] & 2))
    dfs(i - 1, j, c);
  if(!(adj[i][j] & 4))
    dfs(i, j + 1, c);
  if(!(adj[i][j] & 8))
    dfs(i + 1, j, c);
}

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  scanf("%d%d", &M, &N);
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      scanf("%d", adj[i]+j);
  int c = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(!visited[i][j])
        dfs(i, j, c++);
      size[comp[i][j]]++;
      fprintf(stderr, "%3d", comp[i][j]);
    }
    fprintf(stderr, "\n");
  }
  int largest = INT_MIN, best = INT_MIN, best_i, best_j;
  char best_d;
  for(int j = 0; j < M; j++)
    for(int i = N-1; i >= 0; i--) {
      int c1 = comp[i][j];
      largest = max(largest, size[c1]);
      if(i > 0 && adj[i][j] & 2) {
        int c2 = comp[i-1][j];
        if(c1 != c2 && size[c1] + size[c2] > best) {
          best = size[c1] + size[c2];
          best_j = j;
          best_i = i;
          best_d = 'N';   
        }
      }
      if(j < M - 1 && adj[i][j] & 4) {
        int c2 = comp[i][j+1];
        if(c1 != c2 && size[c1] + size[c2] > best) {
          best = size[c1] + size[c2];
          best_j = j;
          best_i = i;
          best_d = 'E';
        }
      }
    }
  printf("%d\n%d\n%d\n%d %d %c\n", c, largest, best, best_i+1, best_j+1, best_d);
  return 0;
}