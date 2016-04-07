#include <iostream>

using namespace std;

#define MOD 1000000007

int main() {
    cout << "long long inv[801] = {";
    for (int i = 1; i <= 800; ++i) {
        long long a = 1;
        while(a % i) a += MOD;
        cout << a/i << ',';
    }
    cout << "};" << endl;
}