#include <iostream>
#include <climits>
using namespace std;

int main() {
  int N;
  cin >> N;
  int min_index, max_index, min_area = INT_MAX, max_area = 0;
  for(int n = 1; n <= N; n++) {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int area = (x1 - x3) * (y2 - y1) - (x1 - x2) * (y3 - y1);
    if(area < 0) area = -area;
    if(area >= max_area) {
      max_area = area;
      max_index = n;
    }
    if(area <= min_area) {
      min_area = area;
      min_index = n;
    }
  }
  cout << min_index << ' ' << max_index << endl;
}