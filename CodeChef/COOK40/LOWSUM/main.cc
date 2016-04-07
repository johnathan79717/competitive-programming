#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll A[20000], B[20000];

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int K, Q;
    scanf("%d%d", &K, &Q);
    for(int i = 0; i < K; i++)
      scanf("%lld", A + i);
    sort(A, A+K);
    for(int i = 0; i < K; i++)
      scanf("%lld", B + i);

    sort(B, B+K);

    vector<int> sum;
    for(int i = 0; i < min(K, 10000); i++) {
      for(int j = 0; j < min(K, 9999 - i); j++) {
        sum.push_back(A[i] + B[j]);
      }
    }
    sort(sum.begin(), sum.end());

    while(Q--) {
      int q;
      scanf("%d", &q);
      cout << sum[q-1] << endl;
      // int k = min(K, q);
      // q--;
    //   ll lb = 1, ub = 2000000000000000001LL, mid;
    //   while(ub - lb > 1) {
    //     mid = (lb + ub) / 2;
    // // ll mid = 13;
    //     int upper = 0, lower = 0;
    //     for(int i = 0; i < k; i++) {
    //       auto p = equal_range(B, B+k, mid - A[i]);
    //       lower += p.first - B;
    //       upper += p.second - B;
    //     }
    //     // cout << q << ' ' << mid << ' ' << lower << ' ' << upper << endl;
    //     if(q < lower)
    //       ub = mid;
    //     else if(q >= upper)
    //       lb = mid;
    //     else {
    //       break;
    //     }
    //   }
    //   cout << mid << endl;
    }
  }
}