#include <iostream>
using namespace std;
bool isprime[100001];

int main() {
    memset(isprime, true, sizeof isprime);
    for (int p = 2; p * p <= 100000; p++) {
        for (int k = p+p; k <= 100000; k+=p) {
            isprime[k] = false;
        }
    }
    long long  ans = 0;
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            int x = 2 * i + 1, y = 2 * j + 2;
            int c = x * x + y * y, b = 2 * x * y, a = abs(x * x - y * y);
            if (c > 100000) {
                break;
            }
            if (isprime[c] && isprime[a]) {
                ans += a + b + c;
            }
        }
    }
    cout << ans << endl;
}
