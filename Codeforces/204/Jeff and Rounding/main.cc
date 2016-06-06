#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
  int n;
  cin >> n;
  double a[4000];
  double sum = 0;
  int freedom = 0;
  for(int i = 0; i < 2*n; i++) {
    cin >> a[i];
    a[i] -= (int)a[i];
    sum += a[i];
    if(a[i] > 0.0001)
      freedom++;
  }
  double diff = 2000;

  if(freedom >= n) {
    for(int i = freedom - n; i <= n; i++)
      diff = min(diff, abs(i - sum));
  } else {
    for(int i = 0; i <= freedom; i++)
      diff = min(diff, abs(i - sum));
  }
  printf("%.3f\n", diff);
}