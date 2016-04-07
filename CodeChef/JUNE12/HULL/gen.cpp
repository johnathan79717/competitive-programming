#include <iostream>
#include <ctime>

using namespace std;

#define N 5

int main() {
    srand(time(0));
    cout << N << endl;
    for (int i = 0; i < N; ++i) {
        cout << rand() % 5 - 2 << ' ' << rand() % 5 - 2 << endl;
    }
}