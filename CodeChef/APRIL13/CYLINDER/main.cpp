#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    double W, H, R, A, ans = -1e9;
    scanf("%lf%lf", &W, &H);
    for(int i = 0; i < 2; i++) {
      if(W / H < 1 + 1 / M_PI) {
        R = H / 2 / M_PI;
        A = W - 2 * R;
      } else if (W / H < 1 + M_PI / 2) {
        R = W / 2 / (M_PI + 1);
        A = H;
      } else if (W / H > M_PI + 2) {
        R = H / 2;
        A = H;
      } else {
        double a = 4 * (M_PI + 1) * (M_PI + 1);
        double b = -4 * H - 4 * (M_PI + 1) * W;
        double c = W * W + H * H;
        R = (-b - sqrt(b * b - 4 * a * c)) / 2 / a;
        A = H;
      }
      ans = max(ans, M_PI * R * R * A);
      swap(W, H);
    }
    printf("%.12lf\n", ans);
  }
}