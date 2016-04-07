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
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

struct SquareDivisor {
	long long is_square(long long n) {
  	long long r = sqrt(n);
  	while((r+1) * (r+1) <= n) r++;
  	while((r-1) * (r-1) >= n) r--;
  	if(r * r == n) return r * r;
  	return 0;
	}
  long long biggest(long long n) {
  	long long ans = max(1ll, is_square(n));
  	REP1(p, 2, 1000000) {
  		if(n % p) continue;
  		if(n % ((LL) p * p) == 0) ans = max(ans, (LL)p * p);
			ans = max(ans, is_square(n / p));
  	}
  	return ans;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You are given a long long n.
Return the largest divisor of n that is a perfect square.
That is, the correct return value is x if and only if:

x divides n
There is an integer y such that x = y*y.
x is the largest integer that satisfies conditions 1 and 2.


DEFINITION
Class:SquareDivisor
Method:biggest
Parameters:long long
Returns:long long
Method signature:long long biggest(long long n)


CONSTRAINTS
-n will be between 1 and 10^18, inclusive.


EXAMPLES

0)
12

Returns: 4

12 has six divisors: 1, 2, 3, 4, 6, and 12. Among them, 
only 1 and 4 are perfect squares. You should return the 
biggest one.

1)
100

Returns: 100



2)
2014

Returns: 1



3)
999999875021574338

Returns: 499999937510787169



4)
999999998000000002

Returns: 1



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
		cout << "Testing SquareDivisor (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1406529388;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SquareDivisor _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long n = 12LL;
				_expected = 4LL;
				_received = _obj.biggest(n); break;
			}
			case 1:
			{
				long long n = 100LL;
				_expected = 100LL;
				_received = _obj.biggest(n); break;
			}
			case 2:
			{
				long long n = 2014LL;
				_expected = 1LL;
				_received = _obj.biggest(n); break;
			}
			case 3:
			{
				long long n = 999999875021574338LL;
				_expected = 499999937510787169LL;
				_received = _obj.biggest(n); break;
			}
			case 4:
			{
				long long n = 999999998000000002LL;
				_expected = 1LL;
				_received = _obj.biggest(n); break;
			}
			/*case 5:
			{
				long long n = LL;
				_expected = LL;
				_received = _obj.biggest(n); break;
			}*/
			/*case 6:
			{
				long long n = LL;
				_expected = LL;
				_received = _obj.biggest(n); break;
			}*/
			/*case 7:
			{
				long long n = LL;
				_expected = LL;
				_received = _obj.biggest(n); break;
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
