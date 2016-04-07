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

class ChangingChange {
	public:
	vector <int> countWays(vector <int> ways, vector <int> valueRemoved, vector <int> numRemoved) {
		
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// John is a coin collector.
Each of the coins in his collection has an integer value.
Each value is between 1 and D, inclusive.
It is possible that multiple coins have the same value.
It is also possible that some of the possible coin values are not present in John's collection.
John can distinguish between any two coins, even if they have the same value.

You don't know what coins are in John's collection.
The only information you have about the collection is the vector <int> ways with D+1 elements.
Let f(x) be the number of ways to make x dollars using some subset of John's coins.
For each i from 0 to D, inclusive, ways[i] is equal to (f(i) mod 1,000,000,007).

For example, suppose that John's collection consists of two coins, each worth 1 dollar.
Then, f(0) = 1, f(1) = 2, f(2) = 1, and f(x) = 0 for x greater than 2.
(Note that the empty subset of John's coins is worth 0 dollars, hence f(0) = 1.)

John is considering giving some of his coins to his nephew.
He came up with Q independent scenarios.
The scenarios are numbered from 0 to Q-1.
For each valid i, in scenario i John will keep his entire collection, with one exception:
he will give numRemoved[i] coins, each with value valueRemoved[i], to his nephew.
You may assume that all scenarios are valid: numRemoved[i] never exceeds the number of available coins in John's collection.

John now asked you the same question about each scenario:
"After I give the selected coins to my nephew, what will be the value (f(D) mod 1,000,000,007) for my new collection?"

You are given the vector <int>s ways, valueRemoved, and numRemoved.
Return a vector <int> with Q elements.
For each valid i, element i of the return value should be the answer to the question about scenario i.

DEFINITION
Class:ChangingChange
Method:countWays
Parameters:vector <int>, vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> countWays(vector <int> ways, vector <int> valueRemoved, vector <int> numRemoved)


NOTES
-You may assume that the answer to the question about each scenario is the same for all possible collections that correspond to the input data.


CONSTRAINTS
-D will be between 1 and 1999, inclusive.
-ways will contain exactly D+1 elements.
-Each element of ways will be between 0 and 1,000,000,006, inclusive.
-Q will be between 1 and 2000, inclusive.
-valueRemoved will contain exactly Q elements.
-numRemoved will contain exactly Q elements.
-Each element of valueRemoved will be between 1 and D, inclusive.
-Each element of numRemoved will be between 1 and 1,000,000, inclusive.
-There is at least one possible collection of coins that corresponds to the values in ways and makes all scenarios described by valueRemoved and numRemoved possible.


EXAMPLES

0)
{1, 4, 6}
{1, 1, 1}
{1, 2, 3}

Returns: {3, 1, 0 }

Given the input data, one possibility is that John's collection consists of four coins worth 1 dollar each.
For this collection:

If John gives 1 of the 1-dollar coins to his nephew, f(2) will be 3.
If John gives 2 of the 1-dollar coins to his nephew, f(2) will be 1.
If John gives 3 of the 1-dollar coins to his nephew, f(2) will be 0.


1)
{1, 2, 1, 0, 0, 0, 0, 0, 7}
{8, 8, 1, 1}
{1, 7, 1, 2}

Returns: {6, 0, 7, 7 }

John's collection may consist of two coins worth 1 dollar each and seven coins worth 8 dollars each.

2)
{1, 2, 3, 6, 9, 14}
{1, 2, 3, 4, 5, 1, 2, 3, 4, 5}
{1, 1, 1, 1, 1, 2, 2, 2, 2, 2}

Returns: {9, 10, 11, 12, 13, 6, 8, 8, 10, 12 }

John's collection may consist of ten coins: for each x between 1 and 5, inclusive, there are two coins worth x dollars each.

3)
{1, 0}
{1, 1}
{1, 1000000}

Returns: {1000000006, 999000007 }

Remember that the values in ways are given modulo 1,000,000,007 and that your return values must also be given modulo 1,000,000,007.

