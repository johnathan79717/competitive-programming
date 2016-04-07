#include <stdio.h>

int x[1000], y[1000];
int n;

int check(int a, int b) {
    int i;
    for (i = 0; i < n; ++i)
        if (x[i] == a && y[i] == b)
            return 1;
    return 0;
}

int main() {
    int i, j;
    while (scanf("%d", &n) && n) {
        int count = 0;
        for (i = 0; i < n; ++i)
            scanf("%d %d", x+i, y+i);
        for (i = 0; i < n; ++i) {
            for (j = i+1; j < n; ++j) {
                int vectorx = x[j]-x[i];
                int vectory = y[j]-y[i];
                if (check(x[i]-vectory, y[i]+vectorx) && check(x[j]-vectory, y[j]+vectorx))
                    ++count;
                if (check(x[i]+vectory, y[i]-vectorx) && check(x[j]+vectory, y[j]-vectorx))
                    ++count;
            }
        }
        printf("%d\n", count/4);
    }
}

