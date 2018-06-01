#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int kMaxN = 2e4, kMaxC = 5, inf = 1e9;

struct SegTreeNode {
    int mx_cost[kMaxC][kMaxC];

    SegTreeNode() { 
        for (int i = 0; i < kMaxC; i += 1) {
            for (int j = 0; j < kMaxC; j += 1) {
                mx_cost[i][j] = -inf;
            }
        }
    }

    SegTreeNode operator^(const SegTreeNode& rhs) const {
        SegTreeNode result;
        for (int c1 = 0; c1 < kMaxC; c1 += 1) {
            for (int c2 = 0; c2 < kMaxC; c2 += 1) {
                for (int mid = 0; mid < kMaxC; mid += 1) {
                    for (int offset = -1; offset <= +1; offset += 1) {
                        if (mid + offset >= 0 and mid + offset < kMaxC) {
                            result.mx_cost[c1][c2] = max(result.mx_cost[c1][c2], mx_cost[c1][mid] + rhs.mx_cost[mid + offset][c2]);
                        }
                    }
                }
            }
        }

        return result;
    }
};

int els[kMaxC][kMaxN];

struct SegTree {
    int n;
    SegTreeNode vals[4 * kMaxN];

    void Init(int n) {
        this->n = n;
        Init(1, 0, n - 1);
    }

    void Init(int node, int left, int right) {
        if (left == right) {
            for (int i = 0; i < kMaxC; i += 1) {
                vals[node].mx_cost[i][i] = els[i][left];   
            }
            return;
        }

        int mid = (left + right) / 2;
        Init(2 * node, left , mid);
        Init(2 * node + 1, mid + 1, right);
        vals[node] = vals[2 * node] ^ vals[2 * node + 1];
    }

    void Update(int pos) {
        Update(1, 0, n - 1, pos);
    }

    void Update(int node, int left, int right, int pos) {
        if (pos < left) { return; }
        if (right < pos) { return; }
        if (left == right) {
            for (int i = 0; i < kMaxC; i += 1) {
                vals[node].mx_cost[i][i] = els[i][left];
            }
            return;
        }

        int mid = (left + right) / 2;
        Update(2 * node, left, mid, pos);
        Update(2 * node + 1, mid + 1, right, pos);
        vals[node] = vals[2 * node] ^ vals[2 * node + 1];       
    }

    int GetMax() {
        int mx = 0;
        for (int c1 = 0; c1 < kMaxC; c1 += 1) {
            for (int c2 = 0; c2 < kMaxC; c2 += 1) {
                mx = max(mx, vals[1].mx_cost[c1][c2]);
            }
        }

        return mx;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q; cin >> n >> m >> q;
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            cin >> els[i][j];
        }
    }

    SegTree st;
    st.Init(m);

    while (q--) {
        int x, y, val; cin >> x >> y >> val;
        x -= 1;
        y -= 1;
        els[x][y] = val;
        st.Update(y);
        cout << st.GetMax() << '\n';
    }

    return 0;
}