4)
{1, 2, 3, 6, 9, 14}
{1, 3, 5}
{1000000, 4, 2}

Returns: {34955525, 2, 12 }



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
		cout << "Testing ChangingChange (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1437796487;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ChangingChange _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int ways[] = {1, 4, 6};
				int valueRemoved[] = {1, 1, 1};
				int numRemoved[] = {1, 2, 3};
				int __expected[] = {3, 1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.countWays(vector <int>(ways, ways+sizeof(ways)/sizeof(int)), vector <int>(valueRemoved, valueRemoved+sizeof(valueRemoved)/sizeof(int)), vector <int>(numRemoved, numRemoved+sizeof(numRemoved)/sizeof(int))); break;
			}
			case 1:
			{
				int ways[] = {1, 2, 1, 0, 0, 0, 0, 0, 7};
				int valueRemoved[] = {8, 8, 1, 1};
				int numRemoved[] = {1, 7, 1, 2};
				int __expected[] = {6, 0, 7, 7 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.countWays(vector <int>(ways, ways+sizeof(ways)/sizeof(int)), vector <int>(valueRemoved, valueRemoved+sizeof(valueRemoved)/sizeof(int)), vector <int>(numRemoved, numRemoved+sizeof(numRemoved)/sizeof(int))); break;
			}
			case 2:
			{
				int ways[] = {1, 2, 3, 6, 9, 14};
				int valueRemoved[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
				int numRemoved[] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
				int __expected[] = {9, 10, 11, 12, 13, 6, 8, 8, 10, 12 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.countWays(vector <int>(ways, ways+sizeof(ways)/sizeof(int)), vector <int>(valueRemoved, valueRemoved+sizeof(valueRemoved)/sizeof(int)), vector <int>(numRemoved, numRemoved+sizeof(numRemoved)/sizeof(int))); break;
			}
			case 3:
			{
				int ways[] = {1, 0};
				int valueRemoved[] = {1, 1};
				int numRemoved[] = {1, 1000000};
				int __expected[] = {1000000006, 999000007 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.countWays(vector <int>(ways, ways+sizeof(ways)/sizeof(int)), vector <int>(valueRemoved, valueRemoved+sizeof(valueRemoved)/sizeof(int)), vector <int>(numRemoved, numRemoved+sizeof(numRemoved)/sizeof(int))); break;
			}
			case 4:
			{
				int ways[] = {1, 2, 3, 6, 9, 14};
				int valueRemoved[] = {1, 3, 5};
				int numRemoved[] = {1000000, 4, 2};
				int __expected[] = {34955525, 2, 12 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.countWays(vector <int>(ways, ways+sizeof(ways)/sizeof(int)), vector <int>(valueRemoved, valueRemoved+sizeof(valueRemoved)/sizeof(int)), vector <int>(numRemoved, numRemoved+sizeof(numRemoved)/sizeof(int))); break;
			}
			/*case 5:
			{
				int ways[] = ;
				int valueRemoved[] = ;
				int numRemoved[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.countWays(vector <int>(ways, ways+sizeof(ways)/sizeof(int)), vector <int>(valueRemoved, valueRemoved+sizeof(valueRemoved)/sizeof(int)), vector <int>(numRemoved, numRemoved+sizeof(numRemoved)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int ways[] = ;
				int valueRemoved[] = ;
				int numRemoved[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.countWays(vector <int>(ways, ways+sizeof(ways)/sizeof(int)), vector <int>(valueRemoved, valueRemoved+sizeof(valueRemoved)/sizeof(int)), vector <int>(numRemoved, numRemoved+sizeof(numRemoved)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int ways[] = ;
				int valueRemoved[] = ;
				int numRemoved[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.countWays(vector <int>(ways, ways+sizeof(ways)/sizeof(int)), vector <int>(valueRemoved, valueRemoved+sizeof(valueRemoved)/sizeof(int)), vector <int>(numRemoved, numRemoved+sizeof(numRemoved)/sizeof(int))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
