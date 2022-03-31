#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
#include <iomanip>
#include <cctype>
#include <list>
#include <cassert>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define ll long long
#define repi(i,a,b) for(ll i=a;i<b;++i)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
using vvv = vector<vector<vector<ll>>>;
using vv = vector<vector<ll>>;
using vec = vector<ll>;
using P = pair<ll, ll>;

int main(void){
   ll n; cin >> n;
   ++n;
   vec al(n);
   rep(i, n) cin >> al[i];
   reverse(all(al));
   ll ans = 0;
   vec ansl(n);
   ll tmp = 1;
   rep(i, n){
       tmp = min(tmp, (ll)10000000000000);
       if(al[n - i - 1] > tmp) ans = -1;
       //cout << al[i] << " " << tmp << endl;
       ansl[n - i - 1] = tmp;
       tmp *= 2;
   }
   ansl[0] = al[0];
   
   rep(i , n){
       if(i + 1 >= n) break;
       if(ansl[i + 1] < al[i + 1]){
           ans = -1;
       }
       //cout << ansl[i + 1] << " " << ansl[i] << " " << al[i] << endl;
       ansl[i + 1] = min(ansl[i + 1] , ansl[i] + al[i + 1]);
   }
   
   reverse(all(al));
   reverse(all(ansl));
   
   //rep(i, n) cout << ansl[i] << endl;
   
   rep(i, n){
       if(i + 1 >= n) break;
       ansl[i + 1] = min(ansl[i + 1], (ansl[i] - al[i]) * 2);
       if(ansl[i + 1] - al[i + 1] < 0) ans = -1;
   }
   //rep(i, n) cout << ansl[i] << endl;
   if(ans != -1){
       rep(i, n) ans += ansl[i];
   }
   cout << ans << endl;
}
