#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c, q;
        cin >> n >> c >> q;
        cerr << n << ' ' << c << ' ' << q << endl;
        vector<vector<int>> child(n+1);
        vector<int> depth(n+1), color(n+1, 1);
        for (int i = 2; i <= n; i++) {
            int s;
            cin >> s;
            child[s].push_back(i);
            depth[i] = depth[s]+1;
        }
        int ans = 0;
        for (int k = 1; k <= q; k++) {
            int a, c, l;
            cin >> a >> l >> c;
            if (!c) {
                // cerr << color[a] << endl;
                ans = (ans + k * color[a]) % 1000000007;
                continue;
            }
            queue<int> q({a});
            while (!q.empty()) {
                int i = q.front();
                q.pop();
                color[i] = c;
                if (depth[i] < depth[a] + l) {
                    for(int ch: child[i]) {
                        q.push(ch);
                    }
                }
            }
        }
        cout << ans << endl;
    }
}