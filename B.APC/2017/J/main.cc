#include <iostream>
#include <cstdio>
#include <list>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

list<pair<int,int>> adj[1000005];
int dp[1000005];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int p;
        scanf("%d", &p);
        for (int j = 0; j < p; j++) {
            int l, k;
            scanf("%d%d", &l, &k);
            int mask = 0;
            for (int m = 0; m < k; m++) {
                int d;
                scanf("%d", &d);
                mask |= (1 << d);
            }
            adj[mask].emplace_back(mask | (1 << i), l);
        }
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.emplace(0, 0);
    const int INF = 1e9;
    for (int i = 0; i < 1000005; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;
    while (pq.size()) {
        auto pr = pq.top();
        pq.pop();
        int v = pr.second;
        if (pr.first > dp[v]) {
            continue;
        }
        for (auto &e : adj[v]) {
            int u = e.first;
            int l = e.second;
            if (dp[v] + l < dp[u]) {
                dp[u] = dp[v] + l;
                pq.emplace(dp[u], u);
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < (1 << n); i++) {
        if (i & 1) {
            ans = min(ans, dp[i]);
        }
    }
    printf("%d\n", ans);
}
