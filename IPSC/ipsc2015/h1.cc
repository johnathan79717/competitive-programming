#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cerr << t << ' ' << n << endl;
        int adj[201][201];
        memset(adj, 0, sizeof adj);
        while (m--) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u][v] = adj[v][u] = true;
        }
        int ans1 = 0, ans2 = INT_MAX;
        for (int mask = 0; mask < (1 << (n-1)); mask++) {
            if (mask % 4 == 0 || mask % 4 == 3) {
                continue;
            }
            vector<int> team[2];
            team[0].clear();
            team[1].clear();
            for (int i = 0; i < n; i++) {
                team[(mask >> i) & 1].push_back(i);
            }
            int cnt[2] = {};
            for (int k = 0; k < 2; k++) {
                for (int i: team[k]) {
                    for (int j: team[k]) {
                        if (adj[i][j]) {
                            cnt[k]++;
                        }
                    }
                }
                cnt[k] /= 2;
            }
            ans1 = max(ans1, cnt[0] + cnt[1]);
            ans2 = min(ans2, abs(cnt[0] - cnt[1]));
        }
        cout << ans1 << ' ' << ans2 << endl;
    }
}