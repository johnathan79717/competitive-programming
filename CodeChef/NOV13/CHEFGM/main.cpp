#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 50
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int k;
    scanf("%d", &k);
    double total = 0;
    int i = 0;
    while(k--) {
      int n;
      scanf("%d", &n);
      double left = -MAX-1, right = MAX+1, value = 0;
      int a[45];
      for(int j = 0; j < n; j++)
        scanf("%d", a + j);
      sort(a, a + n);
      for(int j = 0; j < n; j++) {
        if(a[j] % 2)
          left = value;
        else
          right = value;

        if(left < -MAX)
          value = right - 1;
        else if(right > MAX)
          value = left + 1;
        else
          value = (left + right) / 2;
        // printf("%.45lf\n", value);
      }
      i += (int) value;
      total += (value - (int) value);
      // total += value;
    }
    i += (int) total;
    total -= (int) total;
    // printf("%.45lf\n", total);
    if(i > 0 || (i == 0 && total > 1e-50))
      puts("ODD");
    else if(i < 0 || (i == 0 && total < -1e-50))
      puts("EVEN");
    else
      puts("DON'T PLAY");
  }
}