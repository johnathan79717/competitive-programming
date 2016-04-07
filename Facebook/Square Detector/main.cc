#include <cstdio>
#include <cstring>
char array[21][21];

bool solve() {
  int N;
  scanf("%d", &N);
  memset(array, 0, sizeof(array));
  for(int i = 0; i < N; i++)
    scanf("%s", array[i]);
  int cnt = 0;
  int ii = -1;
  int jj = -1;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      if(array[i][j] == '#') {
        cnt++;
        if(ii < 0 && jj < 0) {
          ii = i;
          jj = j;
        }
      }
  int s;
  for(s = 1; s <= 20; s++)
    if(s * s == cnt)
      break;
  if(s != 20) return false;
  for(int i = 0; i < s; i++)
    for(int j = 0; j < s; j++)
      if(array[ii+i][jj+j] != '#')
        return false;
  return true;
}

int main() {
  int T, cas = 1;
  scanf("%d", &T);
  for(int i = 1; i <= T; i++) {
    printf("Case #%d: ", i);
    if(solve()) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
}