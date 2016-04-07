#include <iostream>
#include <vector>
using namespace std;

int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541,};

int sum(int n) {
  if(n == 1) return 1;
  for(int i = 0; p[i] * p[i] <= n; ++i) {
    if(n % p[i] != 0) continue;

    int factor = p[i];
    int ans = 1;
    while(n % factor == 0) {
      ans += factor;
      factor *= p[i];
    }
    return ans * sum(n / (factor / p[i]));
  }
  return 1 + n;
}

int d(int n) {
  return sum(n) - n;
}

bool amicable(int n) {
  int dn = d(n);
  return n != dn && n == d(dn);
  // return n == d(d(n)) && n != d(n);
}

int main() {
  int T;
  cin >> T;
  vector<int> a;
  for(int i = 2; i <= 100000; ++i) {
    if(amicable(i)) {
      // cout << i << endl;
      // ans += i;
      a.push_back(i);
    }
    // cout << "(" << i << ", " << d(i) << ") ";
  }
  while(T--) {
    int N;
    cin >> N;
    int ans = 0;
    for(int a: a) {
      if(a < N) ans += a;
    }
    cout << ans << endl;
  }
}