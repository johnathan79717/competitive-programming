#include <stdio.h>
#include <math.h>

int main() {
    int a;
    scanf("%d", &a);
    while (a) {
        double c = (sqrt((double)a*8 + 1) - 1) / 2;
        int n = (int)c;
        int b = (n+1)*n/2;
        printf("%d %d\n", a, (n+1)*n*(2*n+1)/6+(n+1)*(a-b));
        scanf("%d", &a);
    }
}

