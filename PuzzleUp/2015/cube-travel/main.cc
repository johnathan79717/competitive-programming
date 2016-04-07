#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int dp[1 << 21][14];
int adj[15][15];

void add(int i, int j) {
    static int num = 0;
    adj[i][j] = adj[j][i] = num++;
}

int main() {
    memset(adj, -1, sizeof adj);
    add(0, 1);
    add(0, 2);
    add(0, 3);
    add(1, 4);
    add(1, 5);
    add(2, 5);
    add(2, 6);
    add(3, 6);
    add(3, 4);
    add(4, 7);
    add(5, 7);
    add(6, 7);
    add(7, 8);
    add(7, 9);
    add(7, 10);
    add(8, 11);
    add(8, 12);
    add(9, 12);
    add(9, 13);
    add(10, 13);
    add(10, 11);

    add(11, 14);
    add(12, 14);
    add(13, 14);
    dp[0][0] = 1;
    int ans = 0;
    for (int mask = 0; mask < (1<<21); mask++) {
        for (int i = 0; i < 14; i++) {
            if (dp[mask][i] == 0) continue;
            for (int j = 0; j < 15; j++) {
                if (adj[i][j] < 0) continue;
                if (j == 14) {
                    ans += dp[mask][i];
                    continue;
                }
                assert(adj[i][j] < 21);
                if ((mask >> adj[i][j]) & 1) continue;
                dp[mask | (1 << adj[i][j])][j] += dp[mask][i];
            }
        }
    }
    cout << ans << endl;
}
