#include <iostream>
#include <vector>


using namespace std;
typedef vector<int> VI;

struct DisjointSet {
  VI par, _size;
  int N;

  DisjointSet(int N): par(N), _size(N), N(N) {
    init();
  }

  void init() {
    for(int i = 0; i < N; i++) {
      par[i] = i;
      _size[i] = 1;
    }
  }

  int find(int x) {
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(_size[x] < _size[y]) {
      par[x] = y;
      _size[y] += _size[x];
    } else {
      par[y] = x;
      _size[x] += _size[y];
    }
  }

  int size(int x) {
    return _size[find(x)];
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    cerr << t << ' ' << n << ' ' << q << endl;
    DisjointSet s1(n), s2(n);
    int ans = 0;
    for (int k = 1; k <= q; k++) {
      int t, a, b;
      cin >> t >> a >> b;
      a--; b--;
      if (t == 1) {
        s1.unite(a, b);
      } else {
        s2.unite(a, b);
      }
      int cnt = 0;
      for(int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
          if (s1.same(i, j) && s2.same(i, j)) {
            cnt++;
          }
        }
      }
      // cout << cnt << endl;
      ans = (ans + k * cnt) % 1000000007;
    }
    cout << ans << endl;
  }
}