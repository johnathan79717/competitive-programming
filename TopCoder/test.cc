#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int MAX = 10000000;
bool is_prime[MAX], in_stack[MAX], visited[MAX];
vector<int> s;

void dfs(int p) {
    if (in_stack[p]) {
        for (int x : s) {
            cout << x << ' ';
        }
        cout << endl;
        exit(0);
    }
    if (visited[p]) return;
    visited[p] = true;
    in_stack[p] = true;
    s.push_back(p);
    int k = p % 1000000 * 10;
    if (k >= 1000000) {
        for (int q : {k + 1, k + 3, k + 7, k + 9}) {
            if (!is_prime[q]) continue;
            dfs(q);
        }
    }
    in_stack[p] = false;
    s.pop_back();
}

int main() {
    cout << "Hello" << endl;
    memset(is_prime, -1, sizeof is_prime);
    for (int p = 2; p < MAX; p++) {
        if (is_prime[p]) {
            for (int k = p+p; k < MAX; k += p) {
                is_prime[k] = false;
            }
        }
    }
    for (int p = 1000000; p < MAX; p++) {
        cout << p << endl;
        if (!is_prime[p]) continue;
        dfs(p);
    }
}
