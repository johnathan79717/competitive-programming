#include <cstdio>
long long b[100005];

int MOD = 1000000007;

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", b + i);
    }
    long long c = 0;
    for (int i = N-1; i >= 0; i--) {
        c += b[i];
        c = (c + 1) / 2;
    }
    if (c > 1) {
        puts("error");
        return 0;
    }
    c = 1;
    for (int i = 0; i < N; i++) {
        c = (c * 2 - b[i]) % MOD;
        if (c >= MOD) c -= MOD;
        if (c < 0) c += MOD;
    }
    printf("%lld\n", c);
}
