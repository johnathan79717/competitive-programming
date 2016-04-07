#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

stack<int> ans;

bool divide(vector<int> &F, const vector<int> &G) {
  if(F.size() < G.size() || F.back() % G.back())
    return false;
  int d = F.back() / G.back();
  ans.push(d);
  auto f = F.rbegin();
  auto g = G.rbegin();
  while(g != G.rend())
    *f++ -= *g++ * d;
  if(F.size() == G.size() && all_of(F.begin(), F.end(), [](int x){ return x == 0; }))
    return true;
  F.pop_back();
  return divide(F, G);
}

int main() {
  int N;
  cin >> N;
  while(N--) {
    int D;
    cin >> D;
    vector<int> F(++D);
    for(auto &f : F)
      cin >> f;
    cin >> D;
    vector<int> G(++D);
    for(auto &g : G)
      cin >> g;
    while(!ans.empty()) ans.pop();
    if(divide(F, G)) {
      while(1) {
        cout << ans.top();
        ans.pop();
        if(ans.empty())
          break;
        else
          cout << ' ';
      }
      cout << endl;
    } else {
      puts("no solution");
    }
  }
}