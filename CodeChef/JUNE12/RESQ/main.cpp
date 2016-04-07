#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N;
        scanf("%d", &N);
        int n = (int)sqrt(double(N));
        // cout << n << endl;
        int i = 0;
        for (i = n; i > 0; --i)
            if (N%i == 0) break;
        printf("%d\n", N/i-i);
    }
}