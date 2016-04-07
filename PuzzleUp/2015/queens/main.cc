#include <iostream>
using namespace std;
const int N = 3;

int main() {
    int ans = 0;
    for (int black = 0; black < (1 << (N*N)); black++) {
        int empty = black ^ ((1 << (N*N)) - 1);
        int white = empty;
        do {
            bool fail = false;
            for (int i = 0; i < N; i++) {
                int cnt1 = 0, cnt2 = 0;
                for (int j = 0; j < N; j++) {
                    if ((black >> (i*N+j)) & 1) {
                        cnt1--;
                    }
                    if ((white >> (i*N+j)) & 1) {
                        cnt1++;
                    }
                    if ((black >> (j*N+i)) & 1) {
                        cnt2--;
                    }
                    if ((white >> (j*N+i)) & 1) {
                        cnt2++;
                    }
                }
                if (cnt1 <= 0 || cnt2 <= 0) {
                    fail = true;
                    break;
                }
            }
            ans += !fail;
            white = (white - 1) & empty;
        } while (white);
    }
    cout << ans << endl;
}
