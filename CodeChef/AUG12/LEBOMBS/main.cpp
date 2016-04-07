#include <cstdio>
#include <cstring>

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int N;
    char S[1001];
    scanf("%d%s", &N, S);
    if(N == 1) { printf("%d\n", 1-(S[0]-'0')); continue; }
    int explode[1000];
    memset(explode, 0, sizeof(explode));
    if(S[0] == '1') explode[0] = explode[1] = 1;
    for(int i = 1; i < N-1; ++i)
      if(S[i] == '1') explode[i] = explode[i-1] = explode[i+1] = 1;
    if(S[N-1] == '1') explode[N-2] = explode[N-1] = 1;
    int ans = 0;
    for(int i = 0; i < N; ++i) ans += explode[i];
    printf("%d\n", N - ans);
  } 
}