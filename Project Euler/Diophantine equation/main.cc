#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>

using namespace std;

pair<__uint128_t, __uint128_t> cf(vector<long long> &v) {
  __uint128_t p = 0, q = 1;
  for(auto it = v.rbegin(); it != v.rend(); it++) {
    swap(p, q);
    q += p * (*it);
  }
  // cout << p << ' ' << q << endl;
  return make_pair(p, q);
}

long long cycle(long long D) {
  long long m = 0, d = 1, a = sqrt(D), a0 = a;
  if(a * a == D) return 0;
  vector<long long> v;
  v.push_back(a);
  while(true) {
    auto pr = cf(v);
    if(pr.second * pr.second == D * pr.first * pr.first + 1) {
      // cout << pr.first << ' ' << pr.second << '\n';
      return pr.second;
    }
    m = d * a - m;
    d = (D - m * m) / d;
    a = (a0 + m) / d;
    v.push_back(a);
  }
}

int main() {
  int ans;
  __uint128_t x = 0;
  for(int D = 1; D <= 1000; D++) {
    __uint128_t a = cycle(D);
    assert(a > 0);
    if(a > x) {
      ans = D;
      x = a;
    }
    // cout << (long long)(ans / (long long)1e18) << ' ' << (long long)(ans % (long long)1e18) << endl;
  }
  cout << ans << endl;
}