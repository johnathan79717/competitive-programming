
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
 
typedef unsigned long long ll;
 
#define MOD 1000000007

ll pow(ll a, ll b, ll c){
    ll x=1,y=a%c; // ll is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; // squaring the base
        b /= 2;
    }
    return x;
}
 
ll solve() {
  ll V, N, P0, P1, A0, B0, C0, M0, Q0, Q1, A1, B1, C1, M1;
  ll L[100], P[100], Q[100];
  scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld", &V, &N, P, P+1, &A0, &B0, &C0, &M0, Q, Q+1, &A1, &B1, &C1, &M1);
  L[0] = P[0] * M1 + Q[0];
  L[1] = P[1] * M1 + Q[1];
  if(!L[0] || !L[1])
    return 1;
  for(ll i = 2; i < N; ++i) {
    P[i] = (A0 * A0 * P[i-1] + B0 * P[i-2] + C0) % M0;
    Q[i] = (A1 * A1 * Q[i-1] + B1 * Q[i-2] + C1) % M1;
    L[i] = P[i] * M1 + Q[i];
    if(!L[i])
      return 1;
  }
  if(V % MOD == 0)
    return 0;

  // L[0] = L[1] = V = (1ll<<63) - 1;

  ll power = 1;
  // ll ans = V;
  for(ll i = 0; i < N; ++i)
    power = ((L[i] % (MOD - 1)) * power) % (MOD - 1);
  return pow(V, power, MOD);
}
 
int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    printf("%llu\n", solve());
  }
} 