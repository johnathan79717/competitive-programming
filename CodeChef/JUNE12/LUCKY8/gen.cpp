#include <iostream>

using namespace std;

int main() {
    cout << 1000 << endl;
    for (int i = 0; i < 2000; ++i) {
        long long A = rand();
        // cout << A << endl;
        A = A << 32 | rand();
        cout << A << endl;
    }
}