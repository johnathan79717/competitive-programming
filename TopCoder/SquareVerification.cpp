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
typedef vector<int> VI;
typedef pair<int, int> PII;

struct SquareVerification {
  int calculateCode(int x) {
  	LL y = (LL) x * x;
  	LL ans = 0;
  	while(y) {
  		ans = max(ans, y % 10);
  		y /= 10;
  	}
  	return ans;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You have received an integer x from a transmission. Now 
the sender requests you to send him back a specific 
integer d obtained from x so that he could verify whether 
the transmission was correct. In order to find d, you 
first need to calculate y = x*x and then to find the 
largest digit of y in decimal notation.

Given an int x, return the value of d.


DEFINITION
Class:SquareVerification
Method:calculateCode
Parameters:int
Returns:int
Method signature:int calculateCode(int x)


CONSTRAINTS
-x will be between 1 and 10,000, inclusive.


EXAMPLES

0)
2

Returns: 4

2*2 = 4. 4 contains only one digit : 4.

1)
13

Returns: 9

13*13 = 169.

2)
766

Returns: 8



3)
777

Returns: 9



4)
1111

Returns: 4



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
		cout << "Testing SquareVerification (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1406529047;
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
		SquareVerification _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x = 2;
				_expected = 4;
				_received = _obj.calculateCode(x); break;
			}
			case 1:
			{
				int x = 13;
				_expected = 9;
				_received = _obj.calculateCode(x); break;
			}
			case 2:
			{
				int x = 766;
				_expected = 8;
				_received = _obj.calculateCode(x); break;
			}
			case 3:
			{
				int x = 777;
				_expected = 9;
				_received = _obj.calculateCode(x); break;
			}
			case 4:
			{
				int x = 1111;
				_expected = 4;
				_received = _obj.calculateCode(x); break;
			}
			/*case 5:
			{
				int x = ;
				_expected = ;
				_received = _obj.calculateCode(x); break;
			}*/
			/*case 6:
			{
				int x = ;
				_expected = ;
				_received = _obj.calculateCode(x); break;
			}*/
			/*case 7:
			{
				int x = ;
				_expected = ;
				_received = _obj.calculateCode(x); break;
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
