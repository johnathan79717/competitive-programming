#include <iostream>

using namespace std;

struct Point { int x, y; };

int sign(Point p1, Point p2, Point p3)
{
  return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool pointInTriangle(Point pt, Point v1, Point v2, Point v3)
{
  bool b1, b2, b3;

  b1 = sign(pt, v1, v2) < 0;
  b2 = sign(pt, v2, v3) < 0;
  b3 = sign(pt, v3, v1) < 0;

  return ((b1 == b2) && (b2 == b3));
}

int main() {
  Point p1, p2, p3, origin({0, 0});
  int ans = 0;
  for(int i = 0; i < 1000; i++) {
    scanf("%d,%d,%d,%d,%d,%d", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y);
    if(pointInTriangle(origin, p1, p2, p3))
      ans++;
  }
  cout << ans << endl;
}