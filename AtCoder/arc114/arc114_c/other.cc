#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <fstream>
#include <chrono>
#include <random>
#include <bitset>
//#include <atcoder/all>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)(x).size())
#define pb push_back
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}

const ll mod = 998244353;

ll mpow(ll a, ll x){
  ll res = 1;
  while(x > 0){
    if(x & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    x >>= 1;
  }
  return res;
}

int main(){
  ll N,M; cin >> N >> M;
  ll ans = N*mpow(M,N)%mod;
  ll cnt = 0;
  for(ll l=1;l<N;l++){
    ll els = mpow(M,N-1-l);
    ll pos = N-l;

    for(ll x=1;x<=M;x++){
      ll lft = M-x;
      ll ovr = mpow(lft,l-1);
      cnt += (ovr*els%mod)*pos%mod;
      cnt %= mod;
    }
  }

  cout << (ans-cnt+mod)%mod << endl;
  return 0;
}

