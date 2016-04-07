#include <cstdio>
#include <algorithm>

#define MAX 50
using std::sort;
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int k;
    scanf("%d", &k);
    double total = 0;
    while(k--) {
      int n;
      scanf("%d", &n);
      bool start = true;
      int first;
      double value = 0;
      double bit = 0.5;
      int a[45];
      for(int j = 0; j < n; j++)
        scanf("%d", a + j);
      sort(a, a + n);
      for(int j = 0; j < n; j++) {
        if(j == 0)
          first = a[j] % 2;
        if(start) {
          if(a[j] % 2 == first) {
            value += first ? -1 : 1;
            continue;
          }
          else
            start = false;
        }
        if(a[j] % 2)
          value -= bit;
        else
          value += bit;

        bit /= 2;
      }
      total += value;
    }
    // printf("%lf\n", total);
    if(total > 1e-50)
      puts("EVEN");
    else if(total < -1e-50)
      puts("ODD");
    else
      puts("DON'T PLAY");
  }
}