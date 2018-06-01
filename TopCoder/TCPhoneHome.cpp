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
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#line 40 "TCPhoneHome.cpp"
#include <string>
#include <vector>
class TCPhoneHome {
public:
  long long validNumbers(int digits, vector <string> specialPrefixes) {

  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Typically, telephone numbers are sequences of digits (0-9) that all have the same length.
However, some prefixes may be reserved for special purposes.
This limits the total number of possible full-length telephone numbers that are available for general use in the system.

As an example, in much of the United States and Canada the local telephone numbers are 7 digits long.
However, dialing 1 starts a special sequence for long distance, dialing 0 connects to the operator, and dialing 911 connects to emergency services.
Thus, there are fewer than the theoretical 10,000,000 possible valid telephone numbers.

You are given the int digits: the length of the standard telephone numbers in the system.
You are also given a vector <string> specialPrefixes.
Each element of specialPrefixes is a string of digits that defines one reserved prefix.
Standard telephone numbers cannot start with any of the reserved prefixes.

Compute and return the number of different standard telephone numbers in the system.


DEFINITION
Class:TCPhoneHome
Method:validNumbers
Parameters:int, vector <string>
Returns:long long
Method signature:long long validNumbers(int digits, vector <string> specialPrefixes)


CONSTRAINTS
-digits will be between 1 and 17, inclusive.
-specialPrefixes will contain beteween 0 and 50 elements, inclusive.
-The length of each element of specialPrefixes will be between 1 and digits, inclusive.
-Each character of each element of specialPrefixes will be a digit ('0'...'9').
-No two elements of specialPrefixes will be the same.


EXAMPLES

0)
7
{"0", "1", "911"}

Returns: 7990000

The example from the problem statement.

1)
10
{"0", "1", "911"}

Returns: 7990000000

Same prefixes, longer numbers.

2)
8
{"1", "12", "123"}

Returns: 90000000

The sets of numbers reserved by different special prefixes may sometimes overlap.
For example, in this case the net effect of these three special prefixes is that all numbers that start with "1" are reserved.

3)
9
{"12", "13", "14"}

Returns: 970000000



4)
3
{"411"}

Returns: 999

Sometimes a "prefix" is actually a full length phone number that is specially reserved for some reason.

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
		cout << "Testing TCPhoneHome (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1510952584;
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
		TCPhoneHome _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int digits = 7;
				string specialPrefixes[] = {"0", "1", "911"};
				_expected = 7990000LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
			}
			case 1:
			{
				int digits = 10;
				string specialPrefixes[] = {"0", "1", "911"};
				_expected = 7990000000LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
			}
			case 2:
			{
				int digits = 8;
				string specialPrefixes[] = {"1", "12", "123"};
				_expected = 90000000LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
			}
			case 3:
			{
				int digits = 9;
				string specialPrefixes[] = {"12", "13", "14"};
				_expected = 970000000LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
			}
			case 4:
			{
				int digits = 3;
				string specialPrefixes[] = {"411"};
				_expected = 999LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
			}
			/*case 5:
			{
				int digits = ;
				string specialPrefixes[] = ;
				_expected = LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int digits = ;
				string specialPrefixes[] = ;
				_expected = LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				int digits = ;
				string specialPrefixes[] = ;
				_expected = LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
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
