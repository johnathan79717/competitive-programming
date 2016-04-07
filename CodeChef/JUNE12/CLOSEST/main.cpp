#include <cstdio>
#include <algorithm>
#include <climits>
#include <ctime>

#define TRY 447

int N, Q;
unsigned long long X[50000], Y[50000], Z[50000], A[TRY], B[TRY], C[TRY];

unsigned long long d(unsigned long long x, unsigned long long y, unsigned long long z, unsigned long long a, unsigned long long b, unsigned long long c) {
    return (x-a)*(x-a)+(y-b)*(y-b)+(z-c)*(z-c);
}

int main() {
    srand(time(0));
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%llu%llu%llu", X+i, Y+i, Z+i);
    scanf("%d", &Q);
    for (int i = 0; i < TRY; ++i)
        scanf("%llu%llu%llu", A+i, B+i, C+i);
    for (int j = 0; j < TRY; ++j) {
        unsigned long long dist = ULLONG_MAX;
        int ans;
        for (int i = 0; i < N; ++i) {
            unsigned long long l = d(X[i], Y[i], Z[i], A[j], B[j], C[j]);
            // printf("%d\n", l);
            if (l < dist) {
                dist = l;
                ans = i;
            }
        }
        printf("%d\n", ans);
    }
    for (int i = TRY; i < Q; ++i) puts("0");
}