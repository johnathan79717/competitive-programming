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
 
typedef long long LL;

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

struct Byteland {
  int CountDifferentMaps(int n, int k) {
  	Z ans = choose(n-1, k) * n * choose(n-2, k-1) * fact(n-k-1);
  	return ans.i;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Long long ago the people in Byteland were almost wild and 
had no cities.
But there was one place they all liked and called it the 
Central Place of the Universe (CPU).
People where coming to CPU from all parts of Byteland at 
least once per year.
As a result, the country soon contained exactly k roads.
The roads were pairwise disjoint, except for one endpoint: 
each of the roads started at the CPU.

Later, Bytelandians decided to build some cities.
Of course, each city needs a name, so they first came up 
with some names: Byte City, Bit City, New Byte, 7Bit, Hard 
Drive, Medium Drive, and many others.
Together, they came up with exactly n names for the cities.
Therefore, they decided to build exactly n cities.
The locations (but not names) of k + 1 of those cities are 
certain: one city has to contain the CPU, and k other 
cities will lie on the opposite ends of the k roads.
Bytelandians do not want to build any more roads, 
therefore each of the remaining n − k − 1 cities has to be 
built on one of the roads.
Sadly, this still leaves a lot of options.

The Council of Elders started to draw all possible maps of 
Byteland so they can choose the nicest one and build the 
cities accordingly.
For a particular map, two cities A and B are considered 
neighbors if we can get from A to B along one of the 
roads, without passing through another city.
Two maps are different if and only if there is a city such 
that the set of its neighbors on one map is not equal to 
the set of its neighbors on the other map.

You are given the integer n and k.
Compute and return the number of different maps, modulo 
1,000,000,007.


DEFINITION
Class:Byteland
Method:CountDifferentMaps
Parameters:int, int
Returns:int
Method signature:int CountDifferentMaps(int n, int k)


CONSTRAINTS
-n will be between 2 and 2^20, inclusive.
-k will be between 1 and n − 1, inclusive.


EXAMPLES

0)
5
4

Returns: 5

There are 5 ways how to choose the central city (the one 
that will contain the CPU). For each choice there is only 
one possible map.

1)
6
3

Returns: 720

There are 5 ways how to choose the central city. For each 
such choice we know that there has to be one road with two 
cities and two roads with one city. There are 6 ways how 
to choose the two separate cities, and for each of them 
there are two ways for the order of the remaining two 
cities on their road. This gives us a total of 5 × 6 
&times 2 = 60 possible maps.

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
		cout << "Testing Byteland (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1406529886;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Byteland _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 5;
				int k = 4;
				_expected = 5;
				_received = _obj.CountDifferentMaps(n, k); break;
			}
			case 1:
			{
				int n = 6;
				int k = 3;
				_expected = 720;
				_received = _obj.CountDifferentMaps(n, k); break;
			}
			/*case 2:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.CountDifferentMaps(n, k); break;
			}*/
			/*case 3:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.CountDifferentMaps(n, k); break;
			}*/
			/*case 4:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.CountDifferentMaps(n, k); break;
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
