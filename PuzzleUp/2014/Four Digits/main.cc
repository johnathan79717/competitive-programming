#include <algorithm>
#include <bitset>
#include <iostream>

// using namespace std;
using std::cout;
using std::endl;
using std::bitset;
using std::next_permutation;

const int n = 4;
const int N = 24;
const int b = 2;

void print(int i) {
    cout << bitset<n*b>(i) << ' ';
}

int dp[1<<N][N];
int d[N][N];
int next[1<<N][N];
int map[N];
int a[] = {0, 1, 2, 3};

int f(int mask, int i) {
    if (dp[mask][i] >= 0) return dp[mask][i];
    if (mask == (1 << i)) {
        return dp[mask][i] = 0;
    }
    dp[mask][i] = 1e9;
    for (int j = 0; j < N; j++) {
        if (((mask >> j) & 1) && i != j) {
            int v = f(mask ^ (1 << i), j) + d[i][j];
            if (v < dp[mask][i]) {
                dp[mask][i] = v;
                next[mask][i] = j;
            }
        }
    }
    return dp[mask][i];
}

int main() {
    int j = 0;
    do {
        cout << j << ' ';
        for (int i = 0; i < n; i++) {
            map[j] |= (a[i] << (b*(n-1-i)));
            cout << a[i]+1;
        }
        cout << endl;
        j++;
    } while (next_permutation(a, a + n));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // print(map[i]); print(map[j]);
            // puts("");
            for (int k = 0; k <= n; k++) {
                // print(1 << ((b*n-b*k) - 1));
                // print(map[i] & ((1 << (b*n-b*k)) - 1));
                // print(map[j] >> (b*k));
                // puts("");
                if ((map[j] >> (b*k)) == (map[i] & ((1 << (b*n-b*k)) - 1))) {
                    // print(map[i] & (1 << ((b*n-b*k) - 1)));
                    // print(map[j] >> (b*k));
                    // puts("");
                    d[i][j] = k;
                    break;
                }
            }
            // cout << map[i] << ' ' << map[j] << ' ';
            // cout << d[i][j] << endl;
        }
    }
    int h = 0;
    memset(dp, -1, sizeof dp);
    memset(next, -1, sizeof next);

    for (int i = 0; i < N; i++)
        f((1 << N) - 1, i);
    int mask = (1 << N) - 1;
    for (int i = 0; i < n; i++) {
        if (dp[mask][i] < dp[mask][h])
            h = i;
    }
    while (h >= 0) {
        cout << h << endl;
        int tmp = next[mask][h];
        mask ^= (1 << h);
        h = tmp;
    }
}