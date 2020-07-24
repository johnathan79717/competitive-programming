#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> blocks;
vector<int> in_deg;
vector<int> dp;
int K;

int solve(int mask) {
    if (mask == 0) {
        return dp[mask] = 0;
    }
    if (dp[mask] >= 0) {
        return dp[mask];
    }
    int n = in_deg.size();
    int canTake = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        if (((mask >> i) & 1) && in_deg[i] == 0) {
            canTake ^= (1 << i);
            c2++;
        }
    }
    if (c2 <= K) {
        for (int i = 0; i < n; i++) {
            if ((canTake >> i) & 1) {
                for (int v : blocks[i]) {
                    in_deg[v]--;
                }
            }
        }
        int ans = 1 + solve(mask ^ canTake);
        for (int i = 0; i < n; i++) {
            if ((canTake >> i) & 1) {
                for (int v : blocks[i]) {
                    in_deg[v]++;
                }
            }
        }
        return ans;
    }
    int set = canTake;
    int ans = 10000;
    while (set) {
        int c = 0;
        for (int i = 0; i < n; i++) {
            if ((set >> i) & 1) {
                c++;
                for (int v : blocks[i]) {
                    in_deg[v]--;
                }
            }
        }
        if (c == K) {
            ans = min(ans, 1 + solve(mask ^ set));
        }
        for (int i = 0; i < n; i++) {
            if ((set >> i) & 1) {
                c++;
                for (int v : blocks[i]) {
                    in_deg[v]++;
                }
            }
        }
        set = (set - 1) & canTake;
    }
    return dp[mask] = ans;
}
int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
    K = k;
    blocks.clear();
    blocks.resize(n);
    in_deg = vector<int>(n);
    dp = vector<int>(1 << n, -1);
    for (auto &vi : dependencies) {
        blocks[vi[0]-1].push_back(vi[1]-1);
        in_deg[vi[1]-1]++;
    }
    return solve((1 << n) - 1);
}
int main() {
    vector<vector<int>> v({{1,6},{2,7},{8,7},{2,5},{3,4}});
    //v.push_back({2, 1});
    //v.push_back({3, 1});
    //v.push_back({1, 4});
    cout << minNumberOfSemesters(8, v, 3) << endl;
}
