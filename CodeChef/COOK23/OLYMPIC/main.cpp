#include <cstdio>
#include <cstring>

#define MOD 1000000007
#define MAX 100000
#define LL long long
#define div(a,b) (a/b + (a%b ? 1 : 0))

// typedef signed long long int LL

long long fact[100001], ifact[100001];

LL inv(long long a) {
    LL b = MOD;
    LL x = 0; LL y = 1; LL u = 1; LL v = 0;
    while(a) {
        LL q = b/a; LL r = b%a;
        LL m = x - u*q; LL n = y - v * q;
        b = a; a = r; x = u; y = v; u = m; v = n;
    }
    // printf("%lld %lld %lld\n", b, x, y);
    return x > 0 ? x : x + MOD;
}

int main() {
    fact[0] = 1;
    ifact[0] = 1;
    for (long long i = 1; i <= MAX; ++i) {
        fact[i] = (fact[i-1] * i) % MOD;
        ifact[i] = (ifact[i-1] * inv(i)) % MOD;
    }
    // printf("%lld %lld %lld %lld\n", ifact[1], ifact[2], ifact[3], ifact[4]);
    int N;
    scanf("%d", &N);
    int count[100001];
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%d", count+i);
    }
    int Q;
    scanf("%d", &Q);
    while(Q--) {
        int S;
        long long ans = 1;
        scanf("%d", &S);
        int sum = 0;
        int odd = 0;
        for (int i = 0; i < N; ++i) {
            // printf("%d\n", div(count[i], S));
            int c = div(count[i], S);
            ans = ans * ifact[c] % MOD;
            sum += c;
            if (c%2) ++odd;
        }
        ans = ans * fact[sum] % MOD;
        if (odd <= 1) {
            LL sym = fact[sum/2];
            for (int i = 0; i < N; ++i) {
                sym = sym * ifact[div(count[i],S)/2] % MOD;
            }
            ans = (ans + sym) % MOD;
        }
        printf("%lld\n", ans/2);
    }
}