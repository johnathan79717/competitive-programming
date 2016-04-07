#include <cstdio>

#define M 1000000007
#define ll long long

ll e[2][2] = { { 2, 2 }, { 1, 0 } };

void mul(const ll A[2][2], const ll B[2][2], ll out[2][2]) {
    out[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % M;
    out[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % M;
    out[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % M;
    out[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % M;
}

void exp(int n, ll out[2][2]) {
    if (n == 0) {
        out[0][0] = out[1][1] = 1;
        out[1][0] = out[0][1] = 0;
        return;
    }
    ll A[2][2];
    exp(n / 2, A); // A = e^(n/2)
    if(n % 2) {
        ll temp[2][2];
        mul(A, A, temp); // temp = A * A
        mul(temp, e, out); // out = temp * e
    } else {
        mul(A, A, out); // out = A * A
    }
}

ll solve(int n) {
    if(n == 1) return 1;
    ll A[2][2];
    exp(n - 2, A);
    return (A[0][0] * 3 + A[0][1]) % M;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N;
        scanf("%d", &N);
        printf("%lld\n", solve(N));
    }
}