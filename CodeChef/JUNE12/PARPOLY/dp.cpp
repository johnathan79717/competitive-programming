#include <cstdio>
#include <cstring>

#define MOD 1000000007

int M, N, D, set[404][804];
long long store[405][805], X, P[808], C[12];

long long f(int m, int n, int s = 0) {
    if (m == 1) {
        // printf("f(%d, %d) = %lld\n", m, n, P[n]);
        return P[n];
    }
    if (set[m][n]) {
        // printf("f(%d, %d) = %lld\n", m, n, store[m][n]);
        return store[m][n];
    }
    set[m][n] = 1;
    long long ans = 0;
    if (s)
        for (int i = 0; i <= n; ++i)
            ans = (ans + P[i] * f(m-1, n-i)) % MOD;
    else if (m % 2 == 0)
        for (int i = 0; i <= n; ++i)
            ans = (ans + f(m/2, i) * f(m/2, n-i)) % MOD;
    else
        for (int i = 0; i <= n; ++i)
            ans = (ans + f(m/2+1, n-i, 1) * f(m/2, i)) % MOD;
    // printf("f(%d, %d) = %lld\n", m, n, ans);
    return store[m][n] = ans;
}

int solve() {
    scanf("%d%d%lld%d", &M, &N, &X, &D);
    for (int i = 0; i <= D; ++i)
        scanf("%lld", C+i);
    long long iX = 0;
    for (int i = 0; i <= N; ++i) {
        P[i] = 0;
        for (int j = D; j >= 0; --j)
            P[i] = (P[i] * iX + C[j]) % MOD;
        iX = (iX + X) % MOD;
    }
    memset(set, 0, sizeof(set));
    return f(M, N);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        printf("%d\n", solve());
    }
}