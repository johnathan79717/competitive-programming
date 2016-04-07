#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

ll sort(ll n) {
  vector<int> digits;
  while(n) {
    digits.push_back(n % 10);
    n /= 10;
  }
  sort(digits.begin(), digits.end(), greater<int>());
  ll ret = 0;
  for(int d : digits)
    ret = 10 * ret + d;
  return ret;
}

int main() {
  map<ll, int> cnt;
  map<ll, ll> fst; 
  for(ll i = 0; i < 10000; i++) {
    ll cube = i * i * i;
    ll key = sort(cube);
    if(!cnt[key])
      fst[key] = cube;
    cnt[key]++;
  }
  for(auto p : cnt) {
    if(p.second == 6)
      cout << fst[p.first] << endl;
  }
}