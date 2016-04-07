#include <iostream>
using namespace std;
int main() {
    int a = 1, b = 0;
    int ans = 1;
    for (int i = 0; i < 123456789; i++) {
        int aa = b * 5ll % 1000000007;
        int bb = (a + b * 4ll) % 1000000007;
        a = aa;
        b = bb;
        ans = (ans + a) % 1000000007;
    }
    cout << ans << endl;
}
