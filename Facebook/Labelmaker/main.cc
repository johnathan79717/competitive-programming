#include <cstdio>
#include <cstring>
typedef long long ll;

char L[30];
ll N;

void solve() {
  ll num = 1;
  N--;
  int l = strlen(L), digits = 1;
  while(N / num >= l) {
    num *= l;
    N -= num;
    digits++;
  }
  for(int i = 0; i < digits; i++) {
    printf("%c", L[N / num]);
    fprintf(stderr, "%c", L[N / num]);
    N %= num;
    num /= l;
  }
  puts("");
  fputs("\n", stderr);
}

int main() {
  int T, cas = 1;
  scanf("%d", &T);
  while(T--) {
    scanf("%s%lld", L, &N);
    printf("Case #%d: ", cas++);
    solve();
  }
}