#include <cassert>
#include <cstdio>
#include <iostream>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int to, cap, num;
};

list<Edge> adj[1005];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        Edge e;
        e.to = b;
        e.cap = c;
        e.num = i;
        adj[a].push_back(e);
        e.to = a;
        adj[b].push_back(e);
    }
    if (n == 1) {
        puts("none");
        return 0;
    }
    int lb = -1, ub = 500001;
    while (ub - lb > 1) {
        int m = (ub + lb) / 2;
        queue<int> q;
        q.push(0);
        vector<int> last(n+1, -1);
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (auto& e : adj[u]) {
                if (e.cap < m) continue;
                if (last[e.to] != -1) continue;
                last[e.to] = u;
                q.push(e.to);
            }
        }
        if (last[n-1] == -1) {
            ub = m;
        } else {
            lb = m;
        }
    }
    queue<int> q;
    q.push(0);
    vector<int> last(n+1, -1);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto& e : adj[u]) {
            if (e.cap < lb) continue;
            if (last[e.to] != -1) continue;
            last[e.to] = u;
            q.push(e.to);
        }
    }
    //cerr << lb << endl;
    assert(last[n-1] != -1);
    vector<int> path = {n-1};
    int v = n-1;
    while (last[v]) {
        v = last[v];
        path.push_back(v);
    }
    path.push_back(0);
    vector<int> ans;
    for (int i = 0; i < (int)path.size(); i++) {
        int u = path[i];
        for (auto& e : adj[u]) {
            if ((i == 0 || e.to != path[i-1]) && (i+1u==path.size() ||e.to != path[i+1])) {
                ans.push_back(e.num);
            }
        }
    }
    if (ans.empty()) {
        puts("none");
        return 0;
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    for (size_t i = 0; i < ans.size(); i++) {
        printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
    }
}
