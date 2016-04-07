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
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define ALL(x) (x).begin(),(x).end()
#define FOR(i, c) for(auto &i: c)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define V(T) vector<T >
#define EB emplace_back
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int MOD = 1000000007;
struct Z {
  int i;
  Z():i(0) {}
  Z(int i): i(i >= 0 ? i : i + MOD) {}
  void operator +=(const Z& z) { i += z.i; if(i >= MOD) i -= MOD; }
  void operator -=(const Z& z) { i -= z.i; if(i < 0) i += MOD; }
  void operator *=(const Z& z) { i = (LL) i * z.i % MOD; }
  void operator /=(const Z& z) { (*this) *= z.inverse(); }
  Z operator +(const Z& z) const { Z ret(i); ret += z; return ret; }
  Z operator -(const Z& z) const { Z ret(i); ret -= z; return ret; }
  Z operator *(const Z& z) const { Z ret(i); ret *= z; return ret; }
  Z operator /(const Z& z) const { return (*this) * z.inverse(); }
  // Z operator -() const { return Z(-i); }
  Z inverse() const {
    int a = i, d = MOD, x = 0, s = 1;
    while(a) {
      int q = d / a, r = d % a, t = x - q * s;
      d = a, a = r, x = s, s = t;
    }
    if (d != 1) return -1;
    return x < 0 ? x + MOD : x;
  }
  Z pow(int b) {
    Z x=1,y=*this; // ll is taken to avoid overflow of intermediate results
    while(b > 0){
      if(b%2 == 1)
        x *= y;
      y *= y; // squaring the base
      b /= 2;
    }
    return x;
  }
};

vector<Z> factorial(1, 1), inv_factorial(1, 1);

Z inv_fact(int n) {
  while(inv_factorial.size() <= n)
    inv_factorial.push_back(inv_factorial.back() / inv_factorial.size());
  return inv_factorial.at(n);
}

Z fact(int n) {
  while(factorial.size() <= n)
    factorial.push_back(factorial.back() * factorial.size());
  return factorial.at(n);
}

Z choose(int n, int k) {
  if(n < k) return 0;
  return fact(n) * (inv_fact(k) * inv_fact(n-k));
}

class AquaparkPuzzle {
	public:
	int countSchedules(int k, int m, vector <int> c) {
		int N = c.size();
		VI cand;
		REP(mask, 1 << N) {
			int sum = 0;
			REP(i, N) {
				if ((mask >> i) & 1) {
					sum += c[i];
				}
			}
			if (sum <= m) {
				cand.PB(mask);
			}
		}

		VI prev(1 << N), next(1 << N);


		Z ans = 0;
		REP(mask, 1 << N) {
			int len = 0;
			REP(i, N) {
				if ((mask >> i) & 1) {
					len += 1;
				}
			}
			int cnt = 0;
			FOR(c, cand) {
				if (!(mask & c)) {
					cnt++;
				}
			}
			if (len % 2)
				ans -= Z(cnt).pow(k);
			else
				ans += Z(cnt).pow(k);
		}
		return ans.i;
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Young Ania's dream has come true: a great aquapark was built in her town.
There are many attractions in the aquapark.
For each valid i, there is an attraction that costs c[i] dollars.

Ania is going to visit the aquapark exactly k times.
As she doesn't have too much money, she decided that:

during each visit she is going to visit each attraction at most once
during each visit she will spend at most m dollars on attractions


You are given the ints k and m, and the vector <int> c.
You know that during her k visits to the aquapark Ania wants to visit each attraction at least twice.
Count the number of ways in which she can do so, and return that count modulo 1,000,000,007.

Two ways are considered different if there are integers i and j such that on the i-th visit to the aquapark she is going to visit the j-th attraction in one of the ways but not in the other.


DEFINITION
Class:AquaparkPuzzle
Method:countSchedules
Parameters:int, int, vector <int>
Returns:int
Method signature:int countSchedules(int k, int m, vector <int> c)


NOTES
-During some visits to the aquapark Ania may not visit any attractions at all.


CONSTRAINTS
-k will be between 2 and 1,000,000, inclusive.
-m will be between 1 and 1,000, inclusive.
-Each element of c will be between 1 and 1,000, inclusive. 
-c will have between 2 and 11 elements.


EXAMPLES

0)
3
3
{1, 2}

Returns: 16

Ania has enough money to visit all attractions during each visit to the aquapark, so we can treat each attraction independently.
For each attraction we have 4 possibilities: either she visits it all three times, or she skips it on one of her three visits to the aquapark.
Hence, there are 4*4 = 16 valid schedules.

1)
3
3
{2, 2}

Returns: 0

During each visit Ania can only afford one attraction.
Given that constraint, three visits to the aquapark are not enough to visit each attraction at least twice.

2)
4
3
{1, 2, 2}

Returns: 66



3)
6
7
{2, 3, 4, 7}

Returns: 4800



4)
1000
20
{8, 2, 13, 18, 7, 3}

Returns: 15681195



*/
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing AquaparkPuzzle (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1421080347;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AquaparkPuzzle _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int k = 3;
				int m = 3;
				int c[] = {1, 2};
				_expected = 16;
				_received = _obj.countSchedules(k, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 1:
			{
				int k = 3;
				int m = 3;
				int c[] = {2, 2};
				_expected = 0;
				_received = _obj.countSchedules(k, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 2:
			{
				int k = 4;
				int m = 3;
				int c[] = {1, 2, 2};
				_expected = 66;
				_received = _obj.countSchedules(k, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 3:
			{
				int k = 6;
				int m = 7;
				int c[] = {2, 3, 4, 7};
				_expected = 4800;
				_received = _obj.countSchedules(k, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 4:
			{
				int k = 1000;
				int m = 20;
				int c[] = {8, 2, 13, 18, 7, 3};
				_expected = 15681195;
				_received = _obj.countSchedules(k, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			/*case 5:
			{
				int k = ;
				int m = ;
				int c[] = ;
				_expected = ;
				_received = _obj.countSchedules(k, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int k = ;
				int m = ;
				int c[] = ;
				_expected = ;
				_received = _obj.countSchedules(k, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int k = ;
				int m = ;
				int c[] = ;
				_expected = ;
				_received = _obj.countSchedules(k, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
