#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int a[10];
    for (int i = 0; i < 10; i++)
        a[i] = i;
    int ans = 0, total = 0;
    do {
        int black = 0, red = 0;
        ans++;
        total++;
        for (int i = 0; i < 10; i++) {
            if (a[i] < 4) {
                black++;
            } else {
                red++;
            }
            if (red <= black) {
                ans--;
                break;
            }
        }
    } while (next_permutation(a, a + 10));
    cout << total << ' ' << ans << endl;
}