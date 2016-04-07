#include <iostream>
#include <vector>
using namespace std;

int main() {
  // int T, P, H, dt, dp, dh;
  // T = P = H = 40755;
  // dt = 286;
  // dp = 496;
  // dh = 573;
  // do {
  //   if(T <= P && T <= H) {
  //     T += dt;
  //     ++dt;
  //   }
  //   else if (P <= T && P <= H) {
  //     P += dp;
  //     dp += 3;
  //   }
  //   else {
  //     H += dh;
  //     dh += 4;
  //   }
  // } while(T != P || P != H);
  // cout << T << endl;
  long long N, a, b;
  cin >> N >> a >> b;
  vector<long long> t;
  if(a == 3) {
    for(int i = 1; (long long)i*(i+1)/2 < N; i++)
      t.push_back((long long)i*(i+1)/2);
  } else {
    for(int i = 1; (long long)i*(2*i-1) < N; i++) {
      t.push_back((long long)i*(2*i-1));
    }
  }
  vector<long long> p;
  for(int i = 1; (long long)i*(3*i-1)/2 < N; i++) {
    p.push_back((long long)i * (3*i-1) / 2);
  }
  int i = 0, j = 0;
  while(i < t.size() && j < p.size()) {
    if(t[i] < p[j]) i++;
    else if(t[i] > p[j]) j++;
    else {
      printf("%lld\n", t[i]);
      i++;
      j++;
    }
  }
}