#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

#define MP make_pair
#define EB emplace_back

struct Edge {
    int f, t, c;
    Edge(int f, int t, int c): f(f), t(t), c(c) {}
};

int i;

pair<int, vector<Edge> > solve(int p) {
    vector<Edge> e;
    switch (p) {
        case 1:
            return MP(1, e);
        case 2:
            e.EB(2, 1, 0);
            return MP(2, e);
    }
    if (p % 2 == 1) {
        auto pr = solve(p - 1);
        int n = pr.first;
        swap(e, pr.second);
        e.EB(n+1, n, 0);
        return MP(n+1, e);
    } else {
        auto pr = solve(p / 2 - 1);
        int n = pr.first;
        swap(e, pr.second);
        e.EB(n+2, n+1, i);
        i *= 2;
        e.EB(n+1, n, -i);
        e.EB(n+2, n, 0);
        return MP(n+2, e);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p;
        cin >> p;
        // cerr << t << ' ' << p << endl;
        i = 1;
        auto pr = solve(p-1);
        pr.second.EB(0, pr.first, 0);
        pr.first++;
        cout << pr.first << endl;
        assert(pr.first <= 60);
        cout << pr.second.size() << endl;
        for (auto &e: pr.second) {
            cout << e.f << ' ' << e.t << ' ' << e.c << endl;
        }
    }
}