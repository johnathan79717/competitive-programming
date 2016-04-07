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

struct TheArray {
  int find(int n, int d, int first, int last) {
  	int lb = max(first, last), ub = 1e9 + 1001;
  	while(ub - lb > 1) {
  		int m = lb + (ub - lb) / 2;
	  	int a = first;
	  	bool rev = false;
	  	REP(i, n-1) {
	  		if(a >= m) {
	  			a = m;
	  			rev = true;
	  		}
	  		if(rev) a -= d;
	  		else a += d;
	  	}
	  	if(rev && a <= last)
	  		lb = m;
	  	else
	  		ub = m;
  	}
  	return lb;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
John has an array of n integers.
Each pair of neighboring elements differs by at most d.
The first and the last elements of the array are equal to 
first and last, respectively.


Brus does not know John's array.
He only knows n, d, first and last.
He wants to compute the maximal possible element John 
might have in his array.


You are given ints n, d, first and last.
Return the maximal possible element the array might contain.


DEFINITION
Class:TheArray
Method:find
Parameters:int, int, int, int
Returns:int
Method signature:int find(int n, int d, int first, int last)


NOTES
-The constraints given below guarantee that there will 
always be at least one array that matches the values Brus 
knows.
-For the constraints given below, the correct answer will 
always fit into an int.


CONSTRAINTS
-n will be between 2 and 1,000,000, inclusive.
-d will be between 0 and 1000, inclusive.
-first will be between -1000 and 1000, inclusive.
-last will be between -1000 and 1000, inclusive.
-|first - last| will be at most (n-1)*d.


EXAMPLES

0)
3
5
2
4

Returns: 7

Only the second element of the array is unknown.
Its maximal valid value is 7.


1)
10
100
999
100

Returns: 999

Due to the limitations, the first element is the largest 
element of the array.

2)
1000000
0
474
474

Returns: 474

All elements of the array are equal.

3)
97
53
-92
441

Returns: 2717



4)
99
3
-743
-619

Returns: -535



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
		cout << "Testing TheArray (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396670629;
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
		TheArray _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				int d = 5;
				int first = 2;
				int last = 4;
				_expected = 7;
				_received = _obj.find(n, d, first, last); break;
			}
			case 1:
			{
				int n = 10;
				int d = 100;
				int first = 999;
				int last = 100;
				_expected = 999;
				_received = _obj.find(n, d, first, last); break;
			}
			case 2:
			{
				int n = 1000000;
				int d = 0;
				int first = 474;
				int last = 474;
				_expected = 474;
				_received = _obj.find(n, d, first, last); break;
			}
			case 3:
			{
				int n = 97;
				int d = 53;
				int first = -92;
				int last = 441;
				_expected = 2717;
				_received = _obj.find(n, d, first, last); break;
			}
			case 4:
			{
				int n = 99;
				int d = 3;
				int first = -743;
				int last = -619;
				_expected = -535;
				_received = _obj.find(n, d, first, last); break;
			}
			/*case 5:
			{
				int n = ;
				int d = ;
				int first = ;
				int last = ;
				_expected = ;
				_received = _obj.find(n, d, first, last); break;
			}*/
			/*case 6:
			{
				int n = ;
				int d = ;
				int first = ;
				int last = ;
				_expected = ;
				_received = _obj.find(n, d, first, last); break;
			}*/
			/*case 7:
			{
				int n = ;
				int d = ;
				int first = ;
				int last = ;
				_expected = ;
				_received = _obj.find(n, d, first, last); break;
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
