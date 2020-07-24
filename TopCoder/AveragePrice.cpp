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

#line 41 "AveragePrice.cpp"
#include <string>
#include <vector>
class AveragePrice {
public:
    double nonDuplicatedAverage(vector <int> prices) {
	set<int> s;
	for (int p: prices) {
	    s.insert(p);
	}
	double sum = 0; 
	for (int p: s) {
	    sum += p;
	}
	return sum / s.size();
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You have scanned the prices of several products for sale. You now wish to determine the average product price.  Unfortunately, you know that you have been sloppy, and you may have scanned some products more than once.  However, you know that you have scanned every product at least once, and that no two products have exactly the same price.  Given vector <int> prices containing the prices you have scanned, return a double indicating the average (mean) product price.


DEFINITION
Class:AveragePrice
Method:nonDuplicatedAverage
Parameters:vector <int>
Returns:double
Method signature:double nonDuplicatedAverage(vector <int> prices)


NOTES
-Returned value must be within 1e-9 absolute or relative error of the reference output to be considered correct.


CONSTRAINTS
-prices will contain between 1 and 50 elements, inclusive.
-Each element of prices will be between 1 and 10000, inclusive.


EXAMPLES

0)
{ 10, 20, 10 }

Returns: 15.0


There are two items, with prices of 10 and 20. We scanned the item priced 10 more than once.


The average price of an item is (10 + 20) / 2 = 15.


1)
{ 1, 2, 3, 4, 5 }

Returns: 3.0

There are five items, we didn't scan any of them more than once.

2)
{ 10, 10, 10, 10, 10, 10 }

Returns: 10.0

Only one item, which apparently we really enjoyed scanning.

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
		cout << "Testing AveragePrice (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1587226202;
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
		AveragePrice _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int prices[] = { 10, 20, 10 };
				_expected = 15.0;
				_received = _obj.nonDuplicatedAverage(vector <int>(prices, prices+sizeof(prices)/sizeof(int))); break;
			}
			case 1:
			{
				int prices[] = { 1, 2, 3, 4, 5 };
				_expected = 3.0;
				_received = _obj.nonDuplicatedAverage(vector <int>(prices, prices+sizeof(prices)/sizeof(int))); break;
			}
			case 2:
			{
				int prices[] = { 10, 10, 10, 10, 10, 10 };
				_expected = 10.0;
				_received = _obj.nonDuplicatedAverage(vector <int>(prices, prices+sizeof(prices)/sizeof(int))); break;
			}
			/*case 3:
			{
				int prices[] = ;
				_expected = ;
				_received = _obj.nonDuplicatedAverage(vector <int>(prices, prices+sizeof(prices)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int prices[] = ;
				_expected = ;
				_received = _obj.nonDuplicatedAverage(vector <int>(prices, prices+sizeof(prices)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int prices[] = ;
				_expected = ;
				_received = _obj.nonDuplicatedAverage(vector <int>(prices, prices+sizeof(prices)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
