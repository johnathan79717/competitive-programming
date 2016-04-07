#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
  int i;
  double lat, lon, x, y, z;
  Point(int i, double a, double b): i(i), lat(a * M_PI / 180), lon(b * M_PI / 180) {
  }
  bool operator<(const Point &p) const {
    return lon < p.lon;
  }
};

double d(Point p1, Point p2) {
  if(p1.lon > p2.lon)
    p2.lon += 2 * M_PI;
  double x1 = cos(p1.lat) * cos(p1.lon);
  double y1 = cos(p1.lat) * sin(p1.lon);
  double z1 = sin(p1.lat);
  double x2 = cos(p2.lat) * cos(p2.lon);
  double y2 = cos(p2.lat) * sin(p2.lon);
  double z2 = sin(p2.lat);
  if(p2.lon - p1.lon <= 180)
    return 6371 * acos(x1 * x2 + y1 * y2 + z1 * z2);
  else
    return 6371 * (2 * M_PI - acos(x1 * x2 + y1 * y2 + z1 * z2));
}

int main() {
  int N;
  scanf("%d", &N);
  vector<Point> l;
  for(int i = 0; i < N; i++) {
    double lat, lon;
    scanf("%lf%lf", &lat, &lon);
    l.emplace_back(i, lat, lon);
  }

  printf("%lf\n", d(l[4],l[1]) + d(l[1], l[5]) + d(l[5], l[2]) + d(l[2], l[0]) + d(l[0], l[3]) + d(l[3], l[4]));

  sort(l.begin(), l.end());
  double ans = 0;
  for(int i = 1; i < N; i++) {
    ans += d(l[i-1], l[i]);
  }
  l[0].lon += 2 * M_PI;
  ans += d(l[N-1], l[0]);
  printf("%lf\n", ans);
  for(int i = 0; i < N; i++)
    printf("%d%c", l[i].i, i == N-1 ? '\n' : ' ');

}