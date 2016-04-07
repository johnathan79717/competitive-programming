#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int N;
    scanf("%d", &N);
    long long D[10000];
    for(int i = 0; i < N; ++i)
      scanf("%lld", D+i);
    long long maxl[10000], minl[10000];
    maxl[0] = minl[0] = D[0];
    long long maxt = max(0ll, D[0]), mint = min(0ll, D[0]);
    for(int i = 1; i < N; ++i) {
      maxl[i] = max(maxl[i-1], D[i] + maxt);
      minl[i] = min(minl[i-1], D[i] + mint);
      maxt = max(0ll, maxt + D[i]);
      mint = min(0ll, mint + D[i]);
    }
    long long maxr[10000], minr[10000];
    maxt = max(0ll, D[N-1]); mint = min(0ll, D[N-1]);
    maxr[N-1] = minr[N-1] = D[N-1];
    for(int i = N-2; i >= 0; --i) {
      maxr[i] = max(maxr[i+1], D[i] + maxt);
      minr[i] = min(minr[i+1], D[i] + mint);
      maxt = max(0ll, maxt + D[i]);
      mint = min(0ll, mint + D[i]);
    }
    long long ans = 0;
    for(int i = 0; i < N-1; ++i) {
      ans = max(ans, maxl[i] - minr[i+1]);
      ans = max(ans, maxr[i+1] - minl[i]);
    }
    printf("%lld\n", ans);
  }
}