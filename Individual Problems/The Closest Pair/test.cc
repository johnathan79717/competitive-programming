#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main() {
  int n;
  cin >> n;
  pair<int, int> p[2000];
  for(int i = 0; i < n; ++i) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p, p+n);
  int tot = 0;
  double d = 1e9;
  for(int i = 0; i < n; ++i) {
    for(int j = i+1; j < n; ++j) {
      ++tot;
      if(p[j].first - p[i].first >= d) break;
      d = min(d, sqrt((p[i].first - p[j].first) * (p[i].first - p[j].first) + (p[i].second - p[j].second) * (p[i].second - p[j].second)));
    }
  }
  cout << tot << endl;
}