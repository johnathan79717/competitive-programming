#include <iostream>
#include <string>

using namespace std;

string A[50];
int K, N;

bool solve() {
    string B;
    cin >> B;
    if (B.size() >= 47) return true;
    for (int i = 0; i < K; ++i)
        if (B.find(A[i]) != string::npos)
            return true;
    return false;           
}

int main() {
    cin >> K >> N;
    for (int i = 0; i < K; ++i)
        cin >> A[i];
    for (int i = 0; i < N; ++i) {
        if (solve()) cout << "Good" << endl;
        else cout << "Bad" << endl;
    }
}