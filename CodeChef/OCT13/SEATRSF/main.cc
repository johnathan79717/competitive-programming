#include <iostream>
using namespace std;

typedef long long ll;

ll mul(ll a,ll b,ll c){
  ll x = 0,y=a%c;
  while(b > 0){
    if(b%2 == 1){
      x = (x+y)%c;
    }
    y = (y*2)%c;
    b /= 2;
  }
  return x%c;
}

ll mul(ll a, ll b, int c) {
  return (a%c) * (b%c) % c;
}

int mul(int a, int b, int c) {
  ll temp = ll(a) * b;
  return temp % c;
}

template<class T>
T pow(T a, T b, T c){
  ll x=1,y=a; // ll is taken to avoid overflow of intermediate results
  while(b > 0){
    if(b%2 == 1){
      x=mul(x, y, c);
    }
    y = mul(y, y, c); // squaring the base
    b /= 2;
  }
  return x%c;
}

#define M 1000000007

int solve() {
  int n, m, k, q;
  ll ans = 0;
  cin >> n >> m >> q >> k;
  if(m <= q)
    return 0;
  ans = ( (ll)pow(q + 1, n, M) - 2 * (ll)pow(q, n, M) + (ll)pow(q - 1, n, M) ) % M;
  if(ans < 0)
    ans += M;
  return mul(ans, ll(m - q), M);
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    cout << solve() << endl;
  }
}