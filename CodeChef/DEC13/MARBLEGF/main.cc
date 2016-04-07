#include <cstdio>
#define MAX_N 1000005
long long bit[MAX_N + 1];
int n;

long long sum(int i) {
  long long s = 0;
  while(i > 0) {
    s += bit[i];
    i &= i - 1;
  }
  return s;
}

void add(int i, int x) {
  while(i <= n) {
    bit[i] += x;
    i += i & -i;
  }
}

int main() {
  int Q;
  scanf("%d%d", &n, &Q);
  for(int i = 1; i <= n; i++) {
    int A;
    scanf("%d", &A);
    add(i, A);
  }
  while(Q--) {
    char action;
    int i, j;
    scanf("\n%c%d%d", &action, &i, &j);
    switch(action) {
      case 'S': printf("%lld\n", sum(j+1) - sum(i)); break;
      case 'G': add(i+1, j); break;
      default: add(i+1, -j); break;
    }
  }
}