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
#include <cassert>
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
typedef vector<int> VI;
typedef pair<int, int> PII;

#line 41 "FixedNumberOfDigits.cpp"
#include <string>
#include <vector>
class FixedNumberOfDigits {
public:
    long long sum(int start, int step, long long numberOfDigits) {
	LL a = start, d = step;
	LL k = 1, p = 1;
	while (10 * p <= a) {
	    p *= 10;
	    k++;
	}
	while (true) {
	    LL next = (10 * p) / d * d + (a % d);
	    while (next >= 10 * p) {
		next -= d;
	    }
	    LL cnt = ((next - a) / d + 1) * k;
	    if (cnt < numberOfDigits) {
		numberOfDigits -= cnt;
		a = next + d;
		p *= 10;
		k++;
	    } else {
		a += numberOfDigits / k * d;
		numberOfDigits %= k;
		if (numberOfDigits == 0) {
		    return a - d;
		}
		while (numberOfDigits < k) {
		    a /= 10;
		    numberOfDigits++;
		}
		return a;
	    }
	}
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You are writing down numbers in increasing order, starting with start and increasing by step.
You stop after writing down numberOfDigits digits total.
You stop immediately, even if it's in the middle of a number.


Calculate and return the last number you wrote.


DEFINITION
Class:FixedNumberOfDigits
Method:sum
Parameters:int, int, long long
Returns:long long
Method signature:long long sum(int start, int step, long long numberOfDigits)


CONSTRAINTS
-start will be between 0 and 10^9, inclusive.
-step will be between 1 and 10, inclusive.
-numberOfDigits will be between 1 and 10^16, inclusive.


EXAMPLES

0)
47
10
7

Returns: 7

You will write down "47, 57, 67, 7" and stop. The last number you wrote down was 7.

1)
98
1
10

Returns: 101

You will write down "98, 99, 100, 101". The last number written down is 101.

2)
0
1
7

Returns: 6



3)
123456789
10
5

Returns: 12345



4)
123456789
10
17

Returns: 12345679



*/
// END CUT HERE

// BEGIN CUT HERE
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
		cout << "Testing FixedNumberOfDigits (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1595088327;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		FixedNumberOfDigits _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int start = 47;
				int step = 10;
				long long numberOfDigits = 7LL;
				_expected = 7LL;
				_received = _obj.sum(start, step, numberOfDigits); break;
			}
			case 1:
			{
				int start = 98;
				int step = 1;
				long long numberOfDigits = 10LL;
				_expected = 101LL;
				_received = _obj.sum(start, step, numberOfDigits); break;
			}
			case 2:
			{
				int start = 0;
				int step = 1;
				long long numberOfDigits = 7LL;
				_expected = 6LL;
				_received = _obj.sum(start, step, numberOfDigits); break;
			}
			case 3:
			{
				int start = 123456789;
				int step = 10;
				long long numberOfDigits = 5LL;
				_expected = 12345LL;
				_received = _obj.sum(start, step, numberOfDigits); break;
			}
			case 4:
			{
				int start = 123456789;
				int step = 10;
				long long numberOfDigits = 17LL;
				_expected = 12345679LL;
				_received = _obj.sum(start, step, numberOfDigits); break;
			}
			/*case 5:
			{
				int start = ;
				int step = ;
				long long numberOfDigits = LL;
				_expected = LL;
				_received = _obj.sum(start, step, numberOfDigits); break;
			}*/
			/*case 6:
			{
				int start = ;
				int step = ;
				long long numberOfDigits = LL;
				_expected = LL;
				_received = _obj.sum(start, step, numberOfDigits); break;
			}*/
			/*case 7:
			{
				int start = ;
				int step = ;
				long long numberOfDigits = LL;
				_expected = LL;
				_received = _obj.sum(start, step, numberOfDigits); break;
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
