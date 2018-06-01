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
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#line 40 "MinimizeAbsoluteDifferenceDiv1.cpp"
#include <string>
#include <vector>
class MinimizeAbsoluteDifferenceDiv1 {
public:
  vector <int> findTuple(vector <int> x) {
    int a[] = {0, 1, 2, 3, 4};
    VI b(4);
    int ap = 0, aq = 1;
    do {
      int p = x[a[1]] * x[a[3]], q = abs(x[a[0]] * x[a[3]] - x[a[1]] * x[a[2]]);
      if (1ll * ap * q < 1ll * aq * p) {
	ap = p;
	aq = q;
	REP(i, 4) {
	  b[i] = a[i];
	}
      }
    } while (next_permutation(a, a+5));
    return b;
  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You are given a vector <int> x that contains exactly five positive integers.
You want to put four of them instead of the question marks into the following expression: | (?/?) - (?/?) |.
Which numbers should you put there and in what order, if your goal is to make the value of the expression as small as possible?



More formally, you have the following expression: | (xa / xb) - (xc / xd) |.
Here, "/" denotes real division (e.g., 7/2 = 3.5) and "||" denotes absolute value.
You want to find the four distinct subscripts a, b, c, d for which the value of the expression is minimized.



Return a vector <int> with four elements: the optimal subscripts {a, b, c, d}.
If there are multiple optimal answers, return the lexicographically smallest one among them.


DEFINITION
Class:MinimizeAbsoluteDifferenceDiv1
Method:findTuple
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> findTuple(vector <int> x)


NOTES
-Given two distinct arrays A and B with the same number of elements, we say that A is lexicographically smaller than B if A has a smaller value at the first index at which they differ.


CONSTRAINTS
-x will contain exactly five elements.
-Each element of x will be between 1 and 10,000, inclusive.


EXAMPLES

0)
{1,1,1,1,1}

Returns: {0, 1, 2, 3 }

Regardless of our choice of subscripts, the expression always evaluates to | (1/1) - (1/1) | = |1-1| = 0. The lexicographically smallest optimal solution is {0, 1, 2, 3}.

1)
{2,3,5,7,11}

Returns: {0, 3, 1, 4 }

Both {0, 3, 1, 4} ans {1, 4, 0, 3} would minimize the given expression, but {0, 3, 1, 4} comes lexicographically first, so that is the only correct answer.
The corresponding expression is |(2/7) - (3/11)| = 0.012987


2)
{8, 2, 4, 2, 6}

Returns: {1, 0, 3, 4 }

There are four sets of subscripts that minimize the given expression: {1, 0, 3, 4}, {1, 4, 3, 0}, {3, 0, 1, 4}, and {3, 4, 1, 0}.


3)
{124, 182, 9, 33, 70}

Returns: {2, 4, 3, 1 }



4)
{9947, 3, 7, 11, 13}

Returns: {1, 4, 3, 0 }



5)
{10000, 4, 10, 4, 10}

Returns: {1, 2, 3, 4 }

The smallest possible value of our expression is |(4/10) - (4/10)| = 0.

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
		cout << "Testing MinimizeAbsoluteDifferenceDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1523723065;
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
		MinimizeAbsoluteDifferenceDiv1 _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {1,1,1,1,1};
				int __expected[] = {0, 1, 2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findTuple(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {2,3,5,7,11};
				int __expected[] = {0, 3, 1, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findTuple(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {8, 2, 4, 2, 6};
				int __expected[] = {1, 0, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findTuple(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {124, 182, 9, 33, 70};
				int __expected[] = {2, 4, 3, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findTuple(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {9947, 3, 7, 11, 13};
				int __expected[] = {1, 4, 3, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findTuple(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {10000, 4, 10, 4, 10};
				int __expected[] = {1, 2, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findTuple(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			/*case 6:
			{
				int x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findTuple(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findTuple(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findTuple(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
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
