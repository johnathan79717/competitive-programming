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
#define REP(i,n) for(int i=0;i<(n);i++)
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#line 41 "EllysAndXor.cpp"
#include <string>
#include <vector>
class EllysAndXor {
public:
    int getMax(vector <int> numbers) {
	int N = numbers.size();
	int ans = 0;
	REP(mask, 1<<(N-1)) {
	    int n = numbers[0];
	    REP(i, N-1) {
		if ((mask >> i) & 1) {
		    n = n & numbers[i+1];
		} else {
		    n = n ^ numbers[i+1];
		}
	    }
	    ans = max(ans, n);
	}
	return ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Elly has a sequence of small positive integers. You are given this sequence in the vector <int> numbers. The girl wants to place a bitwise AND operator ('&') or a bitwise XOR operator ('^') between each pair of neighboring numbers. Now she wonders what is the maximal result that can be achieved if using optimal placement of operations between the integers?
For this task we will assume that the operations AND and XOR have equal priority (precedence), thus the expression is evaluated left to right. For example, 42 ^ 26 & 38 will be evaluated as (42 ^ 27) & 38 = 49 & 38 = 32. Note, however, that the maximal answer for the numbers (42, 27, 38) is achieved by using the expression 42 & 27 ^ 38 = (42 & 27) ^ 38 = 10 ^ 38 = 44.

DEFINITION
Class:EllysAndXor
Method:getMax
Parameters:vector <int>
Returns:int
Method signature:int getMax(vector <int> numbers)


NOTES
-The result of the bitwise operation AND (denoted as '&') applied on two integers is a new integer, having 1-bits on each position where both integers had a 1 in their binary representation, and 0 on all others. For example, 42(10) & 27(10) = 101010(2) & 011011(2) = 001010(2) = 10(10).
-The result of the bitwise operation XOR (denoted as '^') applied on two integers is a new integer, having 1-bits on each position where exactly one of the integers had a 1 in their binary representation, and 0 on all others. For example, 42(10) ^ 27(10) = 101010(2) ^ 011011(2) = 110001(2) = 49(10).


CONSTRAINTS
-numbers will contain between 1 and 10 elements, inclusive.
-Each element of numbers will be between 1 and 1000, inclusive.


EXAMPLES

0)
{42, 27, 38}

Returns: 44

The example from the problem statement.

1)
{666, 133, 438, 123, 893, 674, 462, 209}

Returns: 976



2)
{42}

Returns: 42

The result of an expression with a single number equals the number.

3)
{123, 456, 789, 987, 654, 321}

Returns: 975



4)
{42, 13, 17, 666, 811, 314, 1, 5, 2, 1000}

Returns: 1007

Please note that the answer can go over 1000.

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
		cout << "Testing EllysAndXor (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1587207061;
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
		EllysAndXor _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int numbers[] = {42, 27, 38};
				_expected = 44;
				_received = _obj.getMax(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 1:
			{
				int numbers[] = {666, 133, 438, 123, 893, 674, 462, 209};
				_expected = 976;
				_received = _obj.getMax(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 2:
			{
				int numbers[] = {42};
				_expected = 42;
				_received = _obj.getMax(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 3:
			{
				int numbers[] = {123, 456, 789, 987, 654, 321};
				_expected = 975;
				_received = _obj.getMax(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 4:
			{
				int numbers[] = {42, 13, 17, 666, 811, 314, 1, 5, 2, 1000};
				_expected = 1007;
				_received = _obj.getMax(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			/*case 5:
			{
				int numbers[] = ;
				_expected = ;
				_received = _obj.getMax(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int numbers[] = ;
				_expected = ;
				_received = _obj.getMax(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int numbers[] = ;
				_expected = ;
				_received = _obj.getMax(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
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
