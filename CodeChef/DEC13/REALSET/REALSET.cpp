#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <cmath>

using namespace std;

const double pi = acos(-1);

bool check(const vector<pair<int, int>>& pairs, int k, int n) {
  complex<long double> s(0.0, 0.0);

  for (auto p : pairs) {
    int j = k * p.first % n;
    complex<long double> x(cos(2 * pi * j / n), sin(2 * pi * j / n));
    s += x * complex<long double>(p.second * 1.0, 0.0);
    // s = s * x + complex<long double>(coeff[i] * 1.0, 0.0);
    //s += x_i * complex<long double>(coeff[i] * 1.0, 0.0);
    //x_i *= x;
  }

  // cout << n << ' ' << k << ' ' << s << ' ' << abs(s) << endl;
  return abs(s.imag()) < 1e-8L && abs(s.real()) < 1e-8L;
}

int main(int argc, char* argv[]) {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++ t) {
    int N;
    cin >> N;

    vector<int> coeff(N);
    for (int i = 0; i < N; ++ i) {
      cin >> coeff[i];
    }

    vector<pair<int, int>> pairs(N);
    for (int i = 0; i < N; ++ i) {
      pairs[i] = {N - i - 1, coeff[i]};
    }

    sort(pairs.begin(), pairs.end(),
        [] (const pair<int, int>& a, const pair<int, int>& b) {
          return abs(a.second) == abs(b.second) ? a.first < b.first : abs(a.second) < abs(b.second);
        });

    bool result = check(pairs, 0, N);
    if (!result) {
      for (int d = 1; d < N; ++ d) {
        if (N % d == 0) {
          if (check(pairs, d, N)) {
            result = true;
            break;
          }
        }
      }
    }

    if (result) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
