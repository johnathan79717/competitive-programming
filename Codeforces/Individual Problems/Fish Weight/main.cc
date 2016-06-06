#include <iostream>
#include <map>
#include <queue>

using namespace std;

bool solve() {
  int n, m, k;
  cin >> n >> m >> k;
  map<int, int> alice, bob;
  priority_queue<int> fish;
  for(int i = 0; i < n; ++i) {
    int f;
    cin >> f;
    ++alice[f];
    if(alice[f] == 1 && bob[f] == 0)
      fish.push(f);
  }
  for(int i = 0; i < m; ++i) {
    int f;
    cin >> f;
    ++bob[f];
    if(bob[f] == 1 && alice[f] == 0)
      fish.push(f);
  }
  int suma = 0, sumb = 0;
  while(!fish.empty()) {
    int f = fish.top();
    fish.pop();
    suma += alice[f];
    sumb += bob[f];
    if(suma > sumb)
      return true;
  }
  return false;
}

int main() {
  if(solve())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
