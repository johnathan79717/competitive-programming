#include <iostream>
#include <vector>
using namespace std;

int W, H;
string s;
vector<int> seg;

bool fit(int size) {
  int numLines = H / size;
  int width = W / size;
  int line = width;
  for(int i = 0; i < seg.size(); i++) {
    bool success;
    do {
      if(line < width && 1 + seg[i] <= line) {
        line -= (1 + seg[i]);
        success = true;
      }
      else if(line == width && seg[i] <= line) {
        line -= seg[i];
        success = true;
      }
      else {
        success = false;
        line = width;
        numLines--;
        if(!numLines)
          return false;
      }
    } while(!success);
  }
  return true;
}

int solve() {
  seg.clear();
  int prev = 0;
  for(int pos = s.find(' '); pos < s.size(); pos = s.find(' ', prev)) {
    seg.push_back(pos - prev);
    prev = pos + 1;
  }
  seg.push_back(s.size() - prev);
  // for(int i = 0; i < seg.size(); i++)
  //   cout << seg[i] << endl;

  int lb = 0, ub = min(W, H) + 1;
  while(ub - lb > 1) {
    int mid = (ub + lb) / 2;
    if(fit(mid))
      lb = mid;
    else
      ub = mid;
  }
  return lb;
}

int main() {
  int T, cas = 1;
  cin >> T;
  while(T--) {
    cin >> W >> H;
    getline(cin, s);
    cout << "Case #" << cas++ << ": " << solve() << endl;
  }
}