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

#line 41 "GridSpiral.cpp"
#include <string>
#include <vector>

class GridSpiral {
public:
    long long findCell(int D) {
	if (D % 2 == 0) {
	    return -1;
	}
	if (D <= 7) {
	    return 0;
	}
	LL n = (D - 7) / 2;
	if (n % 2 == 0) {
	    return (n/2) * ((n/2) + 1);
	}
	return (n/2) * ((n/2) + 1) + n/2 + 1;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
There is an infinite square grid. Each cell of the grid contains a non-negative integer, and each non-negative integer appears in exactly one cell.


Two cells of the grid are called adjacent if they share a side.


The integers are arranged into a spiral that starts with the number 0.
For each n, the cells that contain numbers n and n+1 are adjacent.
If you start at 0 and walk along the spiral, your sequence of steps will be as follows: 1 step up, 1 step right, 2 steps down, 2 steps left, 3 steps up, 3 steps right, 4 steps down, and so on.


Beginning of the spiral:


    9 10 11 12
    8  1  2 13
    7  0  3 14
..  6  5  4 15
.. .. .. .. 16


You are given the int D: a difference we want to find in the grid.
Find and return the smallest x such that the cells that contain x and x+D are adjacent.
If there is no such x, return -1 instead.


DEFINITION
Class:GridSpiral
Method:findCell
Parameters:int
Returns:long long
Method signature:long long findCell(int D)


NOTES
-It is guaranteed that whenever an answer exists, it fits into a long long.


CONSTRAINTS
-D will be between 1 and 10^9, inclusive.


EXAMPLES

0)
5

Returns: 0

Cells with values 0 and 5 are adjacent: a step down from cell 0 will take you to cell 5.

1)
11

Returns: 2

The cell with value 13 is to the right of the cell with value 2. Cells 0 and 11 are not adjacent and neither are 1 and 12, so 2 is the smallest cell with the desired property.

2)
47

Returns: 110



3)
100

Returns: -1



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
		cout << "Testing GridSpiral (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1594292703;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		GridSpiral _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int D = 5;
				_expected = 0LL;
				_received = _obj.findCell(D); break;
			}
			case 1:
			{
				int D = 11;
				_expected = 2LL;
				_received = _obj.findCell(D); break;
			}
			case 2:
			{
				int D = 47;
				_expected = 110LL;
				_received = _obj.findCell(D); break;
			}
			case 3:
			{
				int D = 100;
				_expected = -1LL;
				_received = _obj.findCell(D); break;
			}
			/*case 4:
			{
				int D = ;
				_expected = LL;
				_received = _obj.findCell(D); break;
			}*/
			/*case 5:
			{
				int D = ;
				_expected = LL;
				_received = _obj.findCell(D); break;
			}*/
			/*case 6:
			{
				int D = ;
				_expected = LL;
				_received = _obj.findCell(D); break;
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
