#include <iostream>

using namespace std;

int f(long long N) {
    int c = 0;
    for (int i = 0; i < 64; i++) {
        if ((N >> i) & 1) {
            c++;
        }
    }
    return c;
}

int main() {
    long long N;
    int k;
    cin >> N >> k;
    N++;
    while (true) {
        int c = f(N);
        if (c == k) {
            break;
        }
        if (c < k) {
            for (int i = 0; i < 64; i++) {
                if (!((N >> i) & 1)) {
                    N += (1ll << i);
                    break;
                }
            }
        } else {
            for (int i = 0; i < 64; i++) {
                if ((N >> i) & 1) {
                    N += (1ll << i);
                    break;
                }
            }
        }
    }
    cout << N << endl;
}
