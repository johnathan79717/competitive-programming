#include <stdlib.h>
#include <stdio.h>

int main() {
    int t, T;
    scanf("%d", &T);
    for (t = 0; t < T; ++t) {
        int i, N;
        int LIS[1000];
        scanf("%d", &N);
        long long seq[1000];
        for (i = 0; i < N; ++i) {
            scanf("%lld", seq+i);
            LIS[i] = 1;
        }
        int j;
        for (i = 0; i < N; ++i) {
            for (j = 0; j < i; ++j) {
                if (seq[j] < seq[i]) {
                    LIS[i] = LIS[j] + 1;
                }
            }
        }
        int maxLIS = 0;
        for (i = 0; i < N; ++i) {
            if (maxLIS < LIS[i])
                maxLIS = LIS[i];
        }
        printf("%d\n", maxLIS);
    }
    return 0;
}

