#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <deque>
#include <climits>
#include <set>
#include <vector>
#include <functional>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <list>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
 
typedef long long LL;
#define MOD 1000000007

inline int mul(int a, int b) { return (LL)a * b % MOD; }

int pow(int a, int b) {
  int x=1,y=a; // ll is taken to avoid overflow of intermediate results
  while(b > 0){
    if(b%2 == 1){
      x=mul(x, y);
    }
    y = mul(y, y); // squaring the base
    b /= 2;
  }
  return x;
}

inline int add(int a, int b) { return a + b < MOD ? a + b : a + b - MOD; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + MOD : a - b; }


class PairsOfStrings {
public:
  int getNumber(int n, int k) {
    vector<int> divisors;
    for(int p = 1; p * p <= n; p++) {
      if(n % p == 0) {
        divisors.PB(p);
        if(n / p != p) divisors.PB(n / p);
      }
    }
    sort(ALL(divisors));
    int ans = 0;
    unordered_map<int, int> map;
    for(int d : divisors) {
      int a = pow(k, d);
      for(int d1 : divisors) {
        if(d1 >= d) break;
        if(d % d1) continue;
        a = sub(a, map[d1]);
      }
      // cout << d << ' ' << a << endl;
      ans = add(ans, mul(a, d));
      map[d] = a;
    }
    return ans;
  }
};

// BEGIN CUT HERE
int main() {	
  PairsOfStrings test;
  int n, k;
  while(cin >> n >> k)
    cout << test.getNumber(n, k) << endl;
}
// END CUT HERE
