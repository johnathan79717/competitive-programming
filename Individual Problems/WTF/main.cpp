#include <cstdio>

int main() {
  int tux;
  scanf("%d", &tux);
  int foo = 0, bar = 0, baz = 0, quz = 1;
  int pur;
  for(int i = 0; i < tux; i++) {
    scanf("%d", &pur);
    foo = foo + i + pur;
    bar = bar + i + 1;
    baz = foo;
    quz = bar;
  }
  printf("%f\n", float(baz) / quz);
}