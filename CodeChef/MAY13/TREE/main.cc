#include <iostream>
using namespace std;

typedef long long ll;
const ll c = 1000000007;

ll pow(ll a, ll b){
    ll x=1,y=a; // ll is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x=x*y%c;
        }
        y = y*y%c; // squaring the base
        b /= 2;
    }
    return x;
}

int main() {
  ll n, k;
  cin >> n >> k;
  if(n == 1) {
    cout << ((k == 1) ? 1 : 0) << endl;
    return 0;
  }
  cout << (pow(k * n, n-2) * pow(k * n - k, (k-1) * n) % c) << endl;
}