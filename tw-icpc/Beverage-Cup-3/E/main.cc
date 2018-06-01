#include <cstdio>
#include <cmath>
#include <tgmath.h>

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    long double n = N, m = M;
    printf("%.16LF\n", n * (1-powl(1 - 1 / n, m)));
}
