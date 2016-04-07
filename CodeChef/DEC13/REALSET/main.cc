#include <cstdio>
#include <iostream>
#include <complex>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

typedef double ld;
typedef complex<ld> cld;

#define E 1e-2

int N;
ld A[30005];

bool check(int d) {
  // cld w(cos((ld)2 * M_PI * d / N), sin((ld)2 * M_PI * d / N));
  cld sum = 0;
  for(int i = 0; i < N; i++)
    sum += A[i] * cld(cos((ld)M_PI * 2 * i * d / N), sin((ld)M_PI * 2 * i * d / N));
  // cout << d << ": " << sum << endl;
  return abs(sum) < E;
}

bool solve() {
  for(int d = 1; d * d <= N; d++)
    if(N % d == 0 && (check(d) || check(N / d)))
      return true;
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
      scanf("%Lf", A + i);
    puts(solve() ? "YES" : "NO");
  }
}