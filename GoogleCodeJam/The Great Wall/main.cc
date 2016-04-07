#include <iostream>
#include <vector>
using namespace std;

struct Attack {
  Attack(int d, int w, int e, int s) : d(d), w(w), e(e), s(s) {}
  int d;
  int w;
  int e;
  int s;
};

bool comp(Attack &a, Attack & b) {
  return a.d < b.d;
}


int main() {
  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t) {
    int N;
    cin >> N;
    vector<Attack> v;
    int wall[2001];
    for(int i = 0; i < N; ++i) {
      int d, n, w, e, s, delta_d, delta_p, delta_s;
      cin >> d >> n >> w >> e >> s >> delta_d >> delta_p >> delta_s;
      for(int j = 0; j < n; ++j) {
        v.push_back(Attack(d, w, e, s));
        d += delta_d;
        w += delta_p;
        e += delta_p;
        s += delta_s;
      }
    }
    sort(v.begin(), v.end(), comp);
    for(int i = 0; i < v.size(); ++i) {
      
    }
  }
}